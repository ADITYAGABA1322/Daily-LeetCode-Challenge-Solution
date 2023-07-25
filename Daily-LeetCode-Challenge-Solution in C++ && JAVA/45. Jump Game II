45. Jump Game II


25 July 2023



Medium



# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The intuition behind solving Jump Game II is to keep track of the maximum reachable index from the current position and choose the next position with maximum reach. In other words, at each step, we want to jump as far as we can to reach the end of the array in the minimum number of jumps. This is a greedy approach, as we make the locally optimal choice (jumping as far as possible) at each step, which leads to the globally optimal solution.
# Approach
<!-- Describe your approach to solving the problem. -->
The approach to solve Jump Game II is as follows:

1.) Initialize variables: Set the starting position to be 0, and initialize a variable to keep track of the minimum number of jumps needed to reach the end.

2.) Iterate over the array: Keep moving forward while updating the maximum reachable index from the current position.

3.) Check if the current position has reached the end: If the current position is greater than or equal to the end, break out of the loop and return the number of jumps.

4.) Choose the next position: Select the next position with the maximum reachable index.

5.) Increment the number of jumps: Increment the number of jumps taken to reach the next position.

6.) Repeat steps 2-5 until the end is reached.

This approach has a time complexity of O(n), where n is the length of the array.

# Complexity
- Time complexity: O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code

# Daily-LeetCode-Challenge-Solution


C++:

// Time Complexity : O(n) where n is the length of the vector nums and space complexity is O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();  // variable to store the length of the vector nums
        int res = 0;  // variable to store the result
        int i = 0;  // variable to store the start index of the window
        int j = 0;  // variable to store the end index of the window
        while(j < n - 1){  // while the end index of the window is less than the length of the vector nums
            int maxIndex = j;  // variable to store the maximum index
            for(int k=i; k<=j; k++){  // for each element in the window
                maxIndex = max(maxIndex, k + nums[k]);  // update the maximum index 
            }
            i = j + 1;  // update the start index of the window
            j = maxIndex;  // update the end index of the window
            res++;  // increment the result
        }
        return res;  // return the result
    }
};




Java:


// Time Complexity : O(n) where n is the length of the vector nums and space complexity is O(1)

class Solution {
    public int jump(int[] nums) {
        int n = nums.length;  // variable to store the length of the vector nums
        int res = 0;  // variable to store the result
        int i = 0;  // variable to store the start index of the window
        int j = 0;  // variable to store the end index of the window
        while(j < n - 1){  // while the end index of the window is less than the length of the vector nums
            int maxIndex = j;  // variable to store the maximum index
            for(int k=i; k<=j; k++){  // for each element in the window
                maxIndex = Math.max(maxIndex, k + nums[k]);  // update the maximum index
            }
            i = j + 1;  // update the start index of the window
            j = maxIndex;  // update the end index of the window
            res++;  // increment the result
        }
        return res;  // return the result
    }
}


Python:


// Time Complexity : O(n) where n is the length of the vector nums and space complexity is O(1)

class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)  # variable to store the length of the vector nums
        res = 0  # variable to store the result
        i = 0  # variable to store the start index of the window
        j = 0  # variable to store the end index of the window
        while(j < n - 1):  # while the end index of the window is less than the length of the vector nums
            maxIndex = j  # variable to store the maximum index
            for k in range(i, j + 1):  # for each element in the window
                maxIndex = max(maxIndex, k + nums[k])  # update the maximum index
            i = j + 1  # update the start index of the window
            j = maxIndex  # update the end index of the window
            res += 1  # increment the result
        return res  # return the result




Python3:



// Time Complexity : O(n) where n is the length of the vector nums and space complexity is O(1)

class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)  # variable to store the length of the vector nums
        res = 0  # variable to store the result
        i = 0  # variable to store the start index of the window
        j = 0  # variable to store the end index of the window
        while(j < n - 1):  # while the end index of the window is less than the length of the vector nums
            maxIndex = j  # variable to store the maximum index
            for k in range(i, j + 1):  # for each element in the window
                maxIndex = max(maxIndex, k + nums[k])  # update the maximum index
            i = j + 1  # update the start index of the window
            j = maxIndex  # update the end index of the window
            res += 1  # increment the result
        return res  # return the result



C:


// Time Complexity : O(n) where n is the length of the vector nums and space complexity is O(1)

int jump(int* nums, int numsSize){
    int n = numsSize;  // variable to store the length of the vector nums
    int res = 0;  // variable to store the result
    int i = 0;  // variable to store the start index of the window
    int j = 0;  // variable to store the end index of the window
    while(j < n - 1){  // while the end index of the window is less than the length of the vector nums
        int maxIndex = j;  // variable to store the maximum index
        for(int k=i; k<=j; k++){  // for each element in the window
            maxIndex = fmax(maxIndex, k + nums[k]);  // update the maximum index
        }
        i = j + 1;  // update the start index of the window
        j = maxIndex;  // update the end index of the window
        res++;  // increment the result
    }
    return res;  // return the result


C#:

// Time Complexity : O(n) where n is the length of the vector nums and space complexity is O(1)

public class Solution {
    public int Jump(int[] nums) {
        int n = nums.Length;  // variable to store the length of the vector nums
        int res = 0;  // variable to store the result
        int i = 0;  // variable to store the start index of the window
        int j = 0;  // variable to store the end index of the window
        while(j < n - 1){  // while the end index of the window is less than the length of the vector nums
            int maxIndex = j;  // variable to store the maximum index
            for(int k=i; k<=j; k++){  // for each element in the window
                maxIndex = Math.Max(maxIndex, k + nums[k]);  // update the maximum index
            }
            i = j + 1;  // update the start index of the window
            j = maxIndex;  // update the end index of the window
            res++;  // increment the result
        }
        return res;  // return the result
    }
}


JavaScript:


// Time Complexity : O(n) where n is the length of the vector nums and space complexity is O(1)

var jump = function(nums) {
    let n = nums.length;  // variable to store the length of the vector nums
    let res = 0;  // variable to store the result
    let i = 0;  // variable to store the start index of the window
    let j = 0;  // variable to store the end index of the window
    while(j < n - 1){  // while the end index of the window is less than the length of the vector nums
        let maxIndex = j;  // variable to store the maximum index
        for(let k=i; k<=j; k++){  // for each element in the window
            maxIndex = Math.max(maxIndex, k + nums[k]);  // update the maximum index
        }
        i = j + 1;  // update the start index of the window
        j = maxIndex;  // update the end index of the window
        res++;  // increment the result
    }
    return res;  // return the result
};


Swift:

// Time Complexity : O(n) where n is the length of the vector nums and space complexity is O(1)

class Solution {
    func jump(_ nums: [Int]) -> Int {
        let n = nums.count;  // variable to store the length of the vector nums
        var res = 0;  // variable to store the result
        var i = 0;  // variable to store the start index of the window
        var j = 0;  // variable to store the end index of the window
        while(j < n - 1){  // while the end index of the window is less than the length of the vector nums
            var maxIndex = j;  // variable to store the maximum index
            for k in i...j{  // for each element in the window
                maxIndex = max(maxIndex, k + nums[k]);  // update the maximum index
            }
            i = j + 1;  // update the start index of the window
            j = maxIndex;  // update the end index of the window
            res += 1;  // increment the result
        }
        return res;  // return the result
    }
}
