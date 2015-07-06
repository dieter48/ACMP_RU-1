#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	long n, mx, k, tmx;
	in >> n;
	vector<long> a(n),b(n);
	for (int i = 0; i < n; i++){
		in >> a[i];
		b[i] = a[i];
	}
	sort(a.begin(), a.end());
	mx = 1;
	k = 1;
	tmx = 1;
	for (int i = 1; i < n; i++)
		if (a[i] == a[i-1]) tmx++;
		else{
			if (tmx > mx || tmx == mx && k > a[i - 1]) {
				mx = tmx;
				k = a[i - 1];
			}
			tmx = 1;
		}
	if (tmx > mx || tmx == mx && k > a[n - 1]) {
				mx = tmx;
				k = a[n - 1];
			}
	for (int i = 0; i < n; i++)
		if (b[i] != k) out << b[i] << ' ';
	for (int i = 0; i < mx; i++)
		out << k << ' ';
}