use std::io;

struct ToDoList{
    task: Vec<Task>,
    next_id: usize
}

struct Task{
    id: usize,
    name: String,
    completed: bool
}

impl ToDoList{
    fn add_task(&mut self){

        let mut name = String::new();
        println!("Введите описание задачи: ");
        io::stdin().read_line(&mut name).expect("Ошибка чтения имени");
        name.trim();

        let new_task = Task{
            id: self.next_id,
            name: name,
            completed: false
        };

        self.next_id += 1;
        self.task.push(new_task);
    }

    fn delete_task(&mut self){
        println!("Введите id задачи для удаления!");
        let mut input = String::new();

        io::stdin().read_line(&mut input).expect("Ошибка чтения строки");
        let id: usize = input.trim().parse().expect("Ошибка парсинга");
        self.task.remove(id-1);
        self.next_id -= 1;
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
    println!("5. Завершцить работу");
    println!("Введите действие");
}

fn main(){
    let mut to_do_list = ToDoList {task: Vec::new(), next_id: 1};
    let mut input: String = String::new();
    let mut button: u8;

loop {
    interface();
    io::stdin().read_line(&mut input).expect("Ошибка чтения");
    button = input.trim().parse().expect("Ошибка парсинга");
    match button {
        1 => {
            if to_do_list.next_id == 1{
                println!("Список пуст");
            } else {
                for el in &to_do_list.task{
                    el.print_task();
                }
            }
        }
        2 =>{
            to_do_list.add_task();
        }
        3 =>{
            to_do_list.task.change_status();
        }
        4 => {
            to_do_list.delete_task();
        }
        5 => break,
        _ => println!("Введено неверное число!"),
    }
}

}