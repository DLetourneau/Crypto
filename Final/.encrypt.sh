#!/bin/bash
clear
ls -a
echo ""
echo "Generating keys ..."
rm - f key
./keyGen key
sleep 1
echo "One-time key generated"
echo ""
read -p "Source filename: " src
read -p "Cyphered filename: " cyph
echo ""
echo "Applying Cypher ..."
rm -f $cyph
./encrypt key $src $cyph
sleep 1
echo "Deleting source file ..."
sleep 1
echo "Destroying key ..."
sleep 1
rm -f key
rm -f $src
echo ""
echo "Cypher application          OK"
echo "Key and Source destruction  OK"
echo "Cyphered file creation      OK"
echo ""
echo "Use: cat $cyph to see the encrypted file"
echo ""
