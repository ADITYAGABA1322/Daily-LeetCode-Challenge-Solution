class BIT {
public:
    int n;
    vector<long long> bit1, bit2;

    BIT(int n) {
        this->n = n;
        bit1.assign(n + 2, 0);
        bit2.assign(n + 2, 0);
    }

    int lowbit(int i) {
        return i & -i;
    }

    // Point update on one Fenwick Tree
    void update(vector<long long>& bit, int i, long long delta) {
        while (i <= n) {
            bit[i] += delta;
            i += lowbit(i);
        }
    }

    // Prefix sum of one Fenwick Tree
    long long query(vector<long long>& bit, int i) {
        long long sum = 0;

        while (i > 0) {
            sum += bit[i];
            i -= lowbit(i);
        }

        return sum;
    }

    // Add delta to every element in [left, right]
    void add(int left, int right, long long delta) {
        if (left > right) return;

        update(bit1, left, delta);
        update(bit1, right + 1, -delta);

        update(bit2, left, delta * (left - 1));
        update(bit2, right + 1, -delta * right);
    }

    // Prefix sum of the original array after range updates
    long long prefixSum(int i) {
        return 1LL * i * query(bit1, i) - query(bit2, i);
    }

    // Range sum [left, right]
    long long query(int left, int right) {
        if (left > right) return 0;

        return prefixSum(right) - prefixSum(left - 1);
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1'000'000'007;
        int n = nums.size();

        BIT bit(n + 1);
        unordered_map<int, int> seen;

        long long cur = 0;
        long long res = 0;

        for (int i = 0; i < n; i++) {
            int p = seen.count(nums[i]) ? seen[nums[i]] : -1;

            // 0-based range of starting indices:
            // [p + 1, i]
            int left = p + 1;

            // Convert to 1-based BIT indices.
            int L = left + 1;
            int R = i + 1;

            // Sum of old distinct counts in the affected range.
            long long q = bit.query(L, R);

            // Change in the sum of squares:
            // (x + 1)^2 - x^2 = 2*x + 1
            long long delta = (2 * q + (i - p)) % MOD;

            // Sum of squares for subarrays ending at i.
            cur = (cur + delta) % MOD;

            // Add this endpoint's contribution to the answer.
            res = (res + cur) % MOD;

            // Increment distinct counts in [p + 1, i].
            bit.add(L, R, 1);

            seen[nums[i]] = i;
        }

        return static_cast<int>(res);
    }
};