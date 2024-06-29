// class Solution {
// public:
//     long long maximumImportance(int n, vector<vector<int>>& roads) {
//         vector<int> freq(n, 0);
//         for (auto road : roads){
//             freq[road[0]]++;
//             freq[road[1]]++;
//         }
//         sort(freq.begin(), freq.end());
//         long long maxI = 0, val = 1;
//         for (long long f : freq) {
//             maxI +=  f*val++;
            
//         }
//         return maxI;
//     }
// };

// or using heap

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cityFrequency(n, 0);
        
        // Count how many times each city appears in the roads list
        for (const auto& road : roads) {
            cityFrequency[road[0]]++;
            cityFrequency[road[1]]++;
        }
        
        // Use a priority queue to manage frequencies
        priority_queue<int> pq;
        for (int freq : cityFrequency) {
            pq.push(freq);
        }
        
        long long totalImportance = 0;
        int currentValue = n;
        // Assign the highest values to the most frequently occurring cities
        while (!pq.empty()) {
            int freq = pq.top(); pq.pop();
            totalImportance += static_cast<long long>(freq) * currentValue--;
        }
        
        return totalImportance;
    }
};