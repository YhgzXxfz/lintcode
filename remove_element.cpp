class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int len = A.size();
        if (len <= 0) return len;
        
        int count_del = 0;
        for (int i = 0; i < len; ++i) {
            if (A[i-count_del] == elem) {
                A.erase(A.begin() + i-count_del);
                count_del++;
            }
        }
        return A.size();
    }
};

