/*********************************************************************************
 * Leetcode : Same Tree --https://leetcode.com/problems/same-tree/ 
 * Coded in Seq 11th, 2015
 *
 * [Problem]
 * Given two binary trees, write a function to check if they are equal or not.
 * 
 * Two binary trees are considered equal if they are structurally identical and
 * the nodes have the same value. 
 *********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution One
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL || q == NULL) {
        return p == q;
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// Solution Two
bool isSameTree(TreeNode* p, TreeNode* q) {
    return (p == q) ? true : p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, const char *argv[]) {
    cout << (isSameTree(NULL, NULL) ? "Yes" : "No") << endl;
    return 0;
}
