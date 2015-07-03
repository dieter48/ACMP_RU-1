#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<long, long> pll;
typedef vector<pll> vp;
int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	long n, l ,r;
	in >> n;
	vector<bool> clr(1,1);
	vp irvl(1, pll(0, 1000000000));
	for (int i = 0; i < n; i++){
		in >> l >> r;
		for (int j = 0; j < irvl.size(); j++){
			if (irvl[j].first >= l && irvl[j].second <= r) clr[j] = !clr[j]; else
			if (irvl[j].first < l && irvl[j].second > l) {
				irvl.push_back(pll(l, irvl[j].second));
				clr.push_back(clr[j]);
				irvl[j].second = l;
			}
			else
			if (irvl[j].first < r && irvl[j].second > r) {
				irvl.push_back(pll(r, irvl[j].second));
				clr.push_back(clr[j]);
				irvl[j].second = r;
				clr[j] = !clr[j];
			}
		}
	}
	for (int j = 0; j < irvl.size(); j++) if (!clr[j]) irvl[j] = pll(0, -1);
	sort(irvl.begin(), irvl.end());
 		n = 0;
		l = 0;
		for (int j = 0; j < irvl.size(); j++){
			r = irvl[j].second - irvl[j].first;
			if (!j || irvl[j].first == irvl[j - 1].second) l += r;
			else {
				if (l > n)  n = l;
				l = r;
			}
		}
		if (l > n)  n = l;
		out << n;
		return 0;
}