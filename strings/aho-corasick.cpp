struct vertex {
  int go[26], pch, par, link = -1, super = -1, leaf = 0;
  vertex(): link(0), super(0) { mem(go, -1); }
  vertex(int ch, int from): pch(ch), par(from) { mem(go, -1); }
};
vector<vertex> t(1);
void add(string &s, int pos) {
  int node = 0;
  for(char ch : s) {
    ch -= 'a';
    if(t[node].go[ch] == -1)
      t[node].go[ch] = t.size(); t.emplace_back(ch, node);
    node = t[node].go[ch];
  }
  t[node].leaf = 1;
}
int go(int node, char c);
int suff(int node) {
  if(t[node].link == -1)
    t[node].link = t[node].par == 0 ? 0 : go(suff(t[node].par), t[node].pch);
  return t[node].link;
}
int go(int node, char ch) {
  if(t[node].go[ch] == -1)
    t[node].go[ch] = node == 0 ? 0 : go(suff(node), ch);
  return t[node].go[ch];
}
int super(int v) {
  if(t[v].super == -1)
    t[v].super = t[suff(v)].leaf ? suff(v) : super(suff(v));
  return t[v].super;
}
