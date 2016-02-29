/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        // union set
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        // initialize
        for(int i = 0; i < nodes.size(); i++)
        {
            map[nodes[i]] = nodes[i];
        }
        
        for(int i = 0; i < nodes.size(); i++)
        {
            vector<UndirectedGraphNode*> neighbors = nodes[i]->neighbors;
            for(int j = 0; j < neighbors.size(); j++)
            {
                unite(nodes[i], neighbors[j], map);
            }
        }
        
        unordered_map<UndirectedGraphNode*, vector<int>> ret;
        
        for(int i = 0; i < nodes.size(); i++)
        {
            UndirectedGraphNode* node = find(nodes[i], map);
            vector<int> ary;
            if(ret.find(node) != ret.end())
            {
                ary = ret[node];
            }
            ary.push_back(nodes[i]->label);
            ret[node] = ary;
        }
        
        vector< vector<int> > retAry;
        unordered_map<UndirectedGraphNode*, vector<int>>::iterator it = ret.begin();
        for(; it != ret.end(); it++)
        {
            retAry.push_back(it->second);
        }
        
        return retAry;
        
    }
    
    // make nodeB follow nodeA's boss
    void unite(UndirectedGraphNode* nodeA, UndirectedGraphNode* nodeB,
               unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& map)
    {
        map[find(nodeB, map)] = find(nodeA, map);
    }
    
    UndirectedGraphNode* find(UndirectedGraphNode* node, 
                             unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& map)
    {
        if(map[node] == node)
        {
            return node;
        }  
        
        return find(map[node], map);
    }
};


