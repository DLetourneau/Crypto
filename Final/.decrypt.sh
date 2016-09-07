#!/bin/bash
clear
ls -a
echo ""
read -p "Cyphered File: " cypher
read -p "Decyphered File: " cleartext
echo ""
echo "Reading $cypher ..."
rm -f $cleartext
./decrypt $cypher $cleartext
sleep 1
echo "Decyphering ..."
rm -f $cypher
sleep 1
echo ""
echo "Cyphered file destruction OK"
echo "Clear text file status    OK"
echo ""
echo "Use: cat $cleartext to see the decyphered text"
echo ""
