use libc::{c_int};
 
extern "C" {
    fn times5(n: c_int) -> c_int;
}

fn main() {
    let res = unsafe { times5(5) };

    println!("Hello, world! {}", res);
}
