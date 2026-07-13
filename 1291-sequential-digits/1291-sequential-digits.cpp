class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string c = "123456789";
        vector<int>a;

        for(int i =0;i<c.size();i++){
            for(int j =i+1;j<=c.size();j++){
                int curr = stoi(c.substr(i,j-i));
                if(curr<=high && curr>=low)a.push_back(curr);
            }
        }
        sort(a.begin(),a.end());
        return a;
    }
};
