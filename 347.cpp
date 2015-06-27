#include<iostream>
using namespace std;

int main(){
	FILE* inp = fopen("input.txt", "r");
	FILE* outp = fopen("output.txt", "w");
	int n[15], i, t, cnt2 = 0, cnt345 = 0, str = 0;
	for (i = 0; i < 15; i++) n[i] = 0;
	for (i = 0; i < 5; i++){
		fscanf(inp, "%d", &t);
		n[t]++;
	}
	for (i = 1; i < 15; i++)
		if (n[i] == 2) cnt2++;
		else if (n[i] > 2) cnt345 = n[i];
		else if (n[i - 1] && n[i]) str++;
	
	if (cnt345 == 5) fprintf(outp, "Impossible\n"); else
	if (cnt345 == 4) fprintf(outp, "Four of a Kind\n"); else
	if (cnt345 == 3 && cnt2 == 1) fprintf(outp, "Full House\n"); else
	if (cnt345 == 3) fprintf(outp, "Three of a Kind\n"); else
	if (cnt2 == 2) fprintf(outp, "Two Pairs\n"); else
	if (cnt2 == 1) fprintf(outp, "One Pair\n"); else
	if (str == 4) fprintf(outp, "Straight\n"); else
	fprintf(outp, "Nothing\n");
	fclose(outp);
	return 0;
}