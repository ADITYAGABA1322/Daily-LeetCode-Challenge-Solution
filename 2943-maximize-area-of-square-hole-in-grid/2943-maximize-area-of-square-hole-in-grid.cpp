class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(vBars.begin() , vBars.end());
        sort(hBars.begin() , hBars.end());

        int maxConsHBar = 1 , maxConsVBar = 1;

        int currConsHBar = 1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i] - hBars[i-1] == 1 )currConsHBar++;
            else currConsHBar = 1;
            maxConsHBar = max(maxConsHBar , currConsHBar);
        }

        int currConsVBar = 1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i] - vBars[i-1] == 1 ) currConsVBar++;
            else currConsVBar = 1;
            maxConsVBar = max(maxConsVBar , currConsVBar);
        }
        int side = min(maxConsHBar , maxConsVBar) +1;
        return side * side;
    }
};