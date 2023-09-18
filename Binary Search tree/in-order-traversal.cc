/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// This is the definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Recursive solution
void inorderTraversal(TreeNode *root, vector<int> &result) {
    /*
    My Approach:
    1. Traverse the left subtree
    2. Check if the root is null, if yes, return
    3. Push the root value to the result vector
    4. Traverse the right subtree

    Time complexity: O(n)
    Space complexity: O(n)
    
    */
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

int main() {
    // Create a binary tree
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result;
    inorderTraversal(root, result);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}