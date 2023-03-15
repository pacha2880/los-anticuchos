//  add lines of the form kx+m, and query maximum values at points x.
struct per_hull{
    const int logtam = 18;
    vector<int> k, m;
    vector<vector<int>> pars;
    per_hull(){pars.push_back(vi(logtam)), k.push_back(0), m.push_back(0);}
    int query(int x, int head)
    {
        auto f = [&](int x, int head) {
            return x * k[head] + m[head];
        };
        for(int i = logtam - 1; i > -1; i--)
            if(f(x, pars[head][i]) < f(x, pars[pars[head][i]][1]))
                head = pars[pars[head][i]][1];
        return f(x, head);
    }
    int add(int k1, int m1, int head)
    {
        for(int i = logtam - 1; i > -1; i--)
        {
            if(pars[head][i] == 0) continue;
            int b = pars[head][i];
            int a = pars[pars[head][i]][1];
            if((m[b] - m[a]) * (k[a] - k1) > (m1 - m[a]) * (k[a] - k[b]))
                head = pars[pars[head][i]][1];
        }
        int node = k.size();
        k.push_back(k1), m.push_back(m1);
        pars.push_back(vector<int>(logtam));
        pars[node][0] = node;
        pars[node][1] = head;
        for(int i = 2; i < logtam; i++)
            pars[node][i] = pars[pars[node][i - 1]][i - 1];
        return node;
    }
};