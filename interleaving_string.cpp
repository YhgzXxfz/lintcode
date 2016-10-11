class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if (s1.size() + s2.size() != s3.size()) return false;
        
        if (s1.size() > s2.size()) return isInterleave(s2, s1, s3);
        
        vector<deque<bool>> T(2, deque<bool>(s2.size()+1));
        T[0][0] = true;
        
        for (int j = 0 ; j < s2.size(); ++j) {
            if (s2[j] == s3[j]) T[0][j+1] = true;
            else break;
        }
        
        for (int i = 0; i < s1.size(); ++i) {
            T[(i+1)%2][0] = T[i%2][0] && s1[i] == s3[i];
            
            for (size_t j = 0; j < s2.size(); ++j) {
                T[(i + 1) % 2][j + 1] = (T[i % 2][j + 1] && s1[i] == s3[i + j + 1]) ||
                (T[(i + 1) % 2][j] && s2[j] == s3[i + j + 1]);
            }
        }
        
        return T[s1.size()%2][s2.size()];
    }
};

