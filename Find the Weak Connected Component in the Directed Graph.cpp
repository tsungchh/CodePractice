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
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
      
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        
        vector<int> unionAry(nodes.size());
        unordered_map<DirectedGraphNode*, int> map;
        for(int i = 0; i < unionAry.size(); i++)
        {
            unionAry[i] = i;
            map[nodes[i]] = i;
        }
        
        for(int i = 0; i < nodes.size(); i++)
        {
            DirectedGraphNode* node = nodes[i];
            int parentBoss = findAncestor(unionAry, map[node]);
            for(int j = 0; j < node->neighbors.size(); j++)
            {
                DirectedGraphNode* childNode = node->neighbors[j];
                
                int childBoss = findAncestor(unionAry, map[childNode]);
                if( childBoss != parentBoss )
                {
                     unionAry[childBoss] = parentBoss;
                }
            }
        }
        
        unordered_map<int, vector<int>> ansMap;
        for(int i = 0; i < unionAry.size(); i++)
        {
            int bossI = findAncestor(unionAry, i); 
            if(ansMap.find(bossI) == ansMap.end())
            {
                vector<int> tmp(1, nodes[i]->label);
                ansMap[bossI] = tmp;
            }
            else
            {
                vector<int> tmp = ansMap[bossI];
                tmp.push_back(nodes[i]->label);
                ansMap[bossI] = tmp;
            }
        }
        
        vector<vector<int>> ans;
        unordered_map<int, vector<int>>::iterator it = ansMap.begin();
        for(; it != ansMap.end(); it++)
        {
            ans.push_back(it->second);
        }
        
        return ans;
        
    }
    
    int findAncestor(vector<int>& ary, int idx)
    {
        if(ary[idx] != idx)
            return findAncestor(ary, ary[idx]);
        
        return idx;
    }
};
