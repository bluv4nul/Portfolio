struct Person{
    name: String,
    age: u16
}

trait PrintInfo {
    fn print_info(&self);
}

impl PrintInfo for Person{
    fn print_info(&self) {
        println!("Name: {}, Age: {}", self.name, self.age);
    }
}

fn main(){
    let tom = Person{name: "Tom".to_string(), age: 18};
    tom.print_info();
}