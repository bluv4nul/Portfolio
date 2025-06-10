use std::io;

enum  DayOfWeek{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
}

fn next_day(day: &DayOfWeek)->DayOfWeek{
    match *day {
        DayOfWeek::Monday => DayOfWeek::Tuesday,
        DayOfWeek::Tuesday =>  DayOfWeek::Wednesday,
        DayOfWeek::Wednesday =>  DayOfWeek::Thursday,
        DayOfWeek::Thursday =>  DayOfWeek::Friday, 
        DayOfWeek::Friday =>  DayOfWeek::Saturday,
        DayOfWeek::Saturday =>  DayOfWeek::Sunday,
        DayOfWeek::Sunday =>  DayOfWeek::Monday
    }
}

fn print_day(day: &DayOfWeek){
    match *day {
        DayOfWeek::Monday => println!("Monday"),
        DayOfWeek::Tuesday => println!("Tuesday"),
        DayOfWeek::Wednesday => println!("Wednesday"),
        DayOfWeek::Thursday => println!("Thursday"), 
        DayOfWeek::Friday => println!("Friday"),
        DayOfWeek::Saturday => println!("Saturday"),
        DayOfWeek::Sunday => println!("Sunday")
    }
}

fn main(){
    let mut input = String::new();
    println!("Введите день недели (Monday - 1, Tuesday - 2, Wednesday - 3, Thursday - 4, Friday - 5, Saturday - 6, Sunday - 7): ");

    io::stdin()
        .read_line(&mut input)
        .expect("Ошибка чтения строки!");
    let id: u8 = input.trim().parse().expect("Введено не число!");
    
    let  day = match id {
        1 => DayOfWeek::Monday,
        2 => DayOfWeek::Tuesday,
        3 => DayOfWeek::Wednesday,
        4 => DayOfWeek::Thursday,
        5 => DayOfWeek::Friday,
        6 => DayOfWeek::Saturday,
        7 => DayOfWeek::Sunday,
        _ => {
            println!("Введено неверное число!");
            DayOfWeek::Monday
        }
    };

    println!("Текущий день: ");
    print_day(&day);
    let next = next_day(&day);
    println!("Следующий день: ");
    print_day(&next);
    let next_next = next_day(&next);
    println!("День после следующего: ");
    print_day(&next_next);
}
