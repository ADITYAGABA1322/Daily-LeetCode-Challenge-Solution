class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> res;
        // for(auto num: nums){
        //     vector<int> temp;
        //     while(num > 0){
        //         temp.push_back(num%10);
        //         num /= 10;
        //     }
        //     for(int i=temp.size()-1; i>=0; i--) res.push_back(temp[i]);
        // }
        // return res;
        // traversal
        vector<int> res;
        for(int i = nums.size()-1; i>=0; i--){
            int curr = nums[i];
            while(curr > 0){
                res.push_back(curr % 10);
                curr /= 10;
            }
        }
        reverse(res.begin() , res.end());
        return res;
    }
};