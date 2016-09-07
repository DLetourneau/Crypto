# Crypto

Project coded by Dom Letourneau
From August to Septembre 2016
Part of my final project at CDE College
Final compilation with GCC an a Ubuntu Xenial system
Original work on a Rasp PI 3

Code is available online:
  https://github.com/dletourneau/crypto

Standard convention was used to name the files.
All the source, header and shell files are hidden.
The source files must be recompiled to be used on another system.

**************************************************************************
                          WARNING
 THIS IS NOT MEANT TO BE A SECURE TOOL TO ENCRYPT INFORMATION, THE CYPHER
 USED IS SOMEWHAT SIMPLE AND THE CODE IS PUBLICLY AVAILABLE.
**************************************************************************

Usage:

  To generate a key: bash .keyGen.sh
    -> will output a file named key
    
  To encrypt manually: ./encrypt keyfile sourcefile crytpfile
  
  To decrypt manually: ./decrypt cryptfile clearfile
  
  To encrypt automatically: bash .encrypt.sh
    -> will prompt for source and crypted filenames
    
  To decrypt automatically: bash .decrypt.sh
    -> will prompt for crypted and clear filenames
    
  To compile: bash .make.sh
    -> will prompt for sourcefile and executable
    
File List:

.yates.c      : Source - Key generator

.decrypt.c    : Source - Decyphering tool

.encrypt.c    : Source - Cyphering tool

.persolib.h   : Header - Small library used by the other elements

.make.sh      : Script - Compiling shortcut

.keyGen.sh    : Script - Generate a key set

.decrypt.sh   : Script - Runs the decryption

.encrypt.sh   : Script - Runs the encryption, includes a keyGen call

license.txt   : Text - The distribution license for this software

readme.txt    : Text - This file
