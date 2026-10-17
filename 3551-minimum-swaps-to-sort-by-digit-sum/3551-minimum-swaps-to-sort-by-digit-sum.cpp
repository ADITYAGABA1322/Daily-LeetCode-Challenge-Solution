class Solution {
public:
    int digitSum(int n){
        int ans = 0;
        while(n>0){
            int rem = n%10;
            ans += rem;
            n /= 10;
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> target = nums;
        int cnt = 0 , cycle_len = 0;
        sort(target.begin() , target.end() , [&](int a , int b){
            if(digitSum(a) == digitSum(b)) return a < b ? true : false;
            else return digitSum(a) < digitSum(b);
        });
        unordered_map<int , int> mp;
        for(int i=0; i<n; i++){
            mp[target[i]] = i;
        }
        vector<bool> vis(n , false);
        for(int i=0; i<n; i++){
            int curr = i;
            if(vis[curr]) continue;
            cycle_len = 0;
            while(!vis[curr]){
                vis[curr] = true;
                curr = mp[nums[curr]];
                cycle_len++;
            }
            cnt += cycle_len-1;
        }
        return cnt;
    }
};