pub fn two_crystal_balls(breaks: &[bool]) -> Option<usize> {
    let jump_amount = (breaks.len() as f64).sqrt() as usize; // isqrt is nightly only at the moment
    let mut i = jump_amount;

    while i < breaks.len() {
        if breaks[i] {
            break;
        }

        i += jump_amount;
    }

    i -= jump_amount;

    for _ in 0..jump_amount {
        if i > breaks.len() {
            break;
        }

        if breaks[i] {
            return Some(i);
        }

        i += 1;
    }

    None
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn two_crystal_balls_some() {
        let breaks = [false, false, false, false, false, true, true, true, true];
        let result = two_crystal_balls(&breaks);

        assert_eq!(result, Some(5));
    }

    #[test]
    fn two_crystal_balls_none() {
        let breaks = [false, false, false, false, false, false, false, false];
        let result = two_crystal_balls(&breaks);

        assert_eq!(result, None);
    }
}
