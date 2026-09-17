import matplotlib.pyplot as plt
from matplotlib.widgets import Button, Slider, RadioButtons

from config import (
    WIDTH,
    HEIGHT,
    cmap,
    params,
    MAX_STATE,
)

from model import (
    create_grid,
    update_grid,
    has_fire,
    ignite_dot,
    draw_firebreak,
)


# -------------------------
# Основная функция симуляции
# -------------------------
def run_simulation(grid, params):
    simulation_started = False
    mode = None
    step = 0
    brush_size = 2

    plt.ion()

    # -------------------------
    # Окно программы
    # -------------------------
    fig = plt.figure(figsize=(13, 8))

    # Основное поле симуляции
    ax = fig.add_axes([0.05, 0.16, 0.60, 0.78])

    image = ax.imshow(
        grid,
        cmap=cmap,
        vmin=0,
        vmax=MAX_STATE,
        interpolation="nearest",
    )

    ax.axis("off")

    # -------------------------
    # Кнопки снизу
    # -------------------------
    generate_surface_button = Button(
        fig.add_axes([0.04, 0.04, 0.17, 0.06]),
        "Новая территория",
    )

    select_fire_button = Button(
        fig.add_axes([0.23, 0.04, 0.17, 0.06]),
        "Поставить пожар",
    )

    random_fire_button = Button(
        fig.add_axes([0.42, 0.04, 0.17, 0.06]),
        "Случайный пожар",
    )

    draw_firebreak_button = Button(
        fig.add_axes([0.61, 0.04, 0.17, 0.06]),
        "Рисовать разрыв",
    )

    normal_mode_button = Button(
        fig.add_axes([0.80, 0.04, 0.16, 0.06]),
        "Обычный режим",
    )

    # -------------------------
    # Выбор направления ветра
    # -------------------------
    fig.text(
        0.72,
        0.93,
        "Направление ветра",
        fontsize=11,
        fontweight="bold",
    )

    wind_direction_radio = RadioButtons(
        fig.add_axes([0.72, 0.73, 0.22, 0.18]),
        ("вверх", "вниз", "влево", "вправо"),
        active=("up", "down", "left", "right").index(params["wind_direction"]),
    )

    # -------------------------
    # Ползунки параметров справа
    # -------------------------
    fire_prob_slider = Slider(
        fig.add_axes([0.74, 0.62, 0.20, 0.03]),
        "Вероятность",
        0.0,
        1.0,
        valinit=params["fire_probability"],
    )

    humidity_slider = Slider(
        fig.add_axes([0.74, 0.54, 0.20, 0.03]),
        "Влажность",
        0.0,
        1.0,
        valinit=params["humidity"],
    )

    wind_slider = Slider(
        fig.add_axes([0.74, 0.46, 0.20, 0.03]),
        "Ветер",
        0.0,
        1.0,
        valinit=params["wind_strength"],
    )

    density_slider = Slider(
        fig.add_axes([0.74, 0.38, 0.20, 0.03]),
        "Плотность",
        0.0,
        1.0,
        valinit=params["forest_density"],
    )

    brush_slider = Slider(
        fig.add_axes([0.74, 0.30, 0.20, 0.03]),
        "Кисть",
        1,
        6,
        valinit=brush_size,
        valstep=1,
    )

    spark_slider = Slider(
        fig.add_axes([0.74, 0.22, 0.20, 0.03]),
        "Искра",
        0.0,
        0.3,
        valinit=params["spark_probability"],
    )

    # -------------------------
    # Обработчики кнопок
    # -------------------------
    def on_random_button_click(event):
        nonlocal grid
        nonlocal simulation_started
        nonlocal mode
        nonlocal step

        grid = ignite_dot(grid)

        image.set_data(grid)
        ax.set_title("Пожар запущен из случайной точки")
        fig.canvas.draw_idle()

        step = 0
        mode = None
        simulation_started = True

    def on_select_fire_button_click(event):
        nonlocal mode
        nonlocal simulation_started

        if simulation_started:
            return

        mode = "place_fire"
        ax.set_title("Выберите клетку для начала пожара")
        fig.canvas.draw_idle()

    def on_generate_surface_button_click(event):
        nonlocal grid
        nonlocal simulation_started
        nonlocal mode
        nonlocal step

        simulation_started = False
        mode = None
        step = 0

        grid = create_grid(params)

        image.set_data(grid)
        ax.set_title("Создана новая территория")
        fig.canvas.draw_idle()

    def on_draw_firebreak_button_click(event):
        nonlocal mode
        nonlocal simulation_started

        if simulation_started:
            return

        mode = "draw_firebreak"
        ax.set_title("Режим рисования препятствий")
        fig.canvas.draw_idle()

    def on_normal_mode_button_click(event):
        nonlocal mode

        mode = None
        ax.set_title("Обычный режим")
        fig.canvas.draw_idle()

    # -------------------------
    # Обработка клика мыши
    # -------------------------
    def on_mouse_click(event):
        nonlocal grid
        nonlocal simulation_started
        nonlocal mode
        nonlocal step

        if event.inaxes != ax:
            return

        if event.xdata is None or event.ydata is None:
            return

        i = int(event.ydata)
        j = int(event.xdata)

        if i < 0 or j < 0 or i >= HEIGHT or j >= WIDTH:
            return

        # Режим постановки пожара
        if mode == "place_fire":
            grid = ignite_dot(grid, i, j)

            image.set_data(grid)
            ax.set_title("Пожар запущен из выбранной точки")
            fig.canvas.draw_idle()

            step = 0
            simulation_started = True
            mode = None

        # Режим рисования препятствий
        elif mode == "draw_firebreak":
            grid = draw_firebreak(grid, i, j, brush_size)

            image.set_data(grid)
            ax.set_title("Препятствие добавлено")
            fig.canvas.draw_idle()

    # -------------------------
    # Рисование препятствий зажатой мышью
    # -------------------------
    def on_mouse_move(event):
        nonlocal grid
        nonlocal mode

        if mode != "draw_firebreak":
            return

        if event.inaxes != ax:
            return

        if event.button != 1:
            return

        if event.xdata is None or event.ydata is None:
            return

        i = int(event.ydata)
        j = int(event.xdata)

        if i < 0 or j < 0 or i >= HEIGHT or j >= WIDTH:
            return

        grid = draw_firebreak(grid, i, j, brush_size)

        image.set_data(grid)
        fig.canvas.draw_idle()

    # -------------------------
    # Обновление параметров с ползунков
    # -------------------------
    def update_params(val):
        params["fire_probability"] = fire_prob_slider.val
        params["humidity"] = humidity_slider.val
        params["wind_strength"] = wind_slider.val
        params["forest_density"] = density_slider.val
        params["spark_probability"] = spark_slider.val

    def update_wind_direction(label):
        directions = {
            "вверх": "up",
            "вниз": "down",
            "влево": "left",
            "вправо": "right",
        }

        params["wind_direction"] = directions[label]
        ax.set_title(f"Направление ветра: {label}")
        fig.canvas.draw_idle()

    def update_brush_size(val):
        nonlocal brush_size

        brush_size = int(brush_slider.val)

    # -------------------------
    # Подключение обработчиков
    # -------------------------
    random_fire_button.on_clicked(on_random_button_click)
    select_fire_button.on_clicked(on_select_fire_button_click)
    generate_surface_button.on_clicked(on_generate_surface_button_click)
    draw_firebreak_button.on_clicked(on_draw_firebreak_button_click)
    normal_mode_button.on_clicked(on_normal_mode_button_click)

    fig.canvas.mpl_connect("button_press_event", on_mouse_click)
    fig.canvas.mpl_connect("motion_notify_event", on_mouse_move)

    fire_prob_slider.on_changed(update_params)
    humidity_slider.on_changed(update_params)
    wind_slider.on_changed(update_params)
    density_slider.on_changed(update_params)
    spark_slider.on_changed(update_params)
    brush_slider.on_changed(update_brush_size)
    wind_direction_radio.on_clicked(update_wind_direction)

    ax.set_title("Выберите способ запуска пожара")
    fig.canvas.draw_idle()

    # -------------------------
    # Главный цикл программы
    # -------------------------
    while plt.fignum_exists(fig.number):
        if simulation_started:
            if has_fire(grid):
                image.set_data(grid)
                ax.set_title(f"Fire Simulation — Step {step}")
                fig.canvas.draw_idle()

                plt.pause(0.05)

                grid = update_grid(grid, params)
                step += 1

            else:
                image.set_data(grid)
                ax.set_title(f"Fire Simulation — Finished at step {step}")
                fig.canvas.draw_idle()

                simulation_started = False

        else:
            plt.pause(0.1)

    plt.ioff()


def main():
    grid = create_grid(params)
    run_simulation(grid, params)


if __name__ == "__main__":
    main()
