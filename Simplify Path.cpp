class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        
        // 1. when encounter ..
        // 2. double slash(//) - > /
        
        
        // using stack 
        
        vector<string> aryPath;
        aryPath = helper(path);
        return convert2path(aryPath);
        
    }
    
    /** helper function 
     *  Return the next string after '/'
     *  modify the path. 
     */
     vector<string> helper(string& path)
     {
         vector<string> aryPath;
         
         int i = 0;
         while(i < path.size())
         {
             //find '/'
             while(path[i] != '/' && i < path.size())
             {
                 i++;
             }
             
             //handle multiple '/'
             while(i < path.size() && path[i] =='/')
             {
                 i++;
             }
             
             string tmp = "";
             if(i < path.size())
             {
                int start = i;
                while(i < path.size() && path[i] != '/')
                {
                    i++;
                }
                tmp = tmp + path.substr(start, i-start);
                aryPath.push_back(tmp);
             }
         }
         return aryPath;
     }
     
     string convert2path(vector<string> ary)
     {
         
         stack<string> stk;
        for(int i = 0; i < ary.size(); i++)
        {
            string tmp = ary[i];
            if(tmp == ".")
            {
                continue;
            }
            else if(tmp == "..")
            {
                if(!stk.empty())
                    stk.pop();
            }
            else
            {
                stk.push(tmp);
            }
        }
        
        string ret = "";
        // iteratre from tail of the path
        while(!stk.empty())
        {
            string path = stk.top();
            stk.pop();
            ret = path + "/" + ret;
        }            
         
         if(!ret.empty())
            ret = ret.substr(0, ret.size()-1);
         ret = "/" + ret;
         
         return ret;
     }
    
};