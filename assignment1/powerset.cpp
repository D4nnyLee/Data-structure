#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n; // length of allElements
vector<string> allElements; 
queue<tuple<vector<string>, int> > queueForSubsets;
void recur() {
	if (queueForSubsets.empty()) return;
	vector<string> subset;
	int cur; // the index of the element that can be added to this subset
	tie(subset, cur) = queueForSubsets.front();
	queueForSubsets.pop();
	int len = subset.size();
	subset.push_back("");
	// print subset
	if (len == 0) cout << "{}";
	else {
		cout << '{' << subset[0];
		for (int i = 1; i < len; i++) cout << ' ' << subset[i];
		cout << '}';
	}
	// add new subsets by expending current subset
	while (cur < n) {
		subset[len] = allElements[cur++];
		queueForSubsets.push({subset, cur});
	}
	recur();
}
int main() {
	string s;
	while (getline(cin, s)) {
		istringstream iss(s);
		allElements.clear();
		while (iss >> s) allElements.push_back(s); // split input with space
		n = allElements.size();
		queueForSubsets.push({{}, 0}); // add empty set
		recur();
		cout << endl;
	}
	return 0;
}
