class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        // Check if there are at least 3 elements in the array
        if(n < 3) return false;
        
        for(int i = 0; i < n - 2; i++) {
            // Check if the current, next, and next to next elements are odd
            if(arr[i] % 2 != 0 && arr[i+1] % 2 != 0 && arr[i+2] % 2 != 0) {
                return true;
            }
        }
        // If no three consecutive odds are found, return false
        return false;
    }
};