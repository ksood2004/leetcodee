class RandomizedSet {
public:
vector<int> karan;
unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            return false;
        }
        mp[val]=karan.size();
        karan.push_back(val);
        return true;

    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        int index=mp[val];
        mp[karan.back()] = index;
        mp.erase(val);
        karan[index] = karan.back();
        karan.pop_back();

        return true;
    }
    
    int getRandom() {
        int x=rand()% karan.size();
        return karan[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */