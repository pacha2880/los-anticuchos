struct Node{ int de; Node *par, *go; };
typedef Node* pNode;
pNode find(pNode nod, int de)
{
	while(nod->de > de)
		if(nod->go->de < de)
			nod = nod->par;
		else
			nod = nod->go;
	return nod;
}
pNode add(pNode nod, int ind)
{
	pNode nuevo = new Node();
	nuevo->par = nod;
	nuevo->de = nod->de + 1;
	if(nod->de - nod->go->de == nod->go->de - nod->go->go->de)
		nuevo->go = nod->go->go;
	else
		nuevo->go = nod;
	return nuevo;
}
pNode lca(pNode a, pNode b)
{
	if(a->de < b->de) swap(a, b);
	a = find(a, b->de);
	while(a != b)
		if(a->go == b->go)
			a = a->par, b = b->par;
		else
			a = a->go, b = b->go;
	return a;
}