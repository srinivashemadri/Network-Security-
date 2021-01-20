#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findgcd(int a,int b)
{
    int maxi = max(a,b);
    for(int i=2;i<maxi;i++)
    {
        if(a%i == 0 && b%i == 0)
            return i;
    }
    return 1;
}

int finde(int x)
{
    for(int i=2;i<x;i++)
    {
        if(findgcd(i,x) == 1)
        {
            return i;
        }
            
    }
    return -1;
}

int findd(int e,int piofn)
{
    for(int i=1;true;i++)
    {
        int exp = i*e;
        exp = exp%piofn;
        if(exp == 1)
            return i;
    }
    return -1;
}

int main()
{
   
    ll int msg;
    cout<<"Enter message(which is less than 21)\n";
    cin>>msg;
    ll int p=3,q=7;

    ll int n = p*q;
    int piofn = (p-1)*(q-1);

    //public key

    ll int e = finde(piofn);
    cout<<"Public key="<<e<<endl;

    //private key

    int d = findd(e,piofn);
    cout<<"Private key ="<<d<<endl;

    //encrytping message

    ll int cipher = ((ll int)pow(msg,e))%n;
    cout<<"cipher text = "<<cipher<<endl;

    //decrypting

    ll int message = ((ll int)pow(cipher,d))%n;
    cout<<"message = "<<message<<endl;

}