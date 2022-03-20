#include <iostream>
#include <math.h>
using namespace std;

// 터렛 문제 함수
int calcul(int x1, int y1, int r1, int x2, int y2, int r2);

int main() {
    int T, x1, x2, y1, y2, r1, r2;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        cout << calcul(x1, y1, r1, x2, y2, r2) << endl;
    }
    return 0;
}

int calcul(int x1, int y1, int r1, int x2, int y2, int r2) {
    double dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    if (dist > (r1 + r2)) {
        return 0;
    }
    else if (dist == (r1 + r2)) {
        return 1;
    }
    else {      // dist < (r1 + r2)
        if (r1 > r2) {
            if ((dist + r2) > r1) {
                return 2;
            }
            else if ((dist + r2) == r1) {
                return 1;
            }
            else {      // (dist + r2) < r1
                return 0;
            }
        }
        else if (r1 == r2) {
            if ((dist + r2) > r1) {
                return 2;
            }
            else if ((dist + r2) == r1) {
                return -1;
            }
        }
        else {      // r1 < r2
            if ((dist + r1) > r2) {
                return 2;
            }
            else if ((dist + r1) == r2) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    return -1;
}