#!/bin/bash

# This is a program that keeps your pets checkout routine.

petclinic="/var/tmp/Alpha/petclinic"

echo "Hello, "$USER".  This register your pets in Alpha's petclinic database."

echo -n "Enter it name and press [ENTER]: "
read name
echo -n "Enter it gender and press [ENTER]: "
read -n 1 gender
echo

grep -i "$name" "$petclinic"

if  [ $? == 0 ]; then
  echo "You are already registered, quitting."
  exit 1
elif [ "$gender" == "" ]; then
  echo "You are added to Alpha's petclinic list."
  exit 1
else
  echo -n "How old your pet? "
  read age
  if [ $age -lt 2 ]; then
    echo -n "What its favourite food like? "
    read food
    echo "$name $age $colour" >> "$stuff"
    echo "You are added to Alpha's petclinic list.  Thank you so much!"
  else
    echo "You are added to Alpha's petclinic list."
    exit 1
  fi
fi

Alpha ~/test> cp simple_shell.sh /var/tmp; cd /var/tmp

Alpha ~/test> touch petclinic; chmod a+w petclinic

Alpha ~/test> simple_shell.sh
Hello, Kitten.  This script will register you Alpha's petclinic database.
Enter your name and press [ENTER]: Kitten
Enter your gender and press [ENTER] :F
You are added to Alpha's petclinic list.
