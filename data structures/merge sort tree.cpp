// Mergesort Tree - Time <O(nlogn), O(log^2n)> - Memory O(nlogn)
// Mergesort Tree is a segment tree that stores the sorted subarray
// on each node.
vi t[4*tam];
int ar[tam];
void build(int node, int b, int e) {
  if (b == e) { t[node].pb(ar[b]); return; }
  build(2*node, b, (b+e)/2);
  build(2*node+1, (b+e)/2+1, e);
  merge(t[2*node].begin(), t[2*node].end(),
        t[2*node+1].begin(), t[2*node+1].end(),
        back_inserter(t[node]));
}

int query(int node, int b, int e, int i, int j, int x, int y) {
  if (j < b || i > e) return 0;
  if (i <= b && j >= e)
    return upper_bound(t[node].begin(), t[node].end(), y) -
           lower_bound(t[node].begin(), t[node].end(), x);
  return query(2*node, b, (b+e)/2, i, j, x, y) +
         query(2*node+1, (b+e)/2+1, e, i, j, x, y);
}