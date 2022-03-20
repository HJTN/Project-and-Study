#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    bool prime;
    vector<int> primes;
    int index = 0;

    for (int i = 2; i <= n; i++) {
        prime = true;
        if (primes.size() > 0 && primes[index] * primes[index] == i)
            index++;
        int j = 0;
        while (j < index) {
            if (!(i % primes.at(j))) {
                prime = false;
                break;
            }
            j++;
        }
        if (prime) {
            primes.push_back(i);
        }
    }
    answer = primes.size();
    return answer;
}