#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <string>
class TreeNode {
	friend std::ostream &print(std::ostream &os, TreeNode *root);
public:
	TreeNode() :
		value(""), count(0), left(nullptr), right(nullptr) {}
	TreeNode(const std::string &v, int c, TreeNode *l=nullptr, TreeNode *r=nullptr) :
		value(v), count(c), left(l), right(r) {}
	TreeNode(const TreeNode &rhs) :
		value(rhs.value), count(rhs.count), 
		left(copyTree(rhs.left)),right(copyTree(rhs.right)) {}
	TreeNode &operator=(const TreeNode &);
	~TreeNode() { freeTree(this); }
private:
	TreeNode *copyTree(TreeNode *);
	void freeTree(TreeNode *);
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};
std::ostream &print(std::ostream &os, TreeNode *root);
#endif