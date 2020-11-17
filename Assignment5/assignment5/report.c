/*
Program to look for collaboration from a csv file
***************************************************************
* Author  Dept.        Date Notes
***************************************************************
* Sen W.  Engineering. Nov 9 2020 Initial Version.
* Sen W.  Engineering. Nov 10 2020 Finish Error Handlings
* Sen W.  Engineering. Nov 14 2020 Finish Program Implementation
* Sen W.  Engineering. Nov 15 2020 Finish Testing and code refactor
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// struc definition
typedef struct logrecord {
        char name[100];
        char IPAddress[50];
} Logrecord;

// variables declarations
Logrecord record;
Logrecord seenRecords[100];
int seenRecordsCount = 0;

// methods declaratinons
bool checkNameExists(char* csvfileName, char* name, char* ip);
bool findCollaborators(char* name, char *ip, char* csvfileName, char* rptfileName);

int main(int argc, char *argv[]){
	// error handlings
	// check valid nb of argument
	if (argc != 4){
		fprintf(stderr, "Usage ./report <csvfile> <student name> <reportfile>\n");
		return 1;
	}
	// check if the data file can be read
	if (fopen(argv[1], "r") == NULL){
		fprintf(stderr, "Error, unable to open csv file %s\n", argv[1]);
		return 1;
	}
	// check if name exist
	char *ip;
	if (!checkNameExists(argv[1], argv[2], ip)){
		fprintf(stderr, "Error, unable to locate %s\n", argv[2]);
		return 1;
	}
	// check if output file can be created
	if (fopen(argv[3], "w") == NULL){
		fprintf(stderr, "Error, unable to open the output file %s\n", argv[3]);
		return 1;
	}

	// check for collaborators
	bool found = findCollaborators(record.name, record.IPAddress, argv[1], argv[3]);
	if (!found){
		printf("No collaborators found for %s\n", argv[2]);
	}

	// write to rpt file
	FILE *output = fopen(argv[3], "w");
	for (int i = 0; i < seenRecordsCount; i++){
		fprintf(output, "%s\n", seenRecords[i].name);
	}
	fclose(output);
}

// Read through the CSV data file, keep looking for the name.
// If found, store the IP address associated with the name
// to the variable ip and return success.
bool checkNameExists(char* csvfileName, char* name, char* ip) {
	// open file
	FILE *file;
	char singleLine[200];
	file = fopen(csvfileName, "r");
	while(fgets(singleLine, 200, file)){
		const char s[2] = ",";
       		char *token;
        	token = strtok(singleLine, s);
		int ipCounter = 0;
		bool found = false;
        	while (token != NULL){
			// found the user
			if (strcmp(token, name) == 0){
				found = true;
			}
			// get the ip address
			if (ipCounter == 6 && found){
				//Logrecord record = { .name = *name, .IPAddress = *token};
				// initiate the counters
				int nameCount = 0;
				int ipCount = 0;
				// copy the values into the struct
				while(name[nameCount] != '\0'){
					record.name[nameCount] = name[nameCount];
					nameCount += 1;
				}
				while(token[ipCount] != '\0'){
					record.IPAddress[ipCount] = token[ipCount];
					ipCount += 1;
				}
				return true;
			}
                	token = strtok(NULL, s);
			ipCounter +=1;
        	}
	}
}

// Go through the CSV data file
// look for collaborators of sname by looking for entries with the same ip as sip
// if any collaborators are found, write it to the output report file.
bool findCollaborators(char* name, char *ip, char* csvfileName, char* rptfileName) {
	// open file
	FILE *file;
	char singleLine[200];
	file = fopen(csvfileName, "r");
	bool sameIp = false;
	// iterate each line
	while(fgets(singleLine, 200, file)){
		const char s[2] = ",";
		char *token;
		token = strtok(singleLine, s);
		int ipCounter = 0;
		char *currentUser;
		//iterate each element of line
		while(token != NULL){
			// get current user
			if (ipCounter == 0){
				currentUser = token;
			}
			// if not original user and ip is the same, then print
			if ((strcmp(currentUser, name) != 0) && ipCounter == 6 && (strcmp(ip, token) == 0)){
				//printf("ORIGINAL IP: %s, CURRENT IP: %s", ip, token);
				sameIp = true;
				//check for duplicates and add to seen record
				bool exist = false;
				for (int i = 0; i < seenRecordsCount; i++){
					if (strcmp(seenRecords[i].name, currentUser) == 0){
						exist = true;
					}
				}
				if (!exist){
					int charCount = 0;
					while(currentUser[charCount] != '\0'){
						seenRecords[seenRecordsCount].name[charCount] = currentUser[charCount];
						charCount += 1;
					}
					seenRecordsCount += 1;
				}
			}
			token = strtok(NULL, s);
			ipCounter += 1;
		}
	}
	return sameIp;
}
