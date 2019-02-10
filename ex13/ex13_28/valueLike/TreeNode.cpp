#include "TreeNode.h"
#include <iostream>
using std::ostream;
TreeNode *TreeNode::copyTree(TreeNode *root) {
	if (root == nullptr) return nullptr;
	TreeNode *new_root = new TreeNode(*root);
	return new_root;
}
void TreeNode::freeTree(TreeNode *root) {
	if (root != nullptr) return;
	freeTree(root->left);
	freeTree(root->right);
	delete left;
	delete right;
}
TreeNode &TreeNode::operator=(const TreeNode &rhs) {
	if (this != &rhs) {
		freeTree(this);
		value = rhs.value;
		count = rhs.count;
		left = copyTree(rhs.left);
		right = copyTree(rhs.right);
	}
	return *this;
}
std::ostream &print(std::ostream &os, TreeNode *root) {
	if (root != nullptr) {
		os << root->value << " " << root->count << "\n";
		print(os, root->left);
		print(os, root->right);
	}
	return os;
}