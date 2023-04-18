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
        
        ListNode *prePtr = NULL, *currPtr = head, *nxtPtr;
        while(currPtr){
            nxtPtr = currPtr->next;
            currPtr->next = prePtr;
            prePtr = currPtr;
            currPtr = nxtPtr;
        }
        return prePtr;
    }
};