/*
Stanley lalanne
cs 241
final project
affine cypher

*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++){
       if ((a*x) % m == 1)

          return x;
}
return 0;
}

void encrypt(){
  cout<<"Enter the path of the file you wish to encrypt:\n";
  string text_path;
  cin>>text_path;
  ifstream file(text_path);
  string text((istreambuf_iterator<char>(file)),
                (istreambuf_iterator<char>()));
  int a, b;
  cout<<"Enter the a coefficient:\n";
  cin>>a;
  cout<<"Enter the b coefficient:\n";
  cin>>b;
  ofstream enc("/Users/slalanne/Desktop/encrypted.txt"); //change path to your own machine to create file
  string cypher="";

  for(int i=0; i<text.size(); i++){
    if(isspace(text[i])){
        cypher+=text[i];
      }
    else{
      text[i]=toupper(text[i]); //this ensures that we get the same result whether text is lower or uppercase
      int p = (int)(text[i]-65)%26;
      int c = ((a*p)+b)%26;
      cypher+=(char)(c+65);
      }
  }
      cypher.insert(0,to_string(b));
      cypher.insert(0,to_string(a));
      enc<<cypher;
}

void decrypt(){
  string text_path;
  cout<<"Enter the path of the text you want to decrypt:\n";
  cin>>text_path;
  string message="";
  ifstream file(text_path);
  string text((istreambuf_iterator<char>(file)),
                (istreambuf_iterator<char>()));
  int a=text[0]-'0';
  int b = text[1]-'0';
  int a_inv = modInverse(a, 26);

  for(int i=2; i<text.size(); i++){
    text[i]=toupper(text[i]); //this ensures that we get the same result whether text is lower or uppercase
      if(isspace(text[i])){
            message+=text[i];
          }
      else{
        int p = (int)(text[i]-65)%26;
        int c = (a_inv * (p-b)%26);
        c = ((c+26)%26)+65;
        message+=(char)c;
          }
        }

  ofstream dec("/Users/slalanne/Desktop/decrypted_message.txt"); //change this path to your own path
  dec<<message;

}

int main() {

  //driver program

cout<<"Hi, welcome to the encryption program.\n";
cout<<"Choose an option below:\n";
cout<<"Enter (1) to encrypt a file.\nEnter (2) to decrypt a file.\n";
int option;
cin>>option;

if(option==1){
  encrypt();
}
else if(option==2){
  decrypt();
}
else{
  cout<<"Make sure you enter a valid entry.\n";
}
return 0;
}
