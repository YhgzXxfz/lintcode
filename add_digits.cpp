class Solution {
public:
    /**
     * @param num a non-negative integer
     * @return one digit
     */
    int addDigits(int num) {
        if (num <= 9) return num;
        
        int sum = 0;
        while (num) {
            sum += num%10;
            num /= 10;
        }
        return addDigits(sum);
    }
};
