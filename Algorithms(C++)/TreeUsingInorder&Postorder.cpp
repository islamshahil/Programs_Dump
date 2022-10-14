//Given inorder and postorder traversal of a tree, find unique binary tree from the given traversals.

#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
      };

class Solution {
public:
    TreeNode* f(vector<int> &postorder, int postS, int postE, vector<int> &inorder, int inS, int inE, map<int,int> &inMap){
        if(postS>postE || inS>inE)
            return NULL;
        
        TreeNode * root= new TreeNode(postorder[postE]);
        int inRoot= inMap[root->val];
        int pos= inRoot-inS;
        
        root->left = f(postorder, postS, postS+pos-1, inorder, inS, inRoot-1, inMap);
        root->right= f(postorder, postS+pos, postE-1, inorder, inRoot+1, inE, inMap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        
        map<int,int> inMap;
        
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        
        TreeNode* root = f(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        
        return root;
    }
};

