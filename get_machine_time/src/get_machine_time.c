/*
	Excuse me! What is time right now?
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	time_t timer;
	time(&timer);

	printf("Yes the time is.... %s", ctime(&timer));

	return EXIT_SUCCESS;
}
