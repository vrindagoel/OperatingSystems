#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int buffersize = 7, x = 0;
//let the size of the buffer be 7

//producer function
void producer()
{
	--mutex;
	++full;
	--buffersize;
	x++;
	printf("\tItem Produced: "
		"item %d",
		x);
	printf("\tUpdated Buffer: %d", full);
	++mutex;
}

//consumer function
void consumer()
{
	--mutex;
	--full;
	++buffersize;
	printf("\tConsumed the Item: "
		"item %d",
		x);
	printf("\tUpdated Buffer: %d", full);
	x--;
	++mutex;
}

int main()
{
	int n, i;
	printf("\n1. Press 1 for Producer"
		"\n2. Press 2 for Consumer"
		"\n3. Press 3 for Exit");


#pragma omp critical

	for (i = 1; i > 0; i++) {

		printf("\nEnter your choice:");
		scanf("%d", &n);

		// Switch Cases
		switch (n) {
		case 1:
			if ((mutex == 1) && (buffersize != 0)) {
				producer();
			}
			else {
				printf("Buffer is full!");
			}
			break;

		case 2:
			if ((mutex == 1) && (full != 0)) {
				consumer();
			}
			else {
				printf("Buffer is empty!");
			}
			break;

		case 3:
			exit(0);
			break;
		}
	}
}
