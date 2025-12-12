class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentionCnt(numberOfUsers);
        vector<int> offlineTime(numberOfUsers);
        auto lambda = [](vector<string>& vec1 , vector<string>& vec2){
            int t1 = stoi(vec1[1]) , t2 = stoi(vec2[1]);
            if(t1 == t2){
                return vec1[0][1] > vec2[0][1]; // MEANS OFFLINE 'O' COMES FIRST BEFORE THE MESSAGES ACC TO LEXO STRING 
            }
            return t1 < t2;
        };
        sort(events.begin() , events.end() , lambda);

        for(vector<string> e : events){
            if(e[0] == "MESSAGE"){
                applyMessageEvent(e , mentionCnt  , offlineTime);
            } else if(e[0] == "OFFLINE"){
                int timeStamp = stoi(e[1]);
                int id = stoi(e[2]);
                offlineTime[id] = timeStamp;
            }
        }
        return mentionCnt;
    }

    void  applyMessageEvent(vector<string>& event , vector<int>& mentionCnt , vector<int>& offlineTime){
        int timeStamp = stoi(event[1]);
        vector<string> ids;
        stringstream ss(event[2]);
        string token;
        while(ss >> token){
             ids.push_back(token);
        }
        for(auto id: ids){
            if(id == "ALL"){
                for(int i=0; i<mentionCnt.size(); i++){
                    mentionCnt[i]++;
                }
            } else if(id == "HERE"){
                for(int i=0; i<mentionCnt.size(); i++){
                    if(offlineTime[i] == 0 || offlineTime[i]+60 <= timeStamp){
                        mentionCnt[i]++;
                    }
                }
            } else {
                mentionCnt[stoi(id.substr(2))]++;
            }
        }
    }
};