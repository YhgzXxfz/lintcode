class Solution {
public:
    /**
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (const auto& pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        
        vector<int> indegrees(numCourses);
        for (const auto& node : graph) {
            for (const auto& neighbor : node) {
                indegrees[neighbor]++;
            }
        }
        
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; ++j) {
                if (indegrees[j] == 0) break;
            }
            if (j == numCourses) return false;
            
            indegrees[j] = -1;
            for (auto& neighbor : graph[j]) {
                indegrees[neighbor]--;
            }
        }
        return true;
    }
};
