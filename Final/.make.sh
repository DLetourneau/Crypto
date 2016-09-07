#!/bin/bash
clear
echo ""
ls -a
echo ""
read -p "Source file: " src
read -p "Executable: " ex
echo ""
echo "Compiling ..."
gcc -g -std=c99 $src -o $ex
