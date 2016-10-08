class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if (len <= 1) return;
        
        int pos = -1;
        for (int i = 0; i < len-1; ++i) {
            if (nums[i] > nums[i+1]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) return;
        
        Reverse(nums, 0, pos);
        Reverse(nums, pos+1, len-1);
        Reverse(nums, 0, len-1);
    }
    
    void Reverse(vector<int> &nums, int start, int end) {
        if (end < start) return;
        
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            ++start;
            --end;
        }
    }
};

