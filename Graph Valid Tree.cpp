class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */

     //DFS can achive O(n) time complexity
     // also union find ???

    struct Node
    {
        vector<Node*> neighbors;
        bool isVisited;
        int val;
        
        Node(int _val, bool _isVisted = false) 
        {
            val = _val;
            isVisited = _isVisted;
            
        }
        ~Node() {}
    };
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        
        
        if(n==1 && edges.size() == 0)
            return true;
        
        unordered_map<int, Node*> map;
        for(int i = 0; i < edges.size(); i++)
        {
            vector<int> edge = edges[i];
            Node* n1 = NULL;
            Node* n2 = NULL;
            
            if(map.find(edge[0]) == map.end())
            {
                n1 = new Node(edge[0]);
                map[edge[0]] = n1;
            }
            else
            {
                n1 = map[edge[0]];
            }
            
            if(map.find(edge[1]) == map.end())
            {
                n2 = new Node(edge[1]);
                map[edge[1]] = n2;
            }
            else
            {
                n2 = map[edge[1]];
            }
            
            n1->neighbors.push_back(n2);
            n2->neighbors.push_back(n1);
                    
        }
        
        int i = 0;
        for(; i < n; i++)
        {
            if(map.find(i) != map.end())
                break;
        }
        Node* node = map[0];
        
        return bfsTry(node, map);
    }
    
    bool bfsTry(Node* root, unordered_map<int, Node*> map)
    {
        
        if(root == NULL)
            return false;
        
        queue<Node*> q;
        q.push(root);
        
        while( !q.empty() )
        {
            Node* node = q.front();
            q.pop();
            if(node->isVisited)
                return false;
            
            node->isVisited = true;
            map.erase(node->val);
            
            for(int i = 0; i < node->neighbors.size(); i++)
            {
                
                Node* neiNode = node->neighbors[i];
                for(int j = 0; j < neiNode->neighbors.size(); j++)
                {
                    if(neiNode->neighbors[j] == node)
                        neiNode->neighbors.erase(neiNode->neighbors.begin()+j);
                }
                q.push(neiNode);
            }
        }
        
        return map.size() == 0 ? true : false;
    }
};
