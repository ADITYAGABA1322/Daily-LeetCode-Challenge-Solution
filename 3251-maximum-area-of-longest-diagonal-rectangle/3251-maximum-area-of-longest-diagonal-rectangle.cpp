class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0;
        int maxArea = 0;
        
        for (auto& rectangle : dimensions) {
            double diagonal = sqrt(rectangle[0] * rectangle[0] + rectangle[1] * rectangle[1]);
            int area = rectangle[0] * rectangle[1];
            
            if (diagonal > maxDiagonal || (diagonal == maxDiagonal && area > maxArea)) {
                maxDiagonal = diagonal;
                maxArea = area;
            }
        }
        
        return maxArea;
    }
};