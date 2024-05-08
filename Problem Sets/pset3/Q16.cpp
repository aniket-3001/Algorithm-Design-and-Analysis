#include <bits/stdc++.h>
using namespace std;

void dijkstra(unordered_map<int, vector<pair<int, int>>>& g, vector<int>& distance, int startNode) {
    vector<bool> processed(distance.size(), false);
    distance[startNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPq;
    minPq.push({0, startNode});
    while(!minPq.empty()) {
        auto curr = minPq.top(); minPq.pop();
        int currNodeDistance = curr.first;
        int currNodeLabel = curr.second;
        if(processed[currNodeLabel]) {
            continue;
        }
        processed[currNodeLabel] = true;
        for(auto& edge : g[currNodeLabel]) {
            int neighborNodeLabel = edge.first;
            int weight = edge.second;
            if(currNodeDistance + weight < distance[neighborNodeLabel]) {
                distance[neighborNodeLabel] = currNodeDistance + weight;
                minPq.push({distance[neighborNodeLabel], neighborNodeLabel});
            }
        }
    }
}

int shortestRouteWithRestriction(vector<int>& elevations, vector<vector<int>>& paths) {
    int n = elevations.size();
    vector<int> rising(n, INT_MAX);
    vector<int> falling(n, INT_MAX);

    unordered_map<int, vector<pair<int, int>>> risingGraph;
    unordered_map<int, vector<pair<int, int>>> fallingGraph;

    for(int i = 0; i < n; i++) {
        risingGraph[i] = vector<pair<int, int>>();
        fallingGraph[i] = vector<pair<int, int>>();
    }

    //construct graph with only rising/falling paths
    for(auto& path : paths) {
        if(path[1] > path[0]) {
            risingGraph[path[0]].push_back({path[1], path[2]});
        }
        else if(path[1] < path[0]) {
            fallingGraph[path[1]].push_back({path[0], path[2]});
        }
    }

    dijkstra(risingGraph, rising, 0);
    dijkstra(fallingGraph, falling, 0);

    int res = INT_MAX;
    
    for(int i = 1; i < n; i++) {
        if(rising[i] < INT_MAX && falling[i] < INT_MAX) {
            res = min(res, rising[i] + falling[i]);
        }
    }
    return res;
}

int main() {
    vector<int> elevations = {5,25,15,20,10};
    vector<vector<int>> paths = {{0, 1, 10}, {0, 2, 8}, {0, 3, 15}, {1, 3, 12}, {2, 4, 10}, {3, 4, 5}, {3, 0, 17}, {4, 0, 10}};
    cout << shortestRouteWithRestriction(elevations, paths) << endl;
    return 0;
}
