class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // brute force
        // int n = dominoes.size()  , cnt = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         int a = dominoes[i][0] , b = dominoes[i][1];
        //         int c = dominoes[j][0] , d = dominoes[j][1];
        //         if((a == c && b == d) || (a == d && b == c)) cnt++;
        //     }
        // }
        // return cnt;
        // optimized 
//         Understanding the Domino Encoding Formula
// The line int key = min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]) is a clever way to create a unique identifier for each domino pair regardless of its orientation. Let me break it down in detail:

// The Core Concept
// A domino has two values: [a, b]. When comparing dominoes, orientation doesn't matter, meaning [a, b] is equivalent to [b, a]. We need a consistent way to represent both orientations as the same value.

// The Formula Explained
// This formula:

// Takes the smaller value and makes it the "tens digit"
// Takes the larger value and makes it the "ones digit"
// Combines them into a single integer
// Why This Works
// For any domino [a, b], regardless of order:

// min(a, b) always gives the smaller value
// max(a, b) always gives the larger value
// Multiplying the smaller value by 10 and adding the larger value creates a unique encoding
// Examples
// Domino [1, 2]:

// min(1, 2) = 1
// max(1, 2) = 2
// key = 1 * 10 + 2 = 12
// Domino [2, 1]:

// min(2, 1) = 1
// max(2, 1) = 2
// key = 1 * 10 + 2 = 12
// Both [1, 2] and [2, 1] get encoded as 12, allowing us to count them as equivalent.

// Why Multiply by 10?
// The multiplication by 10 is crucial because it creates a place-value system:

// It ensures that dominoes like [1, 2] and [2, 1] map to the same value (12)
// But dominoes like [1, 3] map to a different value (13)
// Limitations
// This encoding works perfectly for the given problem because:

// Domino values are small (1-9 in the problem constraints)
// We only need to compare if dominoes are equivalent
// If domino values could be larger (≥10), we would need a different encoding method, like:

// In the Context of the Algorithm
// By using this encoding, we can:

// Quickly check if we've seen an equivalent domino before
// Count the number of equivalent pairs in a single pass
// Avoid comparing each domino with every other domino (O(n²))
// When a new domino is processed, we check how many equivalent dominoes we've seen before (using the map count), add that to our result, and then increment the count for this domino pattern.

// This elegant solution turns what would be an O(n²) comparison problem into an O(n) counting problem.
        unordered_map<int , int> mp;
        int cnt = 0;
        for(auto d : dominoes){
            int key = min(d[0] , d[1]) * 10 + max(d[0] , d[1]);
            cnt += mp[key];
            mp[key]++;
        }
        return cnt;
    }
};