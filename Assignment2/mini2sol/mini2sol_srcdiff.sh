#!/bin/bash

# Define function to print the usage.
Usage()
{
    echo "Usage: $0 <originaldirectory> <comparisondirectory>"
}

# Check number of input arguments; script expects 2 (but allows 3).
if [[ $# != 2 ]] && [[ $# != 3 ]]
then
    echo "Error: Expected two input parameters."
    Usage
    exit 1
fi

originalDirectory=$1
comparisonDirectory=$2
extension=$3

# Check that $originalDirectory is a directory
if [[ ! -d $originalDirectory ]]
then
    echo "Error: Input parameter #1 '$originalDirectory' is not a directory."
    Usage
    exit 2
fi
# Check that $comparisonDirectory is a directory
if [[ ! -d $comparisonDirectory ]]
then
    echo "Error: Input parameter #2 '$comparisonDirectory' is not a directory."
    Usage
    exit 2
fi
# Check that $originalDirectory and $comparisonDirectory are different directories
if [[ $originalDirectory == $comparisonDirectory ]]
then
    echo "Error: the original and comparison directories refer to the same directory."
    Usage
    exit 2
fi

# Use ls to get a list of files (-p: add a slash at the end of directory names; grep -v '/$': remove any line ending with a /)
originalDirFiles=$(ls -p "$originalDirectory" | grep -v '/$')
comparisonDirFiles=$(ls -p "$comparisonDirectory" | grep -v '/$')

# Add trailing '/' if necessary (remove it first, if necessary, for pretty printing)
originalDirectory=${originalDirectory%/}/
comparisonDirectory=${comparisonDirectory%/}/

# Loop through original files: look for missing files and files that differ
exit_code=0
for file in $originalDirFiles
do
    originalFile=${originalDirectory}${file}
    comparisonFile=${comparisonDirectory}${file}
    if [[ ! -f $comparisonFile ]]
    then
        echo "$comparisonFile is missing"
        exit_code=3

    elif ! diff "$originalFile" "$comparisonFile" 2>/dev/null 1>/dev/null
    then
        echo "$originalFile differs."
        exit_code=3
    fi
done
# Loop through comparison files: only look for missing files
for file in $comparisonDirFiles
do
    originalFile=${originalDirectory}${file}
    if [[ ! -f $originalFile ]]
    then
        echo "$originalFile is missing"
        exit_code=3
    fi
done

# Done!
exit $exit_code
