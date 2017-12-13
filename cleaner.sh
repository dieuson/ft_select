#!/bin/bash

echo -n "Delete files: "

emacs_files=$(find . -name '*c~'); 
echo -n $emacs_files;
rm -rf $emacs_files;

gch_files=$(find . -name '*.gch');
echo -n $gch_files;
rm -rf $gch_files;

sharp_sh_files=$(find . -name '*#');
echo -n $sharp_sh_files;
rm -rf $sharp_sh_files;

sh_tilde_files=$(find . -name '*~');
echo $sh_tilde_files;
rm -rf $sh_tilde_files;