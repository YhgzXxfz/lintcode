class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        if (A.size() != B.size()) return false;
        
        char letters[256] = {};
        for (int i = 0; i < A.size(); ++i) {
            letters[A[i]]++;
            letters[B[i]]--;
        }
        
        for (int i = 0; i < 256; ++i) {
            if (letters[i]) return false;
        }
        return true;
    }
};
