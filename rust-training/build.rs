
use std::env;
use std::path::Path;
use std::process::Command;

fn main() {
    let out_dir = env::var("OUT_DIR").unwrap();
    Command::new("gcc").args(&["src/addr.c", "-c", "-fPIC", "-o"])
        .arg(&format!("{}/addr.o", out_dir))
        .status().unwrap();

    Command::new("ar").args(&["crus", "libaddr.a", "addr.o"])
        .current_dir(&Path::new(&out_dir))
        .status().unwrap();

    println!("cargo:rustc-link-lib=static=addr");
    println!("cargo:rustc-link-search=native={}", out_dir);
}
