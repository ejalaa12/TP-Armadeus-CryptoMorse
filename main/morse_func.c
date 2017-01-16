#include "morse_func.h"

int ascii2morse(char *s, char *outmsg){

	char *letters[] =  {
			"1 -1 3 ",            // A | a
			"3 -1 1 -1 1 -1 1 ",  // B | b
			"3 -1 1 -1 3 -1 1 ",  // C | c
			"3 -1 1 -1 1 ",       // D | d
			"1 ",                 // E | e
			"1 -1 1 -1 3 -1 1 ",  // F | f
			"3 -1 3 -1 1 ",       // G | g
			"1 -1 1 -1 1 -1 1 ",  // H | h
			"1 -1 1 -1 ",         // I | i
			"1 -1 3 -1 3 -1 3 ",  // J | j
			"3 -1 1 -1 3 ",       // K | k
			"1 -1 3 -1 1 -1 1 ",  // L | l
			"3 -1 3 ",            // M | m
			"3 -1 1 ",            // N | n
			"3 -1 3 -1 3 ",       // O | o
			"1 -1 3 -1 3 -1 1 ",  // P | p
			"3 -1 3 -1 1 -1 3 ",  // Q | q
			"1 -1 3 -1 1 ",       // R | r
			"1 -1 1 -1 1 ",       // S | s
			"3 ",                 // T | t
			"1 -1 1 -1 3 ",       // U | u
			"1 -1 1 -1 1 -1 3 ",  // V | v
			"1 -1 3 -1 3 ",       // W | w
			"3 -1 1 -1 1 -1 3 ",  // X | x
			"3 -1 1 -1 3 -1 3 ",  // Y | y
			"3 -1 3 -1 1 -1 1 "  // Z | z
			};

	char *numbers[] = {
			"3 -1 3 -1 3 -1 3 -1 3 ",  // 0
			"1 -1 3 -1 3 -1 3 -1 3 ",  // 1
			"1 -1 1 -1 3 -1 3 -1 3 ",  // 2
			"1 -1 1 -1 1 -1 3 -1 3 ",  // 3
			"1 -1 1 -1 1 -1 1 -1 3 ",  // 4
			"1 -1 1 -1 1 -1 1 -1 1 ",  // 5
			"3 -1 1 -1 1 -1 1 -1 1 ",  // 6
			"3 -1 3 -1 1 -1 1 -1 1 ",  // 7
			"3 -1 3 -1 3 -1 1 -1 1 ",  // 8
			"3 -1 3 -1 3 -1 3 -1 3 ",  // 9
			};
	
	int i, c;
	for (i=0;i<strlen(s);i++){

		c = s[i];	
		if (c != ' '){
			// selectionner le caractere
			if((c <= 'z') && (c >= 'a'))
				strcat(outmsg, letters[c - 'a']);

			else if((c <= 'Z') && (c >= 'A'))
				strcat(outmsg, letters[c - 'A']);	

			else if((c <= '9') && (c >= '0'))
				strcat(outmsg, numbers[c - '0']);	

			else if(c == '.')
				strcat(outmsg, "1 -1 3 -1 1 -1 3 -1 1 -1 3 ");

			else if(c == ',')
				strcat(outmsg, "3 -1 3 -1 1 -1 1 -1 3 -1 3 ");

			else if(c == '?')
				strcat(outmsg, "1 -1 1 -1 3 -1 3 -1 1 -1 1 ");

			else if(c == '-')
				strcat(outmsg, "3 -1 1 -1 1 -1 1 -1 1 -1 3 ");

			else // caractere non valide
				printf("Le caracter %c n'est pas valide \nValeur en ASCII = %d\ni = %d",s[i],s[i],i);
			
			// espace entre elements
			if (s[i+2] == '\0')
				break;
			if (s[i+1] != ' ')
				strcat(outmsg, "-3 "); // entre elements
			else{
				strcat(outmsg, "-7 "); // fin d'un mot
				i++;
			}
		}
	}	

	//fclose(f);

	return EXIT_SUCCESS;
}
