class MyCalendar {
public:
    set<pair<int , int>> st;
    bool book(int start, int end) {
        auto slot = st.lower_bound({start , end});
        if(slot != st.end() && !(slot->first >= end) || slot != st.begin() && !(prev(slot)->second <= start)) return false;
        st.insert({start , end});
        return true; 
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */