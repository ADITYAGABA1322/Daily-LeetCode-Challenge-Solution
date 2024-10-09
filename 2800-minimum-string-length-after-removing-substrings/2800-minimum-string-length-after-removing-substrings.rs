impl Solution {
    pub fn min_length(mut s: String) -> i32 {
        while s.contains("AB") || s.contains("CD"){
            if let Some(pos) = s.find("AB"){
                s.replace_range(pos..pos + 2 , "");
            } else if let Some(pos) = s.find("CD"){
                s.replace_range(pos..pos + 2 , "");
            } 
        }
        s.len() as i32
    }
}