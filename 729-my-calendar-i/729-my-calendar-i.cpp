class MyCalendar {
public:
    map<int,int> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it=m.upper_bound(start);
        if(it!=m.end() and it->second<end)return false;
        m[end]=start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */