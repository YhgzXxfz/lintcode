class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        // 1
        // sort(A.begin(), A.end());
        
        // 2
        for (int i = 0; i < A.size(); ++i) {
            heapify(A, i);
        }
    }
    
    void heapify(vector<int> & A, int index) {
        while ((index-1)/2 >= 0) {
            int parent = (index-1) /2;
            if (A[parent] > A[index]) {
                swap(A[parent], A[index]);
                index = parent;
            }
            else break;
        }
    }
};

