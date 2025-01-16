class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // the problme is all about xor by doing xor create nums 3 means res and make xor of them and then return it xor count ok so now i am beginer of bit i now how to xor but dont know how to solve this but from my mind i think we start xor in nums1 and nums2 ok  exactly once and do for unms 3 and return cnt i am right or wrong 
//         Approach
// Understand the Problem:

// We need to compute the XOR of all pairs formed by taking one element from nums1 and one element from nums2.
// Simplify the Problem:

// Instead of computing the XOR for each pair individually, we can use the properties of XOR to simplify the computation.
// If the length of nums1 is even, each element in nums2 will be XORed an even number of times, resulting in 0.
// If the length of nums1 is odd, each element in nums2 will be XORed an odd number of times, resulting in the XOR of all elements in nums2.
// Similarly, if the length of nums2 is even, each element in nums1 will be XORed an even number of times, resulting in 0.
// If the length of nums2 is odd, each element in nums1 will be XORed an odd number of times, resulting in the XOR of all elements in nums1.
// Detailed Steps
// Compute XOR of All Elements in nums1:

// Compute the XOR of all elements in nums1.
// Compute XOR of All Elements in nums2:

// Compute the XOR of all elements in nums2.
// Combine Results:

// If the length of nums1 is odd, XOR the result with the XOR of all elements in nums2.
// If the length of nums2 is odd, XOR the result with the XOR of all elements in nums1.

    int xor1 = 0 , xor2 = 0 , res = 0;
    for(auto n1 : nums1) xor1 ^= n1;
    for(auto n2 : nums2) xor2 ^= n2;
    if(nums1.size() % 2 != 0) res ^= xor2;
    if(nums2.size() % 2 != 0) res ^= xor1;
    return res;
    }
};