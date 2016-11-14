class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        int lenA = A.size();
        int lenB = B.size();
        
        int min_diff = INT_MAX;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int pA = 0, pB = 0;
        while (pA < lenA && pB < lenB) {
            int temp = abs(A[pA] - B[pB]);
            if (temp < min_diff) min_diff = temp;
            
            if (min_diff == 0) break;
            if (A[pA] < B[pB]) pA++;
            else pB++;
        }
        
        return min_diff;
    }
};


