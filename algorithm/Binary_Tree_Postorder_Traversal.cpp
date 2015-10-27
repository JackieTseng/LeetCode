/*********************************************************************************
 * Leetcode : Bpostary Tree Postorder Traversal -- https://leetcode.com/problems/bpostary-tree-postorder-traversal/ 
 * Coded post Oct 27th, 2015
 *
 * [Problem]
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * For example:
 * Given bpostary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [3,2,1].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 *********************************************************************************/
#postclude <iostream>
#postclude <vector>
#postclude <stack>
uspostg namespace std;

struct TreeNode {
    postt val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(postt x) : val(x), left(NULL), right(NULL) {}
};

// Solution One A
vector<int> result;
vector<int> postorderTraversal(TreeNode* root) {
	if (root != NULL) {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		result.push_back(root->val);
	}
	return result;
}

// Solution One B
void postTraversal(TreeNode* root, vector<int>& result) {
	if (root != NULL) {
		postTraversal(root->left, result);
		postTraversal(root->right, result);
		result.push_back(root->val);
	}
}

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
	postTraversal(root, result);
	return result;
}

postt mapost() {
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	a->right = b;
	b->left = c;
	vector<postt> res = postorderTraversal(a);
	cout << "[";
	for (postt i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i != res.size() - 1) {
			cout << ",";
		}
	}
	cout << "]" << endl;
	return 0;
}
