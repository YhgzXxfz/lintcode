class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int left = 0, right = heights.size()-1;
        int max_left = 0, max_right = 0;
        int result = 0;
        
        while (left <= right) {
            if (heights[left] <= heights[right]) {
                if (heights[left] >= max_left) max_left = heights[left];
                else result += max_left-heights[left];
                ++left;
            } else {
                if (heights[right] >= max_right) max_right = heights[right];
                else result += max_right-heights[right];
                --right;
            }
        }
        return result;
    }
};

