#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> keyarray,k1,k2,p10order,p8order;
vector<int> IP,EP,p4;
int s0[4][4],s1[4][4];
void print(string msg,vector<int> arr,int size)
{
    cout<<msg;
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void keygeneration(ll int key)
{
    p10order.resize(10);
    cout<<"Enter P10 Permutation array : ";
    for(int i=0;i<10;i++)
        cin>>p10order[i];
    p8order.resize(8);
    cout<<"Enter P8 Permutation array : ";
    for(int i=0;i<8;i++)
        cin>>p8order[i];
    keyarray.resize(10);
    for(int i=0;i<10;i++)
    {
        keyarray[9-i] = key%10;
        key /=10;
    }
    print("Entered key = ",keyarray,10);
    //p10 permutate
    
    vector<int> p10;
    for(int i=0;i<10;i++)
        p10.push_back(keyarray[p10order[i]-1]);
    print("P10 before LS-1 = ",p10,10);
    int startval = p10[0];
    for(int i=0;i<=3;i++)
        p10[i]=p10[i+1];
    p10[4]=startval;
    startval = p10[5];
    for(int i=5;i<=8;i++)
        p10[i]=p10[i+1];
    p10[9]=startval;
    print("P10 after LS-1 = ",p10,10);
    
    vector<int> p8;
    for(int i=0;i<8;i++)
        p8.push_back(p10[p8order[i]-1]);
    for(int i=0;i<8;i++)
        k1.push_back(p8[i]);
    print("K1 = ",k1,8);

    //K2
    int ls2[10];
    for(int i=0;i<=2;i++)
        ls2[i]=p10[i+2];
    ls2[3]=p10[0];
    ls2[4]=p10[1];
    for(int i=5;i<=7;i++)
        ls2[i]=p10[i+2];
    ls2[8]=p10[5];
    ls2[9]=p10[6];
    
    for(int i=0;i<8;i++)
        k2.push_back(ls2[p8order[i]-1]);
    print("K2 = ",k2,8);
}

vector<int> mydoxor(vector<int> a,vector<int> b)
{
    vector<int> result;
    for(int i=0;i<8;i++)
        result.push_back(a[i]^b[i]);
    return result;
}

vector<int> resultofsbox(vector<int> arr)
{
    int row,col;
    vector<int> result;
    result.resize(4);
    row = 2*arr[0] + arr[3];
    col = 2*arr[1] + arr[2];

    int a = s0[row][col];
    
    row = 2*arr[4] + arr[7];
    col = 2*arr[5] + arr[6];

    int b = s1[row][col];

    switch(a)
    {
        case 0: result[0]=0;
                result[1]=0;
                break;
        case 1: result[0]=0;
                result[1]=1;
                break;
        case 2: result[0]=1;
                result[1]=0;
                break;
        case 3: 
                result[0]=1;
                result[1]=1;
                break;
    }
    switch(b)
    {
        case 0: result[2]=0;
                result[3]=0;
                break;
        case 1: result[2]=0;
                result[3]=1;
                break;
        case 2: result[2]=1;
                result[3]=0;
                break;
        case 3: 
                result[2]=1;
                result[3]=1;
                break;
    }
    return result;
}

void encryptionordecryption(ll int text, bool encrption)
{
    cout<<"Enter Initial Permutation array : ";
    vector<int> ipp,epp,p4p,IIP;
    ipp.resize(8);epp.resize(8);p4p.resize(4);IIP.resize(8);
    for(int i=0;i<8;i++)
        cin>>ipp[i];
    cout<<"Enter E/P Array : ";
    for(int i=0;i<8;i++)
        cin>>epp[i];
    cout<<"Enter S0\n";
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cin>>s0[i][j];
    }
    cout<<"Enter S1\n";
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            cin>>s1[i][j];
    }
    cout<<"Enter p4 operation array : ";
    for(int i=0;i<4;i++)
        cin>>p4p[i];
    cout<<"Enter Inverse initial permutation : ";
    for(int i=0;i<8;i++)
        cin>>IIP[i];
    //Input is done
     
    int ptarray[8];
    
    for(int i=0;i<8;i++)
    {
        ptarray[7-i] = text%10;
        text /=10;
    }
    
    for(int i=0;i<8;i++)
        IP.push_back(ptarray[ipp[i]-1]);
    
    print("Initial Permutation of plain text = ",IP,8);
    
    
    for(int i=0;i<8;i++)
        EP.push_back(IP[3+epp[i]]) ;
    print("EP array after computing = ",EP,8);

    vector<int> epxork1,epxork2,result;
    if(encrption)
    {
        epxork1= mydoxor(EP,k1);
        print("EP XOR K1 = ",epxork1,8);
        result = resultofsbox(epxork1);
    }
    else{
        epxork2= mydoxor(EP,k2);
        print("EP XOR K2 = ",epxork2,8);
        result = resultofsbox(epxork2);
    }
    print("Result of S-boxes = ", result,4);
    for(int i=0;i<4;i++)
        p4.push_back( result[p4p[i]-1]);

    print("p4 array = ",p4,4);
    
    vector<int> result2;
    for(int i=0;i<4;i++)
        result2.push_back(IP[i]^p4[i]);
    
    print("XOR between 1st 4 bits of IP input and p4 = ", result2,4);
    
    vector<int> fn1;
    fn1.resize(8);

    for(int i=0;i<4;i++)
        fn1[i] = IP[4+i];
    for(int i=4;i<8;i++)
        fn1[i] = result2[i-4];
    
    print("FN Output 1st time : ",fn1,8);


    //fn for 2nd time

    for(int i=0;i<8;i++)
        EP[i]= (fn1[3+epp[i]]);
    print("EP array after computing = ",EP,8);
    
    if(encrption)
    {
    epxork2 = mydoxor(EP,k2);
    print("EP XOR K2 = ",epxork2,8);

    result = resultofsbox(epxork2);
    }
    else{
        epxork1 = mydoxor(EP,k1);
        print("EP XOR K1 = ",epxork1,8);

        result = resultofsbox(epxork1);
    }

    print("Result of S-boxes = ", result,4);

    for(int i=0;i<4;i++)
        p4[i] = (result[p4p[i]-1]);

    print("p4 array = ",p4,4);

    for(int i=0;i<4;i++)
        result2[i]=(fn1[i]^p4[i]);
    
    print("XOR between 1st 4 bits of IP input and p4 = ", result2,4);
    
    vector<int> fn2;
    fn2.resize(8);

    for(int i=0;i<4;i++)
        fn2[i] = result2[i];
    for(int i=4;i<8;i++)
        fn2[i] = fn1[i];
    
    print("FN Output 2nd time : ",fn2,8);
    vector<int> cipher;
    for(int i=0;i<8;i++)
        cipher.push_back(fn2[IIP[i]-1]);

    if(encrption)
        print("8 bit cipher text = ", cipher,8);
    else
        print("8 bit plain text = ", cipher,8);
    ipp.clear();epp.clear();p4p.clear();IIP.clear();
    IP.clear();EP.clear();p4.clear();
}
int main()
{
    ll int key;
    cout<<"Enter 10 bit key : ";
    cin>>key;
    keygeneration(key);
    int c;
    do
    {
        cout<<"Enter your choice : \n";
        cout<<"1.Encryption\n2.Decryption\n3.EXIT\n";
        cin>>c;
        ll int input;
        switch (c)
        {
        case 1: cout<<"Enter 8 bit plain text : ";
                cin>>input;
                encryptionordecryption(input,true);
                break;
        case 2: cout<<"Enter 8 bit cipher text : ";
                cin>>input;
                encryptionordecryption(input,false);
                break;
        }
    } while (c!=3);
}