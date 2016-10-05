class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
        // 1
        //int result = 0;
        
        //for (int i = 0; i < 32; ++i)
        //{
        //    result += (num >> i) &1;
        //}
        //return result;
        
        // 2
        int count = 0;
        while (num != 0) {
            num = num & (num -1);
            ++count;
        }
        return count;
    }
};

