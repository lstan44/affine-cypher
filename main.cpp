
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Afine_Cypher
{
  public:
    void encrypt(int coef1, int coef2, string filepath);
    void decrypt(string filepath);
    int modInverse(int a, int m);
};


int Afine_Cypher::modInverse(int a, int m)
{
  a = a%m;
  for (int x = 1; x < m; x++ )
  {
    if ((a*x) % m == 1)
      return x;
  }
  return 0;
}

void Afine_Cypher::encrypt(int coef1, int coef2,string filepath)
{
  ifstream file(filepath);
  string text( (istreambuf_iterator<char>(file) ), (istreambuf_iterator<char>() ) );
 
  ofstream enc("encrypted.txt"); //change path to your own machine to create file
  string cypher="";

  for(int i = 0; i < text.size(); i++)
  {
    if( isspace( text[i] ) )
    {
      cypher+=text[i];
    }
    else
    {
      text[i]=toupper(text[i]); //this ensures that we get the same result whether text is lower or uppercase
      int p = (int) ( text[i] - 65 ) % 26;
      int c = ((coef1 * p ) + coef2 ) % 26;
      cypher += (char) ( c + 65 );
    }
  }
  cypher.insert(0, to_string(coef2));
  cypher.insert(0, to_string(coef1));
  enc<<cypher; 
  cout<< "Encrypted text: "<< cypher;
}

void Afine_Cypher::decrypt( string filepath )
{
  string message="";
  ifstream file(filepath);
  string text( (istreambuf_iterator<char>(file) ), (istreambuf_iterator<char>() ) );
  int coef1 = text[0]-'0';
  int coef2 = text[1]-'0';
  int a_inv = modInverse(coef1, 26);

  for(int i = 2; i < text.size(); i++)
  {
    text[i] = toupper( text[i] ); //this ensures that we get the same result whether text is lower or uppercase
    if(isspace( text[i] ) )
    {
      message+=text[i];
    }
    else
    {
      int p = (int)(text[i] - 65 ) % 26;
      int c = (a_inv * (p - coef2) % 26 );
      c = (( c + 26 ) % 26 ) + 65;
      message += (char) c;
    }
  }

  ofstream dec("decrypted.txt"); //change this path to your own path
  dec<<message;
  cout<< "Decrypted text: " << message;

}

int main() {
Afine_Cypher* Cypher = new Afine_Cypher;

cout<<"Hi, welcome to the Afine Cypher encryption program.\n";
cout<<"Choose an option below:\n";
cout<<"Enter (1) to encrypt a file.\nEnter (2) to decrypt a file.\n";
int option;
cin>>option;

if(option==1)
{
  Cypher->encrypt(1,2,"text.txt");
}

else if(option==2)
{
  Cypher->decrypt("encrypted.txt");
}

else
{
  cout<<"Make sure you enter a valid entry.\n";
}

return 0;
}
