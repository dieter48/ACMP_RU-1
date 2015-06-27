#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
#define pii pair<int,int>
#define vi vector<int>
#define vpi vector<pii>
#define it vpi::iterator
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n, t, m, k;
	char c[50];
	map<string, pii> l = map<string,pii>();
	fscanf(inp, "%d", &n);
	vi mark = vi(n,0);
	for (int i = 0; i < n; i++) {
		fscanf(inp, "%s %d", c, &t);
		l[c] = pii(t,i);
	}
	fscanf(inp, "%d %d", &m, &k);
	vpi snglist = vpi();
	for (int i = 0; i < m; i++) {
		fscanf(inp, "%s", c);
		snglist.push_back(l[c]);
	}
	vi brck = vi();
	for (int i = 0; i < k; i++) {
		fscanf(inp, "%d", &t);
		brck.push_back(t);
	}
	t = 0;
	vi::iterator j = brck.begin();
	for (it i = snglist.begin(); i != snglist.end(); i++){
		if (j != brck.end() && *j >= t && *j < (i->first + t)){
			mark[i->second]--;
			t = *j;
			j++;
		}
		else{
			mark[i->second]++;
			t += i->first;
		}
	}
	for (j = mark.begin(); j != mark.end(); j++)
		fprintf(outp, "%d ", *j);
	fprintf(outp, "\n");
	fclose(outp);
	return 0;
}