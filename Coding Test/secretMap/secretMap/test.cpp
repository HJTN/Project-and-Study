#include <iostream>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2);

int main() {
    int n = 5;
    vector<int> arr1 = { 9, 20, 28, 18, 11 };
    vector<int> arr2 = { 30, 1, 21, 17, 28 };
    vector<string> result = solution(n, arr1, arr2);
    for (int i = 0; i < result.size(); i++) {
        cout << result.at(i) << endl;
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<bool> a1b;
    vector<bool> a2b;
    string temp;

    for (int i = 0; i < n; i++) {
        temp = "";
        for (int a1 = arr1.at(i); a1 > 0; a1 /= 2) {
            if (a1 % 2)
                a1b.push_back(true);
            else
                a1b.push_back(false);
        }
        if (a1b.size() < n)
            for (int t = a1b.size(); t < n; t++)
                a1b.push_back(false);

        for (int a2 = arr2.at(i); a2 > 0; a2 /= 2) {
            if (a2 % 2)
                a2b.push_back(true);
            else
                a2b.push_back(false);
        }
        if (a2b.size() < n)
            for (int t = a2b.size(); t < n; t++)
                a2b.push_back(false);

        reverse(a1b.begin(), a1b.end());
        reverse(a2b.begin(), a2b.end());

        for (int boolc = 0; boolc < n; boolc++) {
            if (a1b.at(boolc) || a2b.at(boolc))
                temp += "#";
            else
                temp += " ";
        }
        answer.push_back(temp);
        a1b.clear();
        a2b.clear();
    }
    return answer;
}