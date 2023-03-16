#include <bits/stdc++.h>
using namespace std;

class DisJointSet
{

public:
    vector<int> parent, size;
    DisJointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ultimateParent_u = findUPar(u);
        int ultumateParent_v = findUPar(v);

        if (ultimateParent_u == ultumateParent_v)
        {
            return;
        }
        if (size[ultimateParent_u] < size[ultumateParent_v])
        {
            parent[ultimateParent_u] = ultumateParent_v;
            size[ultumateParent_v] += size[ultimateParent_u];
        }
        else
        {
            parent[ultumateParent_v] = ultimateParent_u;
            size[ultimateParent_u] += size[ultumateParent_v];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> mailNode;
        int n = accounts.size();
        DisJointSet ds(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mailNode.find(mail) == mailNode.end())
                    mailNode[mail] = i;
                else
                    ds.unionBySize(i, mailNode[mail]);
            }
        }

        vector<string> mergeMail[n];
        for (auto it : mailNode)
        {
            string mail = it.first;
            int pa = ds.findUPar(it.second);
            mergeMail[pa].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergeMail[i].size() == 0)
                continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergeMail[i])
                temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};