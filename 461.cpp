#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int k, n = 0;
	in >> k;
	vector<int> a(k);
	for (int i = 0; i < k; i++) in >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < k / 2 + 1; i++)
		n += a[i] / 2 + 1;
	out << n;
		return 0;
}