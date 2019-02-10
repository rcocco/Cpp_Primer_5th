#ifndef BINSTRTREE_H
#define BINSTRTREE_H
#include "TreeNode.h"
class BinStrTree {
public:
	BinStrTree(TreeNode *r = nullptr) :root(r) {}
	BinStrTree(const BinStrTree &rhs) :root(new TreeNode(*rhs.root)) {}
	BinStrTree &operator=(const BinStrTree &rhs) {
		if (this != &rhs) {
			delete root;
			root = new TreeNode(*rhs.root);
		}
		return *this;
	}
	~BinStrTree() { delete root; }
private:
	TreeNode *root;
};
#endif