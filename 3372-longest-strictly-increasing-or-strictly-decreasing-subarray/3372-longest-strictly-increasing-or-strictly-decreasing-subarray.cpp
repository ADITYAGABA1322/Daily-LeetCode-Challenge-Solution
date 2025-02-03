class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int n = arr.size();
        int maxi =  1 , inc = 1 , dec = 1;
        for(int i=1; i<n; i++){
            if(arr[i] < arr[i-1]){
                inc++;
                dec = 1;
            }
            else if(arr[i] > arr[i-1]){
                dec++;
                inc = 1;
            }
            else dec = inc = 1;
            maxi = max(maxi , max(inc , dec));
        }
        return maxi;
    }
};