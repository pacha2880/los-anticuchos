bool circle2PtsRad(point a, point b, double r, point &c) {//dados 2 puntos y un radio
  double det = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
  det = r * r / det - 0.25;
  if(det < 0.0) return false;
  det = sqrt(det);
  c.x = (a.x + b.x) * 0.5 + (b.y-a.y) * det;
  c.y = (a.y + b.y) * 0.5 + (a.x-b.x) * det;      
  return true;
}