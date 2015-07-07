#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class myTime
{
	int month, day, hour, minute;
public:
	myTime(){}
	~myTime(){}
	long operator-(myTime r);
	bool operator<(myTime r);
	friend istream &operator>>(istream &in, myTime &t);
};

bool myTime::operator<(myTime r){
	return r.month > month ||
		r.month == month && r.day > day ||
		r.month == month && r.day == day && r.hour > hour ||
		r.month == month && r.day == day && r.hour == hour && r.minute > minute;
}

long myTime::operator-(myTime r){
	long a = 0;
	if (*this < r) return -(r - *this);
	int d = r.day, m = r.month;
	a = (18 - r.hour - 1) * 60 + 60 - r.minute;
	while (m != month || d != day){
		d++;
		switch (m){
		case 2: if (d == 29) { m++; d = 1; } break;
		case 4: case 6: case 9: case 11: if (d == 31) { m++; d = 1; } break;
		default: if (d == 32) { m++; d = 1; }
		}
		a += 8 * 60;
	}
	a -= (18 - hour - 1) * 60 + 60 - minute - 1;
	return a;
}

istream &operator>>(istream &in, myTime &t){
	char c;
	in >> t.day >> c >> t.month >> c >> t.hour >> c >> t.minute;
	return in;
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	long n, l = 0;
	in >> n;
	vector<myTime> a(n);
	for (int i = 0; i < n; i++) in >> a[i];
	sort(a.begin(), a.end());
	for (int i = 1; i < n; i += 2){
		l += a[i] - a[i - 1];
	}
	out << l / 60 << ':';
	out.width(2);
	out.fill('0');
	out << fixed << l % 60;
}