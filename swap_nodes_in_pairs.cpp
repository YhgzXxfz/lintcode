/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if (NULL == head || NULL == head->next) return head;
        
        ListNode * previousNode = head, *currentNode = head, *nextNode = head->next;
       
        while (NULL != nextNode)
        {
            if(previousNode == head) 
            {
                currentNode->next = nextNode->next;
                nextNode->next = currentNode;
                head = nextNode;
                
                previousNode = currentNode;
                currentNode = currentNode->next;
                if (NULL == currentNode) return head;
                
                nextNode = currentNode->next;
            }
                
            else
            {
                ListNode * temp = currentNode->next;
                currentNode->next = nextNode->next;
                nextNode->next = previousNode->next;
                previousNode->next = temp;

                previousNode = currentNode;
                if(NULL == previousNode->next) break;
            
                currentNode = currentNode->next;
                nextNode = currentNode->next;
            }
        }
        
        return head;
    }
};

