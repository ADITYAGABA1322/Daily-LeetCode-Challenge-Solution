class Solution {
public:
    long long coloredCells(int n) {
        // we are given 2d grid uncolored unit cell given positive int n  and isee one pattern like   when. n == 1 return mesns base contion and for 2 is 5 and you see a aottern like 3 is 13 means the if i add 1 + 2 + 5 *2 = 13 and in another form 3 is n and recent for 2 si alrady 5 just double it or mutiply 2 u see a pattern 
        if (n == 1) return 1;
        long long n_long = n; // Convert n to long long
        return 1 + 4 * (n_long * (n_long - 1) / 2);
    }
};