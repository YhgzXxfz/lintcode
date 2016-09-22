class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        int len = A.size();
        if (len <= 1) return;
        QuickSort(A, 0, len-1);
    }
    
private:
    void QuickSort(vector<int> & A, int start, int end) {
        if (start >= end) return;
        int index = Partition(A, start, end);
        QuickSort(A, start, index-1);
        QuickSort(A, index+1, end);
    }
    
    int Partition(vector<int> & A, int start, int end) {
        int pivot = A[end];
        for (int i = start; i < end; ++i) {
            if (A[i] <= pivot) {
                swap(A[start], A[i]);
                start++;
            }
        }
        swap(A[start], A[end]);
        return start;
    }
};
