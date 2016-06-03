#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define interations 100

int main(){
	int i, y, count = 0;
	int j = 0;
	srand(time(NULL));
	for(i = 0; i < interations; i++){
		y = rand()%21;
		while(y < 10){
			y = rand()%21;
		}
		printf("%d %d %d\n", j, (rand()%8)+1, y);
		count++;
		if (count%10 == 0)
		{
			count = 0;
			j++;
		}
	}
}