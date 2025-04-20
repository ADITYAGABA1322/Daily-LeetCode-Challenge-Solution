class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // given arr [1,1,2] -> [0,1,2] index 1 comes at [0,1] and 2 comes at [2] acc to 
//         The Approach
// The key insight is grouping rabbits efficiently:

// If a rabbit says "x", it means there are x+1 rabbits of its color in total
// We can group up to x+1 rabbits with the same answer into the same color
// If we have more than x+1 rabbits with the same answer, they must be different colors
// Algorithm Steps:
// Count the frequency of each answer using a hash map
// For each unique answer x:
// Calculate the group size: x+1 (total rabbits of one color)
// Calculate how many complete groups: ⌈frequency / (x+1)⌉ (ceiling division)
// Add group_size × number_of_groups to the total

        unordered_map<int , int> mp;
        for(auto x : answers) mp[x]++;
        int total = 0;
        // for(auto [x , cnt] : mp){
        //     // int groupSize = x + 1;
        //     // int groups = ceil(cnt / double(groupSize)); 
        //     total += (x+1) * ceil(cnt/double(x+1));
        // }
        for(auto it : mp){
            total += (it.first+1) * ceil(it.second / double(it.first+1));
        }
        return total;
    }
};