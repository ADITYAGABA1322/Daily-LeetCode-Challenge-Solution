class Solution {
    func minSwaps(_ s: String) -> Int {
        var stackSize = 0;
        let n = s.count;

        for ch in s{
            if ch == "["{
                stackSize += 1;
            } else{
                if stackSize > 0{
                    stackSize -= 1;
                }
            }
        }
        return (stackSize + 1)/2
    }
}