class Solution {
private:
    bool checkCut(vector<vector<int>>& interval) {
        sort(interval.begin(), interval.end());
        int gap = 0, max_end = interval[0][1];
        for (auto i : interval) {
            int st = i[0], end = i[1];
            if (max_end <= st)
                gap++;
            max_end = max(max_end, end);
        }
        return gap >= 2;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_interval, y_interval;
        for (auto rect : rectangles) {
            int stx = rect[0], sty = rect[1];
            int endx = rect[2], endy = rect[3];
            x_interval.push_back({stx, endx});
            y_interval.push_back({sty, endy});
            //             // we want to check that contion make either two
            //             horizontal or two vertical cuts on the grid  and evry
            //             come by each section but how shoudl we do this let me
            //             think  (startx, starty): The bottom-left corner of
            //             the rectangle.
            // (endx, endy): The top-right corner of the rectangle. we know
            // horizontal conatin  (startx, starty and we want to check that
            // they are not overlap ok  , means merge intervals like we solve
            // this
        }
        return checkCut(x_interval) || checkCut(y_interval);
    }
};