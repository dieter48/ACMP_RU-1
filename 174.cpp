#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	double x;
	in >> n;
	vector<long> a(n, 0);
	for (int i = 0; i < n; i++)
		in >> a[i];
	in >> x;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++){
		if (x < a[i]) 
			x = (x + a[i]) / 2;
	}
	out << fixed << x;
}