#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) {
        return root;
    }
    TreeNode* t = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = t;
    return root; 
}

int main(int argc, const char *argv[]) {
    
    return 0;
}
