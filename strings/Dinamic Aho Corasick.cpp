const int alpha = 26;
int node[20][tam][alpha];
struct ahoCorasick
{
    int root, nnode;
    int link[tam], cnt[tam], id;
    bool dead;

    void init(int idx)
    {
        dead = false; id = idx; root = 0; nnode = 0;
        mem(node[id][root], 0);
        fore(i, 0, nnode + 1) cnt[i] = 0;
    }
    void clear()
    {
        dead = true;
    }
    void insert(string &s, int val)
    {
        int len = s.size();
        int now = root;

        fore(i, 0, len)
        {
            int nxt = s[i] - 'a';
            if(!node[id][now][nxt])
            {
                node[id][now][nxt] = ++nnode;
                mem(node[id][nnode],0);
                cnt[nnode] = 0;
            }

            now=node[id][now][nxt];
        }
        cnt[now] += val;
    }
    void insertdict(vector<string> &dict, vector<int> &vals)
    {
        fore(i, 0, sz(dict)) insert(dict[i], vals[i]);
    }
    void pushLinks()
    {
        queue<int> Q; link[root]=-1;
        Q.push(root);
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();

            fore(i, 0, alpha)
            {
                if(!node[id][u][i]) continue;
                int v = node[id][u][i];
                int l = link[u];

                while(l != -1 && !node[id][l][i]) l = link[l];
                if(l!=-1) link[v] = node[id][l][i];
                else link[v] = 0;
                cnt[v] += cnt[link[v]];
                Q.push(v);
            }
        }
    }
    int query(string &p)
    {
        int u = root, ret = 0;
        for(char ch : p)
        {
            int nxt = ch - 'a';
            while(u != -1 && !node[id][u][nxt]) u = link[u];
            if(u == -1) u = 0;
            else u = node[id][u][nxt];
            ret += cnt[u];
        }
        return ret;
    }
} aho[20];

vector<string> dict[20];
vector<int> vals[20];

void add(string &s, int val)
{
    dict[0].pb(s);
    vals[0].pb(val);
    fore(i, 0, 20)
    {
        if(sz(dict[i]) > (1<<i))
        {
            for(auto it : dict[i]) dict[i + 1].pb(it);
            for(auto it : vals[i]) vals[i + 1].pb(it);
            dict[i].clear();
            vals[i].clear();
            aho[i].clear();
        }
        else
        {
            aho[i].init(i);
            aho[i].insertdict(dict[i], vals[i]);
            aho[i].pushLinks();
            break;
        }
    }
}