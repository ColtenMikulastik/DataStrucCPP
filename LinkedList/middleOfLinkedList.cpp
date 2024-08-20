struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x){
          val = x;
          next = NULL;
     }
};

class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        // create two pointers
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
        {
            // slow moves one for every two that fast moves
            slow = slow->next;
            fast = fast->next->next;
        }
        // return the slower pointer
        return slow;
    }
};
