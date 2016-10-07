class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int resultInt = a ^ b;
        return NumberOfOnes(resultInt);
    }
    
    int NumberOfOnes(int num)
    {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if ((num >> i) &1) ++count;
        }
        return count;
    }
};

