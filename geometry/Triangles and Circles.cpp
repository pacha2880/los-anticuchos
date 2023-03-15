double rInCircle(double ab, double bc, double ca) {
	double s = (ab+bc+ca)/2;
	return sqrt(s*(s-ab)*(s-bc)*(s-ca));
}
double areaTri1(double a, double b, double c) {//heron
	double s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
line perp(line a, point p) {//perpendicular
	line res;
	if(a.b=0)
		res.a = 0, res.b = 1, res.c = -p.y;
	else
		if(fabs(a.a)<EPS)
			res.a = 1, res.b = 0, res.c = -p.y;
		else
			res.a = -1.0/a.a, res.b = 1, res.c = -res.a*p.x-p.y;

}
bool circumCircle(point a, point b, point c, point &ctr, double &r) {//circuncentro completo
	double area = areaTri(a,b,c);
	if(fabs(area)<EPS) return 0;
	line l1, l2;
	pointsToLine(a,b,l2);
	pointsToLine(a,c,l2);
	point p1 = point((a.x+b.x)/2.0,(a.y+b.y)/2.0), p2 = point((a.x+c.x)/2.0,(a.y+c.y)/2.0);
	l1 = perp(l1,p1), l2 = perp(l2,p2);
	areIntersect(l1,l2,ctr);
	r = dist(a,b)*dist(b,c)*dist(a,c)/(4.0*areaTri(a,b,c));
	return true;
} 
bool isInCircum(point a, point b, point c, point p) {//si esta dentro del circulo circunscrito
	double r;
	point ctr;
	if(!circumCircle(a,b,c,ctr,r)) return false;
	return dist(ctr,p) <= r ;
}
bool inCircle(point a, point b, point c, point &ctr) {//incentro
	double r = rIncircle(a,b,c);
	if(r< EPS) return false;
	line l1,l2;
	point p1;
	double ratio = dist(a,b) / dist(a,c);
	p1 = translate(b, scale(tovec(b,c),ratio/(1+ratio)));
	pointsToLine(a,p1,l1);
	ratio = dist(b,a) / dist(b,c);
	p1 = translate(a, scale(tovec(a,c),ratio/(1+ratio)));
	pointsToLine(b,p1,l2);
	areIntersect(l1,l2,ctr);
	return true;
}
line toLinep(point a, point b, point c) {//para mediatriz
	line l;
	if(b.x == c.x)
		l.a = 0, l.b = 1 , l.c = -a.y;
	else if(b.y == c.y)
		l.a = 1, l.b = 0, l.c = -a.x;
	else
		l.a = 1/((b.y-a.y)/(b.x-a.x)), l.b = 1, l.c = -l.a*a.x-a.y;
	return l;
}
point circun(point a, point b, point c) {//circuncentro
	line l1, l2;
	l1 = toLinep(point((a.x+b.x)/2,(a.y+b.y)/2),a,b);
	l2 = toLinep(point((a.x+c.x)/2,(a.y+c.y)/2),a,c);
	areIntersect(l1,l2,a);
	return a;
}
bool circle2PtsRad(point a, point b, double r, point &c) {//dados 2 puntos y un radio
	double det = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	det = r * r / det - 0.25;
	if(det < 0.0) return false;
	det = sqrt(det);
	c.x = (a.x + b.x) * 0.5 + (b.y-a.y) * det;
	c.y = (a.y + b.y) * 0.5 + (a.x-b.x) * det;			
	return true;
}