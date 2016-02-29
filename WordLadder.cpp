class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
            
        //BFS search
        queue<string> q;
        q.push(beginWord);
        
        int numStep = 1;
        
        while( !q.empty() )
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                //find each one's children in wordList.
                string str = q.front();
                q.pop();
                
                // try each idx
                for(int s = 0 ; s < str.size(); s++)
                {
                    //try replace it with 'a' to 'z'
                    for(int c = 0 ; c < 26; c++)
                    {
                        string tmp_str = str;
                        tmp_str[s] = 'a' + c;
                        
                        if( tmp_str == endWord)
                            return numStep+1;
                        
                        if(wordList.find(tmp_str) != wordList.end())
                        {
                            q.push(tmp_str);
                            wordList.erase(tmp_str);
                        }
                    }
                }
            }
            
            numStep++;
        }
        
        return 0;
            
    }
    
};