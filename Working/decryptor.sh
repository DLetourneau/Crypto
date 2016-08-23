#!bin/sh
#
# Will automatically decrypt a file

echo "Which file do you want to decypher?"
read target
echo "In which file do you want to write the decyphered text?"
read cleartext
echo ""
echo "Decrypting ..."
rm $cleartext
./decrypt $target $cleartext
sleep 1
echo ""
echo $cleartext" generated"
rm $target
echo $target" destroyed"
vim $cleartext
