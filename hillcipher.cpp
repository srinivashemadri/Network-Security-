#include<bits/stdc++.h>
#define ll long long
using namespace std;
double result[100][3]={0};

string multiplyandgivetext(double textmatrix[][3], double keymatrix[3][3],int numofcols )
{
    int r1=3,c1=3,r2=3,c2=numofcols;
    
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            ll int res=0;
            for(int k=0;k<c1;k++){
                res += keymatrix[i][k]*textmatrix[k][j];
            }
                
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
string decryptciphertext(double keymatrix[3][3],int cols)
{
    double invofkeymatrix[3][3]={4,9,15,15,17,6,24,0,17};
    double ciphermatrix[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<cols;j++)
            ciphermatrix[i][j] = result[i][j];
    }
    
    return multiplyandgivetext(ciphermatrix,invofkeymatrix,cols);

}
void hillcypher(string text)
{
    double keymatrix[3][3]={17,17,5,21,18,21,2,2,19},textmatrix[100][3];
    int it=0;
    
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
    string encryptedmessage = multiplyandgivetext(textmatrix,keymatrix,numofcols);
    cout<<"encrypted message = "<<encryptedmessage<<endl;
    string decryptedmessage = decryptciphertext(keymatrix,text.length()/3);
    cout<<"decrypted message = "<<decryptedmessage<<endl;
}
int main()
{

    string text;
    cout<<"Enter plain text of length which is multiples of 3 \n";
    cin>>text;
    if(text.length()%3 == 0)
        hillcypher(text);
    else
        cout<<"Plain text is not multiples of 3\n";
}