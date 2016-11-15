class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        // 1
        /*
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        
        for (int i = nums.size()-1, j = 0, k = i/2+1; i >= 0; --i) {
            if (i&1) {
                nums[i] = sorted[k];
                ++k;
            } else {
                nums[i] = sorted[j];
                ++j;
            }
        }
        */
        
        // 2
        int len = nums.size();
        auto midptr = nums.begin()+len/2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        #define A(i) nums[(1+2*i)%(len|1)]
        
        int i = 0, j = 0, k = len-1;
        while (j <= k) {
            if (A(j) > mid) swap(A(j++), A(i++));
            else if (A(j) < mid) swap(A(j), A(k--));
            else ++j;
        }
    }
};
