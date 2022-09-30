class SeatManager {
    vector<int> v;
    set<int> s;
public:
    SeatManager(int n) {
        v.resize(n+1,0);
        for(int i = 1 ; i <= n ; i++){
            s.insert(i);
        }
    }
    
    int reserve() {
        int x = *(s.begin());
        v[x] = 1;
        s.erase(x);
        return x;
    }
    
    void unreserve(int seatNumber) {
        int x = seatNumber;
        v[x] = 0;
        s.insert(x);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */