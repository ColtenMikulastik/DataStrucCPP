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
        // loop through list normally, reversing the next of the current ptr
        while(currPtr){
            // start putting nxt ahead
            nxtPtr = currPtr->next;
            // assign our currptr's next behind us
            currPtr->next = prePtr;
            // move the preptr up
            prePtr = currPtr;
            // move the currptr up
            currPtr = nxtPtr;
        }
        // preptr should point to the last existing node
        return prePtr;
    }
};
