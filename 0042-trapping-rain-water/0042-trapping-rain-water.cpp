class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n-1 , leftMax = 0 , rightMax = 0 , res = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= leftMax) leftMax = height[left];
                else res += leftMax - height[left];
                left++;
            }
            else{
                if(height[right] >= rightMax) rightMax = height[right];
                else res += rightMax - height[right];
                right--;
            } 
        }
        return res;
    }
};