#!bin/sh
#
# Will automatically encrypt a textfile

echo "Generating keys ..."
rm autokey.txt
./yates autokey.txt
sleep 1
echo ""
echo "Keys generated"
echo ""
echo "Which file do you want to encrypt?"
read soucre
echo "What will be the name of the encrypted file"
read target
echo "Encrypting the document ..."
echo ""
./encrypt autokey.txt $source $target
sleep 1
echo $target" generated"
echo "Keys and "$source" destroyed"
rm autokey.txt
rm $source
echo ""
