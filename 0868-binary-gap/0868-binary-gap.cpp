class Solution {
public:
    int binaryGap(int n) {
        int prev = -1 , res = 0;
        for(int curr = 0; curr<32; curr++){
            if((n>>curr) & 1){
                if(prev != -1) res = max(res , curr - prev);
                prev = curr;
            } 
        }
        return res;
    }
};