#include<bits/stdc++.h>
using namespace std;
string multiplyandgiveciphertext(int textmatrix[][3], int keymatrix[3][3],int numofcols )
{
    int r1=3,c1=3,r2=3,c2=numofcols;
    int result[3][numofcols]={0};
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            int res=0;
            for(int k=0;k<c1;k++)
                res += keymatrix[i][k]*textmatrix[k][j];
            result[i][j] = res%26;
        }
    }
    string ciphertext="";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<numofcols;j++)
            ciphertext += char(result[i][j] + 'a');
    }
    return ciphertext;

}
string hillencrypt(string text,string key)
{
    int keymatrix[3][3],textmatrix[100][3];
    int it=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            char ch = key[it++];
            if(ch>='a' && ch <= 'z')
            {
                keymatrix[i][j] = int(ch-'a');
            }
            else if(ch>='A' && ch <= 'Z')
            {
                keymatrix[i][j] = int(ch-'A');
            }
            else
            {
                keymatrix[i][j]=-1;
            }
        }
    }
    int numofcols = text.length()/3;
    it=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<numofcols;j++)
        {
            char ch = text[it++];
            if(ch>='a' && ch <= 'z')
            {
                textmatrix[i][j] = int(ch-'a');
            }
            else if(ch>='A' && ch <= 'Z')
            {
                textmatrix[i][j] = int(ch-'A');
            }
            else
            {
                textmatrix[i][j]=-1;
            }
        }
    }
    return multiplyandgiveciphertext(textmatrix,keymatrix,numofcols);
}
int main()
{
    string key;
    cout<<"Enter a key of length 9"<<endl;
    cin>>key;
    if(key.length() == 9)
    {
        string text;
        cout<<"Enter plain text of length which is multiples of 3 \n";
        cin>>text;
        if(text.length()%3 == 0)
        {
            string encrypted = hillencrypt(text,key);
            cout<<"encrypted message = "<<encrypted<<endl;
        }
        else
        {
            cout<<"Plain text is not multiples of 3\n";
        }
        
    }
    else
    {
        cout<<"Key is not of length 9\n";
    }
    
}