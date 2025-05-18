class Solution {
public:
    int colorTheGrid(int m, int n) {
        // the problem is designed like that  i see there is pattern of combonatrics but how first i wanna tell we track the states using combination in dp 
        // But how should we use DP like what is the code is coming on by saying this question like when I talk about there is a MN and these are the two states which defines the how many grades are comes according to based on that so how should I know about like there is three types of colors I should know some combination contains if I say one grade there are the three possibilities of the Color is coming on in one grade like the red blue or green so if I say, I am equal one and an equal one means one row one c so according to that there are three Kullas are coming on so the first one is answer three but for the second one what it say it say m*n is grdi so 1*2 is grid  so acc to how many pairs shoudl we genrate that what i want 
        const int MOD = 1e9+7;
        vector<int> validColumns = generateValidColumns(m);
        int numStates = validColumns.size();
        
        vector<vector<int>> adj(numStates);
        for(int i=0; i<numStates; i++){
            for(int j=0; j<numStates; j++) {
                if(compatible(validColumns[i] , validColumns[j] , m)){
                adj[i].push_back(j);
                }
            }
        }
        vector<vector<long long>> dp(n, vector<long long>(numStates, 0));
        for(int i=0; i<numStates; i++) dp[0][i] = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<numStates; j++){
                for(auto prev : adj[j]) dp[i][j] = (dp[i][j] + dp[i-1][prev])%MOD;
            }
        }
        long long res= 0;
        for(int i=0; i<numStates; i++){
            res = (res + dp[n-1][i]) % MOD;
        }
        return res;
    }
    private:
    vector<int> generateValidColumns(int m){
        vector<int> validColumns;
        for(int mask = 0; mask<pow(3,m); mask++){
            bool valid = true;
            int temp = mask;
            int prev = -1;
            for(int i=0; i<m; i++){
                int color = temp%3;
                temp /= 3;
                if(color == prev){
                    valid = false;
                    break;
                }
                prev = color;
            }
            if(valid) validColumns.push_back(mask);
        }
        return validColumns;
    }
    bool compatible(int col1 , int  col2 , int m){
        for(int i=0; i<m; i++){
            int color1 = (col1 / (int) pow(3,i)) % 3;
            int color2 = (col2 / (int) pow(3,i)) % 3;
            if(color1 == color2) return false;
        }
        return true;
    }
};