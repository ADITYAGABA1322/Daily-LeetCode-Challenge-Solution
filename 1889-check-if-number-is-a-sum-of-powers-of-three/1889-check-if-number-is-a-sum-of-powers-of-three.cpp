class Solution {
public:
    bool checkPowersOfThree(int n) {
        // we need to chekc if n is div by 3 or not first if it then we check that no if its is div means then waht we do we check the sum of thrii powers in distinct using the loop and check the power of 3 one by if in any time sum is equal to n then true else false ok
        while(n > 0){
            if(n%3 == 2)  return false;
            n /= 3;
        }
        return true;
    }
};