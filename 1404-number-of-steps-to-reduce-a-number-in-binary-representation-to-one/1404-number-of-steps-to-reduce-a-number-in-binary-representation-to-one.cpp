class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int op = 0 , carry = 0;
        for(int i=n-1; i>0; i--){
            if(((s[i] - '0') + carry) % 2) {
                op += 2;
                carry = 1;
            }
            else op++;
        }
        return op + carry;
    }
};