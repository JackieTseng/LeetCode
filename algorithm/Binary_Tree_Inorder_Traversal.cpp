/*********************************************************************************
 * Leetcode : Binary Tree Inorder Traversal -- https://leetcode.com/problems/binary-tree-inorder-traversal/ 
 * Coded in Oct 27th, 2015
 *
 * [Problem]
 *  Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 * 
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 * 
 * 
 * OJ's Binary Tree Serialization:
 * The serialization of a binary tree follows a level order traversal, where '#'
 * signifies a path terminator where no node exists below.
 * 
 * Here's an example:
 *    1
 *   / \
 *  2   3
 *     /
 *    4
 *     \
 *      5
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 *********************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution One A
vector<int> result;
vector<int> inorderTraversal(TreeNode* root) {
	if (root != NULL) {
		inorderTraversal(root->left);
		result.push_back(root->val);
		inorderTraversal(root->right);
	}
	return result;
}

// Solution One B
void inTraversal(TreeNode* root, vector<int>& result) {
	if (root != NULL) {
		inTraversal(root->left, result);
		result.push_back(root->val);
		inTraversal(root->right, result);
	}
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	inTraversal(root, result);
	return result;
}

int main() {
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	a->right = b;
	b->left = c;
	vector<int> res = inorderTraversal(a);
	cout << "[";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i != res.size() - 1) {
			cout << ",";
		}
	}
	cout << "]" << endl;
	return 0;
}
