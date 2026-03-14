class Solution {
public:
    string getHappyString(int n, int k) {
        string ans;
        int cnt = 0;
        function<void(string)> bt = [&](string s){
            if(s.size() == n){
                cnt++;
                if(cnt == k) ans = s;
                return;
            }
            for(auto c : {'a', 'b' , 'c'}){
                if(s.empty() || s.back() != c){
                    bt(s + c);

                }
            }
        };
        bt("");
        return ans;
    }
};