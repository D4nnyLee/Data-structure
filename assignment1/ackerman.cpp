#include <iostream>
#include <map>
#define ll long long int
using namespace std;
map<pair<ll, ll>, ll> dp; // record computed results
ll A(ll m, ll n) {
	// this will result in segment fault due to run out of stack
	auto p = make_pair(m, n);
	if (dp.find(p) != dp.end()) return dp[p];
	if (m == 0) return dp[p] = n + 1;
	if (n == 0) return dp[p] = A(m - 1, 1ll);
	return dp[p] = A(m - 1, A(m, n - 1));
}
int main(int argc, char const *argv[]) {
	ll m, n;
	while (cin >> m >> n) cout << A(m, n) << endl;
	return 0;
}
