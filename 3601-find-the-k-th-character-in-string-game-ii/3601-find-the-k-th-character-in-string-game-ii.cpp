class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        k--;
        for (int i = __lg(k); i >= 0; i--) {
            if (k >> i & 1) {
                ans += operations[i];
            }
        }
        return 'a' + (ans % 26);
    }
};