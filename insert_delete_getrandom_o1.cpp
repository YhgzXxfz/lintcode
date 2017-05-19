class RandomizedSet {
public:
    RandomizedSet() {
    }
    
    // Inserts a value to the set
    // Returns true if the set did not already contain the specified element or false
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        
        mp[val] = data.size();
        data.push_back(val);
        return true;
    }
    
    // Removes a value from the set
    // Return true if the set contained the specified element or false
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        
        int index = mp[val], last = data.back();
        mp[last] = index;
        data[index] = last;
        
        mp.erase(mp.find(val));
        data.pop_back();
        return true;
    }
    
    // Get a random element from the set
    int getRandom() {
        return data[rand()% data.size()];
    }

private:
    vector<int> data;
    unordered_map<int, int> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */
