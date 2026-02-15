class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0 , i = a.size() -1 , j = b.size()-1;
        while(i>=0 || j>=0 || carry){
            if(i>=0) carry += a[i--] - '0';
            if(j>=0) carry += b[j--] - '0';
            ans = to_string(carry%2) + ans;
            carry /= 2;
        }
        return ans;
    }
};