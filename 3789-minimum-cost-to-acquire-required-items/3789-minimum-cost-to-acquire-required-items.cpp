class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a = (long long)cost1*need1 + (long long)cost2*need2;
        int m = min(need1 , need2);
        long long b = (long long)m*costBoth + (long long)(need1-m)*cost1 + (long long)(need2-m)*cost2;
        long long c = (long long)max(need1 , need2) * costBoth;
        return min({a,b,c});
    }
};