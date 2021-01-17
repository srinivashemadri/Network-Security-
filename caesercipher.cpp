#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text,cipher,decrypted;
    cout<<"Enter plain text\n";
    getline(cin,text);
    int key;
    cout<<"Enter key\n";
    cin>>key;
    cout<<"Plain text="<<text<<endl;
    cout<<"Key="<<key<<endl;
    for(int i=0;i<text.length();i++)
    {
        char ch = text[i];
        char temp=ch;
        if(ch>='A' && ch<='Z')
        {
            int shift = (int(ch - 'A') + key)%26;
            temp = (char)('A'+shift);
            
        }
        else if(ch>='a' && ch<='z')
        {
            int shift = (int(ch - 'a') + key)%26;
            temp = (char)('a'+shift);
            
        }
        cipher += temp;
    }
    cout<<"Encrypted text="<<cipher<<endl;
    for(int i=0;i<cipher.length();i++)
    {
        char ch = cipher[i];
        char temp=ch;
        if(ch>='A' && ch<='Z')
        {
            int shift = (int(ch - 'A') - key)%26;
            if(shift < 0)
                shift = 26 + shift;
            temp = (char)('A'+shift);
            
        }
        else if(ch>='a' && ch<='z')
        {
            int shift = (int(ch - 'a') - key)%26;
            if(shift < 0) 
                shift = 26 + shift;
            temp = (char)('a'+shift);
            
        }
        decrypted += temp;
    }
    cout<<"Decrypted text="<<decrypted<<endl;
    if(decrypted == text)
        cout<<"Encryption and decryption is success\n";
}