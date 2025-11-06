class Solution {
public:
    vector<int>parent, size;

    void make_set (int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set (int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set (int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] <  size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c+1);
        size.resize(c+1);
        vector<bool>check(c+1, 1);

        map<int, deque<int>>mp;

        for (int i = 1; i <= c; i++) {
            make_set(i);
        }

        int si = connections.size();

        for (int i = 0; i < si; i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            union_set(u, v);
        }

        for (int i = 1; i <= c; i++) {
            mp[find_set(i)].push_back(i);
        }

        int siQ = queries.size();

        vector<int>res;

        for (int i = 0; i < siQ; i++) {
            int type = queries[i][0];
            int id = queries[i][1];

            if (type == 1) {
                if (check[id]) {
                    res.push_back(id);
                } else {
                    int root = find_set(id);
                    while (!mp[root].empty() && !check[mp[root].front()]) {
                        mp[root].pop_front();
                    }
                    if (mp[root].empty()) res.push_back(-1);
                    else {
                        res.push_back(mp[root].front());
                    }
                }
            } else {
                check[id] = 0;
            }
        }

        return res;
    }
};
