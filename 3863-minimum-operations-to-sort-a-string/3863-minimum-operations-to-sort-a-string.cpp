class Solution {
public:
    bool isSorted(string s){
        return is_sorted(s.begin() , s.end());
    }
    int minOperations(string s) {
        // int n = s.size();
        // if (isSorted(s)) return 0;
        // queue<pair<string ,int>> q;
        // unordered_set<string> vis;
        // q.push({s , 0});
        // vis.insert(s);
        // while(!q.empty()){
        //     auto [curr , steps] = q.front();
        //     q.pop();
        //     for(int i=0; i<n; i++){
        //         for(int j=i; j<n; j++){
        //             if(i == 0 && j==n-1) continue;
        //             string next = curr;
        //             sort(next.begin() + i , next.begin() + j + 1);
        //             if(isSorted(next)) return steps + 1;
        //             if(!vis.count(next)){
        //                 vis.insert(next);
        //                 q.push({next , steps+1});
        //             }
        //         }
        //     }
        // }
        // return -1;

        // Optimized one
        int n = s.size();
        if(isSorted(s)) return 0;
        if(n == 2) return -1;
        char mx = *max_element(s.begin() , s.end());
        char mn = *min_element(s.begin() , s.end());
        if(s[0] == mn || s[n-1] == mx) return 1;
        char mx_mid = *max_element(begin(s)+1 , end(s) - 1);
        char mn_mid = *min_element(begin(s)+1 , end(s) - 1);
        if(s[0] > mx_mid &&  s[n-1] < mn_mid) return 3;
        return 2;
    }
};