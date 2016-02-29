#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    struct Node 
    {
        string str;
        bool visited;
        vector<Node*> neighbors;
        
        Node(string _str)
        {
            str = _str;
            visited = false;
        }
        ~Node()
        {
            
        }
    };
      
    vector< vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
    {
        // write your code here
        
        // Use BFS search first to find shortest num of step, and build a graph.
        
        unordered_map<string, Node*> map;
        int depth = bfs(start, end, dict, map);
        
        fprintf(stderr, "===depth=== %d\n", depth);
        

        // Use DFS to find all sequences with that number.
        vector<string> ans;
        vector< vector<string> > ret;
        Node* startNode = map[start];
        dfs(startNode, end, ans, ret, 0, depth);
        
        return ret;
        
    }
    
    void dfs(Node* node, string end, vector<string> ans, 
             vector< vector<string> >& ret, int currDepth, int depth)
    {
        
        fprintf(stderr, "dfs process curr depth %d, %s\n", currDepth, node->str.c_str());

        if(currDepth > depth)
            return;
        
        if(currDepth == depth && node->str == end)
        {
            fprintf(stderr, "Findit!!! %d, %s\n", currDepth, node->str.c_str());

            ans.push_back(end);
            ret.push_back(ans);
            return;
        }
        
        node->visited = true;
        vector<Node*> children = node->neighbors;
        fprintf(stderr, "size %lu\n", children.size());
        ans.push_back(node->str);    
        for(int i = 0; i < children.size(); i++)
        {
            dfs(children[i], end, ans, ret, currDepth+1, depth);
        }
        ans.pop_back();
        node->visited = false;
    }
    
    
    int bfs(string start, string end, unordered_set<string> &dict,
             unordered_map<string, Node*>& map)
    {

        queue<string> q;
        q.push(start);
        Node* startNode = new Node(start);
        map[start] = startNode;
        dict.insert(end);
        
        unordered_set<string> visited;
        visited.insert(start);
        int numSteps = 0;
        bool find = false;
        
        while( !q.empty() )
        {
            
            fprintf(stderr, "\nLINE %d, level = %d\n=====", __LINE__, numSteps);   
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                string parent = q.front();
                if(parent == end)
                {
                    fprintf(stderr, "find end!!! parent = %s, level = %d\n", parent.c_str(), numSteps);
                    find = true;
                }
                Node* node = map[parent];
                q.pop();
                vector<string> neighbors = findNeighbors(parent, dict);
                
                for(int j = 0; j < neighbors.size(); j++)
                {
                    string child = neighbors[j];

                    fprintf(stderr, "LINE %d child = %s\n", __LINE__, child.c_str());
                    Node* childNode;
                    
                    if(visited.find(child) == visited.end())
                    {
                        visited.insert(child);
                        q.push(child);
                    }

                    if(map.find(child) != map.end())
                    {
                        childNode = map[child];
                    }
                    else
                    {
                        childNode = new Node(child);
                        map[child] = childNode;
                    }
                    
                    node->neighbors.push_back(childNode);
                    fprintf(stderr, "node:%s neighbor size =  %lu\n", node->str.c_str(),node->neighbors.size());
                }
                
            }
            

            if( find )
                break;
            
            numSteps++;
            
            
        }

        
        unordered_map<string, Node*>::iterator it =  map.begin();
        for(; it!=map.end(); it++)
        {
            fprintf(stderr, "node:%s size = %lu\n", it->second->str.c_str(), it->second->neighbors.size());
            
            for(int i = 0; i < it->second->neighbors.size(); i++)
            {
                fprintf(stderr, "  %s,", it->second->neighbors[i]->str.c_str());
            }
            fprintf(stderr, "\n" );

        }


        return numSteps;
        
    }
    
    vector<string> findNeighbors(string str, unordered_set<string> &dict)
    {
        // TODO
        vector<string> ret;
        
        for (int i = 0; i < str.length(); i++) 
        {
            for (char ch = 'a'; ch <= 'z'; ch++) 
            {
                if ( ch != str[i] ) 
                {
                    string tmp = str;
                    tmp[i] = ch;
                    
                    
                    if ( dict.find(tmp) != dict.end() ) 
                    {
                        ret.push_back(tmp);
                    }
                }
            }
        }

        return ret;
    }
};


int main()
{
    string start = "kiss";
    string end = "tusk";
    unordered_set<string> dict;
    dict.insert("miss");
    dict.insert("dusk");
    dict.insert("kiss");
    dict.insert("musk");
    dict.insert("tusk");
    dict.insert("diss");
    dict.insert("disk");
    dict.insert("sang");
    dict.insert("ties");
    dict.insert("muss");
    
    Solution sol;
    vector< vector<string> > answer;
    answer = sol.findLadders(start, end, dict);

    for(int i = 0; i < answer.size(); i++)
    {
        for(int j = 0; j < answer[i].size(); j++)
        {
            fprintf(stderr, "%s, ", answer[i][j].c_str());
        }
        fprintf(stderr, "\n");
    }


    return 0;
}
