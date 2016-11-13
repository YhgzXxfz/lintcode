class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        /*
        if (edges.size() != n-1) return false;
        if (n == 1) return true;
        
        unordered_map<int, node> nodes;
        for (auto edge : edges) {
            nodes[edge.front()].neighbours.push_back(edge.back());
            nodes[edge.back()].neighbours.push_back(edge.front());
        }
        
        if (nodes.size() != n) return false;
        
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            visited.emplace(i);
            for (auto node : nodes[i].neighbours) {
                if (node != nodes[i].parent) {
                    if (visited.find(node) != visited.end()) return false;
                    else {
                        q.push(node);
                        visited.emplace(node);
                        nodes[node].parent = i;
                    }
                }
            }
        }
        
        return visited.size() == n;
        */
        vector<vector<int>> matrix(n);
        for (auto edge : edges)
        {
            matrix[edge.front()].push_back(edge.back());
            matrix[edge.back()].push_back(edge.front());
        }
        
        int path[n];
        fill(path, path + n, 0);
        path[0] = 1;
        if (hasCycle(matrix, n, 0, -1, path)) return false; // has cycle
        if (accumulate(path, path + n, 0) < n) return false; // not fully connected
        return true;
    }
    
private:
    bool hasCycle(vector<vector<int>>& matrix, int n, int src, int pre, int path[]) {
        for (auto i : matrix[src]) {
            if (i != pre) {
                if (path[i]) return true;
                path[i] = 1;
                if (hasCycle(matrix, n, i, src, path)) return true;
            }
        }
        return false;
    }
/*
    struct node {
        int parent = -1;
        vector<int> neighbours;
    };
*/
};
