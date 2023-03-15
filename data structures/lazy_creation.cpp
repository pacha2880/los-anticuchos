struct st
{
	int val;
	st* r;
	st* l;
	st() {r = l = NULL; val = 0;}
	st(int v) {r = l = NULL; val = v;}
	st(st* L, st* R) {l = L; r = R, val = l->val + r->val;}
};
typedef st* pst;
void update(pst &t, int b, int e, int pos, int val)
{
    if(!t) t = new st();
	if(b == e)
    {
		t->val += val;
        return;
    }
	int mid = (b + e) / 2;
	if(mid >= pos)
		update(t->l, b, mid, pos, val);
    else
        update(t->r, mid + 1, e, pos, val);
    t->val = (t->l?t->l->val:0) + (t->r?t->r->val:0);
}
int query(pst t, int b, int e, int i, int j)
{
    if(!t) 
        return 0;
	if(b >= i && e <= j)
		return t->val;
	int mid = (b + e) / 2;
	if(mid >= j)
		return query(t->l, b, mid, i, j);
	if(mid < i)
		return query(t->r, mid +1, e, i, j);
	return query(t->l, b, mid, i, j) + query(t->r, mid +1, e, i, j);
}
