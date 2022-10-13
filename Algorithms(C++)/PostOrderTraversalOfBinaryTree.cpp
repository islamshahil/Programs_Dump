//Given a Binary Tree, find out the PostOrder Traversal.

#include<bits/stdc++.h>
using namespace std;

//Approach 1
//Recursive code
struct node {
  int data;
  struct node * left, * right;
};

void postOrderTrav(node * curr, vector < int > & postOrder) {
  if (curr == NULL)
    return;

  postOrderTrav(curr -> left, postOrder);
  postOrderTrav(curr -> right, postOrder);
  postOrder.push_back(curr -> data);
}

//Approach 2
//Iterative code
vector < int > postOrderTrav(node * curr) {

  vector < int > postOrder;
  if (curr == NULL) return postOrder;

  stack < node * > s1;
  stack < node * > s2;
  s1.push(curr);
  while (!s1.empty()) {
    curr = s1.top();
    s1.pop();
    s2.push(curr);
    if (curr -> left != NULL)
      s1.push(curr -> left);
    if (curr -> right != NULL)
      s1.push(curr -> right);
  }
  while (!s2.empty()) {
    postOrder.push_back(s2.top() -> data);
    s2.pop();
  }
  return postOrder;
}