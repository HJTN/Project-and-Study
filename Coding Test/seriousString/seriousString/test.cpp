#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == ' ') {
            j = 0;
            answer += s.at(i);
            continue;
        }
        if (j % 2)       // È¦¼ö
            if (s.at(i) >= 65 && s.at(i) <= 90) {
                answer += s.at(i) + 32;
            }
            else {
                answer += s.at(i);
            }
        else            // Â¦¼ö
            if (s.at(i) >= 97 && s.at(i) <= 122) {
                answer += s.at(i) - 32;
            }
            else {
                answer += s.at(i);
            }
        j++;
    }
    return answer;
}