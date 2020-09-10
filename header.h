/*							COMP20003 ASSIGNMENT 1 

*	Program written by Quang Tri Le/ Student ID: 1118563.

*	To run the program:
*		1. Type "make" in Terminal.
*		2. Type "./dict input_file output_file < key_file" into the terminal
* 		(names of 3 files are flexible depending on command line arguments).

==================================HEADER FILE=================================*/

#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>


#define LINE_MAX_LENGTH 512
#define FIELD_MAX_LENGTH 128

/*struct for data section in each node of a linked list*/
typedef struct {
	char* census_year;
	char* block_id;
	char* prop_id;
	char* base_prop_id;
	char* area_name;
	char* trade_name;
	char* industry_code;
	char* industry_des;
	char* x_coor;
	char* y_coor;
	char* location;
} data_t;

/*Define node in the linked list*/
typedef struct node node_t;

struct node {
	data_t data;
	node_t *next;
};

/*Define linked list*/
typedef struct {
	node_t *head;
	node_t *foot;
} list_t;

/******************************************************************************/
/*FUNCTION PROTOTYPES*/

/*Linked list operation */
list_t *make_empty_list(void);
void free_list(list_t *list);
list_t *insert_at_foot(list_t *list, data_t* value);
void free_data(node_t *business_node);


/*Reading business record*/
int record_business(FILE* fin,list_t* business_record); 
void add_to_dictionary(int field_no, node_t *business_node);
data_t* record_to_struct(int field_no, char* field_value, data_t* data);


/*Read, find and print trade name from keyfile*/
int read_keyfile(FILE *fout ,list_t* business_record);
void find_trade_name(FILE *fout, char*str, list_t* business_record);
void print_data(FILE *fout, node_t* business_node);


#endif //HEADER_H