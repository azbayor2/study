#include <queue>
#include <stack>
#include <string>
#include "Graph.hpp" // Graph 클래스 포함

using namespace std;

// BFS (너비 우선 탐색)
template <typename T>
void BFS(Graph<T> g, int start) {
    vector<bool> is_visited = vector<bool>(g.get_size(), false);
    std::queue<int> _queue = std::queue<int>();

    cout << "너비 우선 탐색(BFS) 방문 순서: " << endl;
    cout << g.get_value(start) << " -> ";
    is_visited[start] = true;
    _queue.push(start);
    while (!_queue.empty()) {
        int index = _queue.front();
        _queue.pop();

        for (int i = 0; i < g.get_size(); i++) {
            if (g.is_edge(index, i) && !is_visited[i]) {
                cout << g.get_value(i) << " -> ";
                is_visited[i] = true;
                _queue.push(i);
            }
        }
    }
    cout << "end" << endl;
}

// DFS (깊이 우선 탐색)
template <typename T>
void DFS(Graph<T> g, int start) {
    vector<bool> is_visited = vector<bool>(g.get_size(), false);
    std::stack<int> _stack = std::stack<int>();

    cout << "깊이 우선 탐색(DFS) 방문 순서: " << endl;
    _stack.push(start);
    while (!_stack.empty()) {
        int index = _stack.top();
        _stack.pop();
        
        if (!is_visited[index]) {
             cout << g.get_value(index) << " -> ";
             is_visited[index] = true;
        }

        for (int i = g.get_size() - 1; i >= 0; i--) {
            if (g.is_edge(index, i) && !is_visited[i])
                _stack.push(i);
        }
    }
    cout << "end" << endl;
}

int main() {
    Graph<string> g = Graph<string>();

    g.add_node("민수"); // 0
    g.add_node("지향"); // 1
    g.add_node("문정"); // 2
    g.add_node("지현"); // 3
    g.add_node("일상"); // 4
    g.add_node("선민"); // 5
    g.add_node("시은"); // 6

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 4);
    g.add_edge(1, 3);
    g.add_edge(3, 0);
    g.add_edge(3, 5);
    g.add_edge(3, 6);
    g.add_edge(6, 1);

    g.print_adj();
    
    BFS(g, 0);
    cout << endl;

    DFS(g, 0);
    cout << endl;

    return 0;
}