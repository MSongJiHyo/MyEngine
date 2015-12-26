#ifndef NFANODE_H
#define NFANODE_H
#include "NfaEdge.h"

class NfaNode
{
public:
	int num;
	NfaNode *next;
	NfaEdge *edge;
	bool visit;
	NfaNode(int num_, NfaNode *next_, NfaEdge *edge_, bool visit_) :num(num_), next(next_), edge(edge_), visit(visit_){}
};


#endif // !NFANODE_H
