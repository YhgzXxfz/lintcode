#include <list>
class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity) : _capacity(capacity) {}
    
    // @return an integer
    int get(int key) {
        // write your code here
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        hit(it);
        return it->second.first;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        auto it = cache.find(key);
        if (it != cache.end()) hit(it);
        else {
            if (cache.size() == _capacity) {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }
    
private:
    int _capacity;
    
    list<int> used;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    
    void hit(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
};
