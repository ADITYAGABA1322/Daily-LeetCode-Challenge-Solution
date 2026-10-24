class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int prefix[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
        auto toDay = [&](const string & s) -> int {
            int month = stoi(s.substr(0,2));
            int day = stoi(s.substr(3));
            return prefix[month-1]+day;
        };
        int start = max(toDay(arriveAlice), toDay(arriveBob));
        int end   = min(toDay(leaveAlice),  toDay(leaveBob));
        return max(0 , end-start+1);
    }
};