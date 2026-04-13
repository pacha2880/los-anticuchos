struct HopcroftKarp{
    const int INF = 1e9 + 7;
    HopcroftKarp(){}
    HopcroftKarp(int nLeft, int nRight){ init(nLeft, nRight); }

    void init(int nLeft, int nRight){
        L = nLeft, R = nRight;
        G.clear(), G.resize(L);
        pairU.assign(L, -1), pairV.assign(R, -1);
        dist.resize(L), Q.resize(L);
    }

    int L, R;
    vector<vi> G;
    vi pairU, pairV, dist, Q;

    void addEdge(int u, int v){ G[u].pb(v); }

    bool bfs(){
        int qh = 0, qt = 0;
        for(int u = 0; u < L; u++){
            if(pairU[u] == -1) dist[u] = 0, Q[qt++] = u;
            else dist[u] = INF;
        }
        bool ok = 0;
        while(qh < qt){
            int u = Q[qh++];
            for(int v : G[u]){
                int u2 = pairV[v];
                if(u2 == -1) ok = 1;
                else if(dist[u2] == INF) dist[u2] = dist[u] + 1, Q[qt++] = u2;
            }
        }
        return ok;
    }

    bool dfs(int u){
        for(int v : G[u]){
            int u2 = pairV[v];
            if(u2 == -1 || (dist[u2] == dist[u] + 1 && dfs(u2))){
                pairU[u] = v, pairV[v] = u;
                return 1;
            }
        }
        dist[u] = INF;
        return 0;
    }

    int maxMatching(){
        pairU.assign(L, -1), pairV.assign(R, -1);
        int match = 0;
        while(bfs()) for(int u = 0; u < L; u++)
            if(pairU[u] == -1 && dfs(u)) match++;
        return match;
    }
};