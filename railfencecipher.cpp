#include<bits/stdc++.h>
using namespace std;
char matrix[100][100];

void fillmatrix(string text,int key)
{
    
}

string encrypttext(string text,int key)
{
    int rows=key;
    int cols = text.length();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            matrix[i][j]='$';
    }
    int i=0,j=0;
    bool down=true;
    for(int k=0;k<cols;k++)
    {
        matrix[i][j]=text[k];
        if(down)
            i++;
        else
            i--;
        j++;
        if(i==rows)
        {
            i=rows-2;
            down = false;
        }
        if(i==-1)
        {
            i=1;
            down = true;
        }
    }
    string ciphertext="";
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(matrix[i][j] != '$')
                ciphertext += matrix[i][j];
        }
    }
    return ciphertext;
}

string decrypttext(string cipher,int key)
{
    int i=0,j=0;
    bool down=true;
    string decryptedtext="";
    for(int k=0;k<cipher.length();k++)
    {
        decryptedtext += matrix[i][j];
        if(down)
            i++;
        else
            i--;
        j++;
        if(i==key)
        {
            i=key-2;
            down = false;
        }
        if(i==-1)
        {
            i=1;
            down = true;
        }
    }
    return decryptedtext;
}

int main()
{
    string text,cipher,decryptedtext;
    cout<<"Enter the plain text: ";
    getline(cin,text);
    cout<<"Enter key: ";
    int key;
    cin>>key;
    cipher = encrypttext(text,key);
    cout<<"Encrypted text = "<<cipher<<endl;
    decryptedtext = decrypttext(cipher,key);
    cout<<"decrypted text = "<<decryptedtext;


}