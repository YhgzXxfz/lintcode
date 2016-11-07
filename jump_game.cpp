class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        int len = A.size();
        int reach = 1;
        for (int i = 0; i < reach && reach < len; ++i) {
            reach = max(reach, A[i]+i+1);
        }
        return reach >= len;
    }
};


