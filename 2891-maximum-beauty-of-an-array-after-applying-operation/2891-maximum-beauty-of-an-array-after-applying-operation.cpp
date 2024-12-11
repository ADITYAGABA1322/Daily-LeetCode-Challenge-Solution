class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // maximize the beauty after applying operation ok given  nums arr and non  int k  in one operation chosse  indix i hasnt been choosen before ok form 0 to nums.len -1 and replase with any int from range nums[i] - k , nums[i] + k
       // sort the array ok use bonary seach adn sliding for like take an ele make its range by using k and apply operation find max subsewunce len or cnt ok of smae no make in that array  
       sort(nums.begin() , nums.end());
       int n = nums.size() , maxLen = 0 , i= 0;
       for(int j=0; j<n; j++){
            while(nums[j] - nums[i] > 2*k) i++;
            maxLen = max(maxLen , j-i+1);
       }
       return maxLen;
    }
};