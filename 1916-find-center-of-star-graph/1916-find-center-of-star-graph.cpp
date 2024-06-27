class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // The center of a star graph will be the common node in the first two edges.
        int u1 = edges[0][0], v1 = edges[0][1];
        int u2 = edges[1][0], v2 = edges[1][1];
        
        // If the first node of the first edge is the same as either node in the second edge, it's the center.
        if (u1 == u2 || u1 == v2) return u1;
        // Otherwise, the second node of the first edge is the center.
        return v1;
    }
};