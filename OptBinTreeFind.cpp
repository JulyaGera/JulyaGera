//Оптимальне бінарне дерево пошуку (динамічне програмування)
#include <iostream>
using namespace std;
#define MAX 300
#define INF 0x3F3F3F3F
int m[MAX], sum[MAX];
int t[MAX][MAX];
//Входные частоты элементов храним в массиве m, в массиве sum будут
//храниться частичные суммы частот: sum[i]. Значения Ti,j будут xраниться в массиве t.
//Частичная сумма  возвращается функцией weight(i, j)
int weight(int i, int j)
{
	if (i > j) return 0;
	return sum[j] - sum[i - 1];
}
//Функция go(i, j) возвращает значение Ti, j.
int go(int i, int j)
{
	int k, temp;
	if (i > j) return 0;
	if (t[i][j] == INF)
	{
		for (k = i; k <= j; k++)
		{
			temp = go(i, k - 1) + go(k + 1, j) + weight(i, k - 1) + weight(k + 1, j);
			if (temp < t[i][j]) t[i][j] = temp;
		}
	}
	return t[i][j];
}
int main() {
	int n = 1; int i;
	while (n == 1) {
		cin >> n;
		memset(t, 0x3F, sizeof(t));
		for (i = 1; i <= n; i++)
			cin >> m[i], t[i][i] = 0;
		//Вычисляем частичные суммы массива m.
		for (sum[0] = 0, i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + m[i];
		//Вычисляем значение T1, n вызовом go(1, n) и печатаем его.
		go(1, n);
		cout << t[1][n] << endl;
	}
	system("pause");
}