std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

// As is shown in the code, the statement if (i % prime[j] == 0) break; 
// terminates the loop when p divides i. 
// From the analysis above, we can see that the inner loop is executed only once for each composite. 
// Hence, the code above performs in O(n) complexity, resulting in its name — the 'linear' sieve.
