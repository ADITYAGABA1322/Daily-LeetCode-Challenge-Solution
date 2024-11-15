class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) { 
        int n = arr.size();
        int left =0 , right = n-1;
        while(left < n-1 && arr[left] <= arr[left+1]) left++;
        if(left == n-1) return 0;
        while(right > 0 && arr[right] >= arr[right-1]) right--;
        int res = min(n-left-1 , right);
        int i=0 ,j = right;
        while(i<=left && j<n){
            if(arr[i] <= arr[j]) {res = min (res,  j-i-1); i++;}
            else j++;
        }
        return res;
    }
};