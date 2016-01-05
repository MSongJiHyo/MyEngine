#include "Nfa.h"
static int nextnum()
{
	return ++num;
}
NfaNode *addNode(Nfa &nfa)
{
	int num = nextnum();
	NfaNode* node = new NfaNode(num, nullptr,nullptr, false);
	node->next = nfa.root->next;
	nfa.root = node;
	return node;
}
NfaNode *nfaAddEdge(NfaNode *start, NfaNode *accept, char c)
{
	NfaEdge *edge = new NfaEdge(start, accept, c,start->edge);
	start->edge = edge;	
}
