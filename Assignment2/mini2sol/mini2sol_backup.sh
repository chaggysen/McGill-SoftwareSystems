#!/bin/bash

# Define function to print the usage.
Usage()
{
    echo "Usage: $0 <backupdirectory> <fileordirtobackup>"
}

# Check number of input arguments; script expects exactly 2.
if [[ $# != 2 ]]
then
    echo "Error: Expected two input parameters."
    Usage
    exit 1
fi

backupDirectory=$1
toBackup=$2

# Check that the backup directory and the directory or file to back up exist, and are not the same 
#   Does $backupDirectory exist?
if [[ ! -e $backupDirectory ]]
then
    echo "Error: Backup directory '$backupDirectory' does not exist."
    Usage
    exit 2
#   Does $toBackup exist?
elif [[ ! -e $toBackup ]]
then
    echo "Error: Directory or file '$toBackup' does not exist."
    Usage
    exit 2
#   Are $backupDirectory and $toBackup the same?
elif [[ $backupDirectory == $toBackup ]]
then
    echo "Error: the backup directory and the directory to backup are the same."
    Usage
    exit 2
fi

# Create the name of the tar file
#   basename xxx => get filename without directory (e.g., /home/20xx/csuser/asgn1.pdf => asgn1.pdf)
#   ${toBackup%.*} => remove the extension (e.g., asgn1.pdf => asgn1)
tarname=$(basename "${toBackup%.*}")
#   ${backupDirectory%/} => $backupDirectory without a trailing slash (to avoid /some/path//backup)
tarname="${backupDirectory%/}/$tarname.$(date "+%Y%m%d").tar"

# Check if a tar file with $tarname already exists. If so, ask user if they want to overwite.
if [[ -f $tarname ]]
then
    # Ask user
    echo -n "Back up file '$tarname' already exists. Overwrite? (y/n) "
    read overwrite

    # User did not respond 'y'; do not overwrite.
    if [[ $overwrite != "y" ]]
    then
        echo "Error: File already exists. Not overwriting."
        exit 3
    fi
fi

# Create/overwrite backup
tar cvf "$tarname" "$toBackup" 2>/dev/null 1>/dev/null

# Done!
exit 0
