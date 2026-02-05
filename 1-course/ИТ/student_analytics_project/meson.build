###############################################################################
# meson.build для проекта "Анализ успеваемости студентов"
#
# Этот файл описывает конфигурацию сборки проекта с использованием системы Meson.
# Он включает настройки проекта, зависимости, исходные файлы и правила сборки.
#
# Дата: 22.05.2025
#
# Для студентов:
# Этот файл также, как и другие файлы проета, демонстрирует типовой корпоративный подход
# к организации сборки проекта, но уже с использованием современной системы сборки Meson.
# Внимательно изучите комментарии и структуру файла, чтобы понять принципы декларативного
# описания проектов.
###############################################################################

# Определение проекта
# project(): задает имя проекта, используемые языки и версию
# version: версия проекта
# default_options: настройки по умолчанию для проекта
project('student_analytics', 'c',
        version : '1.0.0',
        default_options : [
          'warning_level=3',           # Высокий уровень предупреждений
          'c_std=c11',                 # Используем стандарт C11
          'buildtype=debugoptimized'   # Оптимизация с отладочной информацией
        ])

# Вывод информации о конфигурации
message('Конфигурация проекта "Анализ успеваемости студентов"')
message('Версия: @0@'.format(meson.project_version()))
message('Директория исходников: @0@'.format(meson.source_root()))
message('Директория сборки: @0@'.format(meson.build_root()))

# Поиск зависимостей
# dependency(): ищет внешнюю библиотеку через pkg-config или другие механизмы
# required: указывает, что библиотека обязательна для сборки
# Meson автоматически добавит нужные флаги компиляции и линковки
message('Поиск зависимостей...')

# Математическая библиотека (стандартная)
cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : true)
message('Библиотека math: найдена')

# GSL (GNU Scientific Library)
gsl_dep = dependency('gsl', required : true)
message('Библиотека GSL: найдена')

# libcurl для работы с HTTP
curl_dep = dependency('libcurl', required : true)
message('Библиотека libcurl: найдена')

# Определение директорий проекта
# include_directories(): определяет директории для поиска заголовочных файлов
inc_dir = include_directories('include')

# Список исходных файлов
# Явно перечисляем все исходные файлы для лучшего контроля
src_files = [
  'src/main.c',
  'src/student.c',
]

# Создание исполняемого файла
# executable(): определяет цель сборки - исполняемый файл
# sources: список исходных файлов
# include_directories: директории для поиска заголовочных файлов
# dependencies: зависимости (внешние библиотеки)
# install: нужно ли устанавливать исполняемый файл в систему
executable('student_analytics',
           sources : src_files,
           include_directories : inc_dir,
           dependencies : [m_dep, gsl_dep, curl_dep],
           install : true)

# Настройка тестов
# Создаем тестовые данные и проверяем работу программы
test_data = custom_target('test_data',
                         output : 'students.csv',
                         command : [
                           find_program('mkdir', required : true), '-p', 'data'
                         ],
                         build_by_default : true)

# Определение тестов
# test(): определяет тест для запуска
# args: аргументы командной строки для программы
test('generate_data',
     executable('student_analytics', sources : src_files, include_directories : inc_dir, dependencies : [m_dep, gsl_dep, curl_dep]),
     args : ['generate', 'data/students.csv', '20'],
     workdir : meson.source_root())

test('calculate_stats',
     executable('student_analytics', sources : src_files, include_directories : inc_dir, dependencies : [m_dep, gsl_dep, curl_dep]),
     args : ['stats', 'data/students.csv'],
     workdir : meson.source_root(),
     depends : [test_data])

test('sort_students',
     executable('student_analytics', sources : src_files, include_directories : inc_dir, dependencies : [m_dep, gsl_dep, curl_dep]),
     args : ['sort', 'data/students.csv', 'average', 'data/report.csv'],
     workdir : meson.source_root(),
     depends : [test_data])

# Вывод итоговой информации
message('Конфигурация завершена успешно!')
message('Для сборки проекта выполните:')
message('  meson compile -C <директория_сборки>')
message('Для запуска тестов выполните:')
message('  meson test -C <директория_сборки>')

###############################################################################
# Инструкция по использованию:
#
# 1. Создание директории сборки:
#    meson setup build
#
# 2. Компиляция проекта:
#    meson compile -C build
#
# 3. Запуск тестов:
#    meson test -C build
#
# 4. Запуск программы:
#    ./build/student_analytics <команда> [аргументы]
#
# 5. Очистка:
#    rm -rf build
###############################################################################
