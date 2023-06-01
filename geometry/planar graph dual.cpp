vi g[tam];int n; // input graph (must be connected)
vi gd[tam];int nd; // output graph
vi nodes[tam]; // nodes delimiting region (in CW order)
map<ii,int> ps,es;
void get_dual(vector<pt> &p, vi &nods){ // p: points corresponding to nodes
	ps.clear();es.clear();
	for(int x : nods){
        pt p1, p2;
        auto cmp = [&](int a, int b){
            p1 = p[a] - p[x], p2 = p[b] - p[x];
            a = p1.x > 0 && p1.y == 0 || p1.y > 0, b = p2.x > 0 && p2.y == 0 || p2.y > 0;
            if(a == b)
                return p1 % p2 > 0;
            return a < b;
        };
		sort(all(g[x]), cmp);
		fore(i,0,g[x].size())ps[{x,g[x][i]}]=i;
	}
	nd=0;
	for(int xx : nods)for(auto yy:g[xx])if(!es.count({xx,yy})){
		int x=xx,y=yy;gd[nd].clear();nodes[nd].clear();
		while(!es.count({x,y})){
			es[{x,y}]=nd;nodes[nd].pb(y);
			int z=g[y][(ps[{y,x}]+1)%g[y].size()];x=y;y=z;
		}
		nd++;
	}
	for(auto p:es){
		pair<int,int> q={p.f.s,p.f.f};
		assert(es.count(q));
		if(es[q]!=p.s)gd[p.s].pb(es[q]);
	}
	fore(i,0,nd){
		sort(all(gd[i]));
		gd[i].erase(unique(all(gd[i])),gd[i].end());
	}
}
