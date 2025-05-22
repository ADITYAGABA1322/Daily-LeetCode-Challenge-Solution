class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        priority_queue<int> heap;
        int n = nums.size();
        int op = 0; // op -> operations
        vector<int> diff(nums.size() + 1, 0);
        for (int i = 0, j = 0; i < n; i++) {
            op += diff[i];
            while (j < queries.size() && queries[j][0] == i) {
                heap.push(queries[j][1]);
                j++;
            }
            while (op < nums[i] && !heap.empty() && heap.top() >= i) {
                op += 1;
                diff[heap.top() + 1] -= 1;
                heap.pop();
            }
            if (op < nums[i])
                return -1;
        }
        return heap.size();
    }
};