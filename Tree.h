#include "TreeNode.h"
#include <iostream>
using namespace std;
class Tree
{
public:
	char currentChar;
	string exp;
	string::size_type pos;
	TreeNode *root;
	char	  getNextChar();
	TreeNode *ReToTree();
	TreeNode *parse_Exp();
	TreeNode *parse_Concat();
	TreeNode *parse_Alt();
	TreeNode *parse_Closure();

	Tree(string);
	
};

