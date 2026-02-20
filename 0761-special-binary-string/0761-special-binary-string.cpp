class Solution {
public:
    string makeLargestSpecial(string s) {
        int n = s.size();
        vector<string> special;
        int start = 0 , sum = 0;
        for(int i=0; i<n; i++){
            sum += s[i] == '1' ? 1 : -1;
            if(sum == 0){
                string inner = s.substr(start+1 , i-start-1);
                special.push_back('1' + makeLargestSpecial(inner) + '0');
                start = i+1;
            }
        }

        sort(special.begin(), special.end(), greater<string>());
        string res;
        for(auto s : special){
            res += s;
        }
        return res;
    }
};