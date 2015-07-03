#include<fstream>

using namespace std;

long f(long n){
	if (!n) return 0;
	if (n == 1) return 1;
	if (!(n % 2)) return f(n / 2);
	return f(n / 2) + f(n / 2 + 1);
}
int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	long n;
	in >> n;
	out << f(n);
}