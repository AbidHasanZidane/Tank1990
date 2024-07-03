
#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
#include <utility> // For pair
#include<math.h>
#include<random>
using namespace std;

const int MAP[30][30];
// �����ĸ������ҡ��¡����ϣ�˳ʱ�룩
const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// ���һ�������Ƿ�������Χ��
bool isValid(int x, int y, int m, int n) {
	return x >= 0 && x < m && y >= 0 && y < n;
}


class enermy {
private:
	static int number;
	const int HP = 3;
	const int ATK = 1;
	pair<int, int> position;
	enermy* player;
	double Range_find;
	int Direction;
	int Isobstacle[3];//�Ƿ�Ϊ�ϰ���/�ϰ�������
	vector<pair<int, int>>path;
	
	const int speed=4;
public:
	enermy(enermy* player) {
		number += 1;
		this->player = player;
		int Direction = rand()%4;
	}


	void update() {
		double distance = sqrt(((player->position.first - this->position.first)* (player->position.first - this->position.first)) + ((player->position.second - this->position.second)* (player->position.second - this->position.second)));
		if (distance <= Range_find) {
			this->TurnTowards();//�������Թ�������⣬�Եִ����λ��
			Moveto(path);
		}
		else {
			if (MAP[this->position.first+directions[Direction].first][this->position.second+directions[Direction].second] == 1) 
		//�������������һ�����ɾ���
			{

			}
		}
	}




	void Moveto(vector<pair<int, int>> path) {
		int current_index = 0;
		while (current_index < path.size() - 1) {
			// Ŀ��λ��
			pair<int,int> target = path[current_index + 1];

			// �ƶ�����һ��Ŀ��λ��
			while (this->position.first != target.first || this->position.second != target.second) {

				this->position = move_towards(this->position, target, speed_for_frame);

			}

			// ����Ŀ��λ������
			current_index++;
		}
	}




	void shortestPath(vector<vector<int>>& map) {
		int m = map.size();
		if (m == 0) return ; // ������Ч
		int n = map[0].size();

		// �������ȶ��У���С�ѣ�����Dijkstra�㷨
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

		// �������飬�洢����ÿ����Ԫ�����̾���
		vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
		// ���ڵ����飬���ڴ洢·��
		vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n, { -1, -1 }));

		// �������
		pq.push({ map[this->position.first][this->position.second], {this->position.first, this->position.second} });
		dist[this->position.first][this->position.second] = map[this->position.first][this->position.second];

		while (!pq.empty()) {
			int cost = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			// �����ǰ·�����۴��ڼ�¼�����·��������
			if (cost > dist[x][y]) continue;

			// ��������յ㣬��ǰ����
			if (x == player->position.first && y == player->position.second) break;

			// ̽�����ڽڵ�
			for (int i = 0; i < 4; ++i) {
				int new_x = x + directions[i][0];
				int new_y = y + directions[i][1];

				// ����������Ƿ��ڷ�Χ��
				if (isValid(new_x, new_y, m, n)) {
					int new_cost = cost + map[new_x][new_y];

					// ����ҵ��˸��̵�·�������¾��벢����������ȶ���
					if (new_cost < dist[new_x][new_y]) {
						dist[new_x][new_y] = new_cost;
						parent[new_x][new_y] = { x, y };
						pq.push({ new_cost, {new_x, new_y} });
					}
				}
			}
		}

		// �Ӹ��ڵ������ؽ����·��
		int x = player->position.first, y = player->position.second;
		path.clear();
		// �������Ч·������(x, y)
		if (parent[x][y] != make_pair(-1, -1)) {
			while (x != this->position.first || y != this->position.second) {
				path.push_back({ x, y });
				int new_x = parent[x][y].first;
				int new_y = parent[x][y].second;
				x = new_x;
				y = new_y;
			}
			path.push_back({ this->position.first, this->position.second });
			reverse(path.begin(), path.end()); // ��ת�Ի�ȡ����㵽�յ��·��
		}

	}
	void TurnTowards() {
		if (position != player->position) {
			void shortestPath(vector<vector<int>>&map);
		}
		else;//�����ײ
	};
};