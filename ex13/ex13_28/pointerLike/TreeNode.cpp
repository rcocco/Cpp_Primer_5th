#include "TreeNode.h"
#include <iostream>
using std::ostream;
TreeNode &TreeNode::operator=(const TreeNode &rhs) {
	++*rhs.count;
	if (--*count == 0) {
		if (left) {
			delete left;
		}
		if (right) {
			delete right;
		}
		delete count;
	}
	value = rhs.value;
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
	return *this;
}
TreeNode::~TreeNode() {
	if (--*count == 0) {
		if (left) {
			delete left;
		}
		if (right) {
			delete right;
		}
		delete count;
	}
}
std::ostream &print(std::ostream &os, TreeNode *root) {
	if (root != nullptr) {
		os << root->value << "\n";
		print(os, root->left);
		print(os, root->right);
	}
	return os;
}