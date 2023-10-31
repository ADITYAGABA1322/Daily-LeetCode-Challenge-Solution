1035. Uncrossed Lines


  
  

11 May 2023

  
  
  
 Medium
  
  
  
  
  C++:
  
  
  // Time Complexity : O(m * n) where m is the length of the first array and n is the length of the second array and space complexity is O(m * n)



class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));  // dp array
        for(int i = 1; i <= nums1.size(); i++){  // iterate through the first array
            for(int j = 1; j <= nums2.size(); j++){  // iterate through the second array
                if(nums1[i - 1] == nums2[j - 1]){  // if the elements are equal
                    dp[i][j] = dp[i - 1][j - 1] + 1;  // update the dp array
                }
                else{  // if the elements are not equal
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // update the dp array
                }
            }
        }
        return dp[nums1.size()][nums2.size()];  // return the last element of the dp array
    }
};

  
  Java:
  
  
  
// Time Complexity : O(m * n) where m is the length of the first array and n is the length of the second array and space complexity is O(m * n)





class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int[][] dp = new int[nums1.length + 1][nums2.length + 1];  // dp array
        for(int i = 1; i <= nums1.length; i++){  // iterate through the first array
            for(int j = 1; j <= nums2.length; j++){  // iterate through the second array
                if(nums1[i - 1] == nums2[j - 1]){  // if the elements are equal
                    dp[i][j] = dp[i - 1][j - 1] + 1;  // update the dp array
                }
                else{  // if the elements are not equal
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);  // update the dp array
                }
            }
        }
        return dp[nums1.length][nums2.length];  // return the last element of the dp array
    }
}
