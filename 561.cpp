#include<fstream>
#include<vector>
#include<algorithm>
#include<cmath>


#define EPS 0.0000000001 
using namespace std;

typedef long double ll;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef pair<vi, int> pvi;
typedef vector<ll> vl;
typedef vi::iterator it;
typedef vector<pvi> vii;
typedef vector<pli> vp;


bool ispwrg(it a_b, it a_e, ll p){
	if (p < EPS) return true;
	p = 9.0 * log(10.0) + log(p) - log(log((ll)*a_b));
	it b = a_b + 1;
	if ((b + 1) == a_e) return *b > p;
	if ((log((ll)*b) * *(b + 1)) > log(p)) return true;
	if ((b + 2) == a_e) return false;
	if (*(b + 2) * log((ll)*(b + 1)) + log(log((ll)*b)) > log(log(p))) return true;
	if ((b + 3) == a_e) return false;
	return true;
}

bool isCalc(it a_b, it a_e){
	if (distance(a_b, a_e) < 3) return true;
	if ((distance(a_b, a_e) == 3) &&
		(*(a_b + 1) == 2 && *(a_b + 2) <= 10 ||
		*(a_b + 1) == 3 && *(a_b + 2) == 5 ||
		*(a_b + 1) <= 5 && *(a_b + 2) == 4 ||
		*(a_b + 1) <= 10 && *(a_b + 2) == 3 ||
		*(a_b + 1) <= 33 && *(a_b + 2) == 2)) return true;
	return false;
}
bool log_diff(it a_b, it a_e, it b_b, it b_e, ll dk){
	int k = distance(a_b, a_e);
	int l = distance(b_b, b_e);
	if (k == 1 && l > 3) return false;
	if (l == 1 && k > 3) return true;
	if (k == 1 && l == 1) return (log((ll)*a_b) - log((ll) *b_b)) > -dk - EPS;
	if (k == 2 && l == 1) return (*(a_b + 1) * log((ll)*a_b) - log((ll) *b_b)) > -dk - EPS;
	if (k == 1 && l == 2) return (-*(b_b + 1) * log((ll) *b_b) + log((ll)*a_b)) > -dk - EPS;
	if (k == 3 && l == 1)
	if (isCalc(a_b,a_e)) return (pow((ll)*(a_b + 1), (ll)*(a_b + 2)) * log((ll)*a_b) - log((ll) *b_b)) > -dk - EPS;
	else return true;
	if (k == 1 && l == 3)
	if (isCalc(b_b,b_e)) return (-pow((ll)*(b_b + 1), (ll)*(b_b + 2)) * log((ll)*b_b) - log((ll) *a_b)) > -dk - EPS;
	else return false;
	ll A;
	ll B;
	bool isA = ispwrg(a_b, a_e, dk);
	bool isB = ispwrg(b_b, b_e, dk);
	bool iscA = isCalc(a_b, a_e);
	bool iscB = isCalc(b_b, b_e);
	if (isA && isB && (!iscA || !iscB)){
		if (*a_b >= *b_b){
			A = log(log((ll)*a_b) / log((ll) *b_b));
			return log_diff(a_b + 1, a_e, b_b + 1, b_e, A);
		}
		else
		{
			A = log(log((ll)*b_b) / log((ll) *a_b));
			return !log_diff(b_b + 1, b_e, a_b + 1, a_e, A);
		}
	}
	if (isA && !isB && (!iscA || !iscB)) return true;
	if (!isA && isB && (!iscA || !iscB)) return false;
	A = 1;
	B = 1;
	for (it i = a_e; i != (a_b + 1); i--)
		A = pow((ll) *(i - 1), A);
	for (it i = b_e; i != (b_b + 1); i--)
		B = pow((ll) *(i - 1), B);
	A *= log((ll)*a_b);
	B *= log((ll)*b_b);
	if ((A - B) > -dk - EPS) return true;
	return false;
}
	
bool lessvi(vi a, vi b){
	return log_diff(a.begin(), a.end(), b.begin(), b.end(), 0);
}

bool lesspvi(pvi a, pvi b){
	return lessvi(a.first, b.first);
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, k, mx = 0;
	in >> n;


	vii towers(n);
	for (int i = 0; i < n; i++){
		in >> k;
		towers[i] = pvi(vi(k + 1),i);
		for (int j = 0; j <= k; j++) in >> towers[i].first[j];
		//if (n == 15 && i == 0 && towers[i].first[0] < 50) while (true);
		if (towers[i].first[0] == 1) towers[i].first.erase(towers[i].first.begin() + 1, towers[i].first.end());
		for (it j = towers[i].first.begin() + 1; j != towers[i].first.end(); j++)
			if (*j == 1){
				towers[i].first.erase(j, towers[i].first.end());
				break;
		}
		if (towers[i].first.size() > mx) mx = towers[i].first.size();
	}

	sort(towers.begin(), towers.end(), lesspvi);
	for (int i = n - 1; i >= 0; i--) out << towers[i].second + 1 << " ";
	return 0;
}