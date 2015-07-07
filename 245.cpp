#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, i, j;
	long s = 0, ts;
	in >> n;
	vector<long> a(n);
	for (int i = 0; i < n; i++)
		in >> a[i];
	sort(a.begin(), a.end());
	if (n < 2) for (int i = 0; i < n; i++) s += a[i]; else
	{
		ts = a[0] + a[1];
		i = 0;
		j = 2;
		while (j < n){
			while (j < n && a[j] <= a[i] + a[i + 1]) ts += a[j++];
			if (ts > s) s = ts;
			ts -= a[i++];
		}
	}
	out << s;
}