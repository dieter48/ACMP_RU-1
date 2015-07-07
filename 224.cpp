#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	long long n, mx;
	in >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) in >> a[i];
	sort(a.begin(), a.end());
	mx = (long long)a[n - 1] * a[n - 2] * a[n - 3];
	if (mx < (long long)a[0] * a[1] * a[n - 1]) mx = (long long)a[0] * a[1] * a[n - 1];
	out << mx;
}