//필요 개념 : 다익스트라, 비트마스크, 조합
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#define MAX 999999999

std::priority_queue<std::pair<int, std::pair<int, int> > > pq;//dist, node, bit
std::vector<std::pair<int, int> > g_map[1025][1000]; //node, cost
std::map<int, int> trap_map;
std::vector<std::vector<int> > g_road;

int trap_size;
int dist[1025][1001];

bool is_trap(int a) {
    if(trap_map.find(a) != trap_map.end())
        return (1);
    return (0);
}

bool trap_check(int a, int bitmask) {
    if (is_trap(a) && (bitmask & (1 << trap_map[a])))
        return (1);
    return (0);
}

void combination(int max_depth, int depth, int index, int bitmask) {
	if (max_depth == depth) {
		for (auto &i : g_road) {
			int a = i[0];
			int b = i[1];
			int cost = i[2];
			// 현재 트랩인데 다음 것이 트랩이 아닌 경우, 또는 현재 트랩이 아닌데, 다음 것이 트랩인 경우
			if ((trap_check(a, bitmask) && (!trap_check(b, bitmask))) || 
					(!trap_check(a, bitmask)) && (trap_check(b, bitmask)))
				g_map[bitmask][b].push_back({a, cost});
			else
				g_map[bitmask][a].push_back({b, cost});
		}
	}
	for (int i = index ; i < trap_size ; i++) {
		combination(max_depth, depth + 1, i + 1, bitmask | (1 << i) );
	}
}

int solution(int n, int start, int end, std::vector<std::vector<int>> roads, std::vector<int> traps)
{
	int answer = 0;
	int num = 0;
	trap_size = traps.size();
	std::memset(dist, 0x3f, sizeof(dist)); // 무한대로 초기화
	g_road = roads;
	// trap에 번호 부여. 예를 들면, 첫 번째 트랩이 10이면 {10 : 0}
	for (auto &i : traps){
		trap_map[i] = num++;
	}
	//만약 함정을 밟으면, 엣지의 방향이 바뀌므로 미리 다 저장해놓는다.
	for (int i = 0 ; i <= trap_size ; i++) {
		combination(i, 0, 0, 0);
	}
	pq.push({0, {start, 0}});
	while (!pq.empty()){
		int distance = -pq.top().first;
		int node = pq.top().second.first;
		int bit = pq.top().second.second;
		pq.pop();
		if (dist[bit][node] < distance)
			continue;
		for (auto &i : g_map[bit][node]) {
			int next = i.first;
			int next_distance = i.second;
			// 다음것이 트랩일때
			if (is_trap(next)) {
				if (bit & (1 << trap_map[next])) { // 트랩을 밟아왔는데, 다음 꺼가 이미 밟았던 트랩이면
					int next_bit = bit ^ (1 << trap_map[next]);
					if (dist[next_bit][next] < distance + next_distance)
				    		continue;
					dist[next_bit][next] = distance + next_distance;
					pq.push({-(distance + next_distance), {next, next_bit}});
				}
				else {
					int next_bit = bit | 1 << trap_map[next];
					if (dist[next_bit][next] < distance + next_distance)
						continue;
					dist[next_bit][next] = distance + next_distance;
					pq.push({-(distance + next_distance), {next, next_bit}});
				}
			}
			else {
				if (dist[bit][next] < distance + next_distance)
					continue;
				dist[bit][next] = distance + next_distance;
				pq.push({-(distance + next_distance), {next, bit}});
			}
		}
	}
	answer = MAX;
	for (int i = 0 ; i < 1024 ; i++)
		if (answer > dist[i][end])
			answer = dist[i][end];
	return answer;
}
