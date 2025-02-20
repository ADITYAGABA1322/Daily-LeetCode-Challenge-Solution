class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res(n , '0');
        for(int i=0; i<n; i++){
            res[i] = nums[i][i] == '0' ? '1' : '0';
        }
        return res;
    }
};