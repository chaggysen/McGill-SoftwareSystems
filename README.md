# McGill-SoftwareSystems

Assignments completed for Software Systems class at McGill University using Bash and C. 

## Assignment 2:
### Part 1
backup.sh will take an individual file or directory, and back it up into a tar file. Specifically, this script takes two inputs:
1. The directory where the tar file should be saved. 
2. An individual file or directory to backup. 
Furthermore, the name of the tar file created will need to contain the name of the directory or file (without the extension) and the date the backup was created in YYYYMMDD format. Finally, the script will need to returnwith error code 0 upon success and the appropriate error code otherwise.

### Part 2
srcdiff.sh will take two directories as input parameters, iterate over the list of files, and report files which are either present in one directory but missing in the other, or present in both directories but differ in content. 

## Assignment 3:
webmetrics.sh will parse webserver logs and produce three metrics:
1. Number of requests comming from the browsers Safari, Firefox and Chrome.
2. Number of distinct users (distinct IP addresses) per day.
3. Top 20 popular requests by product ID. 
