#include <iostream>

using namespace std;

class Solver {
	string s;
public:	
	Solver(string s) : s(s) {	
		// initialization, precalculation
	}
    long long preComputeHashes(const string& s, int prime, int x) {
	unsigned long long hash = 0;
	for (long long i = s.size() - 1; i >= 0; --i)
		hash = (hash * x + s[i]) % prime;
	return hash;
}

	bool ask(int a, int b, int l) {
		int p1 = 1000000007;
		int p2 = 1000000009;
	int x = rand() % 1000000000 + 1;
	string v= s.substr(a,l);
	string u=s.substr(b,l);
	if((preComputeHashes(v,p1,x)==preComputeHashes(u,p1,x)) && (preComputeHashes(v,p2,x)==preComputeHashes(u,p2,x)))
	    return true;
	else 
	    return false;	
	
	}


};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
