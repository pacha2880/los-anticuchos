vi g[tam];
vector<vi> par(tam), dispa(tam);
vi siz(tam), cintra(tam);
void sisi(int node, int pa, int dis, int papazo)
{
    if(papazo != -1)
        par[node].pb(papazo), dispa[node].pb(dis);
    siz[node] = 1;
    for(int x : g[node])
        if(x != pa && !cintra[x])
            sisi(x, node, dis + 1, papazo), siz[node] += siz[x];
}
int centruida(int node, int pa, int simp)
{
    for(int x : g[node])
        if(x != pa && !cintra[x])
            if(siz[x] > simp / 2)
                return centruida(x, node, simp);
    return node;
}
void centauros(int node, int pa)
{
    sisi(node, -1, 1, pa);
    int centris = centruida(node, -1, siz[node]);
    cintra[centris] = 1;
    for(int x : g[centris])
        if(!cintra[x])
            centauros(x, centris);
}