use chrono::Local;

fn main() {
    println!("Hello from Rust");
    println!("{}", Local::now().format("%Y-%m-%d %H:%M:%S"));
}
