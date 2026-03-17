class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        // for (int r = 0; r < m; r++) {
        //     for (int c = 0; c < n; c++) {
        //         if (matrix[r][c] == 1 && r>0)
        //             matrix[r][c] += matrix[r - 1][c];
        //     }
        //     vector<int> h = matrix[r];
        //     sort(h.begin(), h.end(), greater<int>());
        //     for (int i = 0; i < n; i++) {
        //         int base= i + 1;
        //         int height = h[i];
        //         maxArea = max(maxArea, base * height);
        //     }
        // }
        // return maxArea;

        // 2nd approach without modifying the array
         int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
         vector<int> prevRow(n , 0);
        for (int r = 0; r < m; r++) {
             vector<int> currRow = matrix[r];
            for (int c = 0; c < n; c++) {
                if (currRow[c] == 1 )
                    currRow[c] += prevRow[c];
            }
            vector<int> h = currRow;
            sort(h.begin(), h.end(), greater<int>());
            for (int i = 0; i < n; i++) {
                int base= i + 1;
                int height = h[i];
                maxArea = max(maxArea, base * height);
            }
            prevRow = currRow;
        }
        return maxArea;
    }
};