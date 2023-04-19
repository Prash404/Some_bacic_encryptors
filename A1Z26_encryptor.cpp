#include<bits/stdc++.h>
using namespace std;

string encrypt(string s){
    string res;
    for(int i=0; i<s.length(); i++){
        int k=-1;
        if(s[i]==' '){
            k=0;
        }
        else if(s[i]>='A' && s[i]<='Z'){
            k = ((int)s[i])-64;
        }
        else if(s[i]>='a' && s[i]<='z'){
            k = ((int)s[i])-96;
        }
        else{
            continue;
        }
        stringstream is;
        string ss;
        is<<k;
        is>>ss;
        res += ss;
        res += " ";
    }
    return res;
}

string decrypt(string cipher){
    string res;
    string temp ="";
    for(int i=0; i<cipher.length(); i++){
        if(cipher[i]!=' '){
            temp += cipher[i];
        }
        else if(cipher[i]==' ' || cipher[i+1]==EOF){
            stringstream is;
            int k;
            is<<temp;
            is>>k;
            if(k==0){
                res+=" ";
            }
            else{
                res += (char)(k+64);
            }
            temp = "";
        }
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