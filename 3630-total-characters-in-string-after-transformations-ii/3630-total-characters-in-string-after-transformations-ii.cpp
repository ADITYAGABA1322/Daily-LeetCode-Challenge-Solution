class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        
        // Initialize frequency vector
        vector<long long> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Build transformation matrix
        vector<vector<long long>> matrix(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int k = 0; k < nums[i]; k++) {
                int nextChar = (i + k + 1) % 26;
                matrix[nextChar][i] = (matrix[nextChar][i] + 1) % MOD;
            }
        }
        
        // Compute matrix^t
        auto matrixPower = matrixExponentiation(matrix, t, MOD);
        
        // Compute final frequencies
        vector<long long> finalFreq(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                finalFreq[i] = (finalFreq[i] + (matrixPower[i][j] * freq[j]) % MOD) % MOD;
            }
        }
        
        // Sum up final frequencies
        long long result = 0;
        for (long long f : finalFreq) {
            result = (result + f) % MOD;
        }
        
        return result;
    }
    
private:
    // Matrix multiplication
    vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& A, 
                                            const vector<vector<long long>>& B, 
                                            long long mod) {
        int n = A.size();
        vector<vector<long long>> C(n, vector<long long>(n, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
                }
            }
        }
        
        return C;
    }
    
    // Matrix exponentiation
    vector<vector<long long>> matrixExponentiation(const vector<vector<long long>>& A, 
                                                 long long power, 
                                                 long long mod) {
        int n = A.size();
        
        // Initialize result to identity matrix
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }
        
        // Initialize power matrix
        vector<vector<long long>> powerMatrix = A;
        
        // Binary exponentiation
        while (power > 0) {
            if (power & 1) {
                result = matrixMultiply(result, powerMatrix, mod);
            }
            
            powerMatrix = matrixMultiply(powerMatrix, powerMatrix, mod);
            power >>= 1;
        }
        
        return result;
    }
};