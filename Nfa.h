#include "NfaEdge.h"
#include "NfaNode.h"
#include "Tree.h"
static int num = 0;
class Nfa
{
public:
	NfaNode *start;
	NfaNode *accept;
	NfaNode *root;
	NfaNode *nfaAddEdge(NfaNode *start, NfaNode *accept, char c);
	int nextnum();
	NfaNode *addNode();
	
	Nfa() 
	{		
		start = nullptr;
		accept = nullptr;
		root = nullptr;
	}
};
