258. Add Digits





Easy




26 April 2023





C++:


// Time Complexity : O(1) and space complexity is O(1)







class Solution {
public:
    int addDigits(int num) {
        if(num == 0){  // if the number is 0
            return 0;  // return 0
        }
        if(num%9 == 0){  // if the number is divisible by 9
            return 9;  // return 9
        }
        return num%9;  // return the remainder
    }
};






Java:

// Time Complexity : O(1) and space complexity is O(1)







class Solution {
    public int addDigits(int num) {
        if(num == 0){  // if the number is 0
            return 0;  // return 0
        }
        if(num%9 == 0){  // if the number is divisible by 9
            return 9;  // return 9
        }
        return num%9;  // return the remainder
    }
}



