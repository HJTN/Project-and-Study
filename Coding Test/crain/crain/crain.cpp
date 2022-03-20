#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> currentStack(vector<vector<int>> board) {
    vector<int> stackCount;
    int stack[30] = { 0 };

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (!board[i][j]) stack[j]++;
        }
    }

    for (int i = 0; i < board.size(); i++)
        stackCount.push_back(stack[i]);

    return stackCount;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> curStack = currentStack(board);
    vector<int> boundary;
    int answer = 0;

    for (int i = 0; i < moves.size(); i++) {
        // 한 열에 인형이 있는 경우
        if (curStack[moves[i]-1] != board.size()) {
            if (boundary.size() > 0 && boundary.back() == board[curStack[moves[i] - 1]][moves[i] - 1]) {
                answer += 2; boundary.pop_back();
                curStack[moves[i]-1]++;
            }
            else {
                boundary.push_back(board[curStack[moves[i] - 1]++][moves[i] - 1]);
            }
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    vector<int> moves = {1,5,3,5,1,2,1,4};

    cout << solution(board, moves) << endl;
}