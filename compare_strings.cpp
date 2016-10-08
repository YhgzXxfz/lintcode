class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int lenB = B.size();
        int lenA = A.size();
        if (lenA < lenB) return false;
        
        for (int i = 0; i < lenB; ++i) {
            size_t found = A.find(B[i]);
            if (found == string::npos) return false;
            else if (A.size() > 1) {
                if (found == lenB-1) A = A.substr(0, found);
                else if (found == 0) A = A.substr(1);
                else A = A.substr(0, found)+A.substr(found+1);
            }
            else if (A.size() == 1) A = A.substr(0,0);
        }
        return true;
    }
};


