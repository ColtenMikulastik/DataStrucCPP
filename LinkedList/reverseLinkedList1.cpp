struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x){
          val = x;
          next = NULL;
     }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* revHead = reverseList(head->next);
        ListNode* lastNode = head->next;
        head->next = NULL;
        lastNode->next = head;
        
        return revHead;
    }
};