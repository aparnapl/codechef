#include<iostream>
#include<stack>
#include<cstring>

using namespace std;
int main()
{   int i;
   char c;
   string str;
 stack <char> s;
   cin>>str;
    for(i=0;i<str.length();++i)
    {
    if(s.size()==0)
        s.push(str[i]);
    else if(s.top()==str[i])
        s.pop();
    else
        s.push(str[i]);

    }
    if(s.size()!=0)
        cout<<"No";
    else
        cout<<"Yes";
}

