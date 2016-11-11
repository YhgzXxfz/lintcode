class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int len = num.size();
        if (len == 0) return 0;
        
        int left = 0, right = len-1;
        while (left <= right) {
            int mid = (left+right) /2;
            if (num[mid] >= num[right]) left = mid+1;
            else right = mid;
        }
        return num[right];
    }
};

