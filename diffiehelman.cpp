#include<bits/stdc++.h>
using namespace std;
int findprimitiveroot(int p)
{    int count[p];
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
void diffiehelman(int key)
{
    int alpha = findprimitiveroot(key);
    
    cout<<"Primitive root for "<<key<<" is = "<<alpha<<endl;
    bool conditionfailed;
    int pa,pb;
    do
    {
        cout<<"Enter private key for user-a: (Should be less than "<<key<<" ) ";
        cin>>pa;
        cout<<"Enter private key for user-b: (Should be less than "<<key<<" ) ";
        cin>>pb;
        if(pa >= key || pb >=key)
            conditionfailed = true;
        else if(pa<key && pb<key)
            conditionfailed = false;
        if(conditionfailed)
        {
            cout<<"Please note that private keys for both the users a and b should be less than key\n";
            cout<<"So please enter values of private keys for both the users again\n";
        }
    } while (conditionfailed);
    long long int keyga = ((long long int)pow(alpha,pa))%key;
    //cout<<"Key generated for user a = "<<keyga<<endl;

    long long int keygb = ((long long int)pow(alpha,pb))%key;
    //cout<<"Key generated for user b = "<<keygb<<endl;

    long long int gensecretkeya = ((long long int)pow(keygb,pa))%key;
    cout<<"Secret key for user-a = "<<gensecretkeya<<endl;
    long long int gensecretkeyb = ((long long int)pow(keyga,pb))%key;
    cout<<"Secret key for user-b = "<<gensecretkeyb<<endl;
}
bool isprime(int key)
{
    for(int i=2;i<=sqrt(key);i++)
    {
        if(key%i == 0)
            return false;
    }
    return true;
}
int main()
{
    A:
    int key;
    cout<<"Enter a prime number(less than 20)"<<endl;
    cin>>key;


    if(isprime(key))
    {
        diffiehelman(key);
    }
    else
    {
        cout<<"Key is not a prime number kindly reenter\n";
        goto A;
    }
    
    


}