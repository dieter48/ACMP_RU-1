#include<iostream>
#include<vector>
#include<algorithm>
#define pii pair<int,int>
#define vi vector<pii>
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n, t, k;
	fscanf(inp, "%d", &n);
	vi a = vi(n);
	for (int i = 0; i < n; i++)
	{
		fscanf(inp, "%d", &t);
		a[i] = pii(t, i + 1);
	}
	sort(a.begin(), a.end());
	t = min(a[0].first, a[1].first);
	n = a[1].first - a[0].first;
	k = 1;
	for (int i = 1; i < a.size(); i++){
		if (((a[i].first - a[i - 1].first) < n)
		||  ((a[i].first - a[i - 1].first) == n && min(a[i].first, a[i - 1].first) < t)){
			t = min(a[i].first, a[i-1].first);
			n = a[i].first - a[i-1].first;
			k = i;
		}
	}
	if (a[k].first < a[k - 1].first){
		t = a[k - 1].second;
		k = a[k].second;
	}
	else{
		t = a[k].second;
		k = a[k - 1].second;
	}

	fprintf(outp, "%d\n%d %d\n", n, k , t);
	fclose(outp);
	return 0;
}