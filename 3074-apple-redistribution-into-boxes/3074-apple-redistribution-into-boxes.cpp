class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
         int total_apples = 0;
         for(auto a : apple){
            total_apples += a;
         }
        std::sort(capacity.rbegin(), capacity.rend());
        int total_capacity = 0;
        int box_count = 0;
        for (int cap : capacity) {
            if (total_capacity >= total_apples) {
                break;
            }
            total_capacity += cap;
            box_count++;
        }
        return box_count;
    }
};