class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        // sotre preifx sum for the  only ones
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                prefix[i] = 1;
        }
        for(int i=1; i<n; i++) prefix[i] += prefix[i-1]; 
        for (int i = 0; i < n; i++) {
            int zero = 0, ones = 0;
            for (int j = i; j < n; j++) {
                ones = prefix[j];
                if (i != 0)
                    ones -=  prefix[i - 1];
                zero = (j - i + 1) - ones;
                // if(zero * zero > ones) break;
                if (zero * zero > ones)
                    j += ((zero * zero) - ones - 1);
                if (zero * zero <= ones) {
                    ans++;
                    if (zero * zero < ones) {
                        int diff = sqrt(ones) - zero;
                        int nextj = j + diff;
                        if (nextj >= n)
                            ans += n - j - 1;
                        else
                            ans += diff;
                        j = nextj;
                    }
                }
            }
        }
        return ans;
    }
};