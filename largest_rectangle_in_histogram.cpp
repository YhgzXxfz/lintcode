class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here
        height.push_back(0);
        int len = height.size(), area = 0;
        stack<int> indexes;
        
        for (int i = 0; i < len; i++) {
            while (!indexes.empty() && height[indexes.top()] > height[i]) {
                int h = height[indexes.top()]; 
                indexes.pop();
                int left = indexes.empty() ? -1 : indexes.top();
                area = max(area, h * (i - left - 1));
            }
            indexes.push(i);
        }
        return area; 
    }
};


