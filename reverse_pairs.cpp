class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        int len = A.size();
        long long result = 0;
        vector<pair<int, int>> nums_indexes;
        
        for (int i = 0; i < len; ++i) {
            nums_indexes.push_back({A[i], i});
        }
        
        MergeSort(nums_indexes, 0, len-1, result);
        return result;
    }
    
private:
    void MergeSort(vector<pair<int, int>>& nums_indexes, int start, int end, long long& result) {
        if (start >= end) return;
        
        int mid = start + (end-start)/2;
        MergeSort(nums_indexes, start, mid, result);
        MergeSort(nums_indexes, mid+1, end, result);
        
        int l = start;
        vector<pair<int, int>> temp;
        for (int i = mid+1; i <= end; ++i) {
            while (l <= mid && nums_indexes[l].first <= nums_indexes[i].first) {
                temp.push_back(nums_indexes[l++]);
            }
            temp.push_back(nums_indexes[i]);
            result += mid-l+1;
        }
        
        while (l <= mid) {
            temp.push_back(nums_indexes[l++]);
        }
        
        copy(temp.begin(), temp.end(), nums_indexes.begin() + start);
    }
};
