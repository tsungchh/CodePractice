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
        unordered_map<DirectedGraphNode*, int> map;
        vector<DirectedGraphNode*> answer;
        for(int i = 0; i < graph.size(); i++)
        {
            DirectedGraphNode* node = graph[i];
            
            for(int j = 0; j < node->neighbors.size(); j++)
            {
                DirectedGraphNode* neighborNode = node->neighbors[j];
                if( map.find(neighborNode) != map.end() )
                {
                    map[neighborNode] = map[neighborNode] + 1;
                }
                else
                {
                    map[neighborNode] = 1;
                }
            }
        }
        
        queue<DirectedGraphNode*> q;
        for(int i = 0; i < graph.size(); i++)
        {
            if( map.find(graph[i]) == map.end() )
            {
                q.push(graph[i]);
                answer.push_back(graph[i]);
            }
        }
        
        while( !q.empty() )
        {
            DirectedGraphNode* node = q.front();
            q.pop();
            for(int i = 0; i < node->neighbors.size(); i++)
            {
                map[node->neighbors[i]] = map[node->neighbors[i]] - 1;
                if(map[node->neighbors[i]] == 0)
                {
                    q.push( node->neighbors[i] );
                    answer.push_back(node->neighbors[i]);
                }
            }
        }
        
        
        
        return answer;
    }
};
