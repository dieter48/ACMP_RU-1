#include <fstream>
#include <set>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int m, n, k;
	in >> m >> n;
	set<int> a, b;
	for (int i = 0; i < m; i++) {
		in >> k;
		a.insert(k);
	}
	for (int i = 0; i < n; i++) {
		in >> k;
		b.insert(k);
	}
	if (a == b) out << 1;
	else out << 0;
}