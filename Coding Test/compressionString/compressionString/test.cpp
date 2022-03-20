#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(string s);
string compress(string s, int splitSize);
// Test Case
string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

int main() {
    cout << solution(s) << endl;

}

int solution(string s) {
    int answer = s.length();
    for (int i = 1; i <= (s.length() / 2); i++) {
        string result = compress(s, i);
        if (answer > result.length())
            answer = result.length();
    }
    return answer;
}

string compress(string s, int splitSize) {
    string temp = "";
    string comp = s.substr(0, splitSize);
    int sameC = 0;

    for (int i = splitSize; i < s.length(); i += splitSize) {
        bool check = true;

        for (int j = i, start = 0; j < (j + splitSize) && start < comp.length(); j++, start++) {
            if (j >= s.length()) {
                check = false;
                break;
            }
            else if (j < s.length() && s.at(j) != comp.at(start)) {
                check = false;
                break;
            }
        }
        if (check) {
            sameC++;
        }
        else {
            if (sameC > 0)
                temp += to_string(sameC + 1);
            for (int k = 0; k < comp.length(); k++)
                temp += comp.at(k);
            comp = s.substr(i, splitSize);
            sameC = 0;
        }
    }
    if (sameC > 0)
        temp += to_string(sameC + 1);
    for (int k = 0; k < comp.length(); k++)
        temp += comp.at(k);
    return temp;
}