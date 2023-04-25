//calculates number of integer points (x ; y) such for 0 ≤ x < n and 0 < y ≤ ⌊k * x + b⌋
int count_lattices(double k, double b, long long n) {
    auto fk = floor(k);
    auto fb = floor(b);
    auto cnt = 0LL;
    if (k > 1 - EPS || b > 1 -EPS) {
        cnt += (fk * (n - 1) + 2 * fb) * n / 2;
        k -= fk;
        b -= fb;
    }
    auto t = k * n + b;
    auto ft = floor(t);
    if (ft > 1 - EPS) {
        cnt += count_lattices(1 / k, (t - floor(t)) / k, floor(t));
    }
    return cnt;
}
pair<double, double> kb(point a, point b)
{
	return mp((b.y - a.y) / (b.x - a.x), (a.y * b.x - a.x * b.y) / (b.x - a.x));
}

// # of lattice points s.t. ax+by<=c, x,y>0 (a,b is positive integer)
ll f(ll a, ll b, ll c){
	if(c<=0) return 0;
	if(a<b) swap(a, b);
	ll m=c/a;
	if(a==b) return m*(m-1)/2;
	ll k=(a-1)/b, h=(c-a*m)/b;
	return f(b,a-b*k,c-b*(k*m+h))+k*m*(m-1)/2+m*h;
}
 
// # of lattice points s.t. ax+by<=c, 0<x<=X, 0<y<=Y (a,b is positive integer)
ll g(ll a, ll b, ll c, ll X, ll Y){
	if(a*X+b*Y<=c) return X*Y;
	return f(a,b,c)-f(a,b,c-a*X)-f(a,b,c-b*Y)+f(a,b,c-a*X-b*Y);
}
