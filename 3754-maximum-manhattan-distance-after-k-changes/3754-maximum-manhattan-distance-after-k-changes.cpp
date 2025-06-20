class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;
        for (char it : s) {
            switch (it) {
                case 'N':
                    north++;
                    break;
                case 'S':
                    south++;
                    break;
                case 'E':
                    east++;
                    break;
                case 'W':
                    west++;
                    break;
            }
            int times1 =
                min({north, south, k});  // modification times for N and S
            int times2 = min(
                {east, west, k - times1});  // modification times for E and W
            ans = max(ans,
                      count(north, south, times1) + count(east, west, times2));
        }
        return ans;
    }

    int count(int drt1, int drt2, int times) {
        return abs(drt1 - drt2) + times * 2;
    }  // Calculate modified Manhattan distance
};