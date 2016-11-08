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
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> result;
        
        unordered_set<DirectedGraphNode*> nodes;
        unordered_map<DirectedGraphNode*, int> ancestors;
        
        for (const auto& node : graph) {
            findDependencyBFS(node, nodes, ancestors);
        }
        
        topoSortBFS(result, ancestors, graph);
        return result;
    }
    
    void findDependencyBFS(DirectedGraphNode* node, 
        unordered_set<DirectedGraphNode*>& nodes,
        unordered_map<DirectedGraphNode*, int>& ancestors) {
        if (nodes.emplace(node).second) {
            queue<DirectedGraphNode*> q;
            q.emplace(node);
            
            while (!q.empty()) {
                auto n = q.front();
                q.pop();
                
                for (const auto& neighbor : n->neighbors) {
                    ++ancestors[neighbor];
                    if (nodes.emplace(neighbor).second) q.emplace(neighbor);
                }
            }
        }
    }
    
    void topoSortBFS(vector<DirectedGraphNode*>& result,
        unordered_map<DirectedGraphNode*, int>& ancestors,
        vector<DirectedGraphNode*> & graph) {
        queue<DirectedGraphNode*> q;
        for (auto& node : graph) {
            if (ancestors[node] == 0) q.emplace(node);
        }
        
        while (!q.empty()) {
            auto n = q.front();
            q.pop();
            result.emplace_back(n);
            
            for (const auto & neighbor : n->neighbors) {
                --ancestors[neighbor];
                if (ancestors[neighbor] == 0) q.emplace(neighbor);
            }
        }
    }
};
