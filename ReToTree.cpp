#include "Tree.h"

using namespace std;

Tree::Tree(string s)
{
	exp = s;
	root = nullptr;
	pos = 0;
	currentChar = '\0';
	ReToTree();
}
char Tree::getNextChar()
{
	return exp.at(pos++);
	
}
TreeNode* Tree::ReToTree()
{
	root=Tree::parse_Exp();
}
TreeNode* Tree::parse_Exp()
{
	currentChar = getNextChar();
	TreeNode* l = parse_A();
	while (currentChar == '|')
	{
		currentChar = getNextChar();
		TreeNode* r = parse_A();
		TreeNode* alt = new TreeNode(ALT, '|', l, r);
		l = alt;
	}
	return l;
}
TreeNode* Tree::parse_A()
{
	TreeNode* l = parse_B();
	while (isalpha(currentChar))
	{		
		currentChar = getNextChar();
		TreeNode* r = parse_B();
		TreeNode* Concat = new TreeNode(CONCAT, '.', l, r);
		l = Concat;
	}
	return l;
}
TreeNode* Tree::parse_B()
{
	TreeNode* l = parse_C();
	while (currentChar == '*')
	{
		currentChar = getNextChar();
		TreeNode* r = parse_C();
		TreeNode* Clo = new TreeNode(CLOSURE, '*', l, nullptr);
		l = Clo;
	}
	return l;
}
TreeNode* Tree::parse_C()
{
	if (currentChar=='(')
	{
		currentChar = getNextChar();
		TreeNode* l = parse_Exp();
		getNextChar();
		currentChar = getNextChar();
	}
	if (isalpha(currentChar))
	{
		TreeNode* leaf = new TreeNode(CHAR, currentChar, nullptr, nullptr);
		currentChar = getNextChar();
		return leaf;
	}
}
