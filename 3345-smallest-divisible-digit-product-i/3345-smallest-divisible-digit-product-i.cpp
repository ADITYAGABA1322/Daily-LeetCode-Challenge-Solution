class Solution {
public:
    int smallestNumber(int n, int t) {
        auto check = [&](int num) -> bool {
            int product = 1;
            while(num > 0){
                product *= (num % 10);
                num /= 10;
                // if(!product){
                //     break;
                // }
            }
            return  product % t == 0;
        };
        while(!check(n)){
            n++;
        }
        return n;
    }
};