class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int length = array.size();
        
        if (0 == length) return -1;
        if (1 == length && array[0] == target) return -1;
        
        int left = 0, right = length -1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) /2;
            if (array[mid] == target) {
                for (int i = mid-1; i >= left; --i) {
                    if (array[i] < target) return i+1;
                }
                return mid;
            } else if (array[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

