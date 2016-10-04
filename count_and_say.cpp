class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        string result = "1";
        for (int i = 0; i < n-1; ++i) {
            result = getNext(result);
        }
        return result;
    }
    
    string getNext(const string& seq) {
        stringstream  next_seq;
        for (int i = 0; i < seq.length(); ++i) {
            int cnt = 1;
            while (i < seq.length() - 1 && seq[i] == seq[i + 1]) {
                ++cnt, ++i;
            }
            next_seq << cnt << seq[i];
        }
        return next_seq.str();
    }
};

