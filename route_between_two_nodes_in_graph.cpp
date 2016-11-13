/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        unordered_set<DirectedGraphNode*> visited;
        visited.emplace(s);
        //return bfs(visited, s, t);
        return dfs(visited, s, t);
    }
    
    bool bfs(unordered_set<DirectedGraphNode*> visited, 
        DirectedGraphNode* s, DirectedGraphNode* t) {
        queue<DirectedGraphNode*> q;
        q.emplace(s);
        
        while (!q.empty()) {
            s = q.front();
            q.pop();
            
            if (s == t) return true;
            
            for (const auto& node : s->neighbors) {
                if (visited.emplace(node).second) q.emplace(node);
            }
        }
        return false;
    }
    
    bool dfs(unordered_set<DirectedGraphNode*> visited,
        DirectedGraphNode* s, DirectedGraphNode* t) {
        if (s == t) return true;
        
        for (const auto& node : s->neighbors) {
            if (visited.emplace(node).second) {
                if (dfs(visited, node, t)) return true;
            }
        }
        return false;
    }
};


