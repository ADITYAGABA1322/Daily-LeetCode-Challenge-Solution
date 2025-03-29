class Solution {
private:
    vector<int> smallestPrimeFactor;
    
    void initializeSieve(int maxVal) {
        smallestPrimeFactor.resize(maxVal + 1);
        
        for (int i = 1; i <= maxVal; i++)
            smallestPrimeFactor[i] = i;
            
        for (int i = 4; i <= maxVal; i += 2)
            smallestPrimeFactor[i] = 2;
            
        for (int i = 3; i * i <= maxVal; i += 2) {
            if (smallestPrimeFactor[i] == i) {
                for (int j = i * i; j <= maxVal; j += i) {
                    if (smallestPrimeFactor[j] == j) {
                        smallestPrimeFactor[j] = i;
                    }
                }
            }
        }
    }
    
    int primeScore(int num) {
        if (num <= 1) return 0;
        
        unordered_set<int> primeFactors;
        
        while (num > 1) {
            primeFactors.insert(smallestPrimeFactor[num]);
            num /= smallestPrimeFactor[num];
        }
        
        return primeFactors.size();
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        
        // Find maximum value for Sieve initialization
        int maxVal = *max_element(nums.begin(), nums.end());
        initializeSieve(maxVal);
        
        // Calculate prime scores
        vector<int> primeScores(n);
        for (int i = 0; i < n; i++) {
            primeScores[i] = primeScore(nums[i]);
        }
        
        // Calculate subarray counts with monotonic stacks
        // Use long long to prevent overflow
        vector<long long> subarrayCount(n, 1LL);
        
        // Next greater prime score to the left
        vector<long long> leftLimit(n, -1LL);
        stack<int> leftStack;
        for (int i = 0; i < n; i++) {
            while (!leftStack.empty() && primeScores[leftStack.top()] < primeScores[i]) {
                leftStack.pop();
            }
            
            if (!leftStack.empty()) {
                leftLimit[i] = leftStack.top();
            }
            leftStack.push(i);
        }
        
        // Next greater or equal prime score to the right
        vector<long long> rightLimit(n, n);
        stack<int> rightStack;
        for (int i = n - 1; i >= 0; i--) {
            while (!rightStack.empty() && primeScores[rightStack.top()] <= primeScores[i]) {
                rightStack.pop();
            }
            
            if (!rightStack.empty()) {
                rightLimit[i] = rightStack.top();
            }
            rightStack.push(i);
        }
        
        // Calculate subarray count for each element
        for (int i = 0; i < n; i++) {
            long long left = i - leftLimit[i];
            long long right = rightLimit[i] - i;
            subarrayCount[i] = left * right;
        }
        
        // Create value-count pairs and sort by value
        vector<pair<long long, long long>> valueWithCount;
        for (int i = 0; i < n; i++) {
            valueWithCount.push_back({nums[i], subarrayCount[i]});
        }
        
        sort(valueWithCount.begin(), valueWithCount.end(), 
             [](const auto& a, const auto& b) { return a.first > b.first; });
        
        // Greedily choose highest values
        long long result = 1;
        for (auto& [val, count] : valueWithCount) {
            long long operations = min((long long)k, count);
            k -= operations;
            
            // Binary exponentiation for val^operations
            long long power = 1;
            long long base = val;
            while (operations > 0) {
                if (operations & 1) {
                    power = (power * base) % MOD;
                }
                base = (base * base) % MOD;
                operations >>= 1;
            }
            
            result = (result * power) % MOD;
            if (k == 0) break;
        }
        
        return result;
    }
};