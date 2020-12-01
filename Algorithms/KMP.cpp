void kmp_pre(char x[], int m, int next[]) {
	int i, j;
	j = next[0] = -1;
	i = 0;
	while (i < m) {
		while (-1 != j && x[i] != x[j]) j = next[j];
		next[++i] = ++j;
	}
}

int next[10010];

int KMP_Count(char x[], int m, char y[], int n) {
	int i, j;
	int ans = 0;
	kmp_pre(x, m, next);
	i = j = 0;
	while (i < n) {
		while (-1 != j && y[i] != x[j]) j = next[j];
		i++; j++;
		if (j >= m) {
			ans++;
			j = next[j];
		}
	}
	return ans;
}