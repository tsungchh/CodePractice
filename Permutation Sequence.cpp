class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        
        vector<string> ans;
        vector<bool> visited;
        visited.resize(n, false);
        string tmp = "";
        helper(ans, visited, tmp, n, k);
        
        return ans[ans.size()-1];
    }
    
    void helper(vector<string>& ans, vector<bool>& visited, string tmp, int n, int k)
    {
        if(ans.size() == k)
            return;
           
        if(tmp.size() == n)
        {
            ans.push_back(tmp);
            return;
        }
        
        for(int i = 1; i <= n; i++)
        {
            if(visited[i])
                continue;
            
            visited[i] = true;
            tmp = tmp + to_string(i);
            helper(ans, visited, tmp, n, k);
            tmp = tmp.substr(0, tmp.size()-1);
            visited[i] = false;
        }
    }
       
};