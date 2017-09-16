class Solution {
public:
    /**
     * @param num a positive number
     * @return true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        if (num < 0) return false;
        
        int rev = reverse(num);
        return rev == num;
    }

private:
    long long reverse(int num) {
        long long result = 0;
        while (num) {
            int digit = num%10;
            num /= 10;
            result = result*10 + digit;
            
            if (result > INT_MAX || result < INT_MIN) return 0;
        }
        return result;
    }
};
