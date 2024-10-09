class Solution {
    func minLength(_ s: String) -> Int {
        var s = s;
        while s.contains("AB") || s.contains("CD") {
            if let range = s.range(of: "AB") {
                s.removeSubrange(range);
            } else if let range = s.range(of: "CD") {
                s.removeSubrange(range);
            }
        }
        return s.count;
    }
}