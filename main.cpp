#include <iostream>
#include "Tree.h"
#include "TreeNode.h"
#include <stdlib.h>
using namespace std;

int main(void)
{
	Tree::Tree ("(a|b)d*|b(dd)");
	system("pause");
	return 0;
}
