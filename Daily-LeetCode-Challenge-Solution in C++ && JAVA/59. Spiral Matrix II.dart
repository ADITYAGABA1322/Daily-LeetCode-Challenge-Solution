59. Spiral Matrix II



10 May 2023




Medium




C++:

// Time Complexity : O(n^2) where n is the size of the matrix and space complexity is O(1)



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));  // matrix is the 2D vector of size n*n
        int top = 0;  // top is the topmost row of the matrix
        int bottom = n-1;  // bottom is the bottommost row of the matrix
        int left = 0;  // left is the leftmost column of the matrix
        int right = n-1;  // right is the rightmost column of the matrix
        int num = 1;  // num is the number to be filled in the matrix
        while(top <= bottom && left <= right){  // while the topmost row is less than or equal to the bottommost row and the leftmost column is less than or equal to the rightmost column
            for(int i=left; i<=right; i++){  // for each element in the topmost row
                matrix[top][i] = num++;  // fill the element with the number and increment the number
            }
            top++;  // increment the topmost row
            for(int i=top; i<=bottom; i++){  // for each element in the rightmost column
                matrix[i][right] = num++;  // fill the element with the number and increment the number
            }
            right--;  // decrement the rightmost column
            for(int i=right; i>=left; i--){  // for each element in the bottommost row
                matrix[bottom][i] = num++;  // fill the element with the number and increment the number
            }
            bottom--;  // decrement the bottommost row
            for(int i=bottom; i>=top; i--){  // for each element in the leftmost column
                matrix[i][left] = num++;  // fill the element with the number and increment the number
            }
            left++;  // increment the leftmost column
        }
        return matrix;  // return the matrix
    }
};




Java:


// Time Complexity : O(n^2) where n is the size of the matrix and space complexity is O(1)







class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];  // matrix is the 2D vector of size n*n
        int top = 0;  // top is the topmost row of the matrix
        int bottom = n-1;  // bottom is the bottommost row of the matrix
        int left = 0;  // left is the leftmost column of the matrix
        int right = n-1;  // right is the rightmost column of the matrix
        int num = 1;  // num is the number to be filled in the matrix
        while(top <= bottom && left <= right){  // while the topmost row is less than or equal to the bottommost row and the leftmost column is less than or equal to the rightmost column
            for(int i=left; i<=right; i++){  // for each element in the topmost row
                matrix[top][i] = num++;  // fill the element with the number and increment the number
            }
            top++;  // increment the topmost row
            for(int i=top; i<=bottom; i++){  // for each element in the rightmost column
                matrix[i][right] = num++;  // fill the element with the number and increment the number
            }
            right--;  // decrement the rightmost column
            for(int i=right; i>=left; i--){  // for each element in the bottommost row
                matrix[bottom][i] = num++;  // fill the element with the number and increment the number
            }
            bottom--;  // decrement the bottommost row
            for(int i=bottom; i>=top; i--){  // for each element in the leftmost column
                matrix[i][left] = num++;  // fill the element with the number and increment the number
            }
            left++;  // increment the leftmost column
        }
        return matrix;  // return the matrix
    }
}


Python:

// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(1)

class Solution(object):
    def generateMatrix(self, n):
         """
         :type n: int
         :rtype: List[List[int]]
         """ 
        // matrix = [[0 for i in range(n)] for j in range(n)]  # vector to store the result
        top = 0  # variables to store the top
        bottom = n-1  # variables to store the bottom
        left = 0  # variables to store the left
        right = n-1  # variables to store the right
        count = 1  # variable to store the count
        while top <= bottom and left <= right:  # while top is less than or equal to bottom and left is less than or equal to right
            for i in range(left, right+1):  # loop for i
                matrix[top][i] = count  # update the matrix
                count += 1  # increment the count
            top += 1  # increment the top
            for i in range(top, bottom+1):  # loop for i
                matrix[i][right] = count  # update the matrix
                count += 1  # increment the count
            right -= 1  # decrement the right
            for i in range(right, left-1, -1):  # loop for i
                matrix[bottom][i] = count  # update the matrix
                count += 1  # increment the count
            bottom -= 1  # decrement the bottom
            for i in range(bottom, top-1, -1):  # loop for i
                matrix[i][left] = count  # update the matrix
                count += 1  # increment the count
            left += 1  # increment the left
        return matrix  # return the matrix




Python3:

// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(1)

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:  // add the missing colon after int
       // matrix = [[0 for i in range(n)] for j in range(n)]  # vector to store the result
        top = 0  # variables to store the top
        bottom = n-1  # variables to store the bottom
        left = 0  # variables to store the left
        right = n-1  # variables to store the right
        count = 1  # variable to store the count
        while top <= bottom and left <= right:  # while top is less than or equal to bottom and left is less than or equal to right
            for i in range(left, right+1):  # loop for i
                matrix[top][i] = count  # update the matrix
                count += 1  # increment the count
            top += 1  # increment the top
            for i in range(top, bottom+1):  # loop for i
                matrix[i][right] = count  # update the matrix
                count += 1  # increment the count
            right -= 1  # decrement the right
            for i in range(right, left-1, -1):  # loop for i
                matrix[bottom][i] = count  # update the matrix
                count += 1  # increment the count
            bottom -= 1  # decrement the bottom
            for i in range(bottom, top-1, -1):  # loop for i
                matrix[i][left] = count  # update the matrix
                count += 1  # increment the count
            left += 1  # increment the left
        return matrix  # return the matrix

C:

// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(1)

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int** matrix = (int**)malloc(sizeof(int*)*n);  // vector to store the result
    for(int i=0; i<n; i++){  // loop for i
        matrix[i] = (int*)malloc(sizeof(int)*n);  // vector to store the result
    }
    int top = 0, bottom = n-1, left = 0, right = n-1;  // variables to store the top, bottom, left and right
    int count = 1;  // variable to store the count
    while(top <= bottom && left <= right){  // while top is less than or equal to bottom and left is less than or equal to right
        for(int i=left; i<=right; i++){  // loop for i
            matrix[top][i] = count++;  // update the matrix
        }
        top++;  // increment the top
        for(int i=top; i<=bottom; i++){  // loop for i
            matrix[i][right] = count++;  // update the matrix
        }
        right--;  // decrement the right
        for(int i=right; i>=left; i--){  // loop for i
            matrix[bottom][i] = count++;  // update the matrix
        }
        bottom--;  // decrement the bottom
        for(int i=bottom; i>=top; i--){  // loop for i
            matrix[i][left] = count++;  // update the matrix
        }f
        left++;  // increment the left
    }
    *returnSize = n;  // update the returnSize
    *returnColumnSizes = (int*)malloc(sizeof(int)*n);  // vector to store the result
    for(int i=0; i<n; i++){  // loop for i
        (*returnColumnSizes)[i] = n;  // update the returnColumnSizes
    }
    return matrix;  // return the matrix
}



C#:


// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(1)

public class Solution {
    public int[][] GenerateMatrix(int n) {
        int[][] matrix = new int[n][];  // vector to store the result
        for(int i=0; i<n; i++){  // loop for i
            matrix[i] = new int[n];  // vector to store the result
        }
        int top = 0, bottom = n-1, left = 0, right = n-1;  // variables to store the top, bottom, left and right
        int count = 1;  // variable to store the count
        while(top <= bottom && left <= right){  // while top is less than or equal to bottom and left is less than or equal to right
            for(int i=left; i<=right; i++){  // loop for i
                matrix[top][i] = count++;  // update the matrix
            }
            top++;  // increment the top
            for(int i=top; i<=bottom; i++){  // loop for i
                matrix[i][right] = count++;  // update the matrix
            }
            right--;  // decrement the right
            for(int i=right; i>=left; i--){  // loop for i
                matrix[bottom][i] = count++;  // update the matrix
            }
            bottom--;  // decrement the bottom
            for(int i=bottom; i>=top; i--){  // loop for i
                matrix[i][left] = count++;  // update the matrix
            }
            left++;  // increment the left
        }
        return matrix;  // return the matrix
    }
}




JavaScript:

// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(1)

var generateMatrix = function(n) {
    let matrix = new Array(n);  // vector to store the result
    for(let i=0; i<n; i++){  // loop for i
        matrix[i] = new Array(n);  // vector to store the result
    }
    let top = 0, bottom = n-1, left = 0, right = n-1;  // variables to store the top, bottom, left and right
    let count = 1;  // variable to store the count
    while(top <= bottom && left <= right){  // while top is less than or equal to bottom and left is less than or equal to right
        for(let i=left; i<=right; i++){  // loop for i
            matrix[top][i] = count++;  // update the matrix
        }
        top++;  // increment the top
        for(let i=top; i<=bottom; i++){  // loop for i
            matrix[i][right] = count++;  // update the matrix
        }
        right--;  // decrement the right
        for(let i=right; i>=left; i--){  // loop for i
            matrix[bottom][i] = count++;  // update the matrix
        }
        bottom--;  // decrement the bottom
        for(let i=bottom; i>=top; i--){  // loop for i
            matrix[i][left] = count++;  // update the matrix
        }
        left++;  // increment the left
    }
    return matrix;  // return the matrix
};




Swift:


// Time Complexity : O(n^2) where n is the size of the vector matrix and space complexity is O(1)

class Solution {
    func generateMatrix(_ n: Int) -> [[Int]] {
        var matrix = [[Int]](repeating: [Int](repeating: 0, count: n), count: n)  // vector to store the result
        var top = 0, bottom = n-1, left = 0, right = n-1  // variables to store the top, bottom, left and right
        var count = 1  // variable to store the count
        while top <= bottom && left <= right {  // while top is less than or equal to bottom and left is less than or equal to right
            for i in stride(from: left, through: right, by: 1) {  // loop for i
                matrix[top][i] = count  // update the matrix
                count += 1  // increment the count
            }
            top += 1  // increment the top
            for i in stride(from: top, through: bottom, by: 1) {  // loop for i
                matrix[i][right] = count  // update the matrix
                count += 1  // increment the count
            }
            right -= 1  // decrement the right
            for i in stride(from: right, through: left, by: -1) {  // loop for i
                matrix[bottom][i] = count  // update the matrix
                count += 1  // increment the count
            }
            bottom -= 1  // decrement the bottom
            for i in stride(from: bottom, through: top, by: -1) {  // loop for i
                matrix[i][left] = count  // update the matrix
                count += 1  // increment the count
            }
            left += 1  // increment the left
        }
        return matrix  // return the matrix
    }
}

