class RecentCounter {
  private:

vector<int> s;
int hi;
public:
    RecentCounter() {
        hi=0;
    }
    int ping(int t) {
        s.push_back(t);
        while(s[hi]<t-3000){
            hi++;
        }
        return s.size()-hi;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */