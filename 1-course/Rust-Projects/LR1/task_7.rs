struct Product {
    name: String,
    price: f32,
    category: Category,
}

#[derive(PartialEq)]
enum Category {
    Clothing,
    Books,
    Toys,
}

impl Category {
    fn display_name(&self) -> &'static str {
        match self {
            Category::Books => "Книги",
            Category::Toys => "Игрушки",
            Category::Clothing => "Одежда",
        }
    }
}

impl Product {
    fn product_info(&self) {
        println!("--Информация о продукте--");
        println!("Навзвание: {}", self.name);
        println!("Цена: {} руб.", self.price);
        println!("Категория: {}", self.category.display_name());
        println!("\n");
    }

    fn count_by_category(products: &[Product], category: Category) -> usize{
        let mut count: usize = 0;
        for product in products{
            if product.category == category{
                count += 1;
            }
        }
        count
    }
}

fn main() {
    let products: [Product; 6] = [
        Product {
            name: "Tун Тун Сахур".to_string(),
            price: 899.99,
            category: Category::Toys,
        },
        Product {
            name: "Гарри Поттер".to_string(),
            price: 659.99,
            category: Category::Books,
        },
        Product {
            name: "Цитаты Джейсона Стэтхема".to_string(),
            price: 339.99,
            category: Category::Books,
        },
        Product {
            name: "100 лучших рецептов для дома".to_string(),
            price: 589.99,
            category: Category::Books,
        },
        Product {
            name: "Оптимус Прайм".to_string(),
            price: 299.99,
            category: Category::Toys,
        },
        Product {
            name: "Футболка Пивозавр".to_string(),
            price: 2190.0,
            category: Category::Clothing,
        },
    ];
    
    for product in &products {
        product.product_info();
    }
    println!("Количество книг: {} шт.", Product::count_by_category(&products, Category::Books));
    println!("Количество игрушек: {} шт.", Product::count_by_category(&products, Category::Toys));
    println!("Количество одешды: {} шт.", Product::count_by_category(&products, Category::Clothing));

}
