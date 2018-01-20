#!/bin/bash
# Synchronize with git's server
# usage: $ ./synch.sh <files or folder>
git status

while true; do
    read -p "Do you wish to synchronize the folder with git? (y/n)?" ans
    case $ans in
        [Yy]* )
            git add $1;
            git commit -m "`date`";
            git push;
            exit ;;
        [Nn]* ) exit ;;
        * ) echo "Please answer yes or no";;
    esac
done
