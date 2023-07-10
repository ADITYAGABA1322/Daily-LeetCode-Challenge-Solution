9. Palindrome Number


10 July 2023




Easy




C++:

  

// Time Complexity : O(logn) where n is the number of digits in the number and space complexity is O(1)





class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){  // if the number is negative
            return false;  // return false
        }
        int temp = x;  // variable to store the number
        long long reverse = 0;  // variable to store the reverse of the number
        while(temp){  // iterate until the number becomes 0
            reverse = reverse * 10 + temp % 10;  // update the reverse
            temp /= 10;  // update the number
        }
        return reverse == x;  // return true if the number is palindrome
    }
};





Java:  


// Time Complexity : O(logn) where n is the number of digits in the number and space complexity is O(1)





class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0){  // if the number is negative
            return false;  // return false
        }
        int temp = x;  // variable to store the number
        long reverse = 0;  // variable to store the reverse of the number
        while(temp != 0){  // iterate until the number becomes 0
            reverse = reverse * 10 + temp % 10;  // update the reverse
            temp /= 10;  // update the number
        }
        return reverse == x;  // return true if the number is palindrome
    }
}
