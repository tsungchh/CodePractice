/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution{
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode *middleNode(ListNode *head) {
        // Write your code here
        
        if(head == NULL)
            return NULL;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        delete dummy;
        
        return slow;
        
    }
};

