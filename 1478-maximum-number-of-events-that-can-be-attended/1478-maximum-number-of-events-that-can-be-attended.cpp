class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // return events.size();
        // Hi, when I read the problem statement, what I think I go to start and end this problem is similar like if I say internal internal sorry interval problem it depends on the interval types. There is a start and the end we easily sold the events after sorting that we get the two pointer start in the end, according to that we can attend only the attend one event at any time, which means we go through the area and check from the start to the end of any events zero and one value event zero and one value from that and check there is not the same number. Is there any difference between them and return that only a bunch and count plus plus I think that kind of thing is worki that is my approach check it 
        sort(events.begin() , events.end());
        priority_queue<int , vector<int> , greater<int>> pq;
        int n = events.size() , res = 0  , lastDay = 0 , i = 0;
        for(auto e : events) lastDay = max(lastDay , e[1]);
        for(int day = 1; day<=lastDay; day++){
            while(i<n && events[i][0] == day){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top() < day) pq.pop();
            if(!pq.empty()){
                pq.pop();
                res++;
            }
        }
        return res;
    }
};