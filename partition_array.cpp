class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        // 1
        //sort(nums.begin(), nums.end());
        //for (int i = 0; i < nums.size(); ++i)
        //{
        //    if (nums[i] >= k) return i;
        //}
        //return nums.size();
        
        // 2
        int len = nums.size();
        
        int left = 0, right = len-1;
        while (left < right) {
            while (nums[left] < k && left < len) ++left;
            while (nums[right] >= k && right >= 0) --right;
            
            if (left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }
        
        for (int i = 0; i < len; ++i) {
            if (nums[i] >= k) return i;
        }
        return len;
    }
};

