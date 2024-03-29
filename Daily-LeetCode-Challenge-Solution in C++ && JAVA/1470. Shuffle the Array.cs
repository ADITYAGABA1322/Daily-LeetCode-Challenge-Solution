# Daily-LeetCode-Challenge-Solution



1470. Shuffle the Array




6 Feb 2023


 
Easy
 

C++:

// Time Complexity : O(n) where n is the length of the vector nums and space complexity is O(n)

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;  // vector to store the result
        for(int i=0; i<n; i++){  // for each element of the vector nums
            res.push_back(nums[i]);  // push the element to the result vector
            res.push_back(nums[i + n]);  // push the element to the result vector
        }
        return res;  // return the result vector
    }
};



Java:


// Time Complexity : O(n) where n is the length of the vector nums and space complexity is O(n)

class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] res = new int[2 * n];  // vector to store the result
        for(int i=0; i<n; i++){  // for each element of the vector nums
            res[2 * i] = nums[i];  // push the element to the result vector
            res[2 * i + 1] = nums[i + n];  // push the element to the result vector
        }
        return res;  // return the result vector
    }
}
