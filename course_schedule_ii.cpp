class Solution {
public:
    /**
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (const auto& pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        
        vector<int> indegrees(numCourses);
        for (const auto& node : graph) {
            for (const auto& neighbor : node) {
                ++indegrees[neighbor];
            }
        }
    
        
        queue<int> zero_degrees;
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) zero_degrees.push(i);
        }
        
        vector<int> result;
        for (int i = 0; i < numCourses; ++i) {
            if (zero_degrees.empty()) return {};
            
            auto curr = zero_degrees.front();
            zero_degrees.pop();
            result.push_back(curr);
            for (auto neighbor : graph[curr]) {
                --indegrees[neighbor];
                if (indegrees[neighbor] == 0) zero_degrees.push(neighbor);
            }
        }
        return result;
    }
};
