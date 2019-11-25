#include "methods.h"
#include <stdlib.h>
#include <getopt.h>

struct ParametersStruct{
	bool message, version, help;
} parameters;


int main (int argc, char *argv[]){
	const char* short_keys = "mvh";
	
	const struct option long_keys[] = {
		{"message",no_argument,NULL,'m'},
		{"version",no_argument,NULL,'v'},
		{"help",no_argument,NULL,'h'},
		{NULL,0,NULL,0}
	};

	parameters.message = false;
	parameters.version = false;
	parameters.help = false;
	
	int input, input_index;
    int counter = 0;

    
	while ((input=getopt_long(argc,argv,short_keys, long_keys,&input_index))!=-1)
	{
		switch(input){
			case 'm': {
                if(!parameters.message){
                    message_demo();
                    parameters.message = true;
                    counter++;
                }
				break;
			};
			case 'v': {
		if(!parameters.version){
                    version_demo();
                    parameters.version = true;
                    counter++;
                }
				break;
			};
	
			case 'h': {
		if(!parameters.help){
                    help_demo();
                    parameters.help = true;
                    counter++;
                }
				break;
			};
			case '?': default: {
				error_case();
				break;
			};    
		};
	};
    normal_output(counter);
	return 0;
};
