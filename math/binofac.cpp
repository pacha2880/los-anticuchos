int pot (int b, int e) {
    int res = 1;
    while(e)
    {
        if(e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e /= 2;
    }
    return res;
}
vi fac(tam), facin(tam);
int bino(int n, int k) {
    return k < 0 ? 0 : n < 0 ? 0 : k > n ? 0 : fac[n] * facin[k] % MOD * facin[n - k] % MOD;
};
void precalbino() {
    fac[0] = 1;
    fore(i, 1, tam)
        fac[i] = fac[i - 1] * i % MOD;
    facin[tam - 1] = pot(fac[tam - 1], MOD - 2);
    for(int i = tam - 2; i >= 0; i--)
        facin[i] = facin[i + 1] * (i + 1) % MOD;
}