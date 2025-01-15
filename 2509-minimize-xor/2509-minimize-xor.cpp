class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // we nned to first convert num1 and num2 in binary and then check the xor operation between an int which xor operation is minimal ok  means that int xor with num1 and same set bits in nums2 ok done we convert first and find and check xor and saem set bits as num2 ok done 
        int setN2 = cntBits(num2);
        int setN1 = cntBits(num1);

        if(setN1 > setN2) return reduce(num1 , setN2);
        else if(setN1 < setN2) return inc(num1 , setN2);
        else  return num1;
    }
    int cntBits(int num){
        return bitset<32>(num).count();
    }
    int reduce(int num , int target){
        for(int i=0; i<32 && cntBits(num) > target; i++){
            if(num & (1<< i)) num &= ~(1<<i);
        }
        return num;
    }
    int inc(int num , int target){
        for(int i=0; i<32 && cntBits(num) < target; i++){
            if(!(num & (1<<i))) num |= (1<<i);
        }
        return num;
    }
};