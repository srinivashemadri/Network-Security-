 #include<bits/stdc++.h>
using namespace std;
string encrypt(string text,int a, int b)
{
    string ciphertext="";
    for(int i=0;i<text.length();i++)
    {
        char ch = text[i];
        if(ch>='A' && ch<='Z')
            ciphertext+= char((a*(ch - 'A') + b)%26 +'A');
        else
            ciphertext+=ch;
    }
    return ciphertext;
}
int modInverse(int a) 
{ 
	int a_inv = 0;
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if (flag == 1)
            a_inv = i;
    }
    return a_inv;
} 
string decryptcipher(string cipher,int a,int b)
{
    int invofa = modInverse(a);
    string decryptedtext="";
    for(int i=0;i<cipher.length();i++)
    {
        char ch = cipher[i];
        if(ch>='A' && ch<='Z')
            decryptedtext+= char((invofa*(ch + 'A' - b))%26 +'A');
        else
            decryptedtext+=ch;
    }
    return decryptedtext;

}
int main()
{
    string plaintext;
    cout<<"Enter plain text: ";
    getline(cin,plaintext);
    int a,b;
    cout<<"enter a value: ";
    cin>>a;
    cout<<"enter b value: ";
    cin>>b;
    string ciphertext = encrypt(plaintext,a,b);
    cout<<"Encrypted message = "<<ciphertext<<endl;
    string decrypttext = decryptcipher(ciphertext,a,b);
    cout<<"Decrypted message = "<<decrypttext<<endl;
    if(plaintext == decrypttext)
    cout<<"Success";
}