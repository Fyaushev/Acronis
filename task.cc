#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
	if(argc < 2) {
		printf("ERROR \n");
		return 0;
	}
	const string pattern = argv[1];
	string s = pattern;
	int n = (int) s.length();
	vector<int> pi (n);
	int ans = 0;
	pi[0] = 0;
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	for(;;){
		char ch;
		ch = getchar();
		if(ch == '\n') break;
		int j = ans;
		while (j > 0 && ch != s[j])
			j = pi[j-1];
		if (ch == s[j])  ++j;
		ans = j;

		printf("%c", ch);
		if(ans == n){
			printf("*");
			ans = 0;
		}
	}
	printf("\n");
	return 0;
}

