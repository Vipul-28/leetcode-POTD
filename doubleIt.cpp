//Double a Number Represented as a Linked List

// You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

// Return the head of the linked list after doubling it.

 

// Example 1:


// Input: head = [1,8,9]
// Output: [3,7,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
// Example 2:


// Input: head = [9,9,9]
// Output: [1,9,9,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
 
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
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp=reverseLinkedList(head);
        ListNode*temp1=temp;
        int extra=0;
        while(temp1){
            int data=temp1->val*2+extra;
            temp1->val=(data%10);
            extra=data/10;
            temp1=temp1->next;
        }
        head=reverseLinkedList(temp);
        if(extra!=0)
        {
            ListNode* ext=new ListNode(extra);
            ext->next=head;
            head=ext;
        }
        return head;
    }
};