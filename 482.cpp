#include<fstream>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, k = 1, i = 1; 
	in >> n;
	while (n > k){
		i++;
		n -= k;
		if (i < 10) k++; else
		if (i < 100) k += 2; else
			k += 3;
	}
	i = 1;
	while (n > 3) {
		if (i < 10) n--; else
		if (i < 100) n -= 2; else
			n -= 3;
		i++;
	}
	if (n == 3 && i < 10){ n--; i++; }
	if (n == 2 && i < 10){ n--; i++; }
	if (n == 3 && i < 100){ n -= 2; i++; }
	if (n == 3) out << i % 10;
	if (n == 2 && i >= 100) out << (i % 100) / 10;
	if (n == 2 && i < 100) out << i % 10;
	if (n == 1 && i >= 100) out << i / 100;
	if (n == 1 && i >= 10 && i < 100) out << i / 10;
	if (n == 1 && i < 10) out << i;
	return 0;
}