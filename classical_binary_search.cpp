class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        if (A.empty()) return -1;
        
        int left = 0, right = A.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (A[mid] == target) return mid;
            else if (A[mid] < target) left = mid+1;
            else right = mid;
        }
        return A[left] == target ? left : -1;
    }
};
