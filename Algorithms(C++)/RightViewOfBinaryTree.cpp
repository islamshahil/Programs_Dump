// right View of a binary tree
// approach: find the level order traversal and add only the last elements of each row.

#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data) { 
        this->data = data; 
        left = right = NULL; 
    }
};

struct Node *root = NULL;

vector<int> rightView(struct Node *root) {
    vector<int> result;
    if(root == NULL)
        return result;
    queue<Node *> queue;
    queue.push(root);
    while(!queue.empty()) {
        int levelSize = queue.size();
        for(int i = 0; i < levelSize; i++) {
            Node *current = queue.front();
            queue.pop();
            
            if(i == levelSize - 1) {
                result.push_back(current->data);
            }

            if(current->left != NULL)
                queue.push(current->left);
            if(current->right != NULL)
                queue.push(current->right);
        }
    }
    return result;
}
    
int main() {
    // construt tree
    root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(1);
    root->left->left = new Node(9);
    root->right->left = new Node(10);
    root->right->right = new Node(5);
    root->left->left->left = new Node(3);
    vector<int> ans = rightView(root);
    for (auto node : ans) {
        cout << node << " ";
    }
    cout << endl;
}
