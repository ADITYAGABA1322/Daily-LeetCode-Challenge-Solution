class Solution {
public:
    bool isPos(vector<vector<int>>& tasks , int mid){
        for(auto& t: tasks){
            int a = t[0] , m = t[1];
            if(m > mid) return false;
            mid -= a;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int l = 0 , r = 1e9;
        int res = INT_MAX;
        auto lambda = [](auto a , auto b){
            int d1 = a[1] - a[0] , d2 = b[1] - b[0];
            return d1 > d2;
        };
        sort(begin(tasks) , end(tasks) , lambda);
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(isPos(tasks , mid)){
                res = mid;
                r = mid-1;
            } else{
                l = mid + 1;
            }
        }
        return res;
    }
};