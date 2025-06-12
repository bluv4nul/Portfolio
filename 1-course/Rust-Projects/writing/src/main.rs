use std::io;

struct ToDoList{
    task: Vec<Task>,
    next_id: usize
}

struct Task{
    id: u16,
    name: String,
    completed: bool
}

impl ToDoList{
    fn add_task(&self){
        
    }
}

impl Task {
    fn change_status(&mut self){
        self.completed = !self.completed;
    }

    fn print_task(&self){
        println!("[№ {}] {} - {}", self.id, self.name, if self.completed {"✅"} else {"❌"});
    }
}

fn interface(){
    println!("1. Вывести задачи");
    println!("2. Добавить задачу");
    println!("3. Изменить статус задачи");
    println!("4. Удалить задачу");
    println!("5. Завершить работу");
    println!("Введите действие");
}

fn main(){
    let mut to_do_list = ToDoList {task: Vec::new(), next_id: 1};
    let mut input: String = String::new();
    let mut button: u8;

loop {
    interface();
    io::stdin().read_line(&mut input).expect("Ошибка чтения");
    button = input.parse().expect("Ошибка парсинга");
    match button {
        1 => {
            if to_do_list.next_id == 1{ 
                println!("Список пуст")
            }
            else{
                for el in to_do_list{
                }
            }
        }
        2 =>
        3 =>
        4 => 
        5 => break,
        _ => 
    }
}

}