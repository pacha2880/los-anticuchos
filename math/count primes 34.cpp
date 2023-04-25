using ll = long long;
ll count_primes(ll n) {
    vector<ll> v;
    for (ll k = 1; k * k <= n; ++k) {
        v.push_back(n / k);
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    // return i such that v[i] = x
    // since v[i] = i + 1 for i <= sqrt(n) and v[v.size() - i] = n / i for i <= sqrt(n),
    // we can calculate index in O(1)
    ll sq = sqrt(n);
    auto geti = [&](ll x) {
        if (x <= sq) return (int)x - 1;
        else         return (int)(v.size() - (n / x));
    };

    vector<ll> dp(v.size());

    // S(n, 0) = n
    for (int i = 0; i < v.size(); ++i)
        dp[i] = v[i];

    int a = 0;
    for (ll p = 2; p * p <= n; ++p) {
        // this condition is true for primes
        if (dp[geti(p)] != dp[geti(p - 1)]) {
            ++a;
            for (int i = (int)v.size() - 1; i >= 0; --i) {
                if (v[i] < p * p) break;
                dp[i] -= dp[geti(v[i] / p)] - a;
            }
        }
    }

    return dp[geti(n)] - 1;
}