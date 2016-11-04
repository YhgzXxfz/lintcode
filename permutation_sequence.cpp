class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        string s(n, '0');
        for (int i = 0; i < n; ++i) {
            s[i] += i+1;
        }
        
        for (int i = 0; i < k-1; ++i) {
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
};

