#ifndef TREENODE_H
#define	TREENODE_H
enum TreeNodeKind{
	CHAR,
	CONCAT,
	ALT,
	CLOSURE
};
class TreeNode
{
public:
	TreeNodeKind nodeKind;
	char c;
	TreeNode *left;
	TreeNode *right;
	TreeNode(TreeNodeKind nodeKind_, char c_, TreeNode *left_, TreeNode* right_) :nodeKind(nodeKind_), c(c_), left(left_), right(right_){}
};

#endif
