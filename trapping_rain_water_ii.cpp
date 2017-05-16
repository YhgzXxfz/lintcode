class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        if (heights.empty()) return 0;
        
        int m = heights.size(), n = heights[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    pq.push(make_pair(heights[i][j], i*n+j));
                    visited[i][j] = true;
                }
            }
        }
        
        int result = 0, max_height = INT_MIN;
        vector<vector<int>> directions{{0,1}, {1,0}, {0,-1}, {-1,0}};
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int i = curr.second/n, j = curr.second%n;
            max_height = max(max_height, curr.first);
            for (const auto& d : directions) {
                int x = i+d[0], y = j+d[1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                
                int h = heights[x][y];
                if (max_height > h) result += max_height-h;
                pq.push(make_pair(h, x*n+y));
                visited[x][y] = true;
            }
        }
        return result;
    }
};
