//Remove Nodes From Linked List
// You are given the head of a linked list.

// Remove every node which has a node with a greater value anywhere to the right side of it.

// Return the head of the modified linked list.

 

// Example 1:


// Input: head = [5,2,13,3,8]
// Output: [13,8]
// Explanation: The nodes that should be removed are 5, 2 and 3.
// - Node 13 is to the right of node 5.
// - Node 13 is to the right of node 2.
// - Node 8 is to the right of node 3.
// Example 2:

// Input: head = [1,1,1,1]
// Output: [1,1,1,1]
// Explanation: Every node has value 1, so no nodes are removed.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* reverseLinkedList(ListNode *head)
{
    if(head==nullptr || head->next==nullptr)
    return head;
    ListNode *newhead=reverseLinkedList(head->next);
    ListNode *headnext=head->next;
    headnext->next=head;
    head->next=nullptr;
    return newhead;
}
    ListNode* removeNodes(ListNode* head) {
        ListNode *temp=reverseLinkedList(head);
        ListNode *temp1=temp;
        int maxi=INT_MIN;
        ListNode* da=temp1;
        while(temp1){
            if(temp1->val<maxi){
              da->next=temp1->next;
            }
           else if(temp1->val>=maxi){
            maxi=temp1->val;
            da=temp1;
           }
           temp1=temp1->next;
        }
        head=reverseLinkedList(temp);
        return head;
    }
};