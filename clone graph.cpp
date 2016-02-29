/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if( node == NULL )
            return NULL;
        
        unordered_map< UndirectedGraphNode*, UndirectedGraphNode* > map;
        
        queue< UndirectedGraphNode* > q;
        q.push(node);
        
        //BFS search
        while( !q.empty() )
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                UndirectedGraphNode* curr = q.front();
                q.pop();
                if(map.find(curr) == map.end() )
                {
                    UndirectedGraphNode* newCurr = new UndirectedGraphNode(curr->label);
                    map[curr] = newCurr;
                    
                    for(int j = 0; j < curr->neighbors.size(); j++)
                    {
                        q.push(curr->neighbors[j]);
                    }
                }
            }
        }
        
        
        unordered_map< UndirectedGraphNode*, UndirectedGraphNode* >::iterator it = map.begin();
        for( ; it != map.end(); it++ )
        {
            vector<UndirectedGraphNode *> neighbors = it->first->neighbors;
            
            for( int i = 0; i < neighbors.size(); i++ )
            {
                it->second->neighbors.push_back( map[neighbors[i]] );
            }
        }
        
        return map[node];
    }
};