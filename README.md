# Crypto
Conversion of an encrypter from C# winform to C.

It was done as part of my final project, my teacher challenged me to do it... I obviously accepted :)

The key is 4 randomnized array of 70 chars, the original version was 124 chars it contained most the accented vowels and some special characters. Since this was done in C I wanted to keep it simple so I stuck with the basic ASCII table.

After a few attemps and some research I ended up making a simple Yates & Fisher Shuffle to randomize the keys.

The basic code works as intended, I'll try to optimize it and maybe switch to some sort of GUI.

Enjoy and keep coding :)

USAGE:

Generate the key set: ./yates keyfile

Encrypt the text: ./encrypt keyfile sourceText cryptedText

Decrypt the text: ./decrypt cryptedText clearText

OR

bash encryptor.sh
bash decryptor.sh
