// #include <vector>
// using namespace std;

// class NumArray {
// private:
//     vector<int> prefixSum;
//     vector<int> originalNums;

// public:
//     NumArray(vector<int>& nums) {
//         originalNums = nums;
//         prefixSum.resize(nums.size());
//         if (!nums.empty()) {
//             prefixSum[0] = nums[0];
//             for (int i = 1; i < nums.size(); ++i) {
//                 prefixSum[i] = prefixSum[i - 1] + nums[i];
//             }
//         }
//     }
    
//     void update(int index, int val) {
//         int diff = val - originalNums[index];
//         originalNums[index] = val;
//         for (int i = index; i < originalNums.size(); ++i) {
//             prefixSum[i] += diff;
//         }
//     }
    
//     int sumRange(int left, int right) {
//         if (left == 0) return prefixSum[right];
//         return prefixSum[right] - prefixSum[left - 1];
//     }
// };

// #include <vector>
// using namespace std;

// class NumArray {
// private:
//     vector<int> tree;
//     int n;

//     void buildTree(vector<int>& nums, int treeIndex, int l, int r) {
//         if (l == r) {
//             tree[treeIndex] = nums[l];
//             return;
//         }
//         int mid = l + (r - l) / 2;
//         buildTree(nums, 2 * treeIndex + 1, l, mid);
//         buildTree(nums, 2 * treeIndex + 2, mid + 1, r);
//         tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
//     }

//     void updateTree(int treeIndex, int l, int r, int idx, int val) {
//         if (l == r) {
//             tree[treeIndex] = val;
//             return;
//         }
//         int mid = l + (r - l) / 2;
//         if (idx <= mid) updateTree(2 * treeIndex + 1, l, mid, idx, val);
//         else updateTree(2 * treeIndex + 2, mid + 1, r, idx, val);
//         tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
//     }

//     int sumRangeTree(int treeIndex, int l, int r, int i, int j) {
//         if (i > r || j < l) return 0;
//         if (i <= l && r <= j) return tree[treeIndex];
//         int mid = l + (r - l) / 2;
//         return sumRangeTree(2 * treeIndex + 1, l, mid, i, j) + sumRangeTree(2 * treeIndex + 2, mid + 1, r, i, j);
//     }

// public:
//     NumArray(vector<int>& nums) {
//         if (nums.empty()) return;
//         n = nums.size();
//         tree.resize(4 * n); // Allocate memory for segment tree
//         buildTree(nums, 0, 0, n - 1);
//     }

//     void update(int index, int val) {
//         updateTree(0, 0, n - 1, index, val);
//     }

//     int sumRange(int i, int j) {
//         return sumRangeTree(0, 0, n - 1, i, j);
//     }
// };
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> fenwickTree;
    vector<int> nums;
    int n;

    void updateFenwickTree(int i, int val) {
        while (i <= n) {
            fenwickTree[i] += val;
            i += i & (-i); 
        }
    }

   
    int getPrefixSum(int i) {
        int sum = 0;
        while (i > 0) {
            sum += fenwickTree[i];
            i -= i & (-i); 
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        fenwickTree.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            updateFenwickTree(i + 1, nums[i]);
        }
    }

    void update(int i, int val) {
        int delta = val - nums[i];
        nums[i] = val;
        updateFenwickTree(i + 1, delta);
    }

    int sumRange(int i, int j) {
        return getPrefixSum(j + 1) - getPrefixSum(i);
    }
};