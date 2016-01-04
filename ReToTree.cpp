#include "Tree.h"
#include <iostream>
#include "Nfa.h"
using std::string;
using std::cout;
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
	TreeNode* l = parse_A();
	if (currentChar == '\0')
	{
		return l;
	}
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
	if (currentChar == '\0')
	{
		return l;
	}
	while (isalpha(currentChar)||((currentChar=='(')&&isalpha(getBackChar())))
	{	
			TreeNode* r = parse_B();
			TreeNode* Concat = new TreeNode(CONCAT, '.', l, r);
			l = Concat;		
	}
	return l;
}
TreeNode* Tree::parse_B()
{
	TreeNode* l = parse_C();
	if (currentChar == '\0')
	{
		return l;
	}
	while(currentChar == '*')
	{
		currentChar = getNextChar();
		TreeNode* Clo = new TreeNode(CLOSURE, '*', l, nullptr);
		
		l = Clo;
	}
	return l;
}
TreeNode* Tree::parse_C()
{
	TreeNode* l = nullptr;
	if (currentChar=='(')
	{
		currentChar = getNextChar();		
		l = parse_Exp();
		currentChar = getNextChar();	
		return l;
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


NfaNode *treeToNfa(TreeNode *root, Nfa &nfa)
{
	switch (root->nodeKind)
	{
	case CONCAT:
	{
		NfaNode *oldStart = nfa.start;
		NfaNode *oldAccept = nfa.accept;
		treeToNfa(root->left, nfa);
	    treeToNfa(root->right, nfa);
	    nfa.nfaAddEdge(oldAccept, nfa.start, Eps);
	    nfa.start = oldStart;
	}
	case CHAR:
	{

		NfaNode *
	}

	}

}
