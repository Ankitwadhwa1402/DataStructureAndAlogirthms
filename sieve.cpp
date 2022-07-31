int lp[MX+1];
vector<int> pr;
void sieve()
{
	for (int i=2; i<=MX; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=MX; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}
