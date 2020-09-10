/*							COMP20003 ASSIGNMENT 1 

*	Program written by Quang Tri Le/ Student ID: 1118563.

*	To run the program:
*		1. Type "make" in Terminal.
*		2. Type "./dict input_file output_file < key_file" into the terminal
* 		(names of 3 files are flexible depending on command line arguments).

==================================MAIN FUNCTION===============================*/

#include "header.h"

int main(int argc, char **argv){
	int num_record; /*number of businesses (optional use)*/
	int num_key;  /*number of trade name in keyfile (optional use)*/

	/*Initialize a business record containing information of all business under
	form of a linked list*/
	list_t* business_record = make_empty_list();

	/*Open input file for data recording */
	FILE *fin;
	if ((fin = fopen(argv[1],"r")) == NULL){
		printf("Error opening input file\n");
		exit(0);
	}

	/*Record all business data from input file */
	num_record = record_business(fin, business_record);

	/*Open output file for wrting and displaying information of business */
	FILE *fout;
	if ((fout = fopen(argv[2], "w"))==NULL){
		printf("Error opening output file\n");
		exit(0);
	}

	/*Read trade name from the keyfile and find information of businesses */
	num_key = read_keyfile(fout, business_record);

	/*Close all files used*/
	fclose(fin);
	fclose(fout);

	/*Freeing memories for the business record */
	free_list(business_record);
	business_record = NULL;

	return 0;

}

