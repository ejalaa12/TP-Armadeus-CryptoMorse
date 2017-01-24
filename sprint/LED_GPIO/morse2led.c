#include <stdio.h>
#include <stdlib.h>
#include "as_gpio.h"

#define	LED_GPIO 21
#define time_dot 100  // temps base d'un element simple (point). A verifier

void morseShow(struct as_gpio_device *led, FILE* morseCode);

int	main(int argc, char *argv[])
{	
	if(argc < 2)
	{
		printf("Utilisation :\n./main infile\n");
		return EXIT_FAILURE;
	}
	
	// ouverture du fichier du code morse
	FILE *infile = fopen(argv[1],"r");
	if(infile == NULL)
	{
		printf("Fichier d'entrée \"%s\" n'existe pas\n", argv[1]);
		return EXIT_FAILURE;
	}
	
	// declaration du LED
	struct as_gpio_device *led;
	led	= as_gpio_open(LED_GPIO);
	if(led == NULL) 
	{
		printf("Error: can't open gpio\n");
		exit(1);
	}
	
	// on place	la LED en sortie
	as_gpio_set_pin_direction(led, "out");
	
	// boucle principale
	morseShow(led,infile);

	as_gpio_close(led);
	exit(0);
}

// boucle principale du programme qui envoit les messages
void morseShow(struct as_gpio_device *led, FILE* morseCode)
{	
	// on place	la LED en sortie et	le switch en entrer
	as_gpio_set_pin_direction(led, "out");
	
	// boucle principale
	// lit un element de temps a la fois
	int nthLedDuration, delay;
	while (fscanf(morseCode,"%d[^\n]",&nthLedDuration) == 1)
	{
		if(value > 0) // si positive, allumer le led
		{
			as_gpio_set_pin_value(led,	1);
			delay = nthLedDuration;
		}
		else // si negatif, eteindre le led
		{
			as_gpio_set_pin_value(led,	0);
			delay = -nthLedDuration;
		}
		
		sleep(time_dot*delay); // meilleure option ?
	}
}


