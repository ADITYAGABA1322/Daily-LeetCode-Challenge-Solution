class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low; i<=high; i++){
            if(isSym(i)) cnt++;
        }
        return cnt;
    }
    bool isSym(int num){
        string s = to_string(num);
        int n = s.size();
        if(n % 2 == 1) return false;
        int left = 0 , right = 0;
        for(int i=0; i<n/2; i++){
            left += s[i] - '0';
            right += s[n-1-i] - '0';
        }
        return left == right;
    }
};