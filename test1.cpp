#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<string> dirstr(n);
        vector<bool> flag(n,true);
        for(int i=0;i<n;++i)
        {
            cin>>dirstr[i];
        }
        sort(dirstr.begin(),dirstr.end());
        for(int i=0;i<dirstr.size()-1;++i)
        {
            if(dirstr[i]==dirstr[i+1])
                flag[i]=false;
            else if((dirstr[i].size()<dirstr[i+1].size())
                    &&(dirstr[i]==dirstr[i+1].substr(0,dirstr[i].size()))
                    &&(dirstr[i+1][dirstr[i].size()]=='/'))
                    flag[i]=false;
        }
        for(int i=0;i<dirstr.size();++i)
        {
            if(flag[i])
                cout<<"mkdir -p "<<dirstr[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}