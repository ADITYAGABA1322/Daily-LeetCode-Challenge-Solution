class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1 , right = *max_element(quantities.begin() , quantities.end());
        int res = 0;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(isPossible(n , quantities , mid)) {
                res = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return res;
    }
private:
    bool isPossible(int n ,vector<int>& quantities, int maxProduct){
        int storeNeeded = 0;
        for(auto q : quantities){
            storeNeeded += (q + maxProduct - 1) / maxProduct;
        }
        return storeNeeded<=n;
    }    
};