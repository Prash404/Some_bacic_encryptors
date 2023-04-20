#include<bits/stdc++.h>
using namespace std;

string encrypt(string s){
    string res;
    for(int i=0; i<s.length(); i++){
        int k = (int)s[i];
        char c;
        if(s[i]>='A' && s[i]<='Z'){
            c = (char)(91-(k-64));
        }
        else if(s[i]>='a' && s[i]<='z'){
            c = (char)(123-(k-96));
        }
        else{
            c = (char)k;
        }
        res += c;
    }
    return res;
}

string decrypt(string s){
    string res;
    for(int i=0; i<s.length(); i++){
        int k = (int)s[i];
        char c;
        if(s[i]>='A' && s[i]<='Z'){
            c = (char)(65+(90-k));
        }
        else if(s[i]>='a' && s[i]<='z'){
            c = (char)(97+(122-k));
        }
        else{
            c = (char)k;
        }
        res += c;
    }
    return res;
}

int main(){
    FILE *pfile;
    pfile = fopen("D:/vscode files/code files/cpp_coding/plaintext.txt", "r");     //input file
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
    string cipher = encrypt(s);
    ofstream fout("D:/vscode files/code files/cpp_coding/ciphertext.txt");     //output file
    fout<<cipher;
    fout.close();
    FILE *cfile;
    cfile = fopen("D:/vscode files/code files/cpp_coding/ciphertext.txt", "r");     //input file
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
    string dcrypt = decrypt(s1);
    ofstream fout1("D:/vscode files/code files/cpp_coding/decryptedtext.txt");     //output file
    fout1<<dcrypt;
    fout1.close();
}