use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut i: i32 = 0;
    for v in args.iter() {
        if i == 0 {
            i += 1;
            continue;
        }
        let sp = if i == 1 { "" } else { " " };
        print!("{}{}", sp, v);
        i += 1;
    }
    print!("\n");
}
