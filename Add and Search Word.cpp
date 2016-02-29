class WordDictionary {
 
private:

    class TrieNode
    {
    public:
        TrieNode()
        {
            for(int i = 0; i < 26; i++)
            {
                children[i] = NULL;   
            }
            isWord = false;
        }
        
        ~TrieNode()
        {
            
        }
        
        TrieNode* children[26];
        bool isWord;
    };
    
    void cleanNode(TrieNode* node)
    {
        for(int i = 0; i < 26; i++)
        {
            if(node->children[i] != NULL)
                delete node->children[i];
        }
    }
    
    TrieNode* root;
    
public:
    
    WordDictionary()
    {
        root = new TrieNode();
    }
    
    ~WordDictionary()
    {
        cleanNode(root);
    }


    // Adds a word into the data structure.
    void addWord(string word) {
        
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if(curr->children[idx] == NULL)
            {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        
        curr->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return helper(root, 0, word);
    }
    
    bool helper(TrieNode* node, int idx, string word)
    {
        if(idx == word.size())
        {
            return node->isWord;
        }
        
        if(word[idx] == '.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(node->children[i] != NULL)
                {
                    if( helper(node->children[i], idx+1, word) )
                        return true;
                }
            }
            return false;
            
        }
        else 
        {
            int wordIdx = word[idx] - 'a';
            
            if(node->children[wordIdx] == NULL)
                return false; 
            return helper(node->children[wordIdx], idx+1, word);
        }
        
    }
    
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");