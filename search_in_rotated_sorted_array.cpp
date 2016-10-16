class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int len = A.size();
        
        int left = 0, right = len-1;
        while (left < right) {
            int mid = (left+right) /2;
            if (A[mid] > A[right]) left = mid+1;
            else right = mid;
        }
        int offset = left;
        
        left = 0; right = len-1;
        while (left <= right) {
            int mid = (left+right) /2;
            int readMid = (mid+offset) %len;
            int midNumber = A[readMid];
            
            if (target == midNumber) return readMid;
            if (target > midNumber) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
};

