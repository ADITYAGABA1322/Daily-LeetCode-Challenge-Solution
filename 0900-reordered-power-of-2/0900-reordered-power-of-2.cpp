class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto countDigits = [](int x){
            string s = to_string(x);
            sort(s.begin() , s.end());
            return s;
        };
        string target = countDigits(n);
        for(int i=0; i<31; i++){
            if(countDigits(1<<i) == target) return true;
        }
        return false;
    }
};