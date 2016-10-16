class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int len = A.size();
        
        for (int i = 0; i < len; ++i) {
            if (target == A[i]) return true;
        }
        return false;
    }
};

