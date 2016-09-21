class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        int unhappy[] = {4, 16, 37, 58, 89, 145, 42, 20};
        while (true)
        {
            n = sumDigits(n);
            if (n == 1) return true;
            for (int i = 0; i < 8; ++i)
            {
                if (n == unhappy[i]) return false;
            }
        }
    }
    
    int sumDigits(int n)
    {
        int result = 0;
        while (n > 0)
        {
            result += (n%10) * (n%10);
            n /= 10;
        }
        return result;
    }
};
