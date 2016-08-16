# Crypto
Conversion of an encrypter from C# winform to C.

It was done as part of my final project, my teacher challenged me to do it... I obviously accepted :)

The key is 4 randomnized array of 70 chars, the original version was 124 chars it contained most the accented vowels. Since this was done in C I wanted to keep it simple so I stuck with the basic ASCII table.

The program will take 2 arguments: the name of the file containing the set of keys and another containing the source text.
It will write the keys and the encrypted text in a third file. (might add a third argument: name of the output file).

Decryption is just a reverse process, the keys are loaded for decryption, the text is decrypted and written to a new file.

After a few attemps and some research I ended up making a simple Yates & Fisher Shuffle to randomize the keys.

The rest is pretty straight forward.

Enjoy and keep coding :)
