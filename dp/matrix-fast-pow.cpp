// kth term of linear recurrence 
// of size m a_i = sum(a_(i-j)*p_j)
// f(x) = x^m - sum(x^(m-j)*p_j)
// g(x^k) = g(x^k MOD f)
typedef vector<vector<ll> > Matrix;
Matrix ones(int n) {
  Matrix r(n,vector<ll>(n));
  fore(i,0,n)r[i][i]=1;
  return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
  int n=sz(a),m=sz(b[0]),z=sz(a[0]);
  Matrix r(n,vector<ll>(m));
  fore(i,0,n)fore(j,0,m)fore(k,0,z)
    r[i][j]+=a[i][k]*b[k][j],r[i][j]%=MOD;
  return r;
}
Matrix be(Matrix b, ll e) {
  Matrix r=ones(sz(b));
  while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
  return r;
}
