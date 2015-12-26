#ifndef TREE_H
#define	TREE_H

#include "TreeNode.h"
#include <iostream>
using namespace std;
class Tree
{
public:
	char currentChar;
	char peerChar;
	string exp;
	string::size_type pos;
	TreeNode *root;
	char	  getNextChar();
	char      getBackChar();
	TreeNode *ReToTree();
	TreeNode *parse_Exp();
	TreeNode *parse_B();
	TreeNode *parse_A();
	TreeNode *parse_C();
	void Re_print(TreeNode* root);
	Tree(string);
	
};
#endif
