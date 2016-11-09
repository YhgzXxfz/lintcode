/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode*> map;
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        // 1 DFS
        /*
        if (!node) return node;
        
        if (map.find(node) == map.end()) {
            map[node] = new UndirectedGraphNode(node->label);
            for (auto neighbor : node->neighbors) {
                (map[node]->neighbors).push_back(cloneGraph(neighbor));
            }
        }
        return map[node];
        */
        
        // 2 BFS
        if (!node) return node;
        map[node] = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto neighbor : curr->neighbors) {
                if (map.find(neighbor) == map.end()) {
                    map[neighbor] = new UndirectedGraphNode(neighbor->label);
                    q.push(neighbor);
                }
                (map[curr]->neighbors).push_back(map[neighbor]);
            }
        }
        return map[node];
    }
};
