class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        vector<vector<string> > paths;
        vector<string> path(1, start);
        if (start == end) {
            paths.push_back(path);
            return paths;
        }
        
        unordered_set<string> words1, words2;
        words1.insert(start);
        words2.insert(end);
        
        unordered_map<string, vector<string> > nexts;
        bool words1_is_begin = false;
        
        if (findLaddersHelper(words1, words2, dict, nexts, words1_is_begin)) 
            getPath(start, end, nexts, path, paths);
        return paths;
    }
    
private:
    bool findLaddersHelper(
        unordered_set<string>& words1,
        unordered_set<string>& words2,
        unordered_set<string>& dict,
        unordered_map<string, vector<string> >& nexts,
        bool& words1_is_begin) {
        words1_is_begin = !words1_is_begin;
        if (words1.empty()) return false;
        if (words1.size() > words2.size())
            return findLaddersHelper(words2, words1, dict, nexts, words1_is_begin);
        for (auto it = words1.begin(); it != words1.end(); ++it)
            dict.erase(*it);
        for (auto it = words2.begin(); it != words2.end(); ++it)
            dict.erase(*it);
        
        unordered_set<string> words3;
        bool reach = false;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
            string word = *it;
            for (auto ch = word.begin(); ch != word.end(); ++ch) {
                char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch))
                    if (*ch != tmp)
                        if (words2.find(word) != words2.end()) {
                            reach = true;
                            words1_is_begin ? nexts[*it].push_back(word) : 
                                nexts[word].push_back(*it);
                        } else if (!reach && dict.find(word) != dict.end()) {
                            words3.insert(word);
                            words1_is_begin ? nexts[*it].push_back(word) : 
                                nexts[word].push_back(*it);
                        }
                *ch = tmp;
            }
        }
        return reach || findLaddersHelper(words2, words3, dict, nexts, words1_is_begin);
    }
    
    void getPath(string begin, string& end, unordered_map<string, vector<string> >& nexts, vector<string>& path, vector<vector<string> >& paths) {
        if (begin == end) paths.push_back(path);
        else {
            for (auto next : nexts[begin]) {
                path.push_back(next);
                getPath(next, end, nexts, path, paths);
                path.pop_back();
            }
        }
    }
};

