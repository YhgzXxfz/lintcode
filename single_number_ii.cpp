class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int len = A.size();
        
        int count = 0;
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            count = 0;
            for (int j = 0; j < len; ++j)
            {
                int digit = (A[j] >> i) &1;
                if (digit) ++count;
            }
            result |= (count%3 << i);
        }
        return result;
    }
};

