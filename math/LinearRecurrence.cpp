/*
Description: Generates the k’th term of an n-order linear recurrence
S[i] = ∑ S[i − j − 1]tr[j], given S[0 . . . ≥ n − 1] and tr[0 . . . n − 1]. Faster
than matrix multiplication. Useful together with Berlekamp–Massey.
Usage: linearRec({0, 1}, {1, 1}, k) // k’th Fibonacci number
Time: O (n^2 log k)*/
typedef vector<ll> Poly;
#define sz(x) (int)(x).size()
  ll linearRec(Poly S, Poly tr, ll k) {
  int n = sz(tr);
  auto combine = [&](Poly a, Poly b) {
  Poly res(n * 2 + 1);
  fore(i,0,n+1) fore(j,0,n+1)
    res[i + j] = (res[i + j] + a[i] * b[j]) % mod;
  for (int i = 2 * n; i > n; --i) fore(j,0,n)
    res[i - 1 - j] = (res[i - 1 - j] + res[i] * tr[j]) % mod;
  res.resize(n + 1);
  return res;
  };
  Poly pol(n + 1), e(pol);
  pol[0] = e[1] = 1;
  for (++k; k; k /= 2) {
    if (k % 2) pol = combine(pol, e);
    e = combine(e, e);
  }
  ll res = 0;
  fore(i,0,n) res = (res + pol[i + 1] * S[i]) % mod;
  return res;
}
