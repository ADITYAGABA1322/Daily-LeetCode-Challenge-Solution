# Daily-LeetCode-Challenge-Solution




1137. N-th Tribonacci Number




30 Jan 2023
    
    

Easy

2 Approaches

C++:

1st :

// Time Complexity : O(n) where n is the number and space complexity is O(1)

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){  // if n is 0
            return 0;  // return 0
        }
        if(n == 1 || n == 2){  // if n is 1 or 2
            return 1;  // return 1
        }
        int a = 0;  // a is the first number
        int b = 1;  // b is the second number
        int c = 1;  // c is the third number
        int d = 0;  // d is the fourth number
        for(int i=3; i<=n; i++){  // for each number
            d = a + b + c;  // d is the sum of the first three numbers
            a = b;  // update the first number
            b = c;  // update the second number
            c = d;  // update the third number
        }
        return d;  // return the fourth number
    }
};




2nd:

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1);  // dp vector to store the tribonacci numbers
        dp[0] = 0;  // first number is 0
        if(n >= 1){  // if n is greater than or equal to 1
            dp[1] = 1;  // second number is 1
        }
        if(n >= 2){  // if n is greater than or equal to 2
            dp[2] = 1;  // third number is 1
        }
        for(int i=3; i<=n; i++){  // for each number
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];  // update the tribonacci number
        }
        return dp[n];  // return the tribonacci number
    }
};

              OR
              
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0 || n == 1) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
          
        }
          return dp[n];
    }
};



Java:

class Solution {
    public int tribonacci(int n) {
        if(n == 0 || n == 1) return n;
        int[] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
}


