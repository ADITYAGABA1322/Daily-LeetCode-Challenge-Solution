class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // There is still a concept of a matrix is coming on and in this, but I found like there is a grid like this one is OK but we want to return the diagonals in the suit the matrix standard but there is a condition on we want to diagnose in the bottom left trend, including the middle diagonal are supported in non-vision order the diagonal in the top right triangle are sorted in non-decreasing order so what does it mean the top one in the right side and bottom Left top one is in non-decreasing order and bottom left is in non-increasing order so what does it mean we want to trade through the matrix but we know the concept of the diagonal using the even old matrixes we using the diners counter dinos, and put into that according to the condition of the even and the old consent and after that we need to sort that matrix or the diagonals according to that we need to find the these two conditions we want to edit into and after that we get the res 
        int  n = grid.size();
        auto sortDiagonal = [&](int startRow , int startCol , bool desc){
            vector<int> diagonal;
            vector<pair<int , int>> pos;
            int row = startRow , col = startCol;
            while(row < n && col < n){
                diagonal.push_back(grid[row][col]);
                pos.push_back({row , col});
                row++;
                col++;
            }
            if(desc) sort(diagonal.begin() , diagonal.end() , greater<int>());
            else  sort(diagonal.begin(), diagonal.end());
            for(int i=0; i<diagonal.size(); i++) grid[pos[i].first][pos[i].second] = diagonal[i];
        };
        for(int i=0; i<n; i++){
            sortDiagonal(i , 0 , true);
        }
        for(int j=1; j<n; j++){
            sortDiagonal(0 , j , false);
        }
        return grid;
    }
};