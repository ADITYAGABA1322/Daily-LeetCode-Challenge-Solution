#include <vector>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalWaitingTime = 0; // Use long long to avoid overflow
        int currentTime = 0; // Tracks the current time
        
        for (auto& customer : customers) {
            int arrival = customer[0];
            int time = customer[1];
            
            // If the chef is idle or waiting for the customer, start at the customer's arrival time
            currentTime = max(currentTime, arrival);
            
            // Add the preparation time to the current time
            currentTime += time;
            
            // Calculate the waiting time for this customer
            totalWaitingTime += currentTime - arrival;
        }
        
        // Calculate the average waiting time. Cast to double for floating point division.
        return (double)totalWaitingTime / customers.size();
    }
};