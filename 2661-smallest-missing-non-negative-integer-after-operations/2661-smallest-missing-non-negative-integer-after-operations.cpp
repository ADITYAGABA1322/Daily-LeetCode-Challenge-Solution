class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // Feels like problem is telling about missing positive number, but how should we find that number finding by taking the sum and a half something divided at these numbers find that the number is not in the range but there is a twist the twist is that we need to add or subtract a value from an element of numbers in one operation so that we want to make the air format in a serial wise order and referring to that like which number smallest missing posting number which is minimum excluded from the end so that we need to find this to make an algorithm we use the map to this for finding these numbers and make it mapping towards it and it's depend on how many times you wanna apply that this is something like greedy so how should we solve these? These are the things I think go for it. We wanna start with a map trip to the elements, adding or subtracting the value from that in the operation operations and finding diagnose by using the positive integer type.
        unordered_map<int , int> remCnt;
        for(auto n : nums){
            int rem = ((n % value) + value) % value;
            remCnt[rem]++;
        }
        int mex  = 0;
        while(true){
            int rem = mex % value;
            if(remCnt[rem] == 0) return mex;
            remCnt[rem]--;
            mex++;
        }
        return mex;
    }
};