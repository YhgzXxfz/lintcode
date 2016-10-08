class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here        
        if (m == 0) {
            for (int i = 0 ; i < n; ++i) {
                A[i] = B[i];
            }
            return;
        }
        
        int tailA = m-1, tailB = n-1;
        int tailMerged = m+n-1;
        
        while (tailA >= 0 && tailB >= 0) {
            if (A[tailA] > B[tailB]) {
                A[tailMerged] = A[tailA];
                --tailA;
            } else {
                A[tailMerged] = B[tailB];
                --tailB;
            }
            --tailMerged;
        }
        
        while (tailB >= 0) {
            A[tailMerged] = B[tailB];
            tailMerged--;tailB--;
        }
    }
};

