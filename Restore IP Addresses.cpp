class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        // backtracking
        vector<string> ans;
        dfs(ans, "", s, 0, 0);
        
        return ans;
    }
    
    void dfs(vector<string>& ans, string str, string s, int size, int idx)
    {
        if(size == 4 && idx == s.size())
        {
            ans.push_back(str);
            return;
        }
        
        if(idx >= s.size())
        {
            return;
        }
        
        if(s[idx] == '0')
        {
            string nextStr = size == 0 ? "0" : str + "." + "0";
            dfs(ans, nextStr, s, size+1, idx+1);
        }
        else
        {
            int prev = -1;
            for(int i = idx; i < idx+3; i++)
            {
                string tmp = s.substr(idx, i-idx+1);
            
                int tmpInt = atoi(tmp.c_str());
                if(tmpInt >= 0 && tmpInt < 256 && tmpInt != prev)
                {
                    string nextStr = size == 0 ? tmp : str + "." + tmp;
                    dfs(ans, nextStr, s, size+1, i+1);
                }
                prev = tmpInt;
            }
        }
    }
};