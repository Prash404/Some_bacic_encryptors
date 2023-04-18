#include<bits/stdc++.h>
using namespace std;

string encrypt(string s,short key){
    string res;
    for(int i=0; i<s.length(); i++){
        int k = (int)s[i];
        char c = (char)(k+key);
        res += c;
    }
    return res;
}

string decrypt(string cipher,short key){
    string res;
    for(int i=0; i<cipher.length(); i++){
        int k = (int)cipher[i];
        char c = (char)(k-key);
        res += c;
    }
    return res;
}

int main(){
    FILE *pfile;
    pfile = fopen("D:/vscode files/code files/cpp_coding/plaintext.txt", "r");     //input file
    int key = 12;      //enter te key of choise
    char c;
    string s;
    while(1){
        c = fgetc(pfile);
        if(c==EOF){
            break;
        }
        s+=c;
    }
    fclose(pfile);
    string cipher = encrypt(s, key);
    ofstream fout("D:/vscode files/code files/cpp_coding/ciphertext.txt");     //output file
    fout<<cipher;
    fout.close();
    FILE *cfile;
    cfile = fopen("D:/vscode files/code files/cpp_coding/ciphertext.txt", "r");     //input file
    int keyd = 12;      //enter te key of encryption
    char c1;
    string s1;
    while(1){
        c1 = fgetc(cfile);
        if(c1==EOF){
            break;
        }
        s1+=c1;
    }
    fclose(cfile);
    string dcrypt = decrypt(s1, keyd);
    ofstream fout1("D:/vscode files/code files/cpp_coding/decryptedtext.txt");     //output file
    fout1<<dcrypt;
    fout1.close();
}