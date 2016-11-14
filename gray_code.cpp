class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> result;
        for (int i = 0; i < 1<<n; ++i) {
            result.push_back(i>>1 ^ i);
        }
        return result;
    }
};

