#/!bin/bash

# Varibles declarations===================================================
# array to store student_ids
student_ids=()
student_files=()
student_files_count=0
threshold=7

# set the threshold=========================================================
if [ ! -z "$1" ]
then
    threshold=$1
fi

# Error handling for no student id dir=====================================
has_student_id=false
# get list of dirs without trailing slash
directories=$(ls -d */ | sed 's#/##')
for directory in $directories; do
    # check if it only contains digits (assuming ids only have digits)
    if [[ "$directory" =~ ^[0-9]+$ ]]
	then
	    student_ids+=("$directory")
	    has_student_id=true
    fi
done

# did not found any student id. Print error
if [[ "$has_student_id" == false ]]
    then
    	echo "No valid student id in current directory" >>/dev/stderr
	exit 1
fi

# Check if files exists===================================================
for id in "${student_ids[@]}"
do
    # append file names to student ids. If the file exists, append to student_files array
    a2="$id/a2/srcdiff.sh"
    a3="$id/a3/webmetrics.sh"
    if [ -f "$a2" ]
    then
	student_files+=("$a2")
	student_files_count=$((student_files_count+1))
    fi
    if [ -f "$a3" ]
    then
        student_files+=("$a3")
	student_files_count=$((student_files_count+1))
    fi
done
# Compare files and verify with threshold
for i in "${!student_files[@]}"
do
    kscore=9
    j=$((i+1))
    while [ $j -lt $student_files_count ]
    do
   # kscore=$($PATH/kscore ${student_files[i]} ${student_files[j]})
    if [ "$kscore" -ge "$threshold" ]
    then
	echo "$kscore,${student_files[i]},${student_files[j]}"
    fi
    j=$((j+1))
    done
done
