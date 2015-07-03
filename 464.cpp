#include<fstream>
using namespace std;

int f(long n){
	if (!n) return 0;
	long k = n>>1, p = 1;
	while (k){
		k >>= 1;
		p <<= 1;
	}
	return (f(n % p) + 1) % 3; 
}
int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	long n;
	in >> n;
	out << f(n - 1);
	return 0;
}