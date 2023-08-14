2369. Check if There is a Valid Partition For The Array


13 Aug 2023


Medium



C++:

// Time Complexity : O(n) where n is the size of the vector nums and space complexity is O(1)

class Solution {
public:
   bool validPartition(vector<int>& nums) {
        int n = nums.size(); // variable to store the size of the vector nums
        vector<bool> dp(n+1, false);  // vector to store the result
        dp[0] = true;
        for(int i=0; i<n; i++){
            bool ans = false; // variable to store the ans
            int index = i+1; // variable to store the dpindex
           if(i>0 && nums[i] == nums[i-1]) ans |= dp[(index-2)%3]; // if the current element is equal to the previous element
            if(i>1 && nums[i] == nums[i-1] && nums[i] == nums[i-2]) ans |= dp[(index-3)%3]; // if the current element is equal to the previous two elements
            if(i>1 && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2]+2) ans |= dp[(index-3)%3]; // if the current element is equal to the previous two elements
            dp[index%3] = ans; // update the dp
    }
    return dp[n%3]; // return the dp[n%3]
    }

};


Java:

// Time Complexity : O(n) where n is the size of the vector nums and space complexity is O(1)

class Solution {
    public boolean validPartition(int[] nums) {
        int n = nums.length; // variable to store the size of the vector nums
        boolean[] dp = new boolean[3];  // vector to store the result
        dp[0] = true;
        for(int i=0; i<n; i++){
            boolean ans = false; // variable to store the ans
            int index = i+1; // variable to store the dpindex
           if(i>0 && nums[i] == nums[i-1]) ans |= dp[(index-2)%3]; // if the current element is equal to the previous element
            if(i>1 && nums[i] == nums[i-1] && nums[i] == nums[i-2]) ans |= dp[(index-3)%3]; // if the current element is equal to the previous two elements
            if(i>1 && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2]+2) ans |= dp[(index-3)%3]; // if the current element is equal to the previous two elements
            dp[index%3] = ans; // update the dp
    }
    return dp[n%3]; // return the dp[n%3]
    }
}




Python:


// Time Complexity : O(n) where n is the size of the vector nums and space complexity is O(1)

class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums) # variable to store the size of the vector nums
        dp = [False]*3  # vector to store the result
        dp[0] = True
        for i in range(n):
            ans = False # variable to store the ans
            index = i+1 # variable to store the dpindex
            if i>0 and nums[i] == nums[i-1]: ans |= dp[(index-2)%3] # if the current element is equal to the previous element
            if i>1 and nums[i] == nums[i-1] and nums[i] == nums[i-2]: ans |= dp[(index-3)%3] # if the current element is equal to the previous two elements
            if i>1 and nums[i] == nums[i-1]+1 and nums[i] == nums[i-2]+2: ans |= dp[(index-3)%3] # if the current element is equal to the previous two elements
            dp[index%3] = ans # update the dp
        return dp[n%3] # return the dp[n%3]




Python3:

// Time Complexity : O(n) where n is the size of the vector nums and space complexity is O(1)

class Solution:
    def validPartition(self, nums: List[int) -> bool:  // add the missing bracket after int 
        n = len(nums) # variable to store the size of the vector nums
        dp = [False]*3  # vector to store the result
        dp[0] = True
        for i in range(n):
            ans = False # variable to store the ans
            index = i+1 # variable to store the dpindex
            if i>0 and nums[i] == nums[i-1]: ans |= dp[(index-2)%3] # if the current element is equal to the previous element
            if i>1 and nums[i] == nums[i-1] and nums[i] == nums[i-2]: ans |= dp[(index-3)%3] # if the current element is equal to the previous two elements
            if i>1 and nums[i] == nums[i-1]+1 and nums[i] == nums[i-2]+2: ans |= dp[(index-3)%3] # if the current element is equal to the previous two elements
            dp[index%3] = ans # update the dp
        return dp[n%3] # return the dp[n%3]



C:

// Time Complexity : O(n) where n is the size of the vector nums and space complexity is O(1)

bool validPartition(int* nums, int numsSize){
    int n = numsSize; // variable to store the size of the vector nums
    bool dp[3];  // vector to store the result
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for(int i=0; i<n; i++){
        bool ans = false; // variable to store the ans
        int index = i+1; // variable to store the dpindex
        if(i>0 && nums[i] == nums[i-1]) ans |= dp[(index-2)%3]; // if the current element is equal to the previous element
        if(i>1 && nums[i] == nums[i-1] && nums[i] == nums[i-2]) ans |= dp[(index-3)%3]; // if the current element is equal to the previous two elements
        if(i>1 && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2]+2) ans |= dp[(index-3)%3]; // if the current element is equal to the previous two elements
        dp[index%3] = ans; // update the dp
    }
    return dp[n%3]; // return the dp[n%3]
}




C#:

// Time Complexity : O(n) where n is the size of the vector nums and space complexity is O(1)

public class Solution {
    public bool ValidPartition(int[] nums) {
        int n = nums.Length; // variable to store the size of the vector nums
        bool[] dp = new bool[3];  // vector to store the result
        dp[0] = true;
        for(int i=0; i<n; i++){
            bool ans = false; // variable to store the ans
            int index = i+1; // variable to store the dpindex
            if(i>0 && nums[i] == nums[i-1]) ans |= dp[(index-2)%3]; // if the current element is equal to the previous element
            if(i>1 && nums[i] == nums[i-1] && nums[i] == nums[i-2]) ans |= dp[(index-3)%3]; // if the current element is equal to the previous two elements
            if(i>1 && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2]+2) ans |= dp[(index-3)%3]; // if the current element is equal to the previous two elements
            dp[index%3] = ans; // update the dp
    }
    return dp[n%3]; // return the dp[n%3]
    }
}



JavaScript:

                                        
// Time Complexity : O(n) where n is the size of the vector nums and space complexity is O(1)

var validPartition = function(nums) {
    let n = nums.length; // variable to store the size of the vector nums
    let dp = new Array(3).fill(false);  // vector to store the result
    dp[0] = true;
    for(let i=0; i<n; i++){
        let ans = false; // variable to store the ans
        let index = i+1; // variable to store the dpindex
        if(i>0 && nums[i] == nums[i-1]) ans |= dp[(index-2)%3]; // if the current element is equal to the previous element
        if(i>1 && nums[i] == nums[i-1] && nums[i] == nums[i-2]) ans |= dp[(index-3)%3]; // if the current element is equal to the previous two elements
        if(i>1 && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2]+2) ans |= dp[(index-3)%3]; // if the current element is equal to the previous two elements
        dp[index%3] = ans; // update the dp
    }
    return dp[n%3]; // return the dp[n%3]
};



Swift:

// Time Complexity : O(n) where n is the size of the vector nums and space complexity is O(1)

class Solution {
    func validPartition(_ nums: [Int]) -> Bool {
        let n = nums.count; // variable to store the size of the vector nums
        var dp = [Bool](repeating: false, count: 3);  // vector to store the result
        dp[0] = true;
        for i in 0..<n{
            var ans = false; // variable to store the ans
            let index = i+1; // variable to store the dpindex
            if i>0 && nums[i] == nums[i-1]{ ans = ans || dp[(index-2)%3]; } // if the current element is equal to the previous element
            if i>1 && nums[i] == nums[i-1] && nums[i] == nums[i-2]{ ans = ans || dp[(index-3)%3]; } // if the current element is equal to the previous two elements
            if i>1 && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2]+2{ ans = ans || dp[(index-3)%3]; } // if the current element is equal to the previous two elements
            dp[index%3] = ans; // update the dp
        }
        return dp[n%3]; // return the dp[n%3]
    }
}




Dart:
