/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        if (n == 0 || n == 1) return n;
        
        int mid = (n+1)/2, left = 1, right = n;
        while (left <= right) {
            if (VersionControl::isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = (left + right) /2;
        }
        return left;
    }
};


