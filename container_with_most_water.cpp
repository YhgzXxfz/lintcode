class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int len = heights.size();
        int left = 0, right = len-1, next;
        
        int max_volume = 0;
        while (left < right)
        {
            int volume = min(heights[left], heights[right]) * (right-left);
            if (volume > max_volume) max_volume = volume;
            
            if (heights[left] > heights[right]) {
                next = right-1;
                while (next > left && heights[next] < heights[right]) --next;
                right = next;
            } else {
                next = left+1;
                while (next < right && heights[next] < heights[left]) ++next;
                left = next;
            }
        }
        
        return max_volume;
    }
};

