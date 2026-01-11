class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int  m = matrix.size() , n = matrix[0].size() , maxArea = 0;
        vector<int> left(n) , right(n , n) , height(n);
        for(int i=0; i<m; i++){
            int currL = 0 , currR = n;
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') left[j] = max(left[j] , currL);
                else {left[j] = 0; currL = j+1;}
            }
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j] == '1') right[j] = min(right[j] , currR);
                else {right[j] = n; currR = j;}
            }
            for(int j=0; j<n; j++){
                maxArea = max(maxArea , (right[j] - left[j]) * height[j]);
            }
        }
        return maxArea;
    }
};