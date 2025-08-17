class Solution {
public:
    double new21Game(int N, int K, int W) {  // function to find the probability of winning the game
        if(K == 0 || N >= K+W){  // if the score is 0 or the score is greater than or equal to K+W
            return 1.0;  // return 1
        }
        vector<double> dp(N+1);  // dp vector to store the probabilities
        dp[0] = 1.0;  // initialize the first element of the dp vector to 1
        double Wsum = 1.0;  // Wsum is the variable to store the sum of the probabilities
        for(int i=1; i<=N; i++){  // for each score
            dp[i] = Wsum/W;  // calculate the probability
            if(i < K){  // if the score is less than K
                Wsum += dp[i];  // add the probability to the sum
            }
            if(i-W >= 0){  // if the score is greater than or equal to W
                Wsum -= dp[i-W];  // subtract the probability from the sum
            }
        }
        double ans = 0.0;  // ans is the variable to store the answer
        for(int i=K; i<=N; i++){  // for each score from K to N
            ans += dp[i];  // add the probability to the answer
        }
        return ans;  // return the answer
    }
};



