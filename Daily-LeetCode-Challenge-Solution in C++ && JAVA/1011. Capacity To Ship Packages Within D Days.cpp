1011. Capacity To Ship Packages Within D Days






22 Feb 2023
    

    
    
Medium


    
    
3 Methods
    

C++:
    

// Time Complexity : O(nlogn) where n is the number of weights and space complexity is O(1)
    

class Solution {
public:
    bool isPossible(vector<int>& weights, int D, int mid){  // function to check if the weights can be shipped in D days
        int days = 1;  // variable to store the number of days
        int sum = 0;  // variable to store the sum of the weights
        for(int i = 0; i < weights.size(); i++){  // iterate over the weights
            if(weights[i] > mid){  // if the weight is greater than the mid
                return false;  // return false
            }
            if(sum + weights[i] > mid){  // if the sum of the weights is greater than the mid
                days++;  // increment the number of days
                sum = 0;  // reset the sum
            }
            sum += weights[i];  // add the weight to the sum
        }
        return days <= D;  // return true if the number of days is less than or equal to D
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int low = *max_element(weights.begin(), weights.end());  // variable to store the minimum weight  
        int high = accumulate(weights.begin(), weights.end(), 0);  // variable to store the sum of the weights
        while(low < high){  // iterate until the low is less than the high
            int mid = low + (high - low) / 2;  // variable to store the mid
            if(isPossible(weights, D, mid)){  // if the weights can be shipped in D days
                high = mid;  // update the high
            }
            else{
                low = mid + 1;  // update the low
            }
        }
        return low;  // return the low
    }
};

2nd Method beats 100% 

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int low = *max_element(weights.begin(), weights.end());  // variable to store the minimum weight
        int high = accumulate(weights.begin(), weights.end(), 0);  // variable to store the sum of the weights
        while(low < high){  // iterate until the low is less than the high
            int mid = low + (high - low) / 2;  // variable to store the mid
            int days = 1;  // variable to store the number of days
            int sum = 0;  // variable to store the sum of the weights
            for(int i = 0; i < weights.size(); i++){  // iterate over the weights
                if(sum + weights[i] > mid){  // if the sum of the weights is greater than the mid
                    days++;  // increment the number of days
                    sum = 0;  // reset the sum
                }
                sum += weights[i];  // add the weight to the sum
            }
            if(days <= D){  // if the number of days is less than or equal to D
                high = mid;  // update the high
            }
            else{
                low = mid + 1;  // update the low
            }
        }
        return low;  // return the low
    }
};

3rd Method:
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int days = 1, current_weight = 0;
            
            for (int weight : weights) {
                current_weight += weight;
                if (current_weight > mid) {
                    days++;
                    current_weight = weight;
                }
            }
            
            if (days <= D) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};


Java:


// Time Complexity : O(nlogn) where n is the number of weights and space complexity is O(1)


class Solution {
    public boolean isPossible(int[] weights, int D, int mid){  // function to check if the weights can be shipped in D days
        int days = 1;  // variable to store the number of days
        int sum = 0;  // variable to store the sum of the weights
        for(int i = 0; i < weights.length; i++){  // iterate over the weights
            if(weights[i] > mid){  // if the weight is greater than the mid
                return false;  // return false
            }
            if(sum + weights[i] > mid){  // if the sum of the weights is greater than the mid
                days++;  // increment the number of days
                sum = 0;  // reset the sum
            }
            sum += weights[i];  // add the weight to the sum
        }
        return days <= D;  // return true if the number of days is less than or equal to D
    }
    public int shipWithinDays(int[] weights, int D) {
        int low = Arrays.stream(weights).max().getAsInt();  // variable to store the minimum weight
        int high = Arrays.stream(weights).sum();  // variable to store the sum of the weights
        while(low < high){  // iterate until the low is less than the high
            int mid = low + (high - low) / 2;  // variable to store the mid
            if(isPossible(weights, D, mid)){  // if the weights can be shipped in D days
                high = mid;  // update the high
            }
            else{
                low = mid + 1;  // update the low
            }
        }
        return low;  // return the low
    }
};



2nd Method:

class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int low = Arrays.stream(weights).max().getAsInt();  // variable to store the minimum weight
        int high = Arrays.stream(weights).sum();  // variable to store the sum of the weights
        while(low < high){  // iterate until the low is less than the high
            int mid = low + (high - low) / 2;  // variable to store the mid
            int days = 1;  // variable to store the number of days
            int sum = 0;  // variable to store the sum of the weights
            for(int i = 0; i < weights.length; i++){  // iterate over the weights
                if(sum + weights[i] > mid){  // if the sum of the weights is greater than the mid
                    days++;  // increment the number of days
                    sum = 0;  // reset the sum
                }
                sum += weights[i];  // add the weight to the sum
            }
            if(days <= D){  // if the number of days is less than or equal to D
                high = mid;  // update the high
            }
            else{
                low = mid + 1;  // update the low
            }
        }
        return low;  // return the low
    }
};


3rd Method :



class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int left = Arrays.stream(weights).max().getAsInt();
        int right = Arrays.stream(weights).sum();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int days = 1, current_weight = 0;
            
            for (int weight : weights) {
                current_weight += weight;
                if (current_weight > mid) {
                    days++;
                    current_weight = weight;
                }
            }
            
            if (days <= D) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};

