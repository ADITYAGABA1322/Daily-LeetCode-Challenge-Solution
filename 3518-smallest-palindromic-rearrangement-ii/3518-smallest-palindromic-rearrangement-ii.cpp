class Solution {
public:
    long long comb(long long n, long long m, long long k) {
        long long res = 1;
        m = min(m, n - m);
        for (long long i = 1; i <= m; i++) {
            res = res * (n - i + 1) / i; // interleaved — always exact
            if (res > k)
                return k + 1; // cap safely after division
        }
        return res;
    }

    long long countPerms(vector<int>& freq, int rem, long long k) {
        long long ways = 1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                continue;
            ways *= comb(rem, freq[i], k);
            if (ways > k)
                break; // cap early
            rem -= freq[i];
        }
        return ways;
    }
    string smallestPalindrome(string s, long long k) {
        int n = s.size();

        // step 1
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;

        string half = "";
        vector<int> halfFreq(26, 0);
        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2; // what goes here?
        }

        // step 2
        int halfLen = n / 2; // what goes here?
        long long total = countPerms(halfFreq, halfLen, k);
        cout << "total: " << total << " k: " << k << endl;
        if (total < k)
            return "";

        // step 3
        string first = "";
        long long startIndex = 1;
        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (halfFreq[c] == 0)
                    continue;
                halfFreq[c]--;
                long long ways = countPerms(halfFreq, halfLen - pos - 1, k);
                if (startIndex + ways > k) {
                    first += string(1, 'a' + c);
                    break;
                }
                halfFreq[c]++;
                startIndex += ways;
            }
        }

        // step 4
        string mid = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                mid = string(1, 'a' + i);
                break;
            }
        }
        string second = first;
        reverse(second.begin(), second.end());
        return first + mid + second;
    }
};