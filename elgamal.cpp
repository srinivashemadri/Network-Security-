#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll int findprimitiveroot(ll int p)
{
    int count[p];
    for(int i=2;i<p;i++)
    {
        memset(count,0,sizeof(count));
        bool isprimitive = true;
        for(int j=1;j<p;j++)
        {
            long long int x = ((long long int)pow(i,j)%p);
            if(count[x] > 0)
            {
                isprimitive = false;
                break;
            }
            else
                count[x]++;
        }
        if(isprimitive)
            return i;
    }
    return -1;
}
ll int power(ll int base,ll int power,ll int mod)
{
    ll int res=1;
    for(int i=0;i<power;i++)
    {
        res = (res * base)%mod;
    }
    return res;
}
int main()
{
    ll int P,G,X,M,K;
    ll int r,c,y;

    cout<<"Enter a prime number : ";
    cin>>P;
    G = findprimitiveroot(P);
    //A=10;
    cout<<"Enter private key for user A : ";
    cin>>X;
    y= power(G,X,P);

    cout<<"Public key: "<<"["<<P<<","<<G<<","<<y<<"]\n";

    cout<<"Enter message: ";
    cin>>M;

    cout<<"Enter a random integer: ";
    cin>>K;
    //Encryption

    r = power(G,K,P);
    c = M*(power(y,K,P));

    cout<<"Cipher text = "<<"("<<r<<","<<c<<")\n";


    ll int recievedmessage = (c* power(r,P-1-X,P))%P;
    cout<<"Recieved message = "<<recievedmessage<<endl;
}
