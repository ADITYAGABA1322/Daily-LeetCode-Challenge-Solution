class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        // lets build the approach for this question the questions imsple simple but tricky also if i go through i find that we nned cnt  those arr which differences[i] = hidden[i + 1] - hidden[i] and another their is limit lower and upper just start the loop from those no and count if some array contain this or not 
        // brute force MLE
        // int n = differences.size();
        // int cnt = 0;
        // for(int i=lower; i<=upper; i++){
        //     vector<int> hidden(n+1);
        //     hidden[0] = i;
        //     bool valid = true;
        //     for(int j=0; j<n; j++){
        //         hidden[j+1] = hidden[j] + differences[j];
        //         if(hidden[j+1] < lower || hidden[j+1] > upper){
        //             valid = false;
        //             break;
        //         }
        //     }
        //     if(valid) cnt++;
        // }
        // return cnt;
        // Optimized
        long long min_val = 0, max_val = 0, curr = 0;
        
        // Calculate the min and max possible values in our array
        for (int diff : differences) {
            curr += diff;
            min_val = min(min_val, curr);
            max_val = max(max_val, curr);
        }
        
        // Calculate how many valid starting points we can have
        // For any starting point x, the array values will range from
        // x + min_val to x + max_val
        // These must all be within [lower, upper]
        
        // Lower bound: lower <= x + min_val
        // Upper bound: x + max_val <= upper
        
        // Solving for x:
        // x >= lower - min_val
        // x <= upper - max_val
        
        long long valid_start_min = lower - min_val;
        long long valid_start_max = upper - max_val;
        
        // If valid_start_max < valid_start_min, no valid arrays exist
        if (valid_start_max < valid_start_min) return 0;
        
        // The number of valid starting points is the range size + 1
        return valid_start_max - valid_start_min + 1;
    }
};