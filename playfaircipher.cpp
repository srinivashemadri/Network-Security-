#include<bits/stdc++.h>
using namespace std;
char matrix[5][5];
void generatekeytable(string key)
{    bool visited[26];
    memset(visited,false,sizeof(visited));
    int r=0,c=0;
    for(int i=0;i<key.length();i++)
    {
        visited[key[i]-'a']=true;
        matrix[r][c] = key[i];
        c++;
        if(c==5)
        {
            c=0;
            r++;
        }
    }  
    if(visited['j'-'a'])
        visited['i'-'a']=true;
    else
        visited['j'-'a']=true;
    for(int i=0;i<26;i++)
    {
        if(!visited[i])
        {
            char ch = (char)i+'a';
            matrix[r][c] = ch;
            c++;
            if(c==5)
            {
                c=0;
                r++;
            }
            if(r==6)
                break;
        }
    }
}
void print()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
string removespacesandconvert(string text)
{
    for(int i=0;i<text.length();i++)
        text[i] = tolower(text[i]);
    string temp = "";
    for(int i=0;i<text.length();i++)
    {
        if(text[i] != ' ')
            temp = temp+ text[i];
    }
    int len = temp.length();
    if(len%2 == 1)
        temp = temp + 'z';
    return temp;
}
pair<int,int> search(char ch)
{
    pair<int,int> result;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(ch == matrix[i][j])
            {
                result.first =i;
                result.second=j;
                return result;
            }

        }
    }
    return result;
}
string encrypt(string plaintext)
{
    int len = plaintext.length();
    string encryptedtext="";
    for(int i=0;i<len-1;i=i+2)
    {
        char a = plaintext[i];
        char b = plaintext[i+1];
        pair<int,int> posa = search(a);
        pair<int,int> posb = search(b);
        int xa=posa.first;
        int ya=posa.second;
        int xb=posb.first;
        int yb=posb.second;
        string tempenc="";
        if(xa == xb)
        {
            int temp;
            if(ya<yb)
            {
                temp = yb+1;
                if(yb == 4)
                    temp=0;
                tempenc+= matrix[xa][ya+1];
                tempenc+=matrix[xb][temp];
            }
            else if(yb<ya)
            {
                temp = ya+1;
                if(ya == 4)
                    temp=0;
                tempenc+=  matrix[xa][temp];
                tempenc+=matrix[xb][yb+1];
            }   
        }
        else if(ya == yb)
        {
            int temp;
            if(xa<xb)
            {
                temp = xb+1;
                if(xb == 4)
                    temp=0;
                tempenc+=  matrix[xa+1][ya];
                tempenc+=matrix[temp][ya];
            }
            else if(xb<xa)
            {
                temp = xa+1;
                if(xa == 4)
                    temp=0;
                tempenc+=  matrix[temp][ya];
                tempenc+= matrix[xb+1][yb];
            }   
        }
        else
        {
            tempenc+=  matrix[xa][yb];
            tempenc+=matrix[xb][ya];
        }
        encryptedtext += tempenc;
    }
    return encryptedtext;
}
string decrypt(string ciphertext)
{
    int len = ciphertext.length();
    string decryptedtext="";
    for(int i=0;i<len-1;i=i+2)
    {
        char a = ciphertext[i];
        char b = ciphertext[i+1];
        pair<int,int> posa = search(a);
        pair<int,int> posb = search(b);
        int xa=posa.first;
        int ya=posa.second;
        int xb=posb.first;
        int yb=posb.second;
        string tempenc="";
        if(xa == xb)
        {
            int temp;
            if(ya<yb)
            {
                temp = ya-1;
                if(ya == 0)
                    temp=4;
                tempenc+= matrix[xa][temp];
                tempenc+= matrix[xb][yb-1];
            }
            else if(yb<ya)
            {
                temp = yb-1;
                if(yb == 0)
                    temp=4;
                tempenc+=  matrix[xa][ya-1];
                tempenc+=  matrix[xb][temp];
            }   
        }
        else if(ya == yb)
        {
            int temp;
            if(xa<xb)
            {
                temp = xa-1;
                if(xa == 0)
                    temp=4;
                tempenc+=  matrix[temp][ya];
                tempenc+= matrix[xb-1][yb];
            }
            else if(xb<xa)
            {
                temp = xb-1;
                if(xb == 0)
                    temp=4;
                tempenc+=  matrix[xa-1][ya];
                tempenc+= matrix[temp][yb];
            }   
        }
        else
        {
            tempenc+=  matrix[xa][yb];
            tempenc+=matrix[xb][ya];
        }
        decryptedtext += tempenc;
    }
    if(decryptedtext[len-1]= 'z')
        decryptedtext[len-1]='\0';

    return decryptedtext;
}
int main()
{
    string key,rawplaintext;
    cout<<"Enter plain text: ";
    getline(cin,rawplaintext);
    cout<<"Enter key: ";
    cin>>key;
    generatekeytable(key);
    cout<<"5 X 5 key table = \n";
    print();
    string smoothedplaintext = removespacesandconvert(rawplaintext);

    string encryptedtext = encrypt(smoothedplaintext);   
    cout<<"Encrypted text = "<<encryptedtext<<endl;
    string decryptedtext = decrypt(encryptedtext);   
    cout<<"Decrypted text = "<<decryptedtext<<endl;
}