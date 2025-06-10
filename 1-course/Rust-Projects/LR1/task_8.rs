struct Employee{
    name: String,
    position: Position,
    salary: u32
}

#[derive(PartialEq)]
enum Position{
    TeamLead,
    Designer,
    Developer
}

impl Position{
    fn display_name(&self)->&'static str{
        match self {
            Position::Designer => "Дизайнер",
            Position::Developer => "Инженер-Разработчик",
            Position::TeamLead => "Тим Лид"
        }
    }
}

impl Employee{
    fn employee_info(&self){
        println!("--Информация о работнике--");
        println!("Имя: {}", self.name);
        println!("Должность: {}", self.position.display_name());
        println!("Зарплата: {} руб.", self.salary);
        println!("\n");
    }
}

fn employee_by_position(employees: &[Employee], position: Position) -> Vec<&Employee>{
    employees.iter().filter(|emp| emp.position == position).collect()
}
fn main(){
    let employees = vec![
        Employee {name: "John".to_string(), position: Position::Designer, salary: 250000},
        Employee {name: "Vasya".to_string(), position: Position::Developer, salary: 300000},
        Employee {name: "Petrusha".to_string(), position: Position::TeamLead, salary: 500000},
        Employee {name: "Mattew".to_string(), position: Position::Designer, salary: 250000},
        Employee {name: "Bob".to_string(), position: Position::Designer, salary: 350000},
        Employee {name: "Iluha".to_string(), position: Position::Developer, salary: 250000},
    ];

    let designeers = employee_by_position(&employees, Position::Designer);
    let developers = employee_by_position(&employees, Position::Developer);
    let team_lead = employee_by_position(&employees, Position::TeamLead);

    println!("Дизайнеры: ");
    for el in designeers{
        el.employee_info();
    }

    println!("Инженеры-Разработчики: ");
    for el in developers{
        el.employee_info();
    }

    println!("Тим Лид:");
    for el in team_lead{
        el.employee_info();
    }
}