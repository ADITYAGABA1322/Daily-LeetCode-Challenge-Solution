class Solution {
public:
    string longestPalindrome(string s) {
        string modify = "#";
        for(char c : s){
            modify += c;
            modify += '#';
        }
        int n = modify.size();
        vector<int> p(n , 0);
        int center = 0 , maxLen = 0 , maxCenter = 0 , right = 0;
        for(int i=0; i<n; i++){
            int mirror = 2*center - i;
            if(i<right) p[i] = min(right - i , p[mirror]);
            int a = i+(1+p[i]);
            int b = i-(1+p[i]);
            while(a<n && b>=0 && modify[a] == modify[b]){
                p[i]++;
                a++;
                b--;
            }
            if(i+p[i] > right){
                center = i;
                right = i+p[i];
            }
            if(p[i] > maxLen){
                maxLen = p[i];
                maxCenter = i;
            }
        }
        int start = (maxCenter - maxLen)/2;
        return s.substr(start , maxLen);
    }
};