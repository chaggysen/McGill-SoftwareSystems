#!/bin/bash

#Exception handling
#Less than 1 arguments error
if [ -z "$1" ];
then
        echo "Error: No log file given"
        echo "Usage: ./webmetrics.sh <logfile>"
exit 1
fi
#Check if the logfile exists
if [ ! -f "$1" ]
then
        echo "Error: File '$1' does not exist"
        echo "Usage: ./webmetrics.sh <logfile>"
exit 2
fi

# Number of Requests by Web Browser
echo "Number of requests per web browser"
# Safari count
SAFARI=$(grep -o -i safari "$1" | wc -l)
echo "Safari, $SAFARI"
# Firefox count
FIREFOX=$(grep -o -i firefox "$1" | wc -l)
echo "Firefox, $FIREFOX"
# Chrome count
CHROME=$(grep -o -i chrome "$1" | wc -l)
echo "Chrome, $CHROME"

# Number of Distinct User per Day
echo "Number of distinct users per day"
# create a list of distinct dates and iterate 
for date in `grep -wo "../.../...." "$1" | sort | uniq`;
do
	# for each line in $1 check if line has date. If yes, print the first element of the line(ip address) and count unique
	count=$(awk -v date="$date" '$0 ~ date { print $1 }' < "$1" | sort | uniq | wc -l)
echo "$date, $count"

# Top 20 popular product request
done
echo "Top 20 popular product requests"
PRODUCTS=$(grep -o "GET /product/.\{4,5\}/" "$1")
IDs=$(echo "$PRODUCTS" | awk '{ print $2 }')
list=""
for id in `echo "$PRODUCTS" | awk '{ print $2 }' | sort | uniq`;
do
	list+=$(echo "$PRODUCTS" | awk -v id="$id" '{ if($0 ~ id) { array[id]++ } } END { for (i in array) { print i "," array[i]  } }')
	list="$list"$'\n'
done
for product in `echo "$list" | sort -t"," -k2rn,2 -k1rn,1 | head -20`;
do
	echo "$product" | sed 's/[^0-9,]*//g'
done 

count=$(grep -o "GET $id" "$1"| wc -l)
exit 0
