struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    // recursive function
    ListNode* reverseList(ListNode* head)
    {
        // skip until find null ptr
        if(!head || !head->next) return head;
        
        // call recursively on head's next opening until end of list
        ListNode* revHead = reverseList(head->next);
        // begins on end of list, points to last known node for call of function
        ListNode* lastNode = head->next;
        // recursion is so illegible
        head->next = NULL;
        lastNode->next = head;
        
        return revHead;
    }
};
