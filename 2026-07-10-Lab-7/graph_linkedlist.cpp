#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
void addEdge(vector<vector<pair<int,int>>>& adjList, int u, int v, int weight) {
    adjList[u].push_back({v, weight});
}

// Dijkstra's Algorithm
void dijkstra(const vector<vector<pair<int,int>>>& adjList, int src) {
    int V = adjList.size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    cout << src <<"\n";

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we found a shorter path to 'u' , skip it
        if (d > dist[u]) continue;

        cout << "Locked in Vertex" << u << " (Shortest distance: "<< d << ")\n";

        // Check all neighbor vertices of u
        for (int i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i].first;
            int weight = adjList[u][i].second;

            // If the path through 'u' is shorter than v
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                cout << "  -> Found shorter path to " << v << " : new distance is " << dist[v] << "\n";
            }
        }
    }

    cout << "\n--Final Shortest Distances--\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Vertex " << src << " to Vertex " << i << " : Unreachable\n";
        } else {
            cout << "Vertex " << src << " to Vertex " << i << " : " << dist[i] << "\n";
        }
    }
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adjList(V);
    addEdge(adjList, 0, 1, 4);
    addEdge(adjList, 0, 2, 8);
    addEdge(adjList, 1, 4, 6);
    addEdge(adjList, 1, 2, 3);
    addEdge(adjList, 2, 3, 2);
    addEdge(adjList, 3, 4, 10);
    dijkstra(adjList, 0);
    return 0;
}