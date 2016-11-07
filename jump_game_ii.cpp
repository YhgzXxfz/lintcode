class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int curr = 0, last = 0, count = 0;
        
        int len = A.size();
        for (int i = 0; i < len; ++i) {
            if (i > last) {
                last = curr;
                ++count;
            }
            curr = max(curr, A[i]+i);
        }
        return count;
    }
};

