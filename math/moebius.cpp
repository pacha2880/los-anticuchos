//f(n)=sum(d|n,g(d))=>g(n)=sum(d|n,f(d)*mu(n/d))
//f(d)=sum(i->inf,g(i*d)*mu(i));f(d)=#func(a)->d;g(d)=#d|func(a)
//sum(d|n,mu(d))=e(n)=[n=1] 
int mu[tam], is_prime [tam];
fore(i, 0, tam) mu[i]=is_prime[i]=1;
fore(i, 2, tam) if(is_prime[i]) {
  forg(j, i, tam, i) {
    if(j > i) is_prime[j] = 0;
    if(j / i % i == 0) mu[j]=0;
    mu[j] = -mu[j];
  }
}
