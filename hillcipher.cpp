#include<bits/stdc++.h>
using namespace std;
double result[100][3]={0};

string multiplyandgivetext(double textmatrix[][3], double keymatrix[3][3],int numofcols )
{
    int r1=3,c1=3,r2=3,c2=numofcols;
    
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
string decryptciphertext(double keymatrix[3][3],int cols)
{
    double detvalue=0;
    detvalue += keymatrix[0][0]*((keymatrix[1][1]*keymatrix[2][2])-(keymatrix[2][1]*keymatrix[1][2]));
    detvalue -= keymatrix[0][1]*((keymatrix[1][0]*keymatrix[2][2])-(keymatrix[2][0]*keymatrix[1][2]));
    detvalue += keymatrix[0][2]*((keymatrix[1][0]*keymatrix[2][1])-(keymatrix[2][0]*keymatrix[1][1]));
    cout<<"detvalue="<<detvalue<<endl;
    double matrixofcofactors[3][3];
    matrixofcofactors[0][0] = +(keymatrix[1][1]*keymatrix[2][2])-(keymatrix[2][1]*keymatrix[1][2]);
    matrixofcofactors[0][1] = -(keymatrix[1][0]*keymatrix[2][2])-(keymatrix[2][0]*keymatrix[1][2]);
    matrixofcofactors[0][2] = +(keymatrix[1][0]*keymatrix[2][1])-(keymatrix[2][0]*keymatrix[1][1]);
    matrixofcofactors[1][0] = -(keymatrix[0][1]*keymatrix[2][2])-(keymatrix[2][1]*keymatrix[0][2]);
    matrixofcofactors[1][1] = +(keymatrix[0][0]*keymatrix[2][2])-(keymatrix[2][0]*keymatrix[0][2]);
    matrixofcofactors[1][2] = -(keymatrix[0][0]*keymatrix[2][1])-(keymatrix[2][0]*keymatrix[0][1]);
    matrixofcofactors[2][0] = +(keymatrix[0][1]*keymatrix[1][2])-(keymatrix[1][1]*keymatrix[0][2]);
    matrixofcofactors[2][1] = -(keymatrix[0][0]*keymatrix[1][2])-(keymatrix[1][0]*keymatrix[0][2]);
    matrixofcofactors[2][2] = +(keymatrix[0][0]*keymatrix[1][1])-(keymatrix[1][0]*keymatrix[0][1]);
    double adjointmatrix[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            adjointmatrix[i][j]=matrixofcofactors[j][i];
    }
    double inversematrix[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            inversematrix[i][j]=double(adjointmatrix[i][j]/detvalue);
            cout<<adjointmatrix[i][j]<<" ";
        }
        cout<<endl;
            

    }


    return multiplyandgivetext(result,inversematrix,cols);

}
void hillcypher(string text,string key)
{
    double keymatrix[3][3],textmatrix[100][3];
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
    string encryptedmessage = multiplyandgivetext(textmatrix,keymatrix,numofcols);
    cout<<"encrypted message = "<<encryptedmessage<<endl;
    string decryptedmessage = decryptciphertext(keymatrix,text.length()/3);
    cout<<"decrypted message = "<<decryptedmessage<<endl;
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
            hillcypher(text,key);
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