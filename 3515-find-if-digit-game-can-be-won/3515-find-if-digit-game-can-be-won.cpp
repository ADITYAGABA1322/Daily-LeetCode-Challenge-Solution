class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0 , sum2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] >= 0 && nums[i] <= 9) sum1 += nums[i];
            else if(nums[i] >= 10 && nums[i] <= 99) sum2 += nums[i];
        }
        return sum1>sum2 || sum2>sum1;
    }
};

// or
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     bool canAliceWin(vector<int>& nums) {
//         int sumSingleDigit = 0, sumDoubleDigit = 0;

//         // Calculate the sums of single-digit and double-digit numbers
//         for (int num : nums) {
//             if (num >= 1 && num <= 9) {
//                 sumSingleDigit += num;
//             } else if (num >= 10 && num <= 99) {
//                 sumDoubleDigit += num;
//             }
//         }

//         // Alice wins if the sum of her chosen numbers is strictly greater than the sum of Bob's numbers
//         return sumSingleDigit > sumDoubleDigit || sumDoubleDigit > sumSingleDigit;
//     }
// };