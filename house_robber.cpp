class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        int len = A.size();
        if (len <= 0) return 0;
        
        long long prev = 0, curr = 0;
        for (int i = 0; i < len; ++i) {
            long long temp = max(curr, prev+A[i]);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};

