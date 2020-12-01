void kmp_pre(char x[], int m, int next[]) {
	int i, j;
	j = next[0] = -1;
	i = 0;
	while (i < m) {
		while (-1 != j && x[i] != x[j]) j = next[j];
		next[++i] = ++j;
	}
}

void preKMP(char x[], int m, int KmpNext[]) {
	int i, j;
	j = KmpNext[0] = -1;
	i = 0;
	while (i < m) {
		while(-1 != j && x[i] != x[j]) j = KmpNext[j];
		if (x[++i] == x[++j]) KmpNext[i] = KmpNext[j];
		else KmpNext[i] = j;
	}
}

int KmpNext[10010];
int next[10010];

// 返回模式串的出现次数
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