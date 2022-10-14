//Given a Linked list, delete the middle of the linked list.

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode * getMid(ListNode* head){
        ListNode* slow=new ListNode(0);
        ListNode* fast=slow;
        slow->next=head;
        fast->next=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
            return NULL;
        ListNode* mid=getMid(head);
        mid->next=mid->next->next;
        return head;
    }
    
};