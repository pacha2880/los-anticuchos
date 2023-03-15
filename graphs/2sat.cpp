namespace sat2{
  set<int> G[tam],  Ginv[tam];
  int N,  mark[tam],  mark_comp[tam], valor[tam];
  int neg(const int& x) { return (x>=N)? x - N : x + N;}
  void add_(const int& x,const int& y) {G[x].insert(y);Ginv[y].insert(x);}
  void addor(const int x,const int y) {add_(neg(x),y);add_(neg(y),x);}
  void dfs0(int u, vector<int>& orden) {  mark[u] = 1;
    for(auto& v: G[u]) {
      if (!mark[v])   dfs0(v,orden);
    }   orden.push_back(u);
  }
  void dfs1(int u, const int& cmp) {  mark_comp[u] = cmp;
    for(auto& v: Ginv[u]) {
      if (!mark_comp[v])  dfs1(v,cmp);
    }
  }
  bool check() {  bool impos = false;
    for(int i = 0; i < N; i++) {
      impos |= (mark_comp[i] == mark_comp[neg(i)]);
       valor[i] =  (mark_comp[i] > mark_comp[neg(i)]) ;}
    return !impos;
  }
}
