class Solution {
public:
    /**
     * @param s a string
     * @param p a non-empty string
     * @return a list of index
     */
    vector<int> findAnagrams(string& s, string& p) {
        if (s.size() < p.size()) return vector<int>();
        
        vector<int> pv(26), sv(26);
        int len_p = p.size();
        for (int i = 0; i < len_p; ++i) {
            pv[p[i]-'a']++;
            sv[s[i]-'a']++;
        }
        
        vector<int> result;
        if (pv == sv) result.push_back(0);
        
        for (int i = len_p; i < s.size(); ++i) {
            sv[s[i]-'a']++;
            sv[s[i-len_p]-'a']--;
            
            if (pv == sv) result.push_back(i+1-len_p);
        }
        return result;
    }
};



// time out
class Solution {
public:
    /**
     * @param s a string
     * @param p a non-empty string
     * @return a list of index
     */
    vector<int> findAnagrams(string& s, string& p) {
        vector<int> result;
        int len_s = s.size(), len_p = p.size();
        for (int i = 0; i <= len_s-len_p; ++i) {
            if (isAnagram(s.substr(i, len_p), p)) result.push_back(i);
        }
        return result;
    }

private:
    bool isAnagram(string s, string t) {
        int letters[26] = {};
        for (int i = 0; i < s.size(); ++i) {
            letters[s[i]-'a']++;
            letters[t[i]-'a']--;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (letters[i]) return false;
        }
        return true;
    }
};
