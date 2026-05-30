class Solution {
public:
    vector<int> seg;
    void update(int idx, int val, int p, int l, int r) {
        if (l == r) {
            seg[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) {
            update(idx, val, p << 1, l, mid);
        } else {
            update(idx, val, p << 1 | 1, mid + 1, r);
        }
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    int query(int L, int R, int p, int l, int r) {
        if (L <= l && r <= R) {
            return seg[p];
        }
        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid) {
            res = max(res, query(L, R, p << 1, l, mid));
        }
        if (R > mid) {
            res = max(res, query(L, R, p << 1 | 1, mid + 1, r));
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000;
        seg.resize(mx << 2);
        set<int> st = {0, mx};
        update(mx, mx, 1, 0, mx);
        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = st.upper_bound(x);
                int r = *it;
                int l = *prev(it);
                update(x, x - l, 1, 0, mx);
                update(r, r - x, 1, 0, mx);
                st.insert(x);
            } else {
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                --it;
                int pre = *it;
                int max_space = query(0, pre, 1, 0, mx);
                max_space = max(max_space, x - pre);
                ans.push_back(max_space >= sz);
            }
        }
        return ans;
    }
};