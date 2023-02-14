/// beginword="hit", endword="cog", wordlist="hot","dot","dog","lot","log","cog".
///hit->hot
///hot->dot,lot
///dog->log,cog
///ans=5, as -> hit->hot->dot->dog->cog, (only 1 letter can be changed at a time)
#include<bits/stdc++.h>
using namespace std;
int fun(string start,string end,vector<string>&wordlist)
{
    int count=0;
    unordered_set<string>word;
    auto it=find(wordlist.begin(),wordlist.end(),end);
    if(it==wordlist.end())return 0;///base condition
    int s=start.length();
    for(int i=0;i<wordlist.size();i++)word.insert(wordlist[i]);
    ///traversal of words present in word list
    queue<string>q;
    q.push(start);
    while(!q.empty())
    {
        count++;
        int d=q.size();
        for(int i=0;i<d;i++)
        {
            string temp=q.front();
            q.pop();
            for(int j=0;j<s;j++)
            {
                char c=temp[j];
                for(char a='a';a<='z';a++)
                {
                    temp[j]=a;
                    if(temp==end)return count+1;
                    if(word.find(temp)==word.end())continue;
                    word.erase(temp);///for no repetation of word
                    q.push(temp);
                }
                temp[j]=c;
            }
        }
    }
    return 0;
}
int main()
{
    string s1="hit";
    string s2="cog";
    vector<string>wordlist={"hot","dot","dog","lot","log","cog"};
    cout<<fun(s1,s2,wordlist);
}
