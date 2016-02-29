class Solution {
public:
    
    string arys[12];
       
    vector<string> letterCombinations(string digits) {
        

        //backtracking
         
        if(digits.size()==0)
            return vector<string>();
        
        
        arys[0] = "";
        arys[1] = "abc";
        arys[2] = "def";
        arys[3] = "ghi";
        arys[4] = "jkl";
        arys[5] = "mno";
        arys[6] = "pqrs";
        arys[7] = "tuv";
        arys[8] = "wxyz";
        
        
        vector<string> inputStrs;
        for(int i = 0; i < digits.size(); i++)
        {
            inputStrs.push_back(arys[digits[i] - '0' - 1]);
        }
        
        vector<string> answer;
        string tmp = "";
        helper(inputStrs, 0, tmp, answer);
        
        return answer;
    }
    
    void helper(vector<string> strs, int idx, string tmpAns, vector<string>& ans)
    {
        //base case
        if(idx >= strs.size())
        {
            ans.push_back(tmpAns);
            return;
        }
        
        string str = strs[idx];
        for(int i = 0; i < str.size(); i++)
        {
            tmpAns = tmpAns + str[i];
            helper(strs, idx+1, tmpAns, ans);
            tmpAns.pop_back();
        }
    }
};