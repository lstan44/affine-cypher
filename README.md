# affine-cypher
a program to encrypt and decrypt files based on the Affine cypher

if you want to run this program, you are expected to to provide a path to the file you want to encrypt or decrypt.

You are also expected to choose the two coefficients a&b required by the affine cypher.

Keep in mind that a must be coprime to 26 which the number of letters in the English alphabet.


The encryption algorithm is: for a given letter x, E(x)=ax+b mod 26
The decryption, D(y) = a^-1 x -b mod 26
a^-1 is the multiplicative inverse of a mod 26
