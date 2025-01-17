class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // we need to find valid array ok and find we need to compute xor of adjacent values in a binary array original of length n.If i = n - 1, then derived[i] = original[i] ⊕ original[0].
// Otherwise, derived[i] = original[i] ⊕ original[i + 1]. nust follow the contion and perform xor we done it 
        int xorSum = 0;
        for(auto n : derived) xorSum ^= n;
        return xorSum == 0;
    }
};