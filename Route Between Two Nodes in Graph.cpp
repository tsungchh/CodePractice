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
        
        //BFS search from s node
        
        queue<DirectedGraphNode*> q;
        q.push(s);
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                DirectedGraphNode* node = q.front();
                q.pop();
                if(node == t)
                    return true;
                
                for(int j =0; j < node->neighbors.size(); j++)
                    q.push(node->neighbors[j]);
            }
        }
        
        return false;
    }
};


