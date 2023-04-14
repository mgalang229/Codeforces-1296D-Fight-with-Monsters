#include <bits/stdc++.h>
using namespace std;

/*

input:
6 2 3 3
7 10 50 12 1 8

solution:
a + b = 2 + 3 = 5

1 7 8 10 12 50 (sorted)

1 mod 5 = 1
7 mod 5 = 2
8 mod 5 = 3
10 mod 5 = 0 (so 5)
12 mod 5 = 2
50 mod 5 = 0 (so 5)

note: place the skips on the "last" part:

1:
1

7:
1 2 | 3 4 5 | 6 7

8:
1 2 | 3 4 5 | 6 7 8

10:
1 2 | 3 4 5 | 6 7 8 9 10

10 - 2 = 8
 8 - 3 = 5
 5 - 2 = 3
 3 - 3 = 0

12:
1 2 | 3 4 5 | 6 7 | 8 9 10 | 11 12

50:
1 2 | 3 4 5 | 6 7 | 8 9 10 | ... 40 | 41 42 43 44 45

*/

void test_case(int& tc) {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	int h[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		h[i] %= (a + b);
		if (h[i] == 0)
			h[i] += (a + b);
		h[i] = ((h[i] + a - 1) / a) - 1;
	}
	sort(h, h + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (k - h[i] < 0)
			break;
		++ans;
		k -= h[i];
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	// cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
