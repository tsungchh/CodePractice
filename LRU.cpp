#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class LRUCache{
    
    struct LinkedList {
        LinkedList* next;
        LinkedList* prev;
        
        int val;
        int key;
        
        LinkedList(int _key = 0, int _val = 0) 
          : key(_key),
            val(_val),
            next(NULL),
            prev(NULL)
        {
            
        }
        
        ~LinkedList()
        {
            
        }
    };
    
public:
    LRUCache(int capacity) {
        myCapacity = capacity;
        myHead = new LinkedList(-1, -1);
        myTail = new LinkedList(-1, -1);
        myHead->next = myTail;
        myTail->prev = myHead;
    }
    
    int get(int key) {
        
        if( myMap.find(key) == myMap.end() )
        {
            return -1;
        }
        else
        {
            update(myMap[key]);
            return myMap[key]->val;
        }
    }
    
    void set(int key, int value) {
        
        LinkedList* node;
        
        if(myMap.find(key) != myMap.end())
        {
            node = myMap[key];
            node->val = value;
        }
        else
        {
            if(myMap.size() >= myCapacity)
                remove(); // remove the front node
    
            node = new LinkedList(key, value);
            myMap[node->key] = node;
        }
        update(node);
    }

private:

    void remove()
    {
        LinkedList* curr = myHead->next;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        myMap.erase( curr->key );
        delete curr;
    }
    
    void update(LinkedList* node)
    {
        
        if( node == myTail->prev)
            return;
            
        if(node->next && node->prev)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        myTail->prev->next = node;
        node->prev = myTail->prev;
        node->next = myTail;
        myTail->prev = node;
    }
    
    LinkedList* myHead;
    LinkedList* myTail;
    unordered_map<int, LinkedList*> myMap;
    int myCapacity;
};

int main()
{
    LRUCache* cache = new LRUCache(1);
    cache->set(2,1);
    //cache->get(1);

    return 0;
}