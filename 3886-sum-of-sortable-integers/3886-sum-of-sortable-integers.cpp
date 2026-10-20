class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> fac;

        for (int x = 1; x * x <= n; ++x) {
            if (n % x == 0) {
                fac.push_back(x);
                if (n / x != x) {
                    fac.push_back(n / x);
                }
            }
        }

        vector<int> target = nums;
        ranges::sort(target);

        auto kmp = [](const vector<int>& nums1, const vector<int>& nums2) {
            int n = nums1.size(), m = nums2.size();
            vector<int> pi(m, 0);
            int j = 0;

            for (int i = 1; i < m; ++i) {
                while (j > 0 && nums2[i] != nums2[j]) {
                    j = pi[j - 1];
                }
                if (nums2[i] == nums2[j]) {
                    ++j;
                }
                pi[i] = j;
            }

            j = 0;
            for (int i = 0; i < n; ++i) {
                while (j > 0 && nums1[i] != nums2[j]) {
                    j = pi[j - 1];
                }
                if (nums1[i] == nums2[j]) {
                    ++j;
                }
                if (j == m) {
                    return true;
                }
            }
            return false;
        };

        auto check = [&](const vector<int>& nums1, const vector<int>& nums2) {
            // Check whether cyclic rotations of nums1 can produce nums2
            vector<int> doubled = nums1;
            doubled.insert(doubled.end(), nums1.begin(), nums1.end());
            return kmp(doubled, nums2);
        };

        int ans = 0;

        for (int d : fac) {
            bool allGood = true;
            for (int left = 0; left < n; left += d) {
                int right = left + d - 1;
                vector<int> sub1(nums.begin() + left, nums.begin() + right + 1);
                vector<int> sub2(target.begin() + left,
                                 target.begin() + right + 1);

                if (!check(sub1, sub2)) {
                    allGood = false;
                    break;
                }
            }
            if (allGood) {
                ans += d;
            }
        }

        return ans;
    }
};