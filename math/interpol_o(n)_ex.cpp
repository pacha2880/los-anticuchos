// evaluar un "polinomio interpolado" en o(nlogMOD) 
// debe cumplir xi+1 - xi = xj+1 - xj for all i, j < n
// recibe vector de ys tal que f(i) = y[i]
vi fac(tam), sig(tam), facin(tam);
ll eval(vll &ys, ll x) {
	int n = ys.size();
	if(x < n) return ys[x];
	ll upi, dowi, res = 0;
    vi pre(n), suf(n);
    pre[1] = 1, suf[n - 1] = 1;
    fore(i, 1, n)
    {
		if(i > 1)
        pre[i] = pre[i - 1] * (x - i + 1) % MOD;
        suf[n - i - 1] = suf[n - i] * (x - n + i) % MOD;
    }
	fore(i, 1, n) {
        upi = pre[i] * suf[i] % MOD;
        dowi = facin[n - i - 1] * facin[i - 1] % MOD * sig[n - i - 1] % MOD;
		res = (res + ys[i] * upi % MOD * dowi % MOD) % MOD;
	}
	return res;
}
