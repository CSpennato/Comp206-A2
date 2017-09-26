#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void horStars(int size){
	for(int i = size*7+21; i>0; i--){
		printf("*");
		if(i == 1){
			printf("\n");
		}
	}
}

int printLang(int size, int stop, char lang[]){
	FILE *file;
	file = fopen(lang, "r");
	if(file == NULL){
		printf("Error: The text file does not exist \n");
		return 0;
	}
	char c[300], d[2*size], e[2*size];
	for(int z=0; z < 2*size-1; z++){
		d[z] = 0;
		e[z] = 0;
	}
	int i = 0;
	int j = 0;
	int k = 0;
	int tmp = 0;
	do{
		c[i] = fgetc(file);
		if(feof(file)){
			break;
		}else if(feof(file) && i == 0){
			printf("Error: the text file is empty \n");
			return 0;
		}
		i++;
	}while(1);
	fclose(file);
	while(1){
		if(c[k] == ' ' || c[k] == '\n'){
			j++;
			if(j == stop-1 || stop == 1) break;
		}
		k++;
	}
	if(stop == 1){
		k = 0;
		do{
		d[tmp] = c[k];
		k++;
		tmp++;
		}while(c[k] != ' ' && c[k] != '\n');
	}else{
		do{
			d[tmp] = c[k+1];
			k++;
			tmp++;
		}while(c[k+1] != ' ' && c[k+1] != '\n');
	}
	if(size < tmp){
		for(int x = 0; x < size; x++){
			e[x] = d[x];
		}
	}else{
		for(int x = 0; x < size; x++){
			if(d[x] == 0){
				e[x] = ' ';
			}else{
				e[x] = d[x];
			}
		}
	}
	printf("* %s ", e);
	return 1;
}

void printDays(int size, char lang[]){
	for(int i=1; i < 8; i++){
		printLang(size, i, lang);
	}
}

void printDates(int size, int start, char lang[]){
	int count = 0;
	int end =start;
	for(start; start > 1; start--){
		printf("*");
			for(int i = 0; i < size+2; i++){
				printf(" ");
			}
		count++;
	}
	for(int j = 1; j <= 30; j++){
		if(count%7 == 0 && count > 0){
			printf("\n");
		}
		printf("* %d", j);
		for(int i = 0; i < size-1; i++){
			printf(" ");
		}
		if(j < 10){
			printf(" ");
		}
		count++;
	}
	for(end = 7-(end%7 +1); end > 0; end--){
		printf("*");
			for(int i = 0; i < size+2; i++){
				printf(" ");
			}
		count++;
	}
	printf("\n");
}

void main(int argc, char *argv[]){
	if(argc != 4){
		printf("Error: Incorrect number of arguments \n");
		return;
	}

	int daySize = strtol (argv[argc-2], NULL, 10);
	int startDay = strtol (argv[argc-1], NULL, 10);

	if(daySize < 2){
		printf("Error: DaySize must be greater than or equal to 2 \n");
		return;
	}
	if(startDay >7 || startDay<1){
		printf("Error: StartDay must be between 1 and 7 \n");
		return;
	}
	
	for(int i = 1; i <13; i++){
		horStars(daySize);
		if(printLang(15, i+7, argv[argc-3]) == 0){
			return;
		}
		printf("\n");
		horStars(daySize);
		printDays(daySize, argv[argc-3]);
		printf("\n");
		horStars(daySize);
		printDates(daySize, startDay, argv[argc-3]);
		if(startDay == 7){
			startDay = 0;
		}else if(startDay == 6){
			startDay = 1;
		}
		startDay += 2;
	}
}
