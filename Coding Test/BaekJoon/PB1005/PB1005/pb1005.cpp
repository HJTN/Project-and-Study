#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct node {
	int count = 0;
	vector<int> build;
} node;
int total;
// Functions
void ACM_craft(int n, int w, vector<node> &step, vector<node> backstep, vector<int> cost);

int main() {
	int t, n, k, x, y, w, cos;
	cin >> t;
	for (int i = 0;i < t;i++) {
		cin >> n >> k;
		total = 0;
		vector<int> cost(n + 1);
		vector<node> nextStep(n + 1);
		vector<node> backstep(n + 1);
		for (int j = 1;j <= n;j++) {
			cin >> cos;
			cost[j] = cos;
		}
		for (int j = 0;j < k;j++) {
			cin >> x >> y;
			nextStep[x].build.push_back(y);
			nextStep[y].count++;
			backstep[y].build.push_back(x);
		}
		cin >> w;
		ACM_craft(n, w, nextStep, backstep, cost);
		cout << total << endl;
	}
}

void ACM_craft(int n, int w, vector<node>& step, vector<node> backstep, vector<int> cost) {
	vector<bool> need_build(n + 1);
	queue<int> container;
	int check = 0;
	container.push(w);
	while (container.size() > 0) {
		int element = container.front();
		container.pop();
		if (!need_build[element]) {
			need_build[element] = true;
			check++;
			for (int i = 0;i < backstep[element].build.size();i++) {
				container.push(backstep[element].build[i]);
			}
		}
	}
	while (check > 0) {
		for (int i = 1;i < step.size();i++) {
			if (!step[i].count && need_build[i]) {
				container.push(i);
			}
		}
		if (container.size() == 1) {
			int element = container.front();
			container.pop();
			total += cost[element];
			for (int i = 0;i < step[element].build.size();i++) {
				step[step[element].build[i]].count--;
			}
			step[element].count = -1;
			check--;
		}
		else {
			int max = cost[container.front()];
			for (int i = 0;i < step[container.front()].build.size();i++) {
				step[step[container.front()].build[i]].count--;
			}
			step[container.front()].count = -1;
			container.pop();
			check--;
			while (container.size() > 0) {
				if (max < cost[container.front()])
					max = cost[container.front()];
				for (int i = 0;i < step[container.front()].build.size();i++) {
					step[step[container.front()].build[i]].count--;
				}
				step[container.front()].count = -1;
				container.pop();
				check--;
			}
			total += max;
		}
	}
}