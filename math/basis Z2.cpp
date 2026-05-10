int basis[30], si = 0;
void add(int x) {
  fore(i, 0, 21)    
    if(x & 1 << i) {
      if(basis[i])
        x ^= basis[i];
      else {
        basis[i] = x;
        si++;
        return;
      }
    }
}