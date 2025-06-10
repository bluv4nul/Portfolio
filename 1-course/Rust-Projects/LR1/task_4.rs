
struct Car{
    brand: String,
    model: String,
    year: usize
}

fn main(){
    let car_1 = Car{
        brand: "Kia".to_string(),
        model: "Sorento".to_string(),
        year: 2008
    };

    let car_2 = Car{
        brand: "BMW".to_string(),
        model: "M5 G90".to_string(),
        year: 2025
    };

    let car_3 = Car{
        brand: "Mercedes".to_string(),
        model: "E63S".to_string(),
        year: 2023
    };

    println!("Машина 1: марка - {}, модель - {}, год производства - {}", car_1.brand, car_1.model, car_1.year);
    println!("Машина 2: марка - {}, модель - {}, год производства - {}", car_2.brand, car_2.model, car_2.year);
    println!("Машина 3: марка - {}, модель - {}, год производства - {}", car_3.brand, car_3.model, car_3.year);
}
