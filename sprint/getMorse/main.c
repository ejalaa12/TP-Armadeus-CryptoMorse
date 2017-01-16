#include "functions.h"

int main(int argc, char *argv[]){
    
    if(argc < 3){
		printf("Utilisation :\n ./main infile outfile\n");
		return EXIT_FAILURE;
	}
    
	FILE *infile;
	char s[100];

	// Charger le message
	infile = fopen(argv[1],"r");
	fgets(s,500,infile);
	fclose(infile); 

	FILE *outfile = fopen(argv[2],"w+"); 
	ascii2morse(s,outfile);  

    return EXIT_SUCCESS;
}
