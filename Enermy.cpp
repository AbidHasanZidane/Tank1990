
#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
#include <utility> // For pair
#include<math.h>
#include<random>
using namespace std;

const int MAP[30][30];
// 定义四个方向：右、下、左、上（顺时针）
const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// 检查一个坐标是否在网格范围内
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
	int Isobstacle[3];//是否为障碍物/障碍物类型
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
			this->TurnTowards();//类似于迷宫，最近解，以抵达玩家位置
			Moveto(path);
		}
		else {
			if (MAP[this->position.first+directions[Direction].first][this->position.second+directions[Direction].second] == 1) 
		//如果这个方块的下一个不可经过
			{

			}
		}
	}




	void Moveto(vector<pair<int, int>> path) {
		int current_index = 0;
		while (current_index < path.size() - 1) {
			// 目标位置
			pair<int,int> target = path[current_index + 1];

			// 移动到下一个目标位置
			while (this->position.first != target.first || this->position.second != target.second) {

				this->position = move_towards(this->position, target, speed_for_frame);

			}

			// 更新目标位置索引
			current_index++;
		}
	}




	void shortestPath(vector<vector<int>>& map) {
		int m = map.size();
		if (m == 0) return ; // 网格无效
		int n = map[0].size();

		// 创建优先队列（最小堆）用于Dijkstra算法
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

		// 距离数组，存储到达每个单元格的最短距离
		vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
		// 父节点数组，用于存储路径
		vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n, { -1, -1 }));

		// 设置起点
		pq.push({ map[this->position.first][this->position.second], {this->position.first, this->position.second} });
		dist[this->position.first][this->position.second] = map[this->position.first][this->position.second];

		while (!pq.empty()) {
			int cost = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();

			// 如果当前路径代价大于记录的最短路径，跳过
			if (cost > dist[x][y]) continue;

			// 如果到达终点，提前结束
			if (x == player->position.first && y == player->position.second) break;

			// 探索相邻节点
			for (int i = 0; i < 4; ++i) {
				int new_x = x + directions[i][0];
				int new_y = y + directions[i][1];

				// 检查新坐标是否在范围内
				if (isValid(new_x, new_y, m, n)) {
					int new_cost = cost + map[new_x][new_y];

					// 如果找到了更短的路径，更新距离并将其加入优先队列
					if (new_cost < dist[new_x][new_y]) {
						dist[new_x][new_y] = new_cost;
						parent[new_x][new_y] = { x, y };
						pq.push({ new_cost, {new_x, new_y} });
					}
				}
			}
		}

		// 从父节点数组重建最短路径
		int x = player->position.first, y = player->position.second;
		path.clear();
		// 如果有有效路径到达(x, y)
		if (parent[x][y] != make_pair(-1, -1)) {
			while (x != this->position.first || y != this->position.second) {
				path.push_back({ x, y });
				int new_x = parent[x][y].first;
				int new_y = parent[x][y].second;
				x = new_x;
				y = new_y;
			}
			path.push_back({ this->position.first, this->position.second });
			reverse(path.begin(), path.end()); // 反转以获取从起点到终点的路径
		}

	}
	void TurnTowards() {
		if (position != player->position) {
			void shortestPath(vector<vector<int>>&map);
		}
		else;//如果碰撞
	};
};