class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        int len = nums.size();
        vector<int> result;
        deque<int> q;
        
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
        }
        
        for (int i = k; i < len; ++i) {
            result.push_back(nums[q.front()]);
            
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            while (!q.empty() && q.front() <= i-k) q.pop_front();
            
            q.push_back(i);
        }
        
        if (!q.empty()) result.push_back(nums[q.front()]);
        
        return result;
    }
};


