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
	return exp.at(pos++);
	
}
TreeNode* Tree::ReToTree()
{
	root=Tree::parse_Exp();
	
	return root;
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
 
  switch (root->nodeKind){
  case CHAR:{
    cout<<root->c;
    break;
  }
  case ALT:{
    cout<<"(";
    Re_print (root->left);
    cout<<") | (";
    Re_print (root->right);
    cout<<")";
    break;
  }
  case CONCAT:{
    cout<<"(";
    Re_print (root->left);
    cout<<")(";
    Re_print (root->right);
	cout<<")";
    break;
  }
  case CLOSURE:{
    cout<<"(";
    Re_print (root->left);
    printf (")*");
    break;
  }
  default:
    break;
  }
  return;
}
