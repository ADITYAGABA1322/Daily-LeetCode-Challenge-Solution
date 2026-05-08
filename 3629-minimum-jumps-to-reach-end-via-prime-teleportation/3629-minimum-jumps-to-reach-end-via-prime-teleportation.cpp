class Solution {
public:
    vector<bool> isPrime;
    void buildSeive(int maxEle){
        isPrime.resize(maxEle+1 , true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i=2; i*i<=maxEle; i++){
            if(isPrime[i]){
                for(int multi = i*i; multi<=maxEle; multi+=i){
                    isPrime[multi] = false;
                }
            }
        }
    }
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<int>> mp;
        int maxEle = 0;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
            maxEle = max(maxEle , nums[i]);
        }
        buildSeive(maxEle);
        queue<int> q;
        vector<bool> vis(n ,false);
        q.push(0);
        vis[0] = true;
        unordered_set<int> seen;
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int i = q.front();
                q.pop();
                if(i == n-1) return steps;
                if(i-1>=0 && !vis[i-1]){
                    q.push(i-1);
                    vis[i-1] = true;
                }
                if(i+1<=n-1 && !vis[i+1]){
                    q.push(i+1);
                    vis[i+1] = true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])) continue;

                for(int multi = nums[i]; multi<= maxEle; multi += nums[i]){
                    if(!mp.contains(multi)) continue;
                    for(auto j: mp[multi]){
                        if(!vis[j]){
                            q.push(j);
                            vis[j] = true;
                        }
                    }
                }
                seen.insert(nums[i]);
            }
            steps++;
        }
        return steps;
    }
};