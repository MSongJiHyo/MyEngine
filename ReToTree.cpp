#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree(string s)
{
	exp = s;
	root = nullptr;
	pos = 0;
	currentChar = '\0';
	Tree::ReToTree();
	Tree::Re_print(root);
}
char Tree::getNextChar()
{
	return exp[pos++];
	
}
char Tree::getBackChar()
{
	
	return exp[pos-2];

}
TreeNode* Tree::ReToTree()
{
	currentChar = getNextChar();
	root=Tree::parse_Exp();	
	return root;
}
TreeNode* Tree::parse_Exp()
{	
	TreeNode* left = parse_A();
	if (currentChar == '\0')
	{
		return left;
	}
	while (currentChar == '|')
	{
		currentChar = getNextChar();		
		TreeNode* right = parse_A();
		TreeNode* alt = new TreeNode(ALT, '|', left, right);
		left = alt;
	}
	return left;
}
TreeNode* Tree::parse_A()
{
	TreeNode* left = parse_B();
	if (currentChar == '\0')
	{
		return left;
	}
	while (isalpha(currentChar)||((currentChar=='(')&&isalpha(getBackChar())))
	{	
		TreeNode* right = parse_B();
		TreeNode* Concat = new TreeNode(CONCAT, '.', left, right);
		left = Concat;		
	}
	return left;
}
TreeNode* Tree::parse_B()
{
	TreeNode* left = parse_C();
	if (currentChar == '\0')
	{
		return left;
	}
	while(currentChar == '*')
	{
		currentChar = getNextChar();
		TreeNode* Clo = new TreeNode(CLOSURE, '*', left, nullptr);
		
		left = Clo;
	}
	return left;
}
TreeNode* Tree::parse_C()
{
	TreeNode* left = nullptr;
	if (currentChar=='(')
	{
		currentChar = getNextChar();		
		left = parse_Exp();
		currentChar = getNextChar();	
		return left;
	}
	if (isalpha(currentChar))
	{
		TreeNode* leaf = new TreeNode(CHAR, currentChar, nullptr, nullptr);
		currentChar = getNextChar();
		
		return leaf;
	}
	return nullptr;
}
void Tree::Re_print (TreeNode* root)
{
	switch (root->nodeKind)
	{
	case CHAR:
	{
		cout << root->c;
		break;
	}
	case ALT:
	{
		cout << "(";
		Re_print(root->left);
		cout << ") | (";
		Re_print(root->right);
		cout << ")";
		break;
	}
	case CONCAT:
	{
		cout << "(";
		Re_print(root->left);
		cout << ")(";
		Re_print(root->right);
		cout << ")";
		break;
	}
	case CLOSURE:{
		 cout << "(";
		 Re_print(root->left);
		 printf(")*");
		 break;
	}
	default:
		break;
	}
	return;
}
