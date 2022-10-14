//Design an algorithm to serialize and deserialize a binary tree.

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        if(root==NULL)
            return str;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node=q.front();
            q.pop();
            if(node==NULL)
                str.append("#,");
            else 
                str.append(to_string(node->val)+',');
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
        {
            return NULL;
        }
        stringstream ss(data);
        string str;
        getline(ss,str, ',');
        
        TreeNode *ans;
        queue<TreeNode *> q;
        ans = new TreeNode(stoi(str));
        q.push(ans);
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            getline(ss,str,','); 
            if (str == "#")
            {
                curr->left = NULL;
            }
            else
            {
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            
            getline(ss,str,',');
            if (str == "#")
            {
                curr->right = NULL;
            }
            else
            {
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return ans;        
    }
};
