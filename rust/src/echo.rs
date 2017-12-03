use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    for (i, v) in args.iter().enumerate() {
        if i == 0 {
            continue;
        }
        let sp = if i == 1 { "" } else { " " };
        print!("{}{}", sp, v);
    }
    print!("\n");
}
