class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        string result;
        if (source.empty() || target.empty()) return result;
        
        unordered_map<char, int> tmap;
        unordered_map<char, int> window;
        for (int i = 0; i < target.size(); ++i) {
            tmap[target[i]]++;
        }
        
        int minLength = INT_MAX;
        int letterCount = 0;
        
        for (int slow = 0, fast = 0; fast < source.size(); ++fast) {
            char c = source[fast];
            if (tmap.count(c)) {
                window[c]++;
                if (window[c] <= tmap[c]) letterCount++;
            }
            
            if (letterCount >= target.size()) {
                while (!tmap.count(source[slow]) 
                    || window[source[slow]] > tmap[source[slow]]) {
                    window[source[slow]]--;
                    slow++;
                }
                if (fast-slow+1 < minLength) {
                    minLength = fast-slow+1;
                    result = source.substr(slow, minLength);
                }
                
                window[source[slow]]--;
                slow++;
                letterCount--;
            }
        }
        return result;
    }
};


