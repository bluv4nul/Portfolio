struct Pair<T> {
    x: T,
    y: T,
}

impl<T> Pair<T> {
    fn get_values(&self) -> (&T, &T) {
        (&self.x, &self.y)
    }
    fn change_values(&mut self, new_x: T, new_y: T){
        self.x = new_x;
        self.y = new_y;
    }
}

fn main() {
    let mut pair = Pair { x: 25, y: 52 };
    let (x, y) = pair.get_values();
    println!("x: {}, y: {}", x, y);
    pair.change_values(52, 25);
    let (x, y) = pair.get_values();
    println!("x: {}, y: {}", x, y);
}
