#ifndef NFAEDGE_H
#define NFAEDGE_H
#include "NfaNode.h"
const int Eps = -1;
class NfaEdge
{
public:
	NfaNode *from;
	NfaNode *to;
	char c;
	NfaEdge *edge;
	NfaEdge(NfaNode *from_, NfaNode *to_, char c_, NfaEdge *edge_) :from(from_), to(to_), c(c_), edge(edge_){}
};
#endif
