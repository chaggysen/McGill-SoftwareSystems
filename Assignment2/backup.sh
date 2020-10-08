#!/bin/sh

#Exception handling
#Less than 2 arguments error
if [ -z "$2" ];
then
	echo "Error: excpected two input parameters."
	echo "Usage: ./backup.sh <backupdirectory> <fileordirtobackup>"
exit 1
fi
#Check if the directory to store the tar file exists
if [ ! -d "$1" ]
then
	echo "Error: The directory '$1' does not exist"
exit 2
fi
#check if the file or directory to back up do not exist
if [ -f "$2" ] || [ -d "$2" ];
then
	:
else
	echo "Error: The file/directory '$2' does not exist"
exit 2
fi
#Variables declaration
#directory name
directory="$1";
# file/directory name
fileName="$2";

#current time
TIME=`date +%Y%m%d`
#backup file/directory name
backupName="$fileName.$TIME.tar"

#Check if the tar file with the same name already exists. Ask if they want to overwrite(y/n)
if [ -f "$directory/$backupName" ]
then 
	echo "Backup file '$backupName' already exists. Overwrite? (y/n)"
	read answer
	if [ "$answer" == "y" ];
	then
		#create tar backup file
		tar -cvf "$directory/$backupName" "$fileName"
		exit 0
	else
		exit 3
fi
fi
#create tar backup file
tar -cvf "$directory/$backupName" "$fileName"
exit 0

