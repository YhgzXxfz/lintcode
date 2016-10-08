class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        // 1
        //int len = A.size();
        
        //for (int i = 0; i < len; ++i)
        //{
        //    if (A[i] >= target) return i;
        //}
        //return len;
        
        // 2
        int len = A.size();
        
        int left = 0, right = len-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int mid_number = A[mid];
            if (target == mid_number) return mid;
            
            if (target > mid_number) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};

