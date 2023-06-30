1402. Reducing Dishes




29 March 2023



Hard



C++:


// Time Complexity : O(nlogn) where n is the length of the satisfaction array and space complexity is O(1)







class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());  // sort the satisfaction array
        int result = 0;  // variable to store the result
        int sum = 0;  // variable to store the sum
        for(int i = satisfaction.size()-1; i >= 0; i--){  // iterate from the end of the satisfaction array
            sum += satisfaction[i];  // update the sum
            if(sum > 0){  // if the sum is greater than 0
                result += sum;  // update the result
            }
            else{  // if the sum is less than 0
                break;  // break
            }
        }
        return result;  // return the result
    }
};




Java:


// Time Complexity : O(nlogn) where n is the length of the satisfaction array and space complexity is O(1)







class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);  // sort the satisfaction array
        int result = 0;  // variable to store the result
        int sum = 0;  // variable to store the sum
        for(int i = satisfaction.length-1; i >= 0; i--){  // iterate from the end of the satisfaction array
            sum += satisfaction[i];  // update the sum
            if(sum > 0){  // if the sum is greater than 0
                result += sum;  // update the result
            }
            else{  // if the sum is less than 0
                break;  // break
            }
        }
        return result;  // return the result
    }
}

