class Solution {
public:
    /**
     * @param str a string
     * @return all permutations
     */
    vector<string> stringPermutation2(string& str) {
        // Write your code here
        
        //dfs
        
        vector<string> ans;
        vector<bool> visited(str.size(), false);
        dfs(ans, visited, str, "");
        
        return ans;
    }
    
    void dfs(vector<string>& ans, vector<bool>& visited, string str, string tmp)
    {
        if(tmp.size() == str.size())
        {
            ans.push_back(tmp);
            return;
        }
        
        unordered_set<char> set;
        
        for(int i = 0; i < visited.size(); i++)
        {
            if(visited[i] || set.find(str[i]) != set.end())
                continue;
            
            string tmpAdd = tmp + str[i];
            set.insert(str[i]);
            visited[i] = true;
            dfs(ans, visited, str, tmpAdd);
            visited[i] = false;
        }
    }
};