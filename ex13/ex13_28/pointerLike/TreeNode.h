#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
#include <string>
class TreeNode {
	friend std::ostream &print(std::ostream &os, TreeNode *root);
public:
	TreeNode(const std::string &v=std::string(), 
		TreeNode *l = nullptr, TreeNode *r = nullptr) :
		value(v), count(new int(1)), left(l), right(r) {}
	TreeNode(const TreeNode &rhs) :
		value(rhs.value), count(rhs.count),
		left(rhs.left), right(rhs.right) {
		++*count;
	}
	TreeNode &operator=(const TreeNode &);
	~TreeNode();
private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};
std::ostream &print(std::ostream &os, TreeNode *root);
#endif