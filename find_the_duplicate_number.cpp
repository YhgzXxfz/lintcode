class Solution {
public:
    /**
     * @param nums an array containing n + 1 integers which is between 1 and n
     * @return the duplicate one
     */
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1) {
            int slow = nums[0], fast = nums[0];
            while (true) {
                slow = nums[slow];
                fast = nums[nums[fast]];
                
                if (slow == fast) break;
            }
            
            fast = nums[0];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }
            return fast;
        }
        return -1;
    }
};
