
fn fibonachi(n: i32) -> i32{
    if n == 1{
        0
    } else if n == 2{
        1
    } else {
        fibonachi(n-1)+fibonachi(n-2)
    }
}

fn main(){
    println!("6 число ряда фибоначи: {}", fibonachi(6));
    println!("10 число ряда фибоначи: {}", fibonachi(10));
    println!("11 число ряда фибоначи: {}", fibonachi(11));
}