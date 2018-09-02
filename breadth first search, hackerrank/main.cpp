#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<int> graph[n+1];
        int d,e;
        int i;
        for(i=0;i<m;i++)
        {
            cin>>d>>e;
            graph[d].push_back(e);
            graph[e].push_back(d);
        }
        int st;
        cin>>st;
        queue<int> q;
        q.push(st);
        int visited[n], res[n];

        for(i=1;i<=n;i++)
            {visited[i]=0; res[i]=0;}
        int u;
        visited[st]=1;
        int vis=1;
        vector<int> :: iterator it;

        while(q.empty()==false)
        {
            u=q.front();
            for(it=graph[u].begin(); it!=graph[u].end();it++)
            {
                if(visited[(*it)]==0)
                {
                    visited[(*it)]=1;
                    vis++;
                    res[(*it)]=res[u]+6;
                    q.push(*it);
                }
            }
            q.pop();
        }
        for(int s=1;s<=n;s++)
        {
           if(s!=st&&res[s]!=0)
                cout<<res[s]<<" ";
                 //cout<<s;
            if(res[s]==0&&s!=st)
                cout<<"-1 ";
        }
        cout<<"\n";
    }


    }
