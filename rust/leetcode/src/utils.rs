#[macro_export]
/// Macro to make a `Vec<String>` from multiple `&str` without having to type .to_string()
macro_rules! s {
    ($($x:expr),* $(,)?) => [
        vec![$($x.to_string()),*]
    ];
}
