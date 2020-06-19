#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


int main(void) {

	//declaring words
	char *article[] = { "the" , "a", "one", "some", "any" };
	char *noun[] = { "boy", "girl", "dog", "town", "car" };
	char *verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
	char *preposition[] = { "to", "from", "over", "under", "on" };
	char sentence[100] = ""; 
	int i;

	//loop trhough 20 times
	for (i = 1; i <= 20; i++) {

		//picks a random article
		strcat(sentence, article[ rand() % 5 ]);
		strcat(sentence, " ");

		//picks a random noun
		strcat(sentence, noun[ rand() % 5 ]);
		strcat(sentence, " ");

		//picks a random verb
		strcat(sentence, verb[ rand() % 5 ]);
		strcat(sentence, " " );

		//picks a random preposition
		strcat(sentence, preposition[ rand() % 5 ]);
		strcat(sentence, " ");

		//picks another random article
		strcat (sentence, article[ rand () % 5 ]);
		strcat(sentence, " " );

		//picks another random noun
		strcat(sentence, noun[ rand() % 5 ] );

		putchar(toupper( sentence [0] ));

		printf("%s.\n", &sentence[1]);
		sentence[0] = '\0';
	}

}