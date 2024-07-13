#include <bits/stdc++.h>
using namespace std;

int knapsack(int N, int W, vector<int>& weights, vector<int>& values, vector<int>& dependencies, vector<int>& categories, vector<int>& limits) {
    // Dependency graph and in-degree count
    vector<vector<int> > dependents(N);
    vector<int> inDegree(N, 0);
    
    for (int i = 0; i < N; ++i) {
        if (dependencies[i] != -1) {
            dependents[dependencies[i]].push_back(i);
            inDegree[i]++;
        }
    }

    // Topological sort to handle dependencies
    vector<int> topoOrder;
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);
        for (int v : dependents[u]) {
            if (--inDegree[v] == 0) q.push(v);
        }
    }

    // Initialize DP array
    vector<int> dp(W + 1, 0);
    vector<int> categoryTaken(*max_element(categories.begin(), categories.end()) + 1, -1);

    // Process each item in topological order
    for (int i : topoOrder) {
        if (categoryTaken[categories[i]] != -1) continue;

        vector<int> currentDP = dp;
        for (int k = 1; k <= limits[i]; ++k) {
            for (int w = W; w >= k * weights[i]; --w) {
                dp[w] = max(dp[w], currentDP[w - k * weights[i]] + k * values[i]);
            }
        }
        
        // Mark the category as taken
        categoryTaken[categories[i]] = i;
    }

    return dp[W];
}

int main() {
    int N = 10;
    int W = 100;
    vector<int> weights = {10, 20, 30, 40, 15, 25, 35, 45, 55, 50};
    vector<int> values = {60, 100, 120, 240, 150, 90, 200, 170, 250, 300};
    vector<int> dependencies = {-1, 0, -1, 2, -1, -1, 1, 4, -1, 7}; // Items 1 depends on 0, 3 depends on 2, 6 depends on 1, 7 depends on 4, 9 depends on 7
    vector<int> categories = {1, 0, 0, 1, 2, 2, 3, 3, 4, 4}; // Categories constrain the selection to at most one item per category
    vector<int> limits = {1, 2, 1, 1, 1, 1, 1, 1, 1, 1}; // Maximum times each item can be taken

    int result = knapsack(N, W, weights, values, dependencies, categories, limits);
    cout << "Maximum Knapsack Value: " << result << endl;
    return 0;
}
