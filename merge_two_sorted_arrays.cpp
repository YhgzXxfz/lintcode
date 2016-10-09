class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int lenA = A.size();
        int lenB = B.size();
        
        int pA = 0, pB = 0;
        vector<int> result(lenA+lenB, 0);
        while (pA < lenA && pB < lenB) {
            if (A[pA] <= B[pB]) {
                result[pA+pB] = A[pA];
                pA++;
            } else {
                result[pA+pB] = B[pB];
                pB++;
            }
        }
        
        while (pA < lenA) {
            result[lenB+pA] = A[pA];
            pA++;
        }
        
        while (pB < lenB) {
            result[lenA+pB] = B[pB];
            pB++;
        }
        
        return result;
    }
};

