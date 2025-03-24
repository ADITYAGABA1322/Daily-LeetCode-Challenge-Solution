class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort meetings by start date
        sort(meetings.begin(), meetings.end());
        
        // Merge overlapping meetings
        vector<vector<int>> mergedMeetings;
        
        for (auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            
            // If mergedMeetings is empty or current meeting starts after the last merged meeting ends
            if (mergedMeetings.empty() || start > mergedMeetings.back()[1]) {
                mergedMeetings.push_back({start, end});
            } 
            // If there's an overlap, extend the end time of the last merged meeting if needed
            else {
                mergedMeetings.back()[1] = max(mergedMeetings.back()[1], end);
            }
        }
        
        // Calculate total days covered by meetings
        int meetingDays = 0;
        for (auto& meeting : mergedMeetings) {
            // +1 because both start and end days are inclusive
            meetingDays += (meeting[1] - meeting[0] + 1);
        }
        
        // Return days without meetings
        return days - meetingDays;
    }
};