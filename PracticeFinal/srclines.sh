#!bin/bash

#Error handling
# if no argument
if [ -z "$1"];
then
    echo "Error: expected one input parameter."
    echo "Usage: ./srclines.sh <directory>"
exit 1
fi

#check if directory 1 exists
if [ ! -d "$1" ]
then
    echo "Error: Input parameter #1 '$1' is not a directory"
    echo "Usage: ./srclines.sh <directory>"
exit 1
fi

directory=$1
# Use ls to get a list of files (-p: add a slash at the end of directory names; grep -v '/$': remove any line ending with a /)
directoryFiles=$(ls -p "$directory" | grep -v '/$')

# declare variables
sh_counter=0
sh_total_lines=0
c_counter=0
c_total_lines=0

#check for C files========================================
for file in $directoryFiles
do 
    if [[ "$file" == *.c ]]
    then
        c_counter=`expr $c_counter + 1`
        nb_lines=$($PATH/cparser $file)
        c_total_lines=`expr $c_total_lines + $nb_lines`
        echo "$file $nb_lines"
    fi
done
echo "Total of $c_counter C program with $c_total_lines of code."


#check for sh files========================================
for file in $directoryFiles
do 
    if [[ "$file" == *.sh ]]
    then
        sh_counter=`expr $sh_counter + 1`
        nb_lines=$(cat $directory/$file | sed '/^\s*#/d;/^\s*$/d' | wc -l)
        sh_total_lines=`expr $sh_total_lines + $nb_lines`
        echo "$file $nb_lines"
    fi
done
echo "Total of $sh_counter shell scripts with $sh_total_lines of code."

