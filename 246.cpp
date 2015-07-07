#include <fstream>
using namespace std;
int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, t[2], k = 0;
	in >> n;
	for (int i = 0; i < n; i++){
		in >> t[i % 2];
		if (i && t[(i + 1) % 2] + 1 != t[i % 2]) k++;
	}
	out << k;
}