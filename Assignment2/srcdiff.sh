#!/bin/sh
#Exception handling
#Less than 2 arguments error
if [ -z "$2" ];
then
        echo "Error: expected two input parameters."
        echo "Usage: ./srcdiff.sh <originaldirectory> <comparisondirectory>"
exit 1
fi
#Check if the directory 1 exists
if [ ! -d "$1" ]
then
        echo "Error: Input parameter #1 '$1' is not a directory"
	echo "Usage: ./srcdiff.sh <originaldirectory> <comparisondirectory>"
exit 2
fi
#check if the directory 2 exists
if [ ! -d "$2" ];
then
        echo "Error: Input parameter #2 '$2' is not a directory"
	echo "Usage: ./srcdiff.sh <originaldirectory> <comparisondirectory>"
exit 2
fi

#Variables declaration
#directory name
original_directory="$1";
comparison_directory="$2";

#compare directories
for filename in `cd "$original_directory";ls`;
do
	if [ ! -f "$comparison_directory"/"$filename" ]
	then
		echo "$comparison_directory/$filename is missing"
	else 
		diff "$original_directory/$filename" "$comparison_directory/$filename" > /dev/null
		output=$?
		if  [ ! "$output" -eq 0 ]
		then
			echo "$comparison_directory/$filename differs"
		fi
		
	fi
done
for filename in `cd "$comparison_directory";ls`;
do
	if [ ! -f "$original_directory"/"$filename" ]
        then
                echo "$original_directory/$filename is missing"
        fi
done



