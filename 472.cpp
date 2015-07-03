#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<long> vi;
typedef vi::iterator it;
long give(it b, it e, long &m){
	if ((b + 1) == e) {
		*b += m;
		return 0;
	}
	int cnt = 0, diff = 0, sum;
	it i;
	for (i = b; i != e && (i == b || *(i - 1) == *i); i++) cnt++;
	if (i != e) diff = *i - *(i - 1);
	sum = cnt * diff;
	if (diff && sum <= m){
		for (it j = b; j != i; j++) *j = *i;
		m -= sum;
		return m;
	}
	*b += m / cnt;
	m = 0;
	return 0;
}
int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	long n, m ;
	in >> n >> m;
	vi a(n);
	for (int i = 0; i < n; i++) in >> a[i];
	sort(a.begin(), a.end());
	while (give(a.begin(), a.end(), m));
	out << a[0];
		return 0;
}