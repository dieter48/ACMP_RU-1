#include <fstream>
#include <vector>
using namespace std;


int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, m, p, k, t, l, e = -1;
	in >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		in >> a[i];
		if (i >= k && a[i] != a[i - k])
		if (e != -1 && (i % k) != e){
			out << "FAIL";
			return 0;
		}
		else e = i % k;
	}
	m = p = t = 0;
	if (e != -1){
		for (int i = e; i < n; i += k)
		if (a[i]) { if (!m) t = i; m++; }
		else { if (!p) l = i;  p++; }

		if (m == 1 && p != 1) out << "OK\n" << l + 1; else
		if (m != 1 && p == 1) out << "OK\n" << t + 1; else
		if (m == 1 && p == 1) out << "OK\n" << ((l < t) ? l: t) + 1; else
			out << "FAIL";
	}
	else out << "OK\n0";

}