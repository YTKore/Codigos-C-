#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{
  int n,p,k,n1,x,y;
  while(cin>>n>>p>>k)
  {
    int cont=0,sum=0,sum1;
    vector<int>v,v1,v2,v3;
    n1=n;
    while(n1--)
    {
      cin>>x;
      v.push_back(x);
    }
    n1=n-1;
    while(n1--)
    {
      cin>>x>>y;
    }
    if(v[0]>p)
    v1.push_back(1);
    else
    v1.push_back(2);
    cont=v1[0];
    for(int i=1;i<n;i++)
    {
      if(v[i]<p)
      cont++;
      v1.push_back(cont);
    }
    /*for(int i=0;i<n;i++)
    cout<<v1[i]<<" ";
    cout<<endl;*/
    vector<int>::iterator low,upp;
    low=lower_bound(v1.begin(), v1.end(),k);
    upp=upper_bound(v1.begin(), v1.end(),k);
    sum+=(upp-low);
    v3=v1;
    //cout<<sum<<endl;
    int res;
    for(int i=1;i<n;i++)
    {
      if(v[i]>p)
      v2.push_back(1);
      else
      v2.push_back(2);
      cont=v2[0];
      if(v[i+1]>p)
      v2.push_back(cont);
      else
      v2.push_back(cont+1);
      if(v2[0]<v3[1])
      res=-1;
      else
      res=0;
      if(res==-1)
      k-=res;
      low=lower_bound(v1.begin(), v1.end(),k);
      upp=upper_bound(v1.begin(), v1.end(),k);
      sum1=upp-low;
      sum+=sum1;
      //cout<<sum1<<endl;
      if(sum1==0)
      {
        break;
      }
      v3=v2;
      v2.clear();
    }
    cout<<sum<<endl;
  }
}
