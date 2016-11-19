class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    int maximalRectangle(vector<vector<bool> > &matrix) {
        // Write your code here
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> height(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == false) height[i][j] = 0;
                else height[i][j] = (i == 0) ? 1 : height[i-1][j]+1;
            }
        }
        
        int area = INT_MIN;
        for (int i = 0; i < m; ++i) {
            area = max(area, largestArea(height[i]));
        }
        return area;
    }
    
    int largestArea(vector<int>& container) {
        vector<int> s;
        container.push_back(0);
        
        int sum = 0, i = 0;
        while (i < container.size()) {
            if (s.empty() || container[s.back()] < container[i]) {
                s.push_back(i++);
            } else {
                int t = s.back();
                s.pop_back();
                sum = max(sum, container[t] * (s.empty() ? i : i-1 - s.back()));
            }
        }
        return sum;
    }
};
