class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = INT_MAX, even = INT_MAX;

        for (int x : nums1) {
            if (x % 2) odd = min(odd, x);
            else even = min(even, x);
        }

        return odd == INT_MAX || even == INT_MAX || odd < even;
    }
};