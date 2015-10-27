/*********************************************************************************
 * Leetcode : Binary Tree Preorder Traversal -- https://leetcode.com/problems/binary-tree-preorder-traversal/ 
 * Coded in Oct 27th, 2015
 *
 * [Problem]
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,2,3].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively? 
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
/*
vector<int> result;
vector<int> preorderTraversal(TreeNode* root) {
	if (root != NULL) {
		result.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
	return result;
}
*/

// Solution One B
/*
void preTraversal(TreeNode* root, vector<int>& result) {
	if (root != NULL) {
		result.push_back(root->val);
		preTraversal(root->left, result);
		preTraversal(root->right, result);
	}
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> result;
	preTraversal(root, result);
	return result;
}
*/

// Solution Two A
/*
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> result;
	if (root != NULL) {
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty()) {
			TreeNode* t = s.top();
			s.pop();
			result.push_back(t->val);
			if (t->right) {
				s.push(t->right);
			}
			if (t->left) {
				s.push(t->left);
			}
		}
	}
	return result;
}
*/

// Solution Two B
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> result;
	if (root != NULL) {
		stack<TreeNode*> s;
		TreeNode* t = root;
		while (true) {
			while (t) {
				result.push_back(t->val);
				if (t->right) {
					s.push(t->right);
				}
				t = t->left;
			}
			if (s.empty()) {
				break;
			}
			t = s.top();
			s.pop();
		}
	}
	return result;
}

// Solution Three
// Morris Traversal && threaded binary tree
vector<int> preorderTraversal(TreeNode* root) {
}

int main() {
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	a->right = b;
	b->left = c;
	vector<int> res = preorderTraversal(a);
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
