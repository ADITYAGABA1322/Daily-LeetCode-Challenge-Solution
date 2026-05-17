class Solution {
public:
    int n;
    bool dfs(vector<int>& arr , int i){
        if(i<0 || i>=n || arr[i] < 0) return false;
        if(arr[i] == 0) return true;
        arr[i] *= -1;
        int l = dfs(arr , i-arr[i]);
        int r = dfs(arr , i+arr[i]);
        return l || r;
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        return dfs(arr ,  start);
    }
};