#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<long> vi;
typedef vi::iterator it;
int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	vi a;
	long k;
	while (in >> k) a.push_back(k);
	sort(a.begin(), a.end());
	for (it i = a.begin() + 2; i != a.end(); i++)
	if ((*i - *(i - 1)) != (*(i - 1) - *(i - 2))) {
		out << "No";
		return 0;
	}
	out << "Yes";
		return 0;
}