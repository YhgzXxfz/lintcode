/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode* ori = head, *copy;
        
        // Link
        while (ori) {
            copy = new RandomListNode(ori->label);
            copy->next = ori->next;
            ori->next = copy;
            ori = ori->next->next;
        }
        
        // Assign random pointer
        ori = head;
        while (ori) {
            if (ori->random) {
                ori->next->random = ori->random->next;
            }
            ori = ori->next->next;
        }
        
        // Extract copied nodes
        ori = head;
        RandomListNode* result = new RandomListNode(0), *copyHead = result;
        RandomListNode* oriNext, *copiedNext;
        
        while (ori) {
            copiedNext = ori->next;
            oriNext = ori->next->next;
            
            copyHead->next = copiedNext;
            copyHead = copiedNext;
            
            ori->next = oriNext;
            ori = oriNext;
        }
        return result->next;
    }
};

