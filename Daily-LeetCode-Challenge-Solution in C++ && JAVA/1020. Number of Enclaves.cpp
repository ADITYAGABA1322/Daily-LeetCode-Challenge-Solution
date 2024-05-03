1020. Number of Enclaves



7 April 2023
    
    
Medium



C++:



// Time Complexity : O(m * n) where m is the number of rows and n is the number of columns and space complexity is O(m * n) where m is the number of rows and n is the number of columns




class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0;  // variable to store the result
        for(int i = 0; i < grid.size(); i++){  // iterate through the grid
            for(int j = 0; j < grid[0].size(); j++){  // iterate through the grid
                if(i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1){  // if the value is on the border
                    if(grid[i][j] == 1){  // if the value is 1
                        dfs(grid, i, j);  // perform dfs
                    }
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){  // iterate through the grid
            for(int j = 0; j < grid[0].size(); j++){  // iterate through the grid
                if(grid[i][j] == 1){  // if the value is 1
                    result++;  // increment the result
                }
            }
        }
        return result;  // return the result
    }
    void dfs(vector<vector<int>>& grid, int i, int j){  // function to perform dfs
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){  // if the value is out of bounds
            return;  // return
        }
        if(grid[i][j] == 0){  // if the value is 0
            return;  // return
        }
        grid[i][j] = 0;  // update the value
        dfs(grid, i - 1, j);  // perform dfs
        dfs(grid, i + 1, j);  // perform dfs
        dfs(grid, i, j - 1);  // perform dfs
        dfs(grid, i, j + 1);  // perform dfs
    }
};



Java:



// Time Complexity : O(m * n) where m is the number of rows and n is the number of columns and space complexity is O(m * n) where m is the number of rows and n is the number of columns







class Solution {
    public int numEnclaves(int[][] grid) {
        int result = 0;  // variable to store the result
        for(int i = 0; i < grid.length; i++){  // iterate through the grid
            for(int j = 0; j < grid[0].length; j++){  // iterate through the grid
                if(i == 0 || i == grid.length - 1 || j == 0 || j == grid[0].length - 1){  // if the value is on the border
                    if(grid[i][j] == 1){  // if the value is 1
                        dfs(grid, i, j);  // perform dfs
                    }
                }
            }
        }
        for(int i = 0; i < grid.length; i++){  // iterate through the grid
            for(int j = 0; j < grid[0].length; j++){  // iterate through the grid
                if(grid[i][j] == 1){  // if the value is 1
                    result++;  // increment the result
                }
            }
        }
        return result;  // return the result
    }
    public void dfs(int[][] grid, int i, int j){  // function to perform dfs
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length){  // if the value is out of bounds
            return;  // return
        }
        if(grid[i][j] == 0){  // if the value is 0
            return;  // return
        }
        grid[i][j] = 0;  // update the value
        dfs(grid, i - 1, j);  // perform dfs
        dfs(grid, i + 1, j);  // perform dfs
        dfs(grid, i, j - 1);  // perform dfs
        dfs(grid, i, j + 1);  // perform dfs
    }
}

