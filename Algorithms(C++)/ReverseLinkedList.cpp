// Given a linked list of N nodes. The task is to reverse this list.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node* prev=NULL,*Next=NULL;
        Node* curr=head;
        while(curr!=NULL)
        {
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        head=prev;
        return head;
    }
    
    
};
    