class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        vector<int> count(numberOfUsers);
        vector<int> next_online_time(numberOfUsers);
        sort(events.begin(), events.end(),
             [&](const vector<string>& lth, const vector<string>& rth) {
                 int lth_timestamp = stoi(lth[1]);
                 int rth_timestamp = stoi(rth[1]);
                 if (lth_timestamp != rth_timestamp) {
                     return lth_timestamp < rth_timestamp;
                 }
                 if (rth[0] == "OFFLINE") {
                     return false;
                 }
                 return true;
             });

        for (auto&& event : events) {
            int cur_time = stoi(event[1]);
            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        count[i]++;
                    }
                } else if (event[2] == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (next_online_time[i] <= cur_time) {
                            count[i]++;
                        }
                    }
                } else {
                    int idx = 0;
                    for (int i = 0; i < event[2].size(); i++) {
                        if (isdigit(event[2][i])) {
                            idx = idx * 10 + (event[2][i] - '0');
                        }
                        if (i + 1 == event[2].size() ||
                            event[2][i + 1] == ' ') {
                            count[idx]++;
                            idx = 0;
                        }
                    }
                }
            } else {
                int idx = stoi(event[2]);
                next_online_time[idx] = cur_time + 60;
            }
        }
        return count;
    }
};