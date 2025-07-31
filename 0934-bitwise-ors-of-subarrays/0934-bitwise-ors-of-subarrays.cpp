class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> current;
        
        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num); // Subarray of just current element
            
            // Extend all previous subarrays by including current element
            for (int prev : current) {
                next.insert(prev | num);
            }
            
            current = next;
            
            // Add all current ORs to result
            for (int val : current) {
                result.insert(val);
            }
        }
        
        return result.size();
    }
};