#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // Function to generate prime numbers up to a given limit using Sieve of Eratosthenes
    vector<int> generatePrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= limit; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

    // Function to count non-special numbers in the range [l, r]
    int nonSpecialCount(int l, int r) {
        int totalNumbers = r - l + 1;
        int specialCount = 0;

        int limit = sqrt(r);
        vector<int> primes = generatePrimes(limit);

        for (int prime : primes) {
            int specialNumber = prime * prime;
            if (specialNumber >= l && specialNumber <= r) {
                specialCount++;
            }
        }

        return totalNumbers - specialCount;
    }
};