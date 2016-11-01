class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int len = A.size();
        int xorSum = 0;
        
        for (int i = 0; i < len; ++i) {
            xorSum ^= A[i];
        }
        
        int firstIndex = 0;
        for (int i = 31; i >= 0; --i) {
            if ((xorSum>>i) &1) {
                firstIndex = i;
                break;
            }
        }
        
        int num1 = 0 , num2 = 0;
        vector<int> result;
        for (int i = 0; i < len; ++i) {
            if ((A[i] >> firstIndex) &1) {
                num1 ^= A[i];
            } else {
                num2 ^= A[i];
            }
        }
        result.push_back(num1);
        result.push_back(num2);
        
        return result;
    }
};

