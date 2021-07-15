#include <bits/stdc++.h>


using namespace std;


struct Node {
    string name;
    int depth;
};

typedef struct Node Node;


int main() {
    int m, n;
    map<string, vector<string>> graph;
    map<string, int> inDegree;

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        if (inDegree.find(a) == inDegree.end()) {
            inDegree[a] = 0;
        }
        if (inDegree.find(b) == inDegree.end()) {
            inDegree[b] = 0;
        }

        inDegree[a] = inDegree[a] + 1;

        if (graph.find(b) == graph.end()) {
            vector<string> v;
            graph[b] = v;
        }
        if (graph.find(a) == graph.end()) {
            vector<string> v;
            graph[a] = v;
        }

        graph[b].push_back(a);
    }

    map<int, vector<string>> outMap;
    queue<Node> que;
    int count;

    count = 0;

    for (auto it = inDegree.begin(); it != inDegree.end(); it++) {
        if (it->second == 0) {
            Node n;
            n.name = it->first;
            n.depth = 0;
            que.push(n);
            count++;

            if (outMap.find(n.depth) == outMap.end()) {
                vector<string> v;
                outMap[n.depth] = v;
            }
            outMap[n.depth].push_back(n.name);
        }
    }

    while (!que.empty()) {
        Node n;
        n = que.front();
        que.pop();

        for (string& name: graph[n.name]) {
            inDegree[name] -= 1;
            if (inDegree[name] == 0) {
                Node tmp;
                tmp.name = name;
                tmp.depth = n.depth + 1;
                que.push(tmp);
                count++;

                if (outMap.find(tmp.depth) == outMap.end()) {
                    vector<string> v;
                    outMap[tmp.depth] = v;
                }
                outMap[tmp.depth].push_back(tmp.name);
            }
        }
    }

    if (count == m) {
        cout << "false" << endl;
    }

    for (int i = 0; outMap.find(i) != outMap.end(); i++) {
        vector<string> names;
        names = outMap[i];

        sort(names.begin(), names.end());

        for (string& name: names) {
            cout << name << " ";
        }
    }
}