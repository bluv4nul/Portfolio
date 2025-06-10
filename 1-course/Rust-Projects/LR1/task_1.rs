use std::io;

fn main() {
    let mut name = String::new();
    println!("Введите ваше имя: ");

    io::stdin()
        .read_line(&mut name)
        .expect("Ошибка при чтении строки");
    
    let name = name.trim();

    println!("Привет, {}!", name);
}
