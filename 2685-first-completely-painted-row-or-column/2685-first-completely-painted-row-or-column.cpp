class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // acc to given problme we have an arr and matrix m*n ok mat and arr both cotain all int range 1 , m*n; each idx i. in arr Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

// Return the smallest index i at which either a row or a column will be completely painted in mat.

// ok we need to return the samllest index first their is matrix similar thing we use graph here and we need to find small we heap i think or using bfs and vis is also sove this problem easily what they ask  we need to srart paint first  but rather than using grpah we use hash table pre pricess whole matrix and cont the freq arrys and then traverse it ok thats how it works ok 
//     approach to solve this 
//     1.) take size of amt n and m and arr size and create a map freq and cnt it and using the loop to iterate them ok and after that 
    int m = mat.size() ,  n = mat[0].size();
    unordered_map<int , pair<int , int>> mp;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            mp[mat[i][j]] = {i , j};
        }
    }
    vector<int> rowCnt(m , 0);
    vector<int> colCnt(n , 0);
    for(int i=0; i<arr.size(); i++){    
        int num = arr[i];
        auto[row , col] = mp[num];
        rowCnt[row]++;
        colCnt[col]++;
        if(rowCnt[row] == n || colCnt[col]== m) return i;
    }
    return -1;
    }
};