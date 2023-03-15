int ft[tam+1]; // for more dimensions, make ft multi-dimensional
void update(int pos, int val){ // add val to pos-th element (0-based)
	// add extra fors for more dimensions
	for(int i=pos+1;i<=tam;i+=i&-i)ft[i]+=val;
}
int get(int pos){ // get sum of range [0,pos)
	int r=0;
	// add extra fors for more dimensions
	for(int i=pos;i;i-=i&-i)r+=ft[i];
	return r;
}
int query(int b, int e){ // get sum of range [b,e) (0-based)
	return get(e)-get(b);
}