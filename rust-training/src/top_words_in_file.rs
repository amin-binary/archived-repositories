use std::collections::HashMap;
use std::fs::File;
use std::io;
use std::io::prelude::*;

pub fn top_words_in_file(file_path: &str, count: usize) -> io::Result<Vec<String>> {
    let file = File::open(file_path)?;
    let mut content = String::new();
    io::BufReader::new(file).read_to_string(&mut content)?;

    let mut map = HashMap::new();

    for word in content.split_whitespace() {
        let stat = map.entry(word).or_insert(0);
        *stat += 1;
    }

    let mut all: Vec<(&str, u32)> = map.iter().map(|(word, stat)| (*word, *stat)).collect();
    all.sort_by(|(_, a), (_, b)| b.cmp(a));

    let vec = all
        .iter()
        .take(count)
        .map(|(word, _)| String::from(*word))
        .collect();

    Ok(vec)
}

#[test]
fn test_top_words_in_file() {
    let top = top_words_in_file(
        "/Users/amin/projects/rust-training/src/top_words_in_file.rs",
        2,
    )
    .unwrap();
    assert_eq!(top, ["=", "let"]);
}
