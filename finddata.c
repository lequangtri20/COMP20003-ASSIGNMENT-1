/*							COMP20003 ASSIGNMENT 1 

*	Program written by Quang Tri Le/ Student ID: 1118563.

*	To run the program:
*		1. Type "make" in Terminal.
*		2. Type "./dict input_file output_file < key_file" into the terminal
* 		(names of 3 files are flexible depending on command line arguments).

===========================READ STDIN AND FIND DATA===========================*/

#include "header.h"

/*Function below is used to read trade name from key file and find them in 
business record */
int read_keyfile(FILE* fout,list_t* business_record){
	char key[FIELD_MAX_LENGTH + 1], c;
	int num_key = 0, i = 0;
	
	while(1){

		if (scanf("%c",&c) == EOF){
			/*Last line of keyfile */
			key[i] = '\0'; 
			find_trade_name(fout, key, business_record);
			num_key += 1;
			break;
		}

		if (c == '\n'){
			/*End of each line in keyfile */
			key[i] = '\0'; 
			i = 0;
			find_trade_name(fout, key, business_record);
			num_key += 1;
			continue;
		}
		key[i] = c;
		i += 1;

	}
	return num_key;
}


/*Function below iterates through the business record to find all matching trade
names. If matching found, print its business information into output file */
void find_trade_name(FILE* fout, char* key, list_t* business_record){
	node_t *current;
	current = business_record->head;
	int found = 0;

	while (current != NULL){
		if (strcmp(key, current->data.trade_name) == 0){
			found = 1;
			print_data(fout, current);
		}
		current = current->next;
	}
	if (!found && (strlen(key)!= 0))
		fprintf(fout, "%s -- > NOT FOUND\n", key);
}

/*Function below print business information into ouput file */
void print_data(FILE *fout ,node_t* business_node){
	fprintf(fout, "%s --> Census year: %s || Block ID: %s || Property ID: %s "
	 "|| Base property ID: %s || CLUE small area: %s || "
	 "Industry (ANZSIC4) code: %s || Industry (ANZSIC4) description: %s || "
	 "x coordinate: %s || y coordinate: %s || Location: %s || \n",
	 		business_node->data.trade_name, business_node->data.census_year,
	 		business_node->data.block_id, business_node->data.prop_id,
	 		business_node->data.base_prop_id,business_node->data.area_name,
	 		business_node->data.industry_code, business_node->data.industry_des,
	 		business_node->data.x_coor, business_node->data.y_coor,
	 		business_node->data.location);

}