#/!bin/bash

# check if csv file exist
if [ -z "$1" ]
then
    echo "Error no csv file given"
    exit 1
fi
dash='/'
comma=','
output=$(./similar.sh)

# replace dashes with commas using sed
sed -i "s/$dash/$comma/g" < "$output"

# since we know the order of each element, print them in order.
csv_format=$(awk 'BEGIN {FS=","}{print $2,$5,$3,$7,$1}' < "$output")

# append to csv file
echo ${csv_format} >> $1



