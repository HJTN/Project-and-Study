#include <iostream>
#include <cmath>
using namespace std;

int ionum;
void iocheck(int x1, int y1, int x2, int y2, int cx, int cy, int r);

int main() {
	int T, x1, y1, x2, y2, n, cx, cy, r;
	cin >> T;
	for (int i = 0; i < T;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		ionum = 0;
		for (int j = 0; j < n; j++) {
			cin >> cx >> cy >> r;
			iocheck(x1, y1, x2, y2, cx, cy, r);
		}
		cout << ionum << endl;
	}
	return 0;
}

// Function
void iocheck(int x1, int y1, int x2, int y2, int cx, int cy, int r) {
	double length1 = sqrt(pow((cx - x1), 2) + pow((cy - y1), 2));
	double length2 = sqrt(pow((cx - x2), 2) + pow((cy - y2), 2));
	if (r > length1 && r < length2)
		ionum++;
	else if (r < length1 && r > length2)
		ionum++;
}