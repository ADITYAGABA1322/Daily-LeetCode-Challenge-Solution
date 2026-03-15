class Fancy {
private:
    static constexpr int mod = 1000000007;
    vector<int> v, a, b;

public:
    Fancy() {
        a.push_back(1);
        b.push_back(0);
    }

    // fast exponentiation
    int quickmul(int x, int y) {
        int ret = 1;
        int cur = x;
        while (y) {
            if (y & 1) {
                ret = (long long)ret * cur % mod;
            }
            cur = (long long)cur * cur % mod;
            y >>= 1;
        }
        return ret;
    }

    // multiplicative inverse
    int inv(int x) { return quickmul(x, mod - 2); }

    void append(int val) {
        v.push_back(val);
        a.push_back(a.back());
        b.push_back(b.back());
    }

    void addAll(int inc) { b.back() = (b.back() + inc) % mod; }

    void multAll(int m) {
        a.back() = (long long)a.back() * m % mod;
        b.back() = (long long)b.back() * m % mod;
    }

    int getIndex(int idx) {
        if (idx >= v.size()) {
            return -1;
        }
        int ao = (long long)inv(a[idx]) * a.back() % mod;
        int bo = (b.back() - (long long)b[idx] * ao % mod + mod) % mod;
        int ans = ((long long)ao * v[idx] % mod + bo) % mod;
        return ans;
    }
};