#include<bits/stdc++.h>
using namespace std;
char tj[5][3],tk[5][3];
char j[5][5][5],k[5][5][5];
int f(char ch,char ch2)
{
    if(ch=='0')
    {
        if(ch2=='0')return 0;
        return 1;
    }
    if(ch=='1')
    {
        if(ch2=='1')return 2;
        return 3;
    }
}
int i,p,m,x,y,n;
string str[20],str2;
string f2(char ch)
{
    int num,test=4,rem;
    //cout<<ch<<endl;
    if(ch>='A'&&ch<='F')num=ch-'A'+10;
    else num=ch-'0';
    //cout<<num<<endl;
    string rslt;
    while(test--)
    {
        rem=num%2;
        num/=2;
        rslt.push_back(rem+'0');
    }

    reverse(rslt.begin(),rslt.end());
    cout<<rslt<<endl;
    return rslt;
}
int main()
{
    tj[0][0]='0',tk[0][0]='*';
    tj[0][1]='1',tk[0][1]='*';
    tj[1][0]='*',tk[1][0]='1';
    tj[1][1]='*',tk[1][1]='0';
    int y;
    while(cin>>str2)
    {
        y=1;
        reverse(str2.begin(),str2.end());
        y=0;
        printf("for y = %d\n",y);
        printf("format Q2 \\ Q1 Q0 ::: \n");
        memset(j,'*',sizeof(j));
        memset(k,'*',sizeof(k));
        n=str2.size();
        for(i=0;i<n;i++)
        {
            str[i]=f2(str2[i]);
        }

        for(i=0;i<n;i++)
        {
            x=f(str[i][0],str[i][1]);
            y=f(str[i][2],str[i][3]);
            for(p=0;p<4;p++)
            {
                j[p][x][y]=tj[str[i][p]-'0'][str[(i+1)%n][p]-'0'];
                k[p][x][y]=tk[str[i][p]-'0'][str[(i+1)%n][p]-'0'];
            }
        }
        for(i=0;i<4;i++)
        {
            cout<<"j"<<4-i-1<<endl;
            for(p=0;p<4;p++)
            {
                for(m=0;m<4;m++)
                {
                    cout<<j[i][p][m]<<" ";
                }
                cout<<endl;
            }
            cout<<"k"<<4-i-1<<endl;
            for(p=0;p<4;p++)
            {
                for(m=0;m<4;m++)
                {
                    cout<<k[i][p][m]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
