// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by 
// splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    ListNode* merge(ListNode* first,ListNode* second)
    {
        if(first==NULL) return second;
        if(second==NULL) return first;
        
        if(first->val>second->val)
        {
            second->next=merge(first,second->next);
            return second;
        }
        else
        {
            first->next=merge(first->next,second);
            return first;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1,list2);
    }
};