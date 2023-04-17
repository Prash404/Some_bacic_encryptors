#include <bits/stdc++.h>
using namespace std;

string encrypt(string s, int key) {
        string res[key];
        int n=0,c=1,j=0;
        if(key==1){
            return s;
        }
        else if(key==2){
            for(int i=0; i<s.length(); i++){
                if(i%2==0){
                    res[0]+=s[i];
                }
                else{
                    res[1]+=s[i];
                }
            }
        }
        else{
            for(int i=0; i<s.length(); i++){
                if(n==0){
                    res[j]+=s[i];
                    j++;
                    c++;
                    if(c==key){
                        n=key-1;
                        j=0;
                        c=1;
                    }
                }
                else {
                    res[n]+=s[i];
                    n--;
                }
            }
        }
        string cipher;
        for(int i=0;i<key;i++){
            cipher+=res[i];
        }
        return cipher;
    }

int main()
{
    FILE *pfile;
    pfile = fopen("D:/vscode files/code files/cpp_coding/plaintext.txt", "r");     //input file
    int key = 3;      //enter te key of choise
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
    cout<<cipher;
}