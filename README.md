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

## Assignment 4:
Built-in data types of programming languages (including C) have limitations in terms of size and range of data (example integers) that they can work with. This is often an impediment for many calculations (such as scientific computations) which can involve numbers beyond the range that is supported by built-in data types.
This assignment consists a scientific calculator that can perform calculations over arbitrarily large numbers.

## Assignment 5:
Online platforms can track users easily and study and analyze user behaviour. Such
data analytics are also relevant with remote delivery of exams. This assignment consists of analyzing an user event file (data.csv) for such an exam generated from mycourses (anonymised) to look for students who could have possibly collaborated.

## Assignment 6:
Word clouds are often used to visualize the context of an article or someone's academic research. This is because they are a good visual representation of the main research categories on which one or more articles focus. This is accomplished by constructing an image where words are organized in the shape of a cloud with words which occur
at a higher frequency getting more emphasis (i.e., larger fonts). The first task in building a word cloud is to scan the relevant articles and compute the frequency of different words in it. To facilitate this, in this exercise, I created a C program, wcloud, a simple application that reads through all the text files passed in as its argument and prints the number of times each word occurs across all those text files.
The output is printed in alphabetical order. The program is expected to contain multiple modules (multiple C files).
