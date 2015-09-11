/*********************************************************************************
 * Leetcode : Invert Binary Tree -- https://leetcode.com/problems/invert-binary-tree/
 * Coded in Seq 11th, 2015
 *
 * [Problem]
 * Invert a binary tree.
 * 
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * to
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 *********************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution One
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return root;
    }
    TreeNode* t = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = t;
    return root; 
}

// Solution Two
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return root;
    }
    queue<TreeNode*> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode* cur = s.front();
        s.pop();
        TreeNode* t = cur->left;
        cur->left = cur->right;
        cur->right = t;

        if (cur->left != NULL) {
            s.push(cur->left);
        }
        if (cur->right != NULL) {
            s.push(cur->right);
        }
    }
    return root;
}

int main(int argc, const char *argv[]) {
    return 0;
}
