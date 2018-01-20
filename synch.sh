#!/bin/bash
# Synchronize with git's server
git status

while true; do
    read -p "Do you wish to synchronize the folder with git? (y/n)?" ans
    case $ans in
        [Yy]* )
            git add .;
            git commit -m "`date`";
            git push;
            ;;
        [Nn]* ) exit ;;
        * ) echo "Please answer yes or no";;
    esac
done
