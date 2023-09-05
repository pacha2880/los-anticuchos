struct PersistentTrie{
	vector<int> trie[2];
	vector<int> root;
	vector<int> frec;
	vector<bool> term;
    int tao;
	PersistentTrie(int tao) : tao(tao){
		root.pb(0);
		add_node();
	}
	void add_node(){
		trie[0].pb(0);
		trie[1].pb(0);
		frec.pb(0);
		term.pb(false);
	}
	void add_node(int from) {
		trie[0].pb(0);
		trie[1].pb(0);
		term.pb(term[from]);
		frec.pb(frec[from]);
	}
	void insert(int x, int last_root, int new_root) {
		for(int i = tao - 1; i >= 0; i--) {
			int nxt = (x >> i) & 1;
			trie[nxt ^ 1][new_root] = ~last_root ? trie[nxt ^ 1][last_root] : 0;
			if(~last_root && trie[nxt][last_root]) {
				trie[nxt][new_root] = trie[0].size();
				add_node(trie[nxt][last_root]);
			}
			else{
				trie[nxt][new_root] = trie[0].size();
				add_node();
			}
			last_root = ~last_root && trie[nxt][last_root] ? trie[nxt][last_root] : -1;
			new_root = trie[nxt][new_root];
			frec[new_root] += 1;
		}
		term[new_root] = true;
	}
	void insert(int x) {
		root.pb(trie[0].size());
		add_node();
		insert(x, root[root.size() - 2], root.back());
	}
};
