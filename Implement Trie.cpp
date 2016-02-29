/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */

static const int CHILDSIZE = 26; 
 
class TrieNode {
    
public:
    // Initialize your data structure here.
    TrieNode() {
        
        for(int i = 0; i < CHILDSIZE; i++)
        {
            childrenNode[i] = NULL;
        }
        count = 0;
    }
    
    int count;
    TrieNode* childrenNode[CHILDSIZE];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
            
        int idx = 0;
        TrieNode* curr = root;
        while(idx < word.size())
        {
            TrieNode* next = curr->childrenNode[word[idx] - 'a'];
            if(next == NULL)
            {
                next = new TrieNode();
            }
            curr->childrenNode[word[idx] - 'a'] = next;
            curr = next;//curr->childrenNode[word[idx] - 'a'];
            idx++;
        }
        
        if(curr->count == 0)
            curr->count = 1;
        else 
            curr->count++;
        
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        
        int idx = 0;
        TrieNode* curr = root;
        while(idx < word.size())
        {
            TrieNode* next = curr->childrenNode[word[idx] - 'a'];
            idx++;
            if(next == NULL)
            {
                return false;
            }
            curr = next;//curr->childrenNode[word[idx] - 'a'];
        }
        
        if(curr->count > 0)
            return true;
        else
            return false;
        
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        
        int idx = 0;
        TrieNode* curr = root;
        while(idx < prefix.size())
        {
            TrieNode* next = curr->childrenNode[prefix[idx] - 'a'];
            idx++;
            if(next == NULL)
                return false;
            
            curr = next;
        }
        
        return true;
    }

private:
    TrieNode* root;
};
