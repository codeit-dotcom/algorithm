#include <iostream>

using namespace std;

struct Answer {
	size_t i, j, len;
};

/*Answer solve(const string &s, const string &t) {
	Answer ans = {0, 0, 0};
	for (size_t i = 0; i < s.size(); i++)
		for (size_t j = 0; j < t.size(); j++)
			for (size_t len = 0; i + len <= s.size() && j + len <= t.size(); len++)
				if (len > ans.len && s.substr(i, len) == t.substr(j, len))
					ans = {i, j, len};
                    
	return ans;
}*/
long long polyHash(const string& s, int prime, int x) {
	unsigned long long hash = 0;
	for (long long i = s.size() - 1; i >= 0; --i)
		hash = (hash * x + s[i]) % prime;
	return hash;
}
std::vector<long long> preComputeHashes(string text, int pLength, int p, int x) {
	int tLength = text.size();
	std::vector<long long> H(tLength - pLength + 1);
	string s = text.substr(tLength - pLength, pLength);
	H[tLength - pLength] = polyHash(s, p, x);
	long long y = 1;
	for (int i = 1; i <= pLength; ++i)
		y = y * x % p;
	for (int i = tLength - pLength - 1; i >= 0; --i) {
		long long preHash = x * H[i + 1] + text[i] - y * text[i + pLength];
		while (preHash < 0) {
			preHash += p;
		}
		H[i] = preHash % p;
	}
	return H;
}
median(Answer ans){
    if(ans!={0,0,0}){
    std::vector<long long> H11 = preComputeHashes(s,z+m/2,p1,x);
    std::vector<long long> H21 = preComputeHashes(t,z+m/2,p1,x);
    std::vector<long long> H12 = preComputeHashes(s,z+m/2,p2,x);
    std::vector<long long> H22 = preComputeHashes(t,z+m/2,p2,x);
    for(int i=0; i<H11.size(); i++){
        for(int j=0; j< H21.size() ;j++){
            if((H11[i]==H21[j])&& H12[i]==H22[j])
              {
                  ans={i , j, s-H11.size()+1}
               break;
              }  
            }

        }
    }
   if(ans=={0,0,0}){
    std::vector<long long> H11 = preComputeHashes(s,z-m/2,p1,x);
    std::vector<long long> H21 = preComputeHashes(t,z-m/2,p1,x);
    std::vector<long long> H12 = preComputeHashes(s,z-m/2,p2,x);
    std::vector<long long> H22 = preComputeHashes(t,z-m/2,p2,x);
    for(int i=0; i<H11.size(); i++){
        for(int j=0; j< H21.size() ;j++){
            if((H11[i]==H21[j])&& H12[i]==H22[j])
              {
                  ans={i , j, s-H11.size()+1}
               break;
              }  
            }

        }
    } 

}
solving(const string &s ,const string &t){
    Answer ans ={0,0,0}
    int x=s.size(), y=t.size();
    int z= std::min(x,y);
    int p1 = 1000000007;
    int p2 = 1000000009;
    int m=0;
	int x = rand() % (p-1) + 1;
    
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}
