// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    /**
     * @param n an integer
     * @return the number you guess
     */
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left+(right-left)/2;
            int trial = guess(mid);
            
            if (trial == 0) return mid;
            else if (trial == 1) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};
