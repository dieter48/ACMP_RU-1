#include <fstream>
#include <vector>
#include <numeric>
#define N 24 * 60
using namespace std;

class myClock{
	int hour, minute;
public:
	friend istream& operator>> (istream &in, myClock &t){
		in >> t.hour >> t.minute;
		return in;
	}
	bool operator==(myClock r){
		return hour == r.hour && minute == r.minute;
	}
	operator int(){
		return minute + hour * 60;
	}
	myClock &operator++(){
		minute++;
		if (minute == 60){ minute = 0; hour++;}
		if (hour == 24)  hour = 0; 
		return *this;
	}
};

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	myClock b, e;
	in >> n;
	vector<int> a(N, 1);
	for (int i = 0; i < n; i++) {
		in >> b >> e;
		for (myClock i = e; i != b; i++) a[i] = 0;
	}
	n = accumulate(a.begin(), a.end(), 0);
	out << n;
}