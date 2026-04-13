struct Kuhn{
    Kuhn(){}
    Kuhn(int nLeft, int nRight){ init(nLeft, nRight); }

    void init(int nLeft, int nRight){
        L = nLeft, R = nRight;
        G.clear(), G.resize(L);
        mt.assign(R, -1);
        used.assign(L, 0);
        cc = 1;
    }

    int L, R, cc;
    vector<vi> G;
    vi mt, used; // mt[to] = nodo izquierdo emparejado con to

    void addEdge(int u, int v){ G[u].pb(v); }

    bool dfs(int v){
        if(used[v] == cc) return 0;
        used[v] = cc;
        for(int to : G[v]) if(mt[to] == -1 || dfs(mt[to])) return mt[to] = v, 1;
        return 0;
    }

    int maxMatching(){
        mt.assign(R, -1);
        int match = 0;
        for(int v = 0; v < L; v++){
            ++cc;
            if(dfs(v)) match++;
        }
        return match;
    }
};