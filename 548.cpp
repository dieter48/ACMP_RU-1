#include <fstream>
#include <string>
using namespace std;
typedef  string::iterator it;
it& lessit(it &ab, it ae,it &bb, it be){
	it a = ab, b = bb;
	do{
		a++;
		b++;
	} while (a != ae && b != be && *a == *b);
	if (a == ae || b != be && *b < *a) return bb;
	return ab;
}
int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	string a, b;
	in >> a >> b;
	string::iterator ai = a.begin(), bi = b.begin();
	while (ai != a.end() || bi != b.end()){
		if (ai == a.end() || (bi != b.end() && *bi < *ai)) {
			out << *bi;
			bi++;
		}
		else
		if (bi != b.end() && *bi == *ai){
			it& t = lessit(ai, a.end(), bi, b.end());
			out << *t;
			t++;
		}
		else
		{
			out <<*ai;
			ai++;
		}
	}
}