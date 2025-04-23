class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int , int> mp;
        for(int i=1; i<=n; i++){
            int num = i;
            int sum = 0;
            while(num > 0){
                sum += num%10;
                num /= 10;
            }
            mp[sum]++;
        }
        int maxFreq = 0;
        for(auto it : mp){
            maxFreq = max(maxFreq , it.second);
        }
        int cnt = 0;
        for(auto it : mp){
            if(maxFreq == it.second) cnt++;
        }
        return cnt;
    }
};