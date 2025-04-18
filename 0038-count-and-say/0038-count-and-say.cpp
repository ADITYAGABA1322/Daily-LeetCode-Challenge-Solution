class Solution {
public:
    string countAndSay(int n) {
        // if  n == 1 reutn 11 simple and if we go to n we n-1 operation to a string just we nned to cnt the frequeny of element from the start oje meaintin the cnt and thier is no of that string just add the cnt no of that no like 3322251 -> 23321511
        if(n==1) return "1";
        // now we need to get the n number start with from the start of 1 to n and perform operation of this one rle of no like for n = 4 sart with 1 we know its 1 and for 2 we know its 11 and for 3 its 21 and for 4 its 1211 we know we print cnt first then no and then cnt then no so one ok but how like u know we itrate thorugh a no or use string methid to get the char of each string cnt ok  
        string ans = "";
        int cnt = 1;
        string s = countAndSay(n-1);
        for(int i=0; i<s.size(); i++){
            if(s[i] == s[i+1]) cnt++;
            else{
                ans += to_string(cnt) + s[i];
                cnt = 1;
            }
        }
        return ans;
    }
};