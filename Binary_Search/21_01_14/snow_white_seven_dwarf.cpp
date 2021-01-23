#include <iostream>
#include <vector>
#define endl "\n"

int N,C,M;
std::vector<int> hats;
std::vector<std::pair<int, int> >pictures;

std::vector<std::pair<std::pair<int, int>, std::pair<int, int>seg_tree; // (the numbers of , range), (number, 

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}
void input()
{
	input_faster();
	std::cin >> N >> C;
	hats.resize(N);
	seg_tree.resize(2*N - 1. -1);
	for(size_t i = 0 ; i < N; i++)
		std::cin >> hats[i];
	std::cin >> M;
	pictures.resize(M);
	for(size_t i = 0 ; i < M ; i++)
		std::cin >> pictures[i].first >> pictures[i].second;
}

int make_children(int l_node, int r_node, int node)
{
	int l_node_avg = seg_tree[l_node].first.first / seg_tree[l_node].first.second;
	int r_node_avg = seg_tree[r_node].first.first / seg_tree[r_node].first.second;
	seg_tree[node].first.second = seg_tree[l_node].first.second + seg_tree[r_node].first.second;
	if (l_node_avg > r_node_avg)
	{
		seg_tree[node].first.first = seg_tree[l_node].first.first + seg_tree[r_node].first.first;
		
		int seg_tree[node].second = 
}

int make_segtree(int node, int start, int end)
{
	if (start == end)
	{
		seg_tree[node].second = hats[start];
		seg_tree[node].first.first = 1;
		seg_tree[node].first.second = 1;
		return (node);
	}
	else
	{
		seg_tree[node].first.second = end - start;
		make_children(make_segtree(node * 2, start, (start+end)/2), make_segtree(node * 2 + 1, (start+end)/2 + 1, end), node);
	}
}

int main()
{
	input();
	make_segtree();
	return (0);
}

