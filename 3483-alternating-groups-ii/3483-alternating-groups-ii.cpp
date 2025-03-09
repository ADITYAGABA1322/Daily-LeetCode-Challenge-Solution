class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // color i = 0 means red and 1 is blue ok given int k now what we need to count alternative using means modulo in circle and count that how many is different ok we to first iterate to arr of colors adn check 1 and 0 and acc to k we nned to make that colors ok inthat pos means form 1 color on another k side the color is alternate ok 
        for(int i=0; i<k-1; i++) colors.push_back(colors[i]);
        int res = 0 , cnt = 1 , n = colors.size();  
        for(int i=1; i<n; i++){
            if(colors[i] != colors[i-1]) cnt++;
            else cnt  = 1;
            if(cnt>=k) res++;
        }
        return res;
    }
};