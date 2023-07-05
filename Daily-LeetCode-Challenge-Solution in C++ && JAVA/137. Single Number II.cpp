137. Single Number II


4 July 2023

  


Medium


3 APPROACHES


C++:


// Time Complexity : O(n) where n is the number of elements in the array and space complexity is O(1)




class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();  // variable to store the length of the array
        int result = 0;  // variable to store the result
        for(int i = 0; i < 32; i++){  // iterate through the bits
            int sum = 0;  // variable to store the sum
            for(int j = 0; j < n; j++){  // iterate through the array
                if(nums[j] & (1 << i)){  // if the ith bit of the current element is set
                    sum++;  // increment the sum
                }
            }
            if(sum % 3){  // if the sum is not divisible by 3
                result |= (1 << i);  // set the ith bit of the result
            }
        }
        return result;  // return the result
    }
};


second method 




// Time Complexity : O(n) where n is the number of elements in the array and space complexity is O(1)




class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();  // variable to store the length of the array
        int ones = 0;  // variable to store the ones
        int twos = 0;  // variable to store the twos
        for(int i = 0; i < n; i++){  // iterate through the array
            ones = (ones ^ nums[i]) & (~twos);  // update the ones
            twos = (twos ^ nums[i]) & (~ones);  // update the twos
        }
        return ones;  // return the ones
    }
};



third Method  using map




// Time Complexity : O(n) where n is the number of elements in the array and space complexity is O(n


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();  // variable to store the length of the array
        unordered_map<int, int> mp;  // unordered map to store the frequency of the elements
        for(int i = 0; i < n; i++){  // iterate through the array
            mp[nums[i]]++;  // update the frequency
        }
        for(auto i : mp){  // iterate through the map
            if(i.second == 1){  // if the frequency is 1
                return i.first;  // return the element
            }
        }
        return -1;  // return -1
    }
};

  

  
Java:





// Time Complexity : O(n) where n is the number of elements in the array and space complexity is O(1)




class Solution {
    public int singleNumber(int[] nums) {
        int n = nums.length;  // variable to store the length of the array
        int result = 0;  // variable to store the result
        for(int i = 0; i < 32; i++){  // iterate through the bits
            int sum = 0;  // variable to store the sum
            for(int j = 0; j < n; j++){  // iterate through the array
                if((nums[j] & (1 << i)) != 0){  // if the ith bit of the current element is set
                    sum++;  // increment the sum
                }
            }
            if(sum % 3 != 0){  // if the sum is not divisible by 3
                result |= (1 << i);  // set the ith bit of the result
            }
        }
        return result;  // return the result
    }
}


second method 


// Time Complexity : O(n) where n is the number of elements in the array and space complexity is O(1)





class Solution {
    public int singleNumber(int[] nums) {
        int n = nums.length;  // variable to store the length of the array
        int ones = 0;  // variable to store the ones
        int twos = 0;  // variable to store the twos
        for(int i = 0; i < n; i++){  // iterate through the arra
            ones = (ones ^ nums[i]) & (~twos);  // update the ones
            twos = (twos ^ nums[i]) & (~ones);  // update the twos
        }
        return ones;  // return the ones
    }
}






third Method  using map


// Time Complexity : O(n) where n is the number of elements in the array and space complexity is O(n)







class Solution {
    public int singleNumber(int[] nums) {
        int n = nums.length;  // variable to store the length of the array
        HashMap<Integer, Integer> mp = new HashMap<>();  // hashmap to store the frequency of the elements
        for(int i = 0; i < n; i++){  // iterate through the array
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);  // update the frequency
        }
        for(Map.Entry<Integer, Integer> entry : mp.entrySet()){  // iterate through the map
            if(entry.getValue() == 1){  // if the frequency is 1
                return entry.getKey();  // return the element
            }
        }
        return -1;  // return -1
    }
}


