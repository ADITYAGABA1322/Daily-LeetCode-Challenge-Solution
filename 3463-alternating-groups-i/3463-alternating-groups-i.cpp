class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int count = 0;
        int n = colors.size();
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        for(int i=2; i<n; i++){
            if(colors[i-1] != colors[i] && colors[i-2] != colors[i-1]) count++;
        }
        // Check for alternating groups in the main part of the array, including
        // wrapping around
        // for (int i = 0; i < n; ++i) {
        //     // Use modulo operator to wrap around the array indices
        //     if (colors[i] != colors[(i + 1) % n] &&
        //         colors[(i + 1) % n] != colors[(i + 2) % n]) {
        //         count++;
        //     }
        // }
        return count;
    }
};