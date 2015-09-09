/*********************************************************************************
 * Leetcode : Binary Tree Paths -- https://leetcode.com/problems/binary-tree-paths/ 
 * Coded in Seq 9th, 2015
 *
 * [Problem]
 * Given a binary tree, return all root-to-leaf paths.
 *  
 * For example, given the following binary tree:
 * 
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 *
 * All root-to-leaf paths are:
 * 
 * ["1->2->5", "1->3"]
 *********************************************************************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

inline string to_string(int val) {
    char buffer[10];
    sprintf(buffer, "%d", val);
    return string(buffer);
}

void binaryTreePaths(vector<string>& result, TreeNode* root, string temp) {
    if (!root->left && !root->right) {
        result.push_back(temp);
        return;
    }

    if (root->left) {
        binaryTreePaths(result, root->left, temp + "->" + to_string(root->left->val));
    }
    if (root->right) {
        binaryTreePaths(result, root->right, temp + "->" + to_string(root->right->val));
    }
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if (!root) {
        return result;
    }
    binaryTreePaths(result, root, to_string(root->val));
    return result;
}

int main(int argc, const char *argv[]) {
    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);  
    t->left->right = new TreeNode(5);
    vector<string> result = binaryTreePaths(t);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
