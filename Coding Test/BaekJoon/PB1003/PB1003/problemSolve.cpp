#include <iostream>
#define MAX 40
using namespace std;

struct zeroone {
	bool stored;
	int zeros;
	int ones;
};

zeroone fibo[MAX] = { 0 };

void fibonacci(int n);

int main() {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		fibonacci(N);
		cout << fibo[N].zeros << " " << fibo[N].ones << endl;
	}
	return 0;
}

void fibonacci(int n) {
	int i = 0;
	if (!fibo[n].stored) {
		while (i <= n) {
			if (i == 0 && !fibo[i].stored) {
				fibo[i].stored = true;
				fibo[i].zeros++;
			}
			else if (i == 1 && !fibo[i].stored) {
				fibo[i].stored = true;
				fibo[i].ones++;
			}
			else {
				if (!fibo[i].stored) {
					fibo[i].stored = true;
					fibo[i].zeros = fibo[i - 1].zeros + fibo[i - 2].zeros;
					fibo[i].ones = fibo[i - 1].ones + fibo[i - 2].ones;
				}
			}
			i++;
		}
	}
}