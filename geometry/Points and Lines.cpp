struct point
{
	double x,y;
	point() {x=y=0;}
	point(double _x, double _y) : x(_x), y(_y) {}
	point operator+(point a) const {
		a.x+=x;
		a.y+=y;
		return a;
	}
};
double dist(point a, point b) {
	return hypot(a.x-b.x,a.y-b.y);
}
point tovec(point a, point b) {
	return point(b.x-a.x,b.y-a.y);
}
point translate (point p, point v) {
	return point(p.x+v.x,p.y+v.y);
}
point scale(point v, double sc) {
	return point(v.x*sc,v.y*sc);
}
point rotate(point v, double theta) {//rotacion antihorario ccw
	theta *= acos(-1)/180.0;
	return point(v.x*cos(theta)-v.y*sin(theta),v.x*sin(theta)+ v.y*cos(theta));
}
point clos(point a, line l, line &pe) {//closest point in a line and perpendicular line from a
	if(fabs(l.a) < EPS) {
		pe.a = 1, pe.b = 0, pe.c = -a.x;
		return point(a.x,-l.c); 
	}
	if(fabs(l.b) < EPS) {
		pe.a = 0, pe.b = 1, pe.c = -a.y;
		return point(-l.c,a.y);
	}
	tolinegr(a, 1/(l.a),pe);
	areIntersect(l,pe,a);
	return a;
}
point reflexion(point p, point a, point b) {// del punto p a linea ab
	line l,li;
	toline(a,b,li);
	point p1 = clos(p,li,l);
	p1 = p1+(tovec(p,p1));
	return p1;
}
double norm_sq(point a) {
	return a.x * a.x + a.y * a.y;
}
double dot(point a, point b) {
	return a.x*b.x + b.y*a.y;
}
double angle(point a, point b, point c) {//b el del medio
	a = tovec(b,a), b = tovec(b,c);
	double res = dot(a,b);
	res = acos(res / (sqrt(norm_sq(a))*sqrt(norm_sq(b))));
	res*= 180.0/acos(-1);
	return res;
}
double cross(point a, point b) {//prosucto cruz
	return a.x * b.y - a.y * b.x;
}
double distToLine(point p, point a, point b, point &c) {//con producto punto halla el punto
	//c = a + u*ab
	point ab = tovec(a,b), ap = tovec(a,p);
	double u = dot(ab,ap) / norm_sq(ab);
	c = translate(a, scale(ab,u));
	return dist(p,c);
}
double distToline1(point p, point a, point b) {//con producto cruz solo distancia
	point ap = tovec(a,p), ab = tovec(a,b);
	return fabs(cross(ab,ap)/hypot(ab.x,ab.y));
}