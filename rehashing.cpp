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
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int old_size = hashTable.size();
        int new_size = old_size*2;
        
        if (old_size == 0) return hashTable;
        
        vector<ListNode*> rehash_table(new_size, nullptr);
        
        for (int i = 0 ;i < old_size; ++i) {
            if (hashTable[i]) rehash(hashTable, rehash_table, i);
        }
        return rehash_table;
    }
    
    vector<ListNode*> rehash(vector<ListNode*>& hash_table, 
        vector<ListNode*>& rehash_table, int i) {
        int size = rehash_table.size();
        ListNode* curr = hash_table[i];
        
        while (curr) {
            int val = curr->val;
            int pos = (val % size + size) %size;
            
            if (!rehash_table[pos]) {
                rehash_table[pos] = new ListNode(val);
            } else {
                ListNode* temp = rehash_table[pos];
                while (temp->next) temp = temp->next;
                temp->next = new ListNode(val);
            }
            
            curr = curr->next;
        }
    }
};


