#include <stdio.h>
#include <string.h>

int printNewLang(int stop, char lang[]){
	FILE *file;
	file = fopen(lang, "r");
	if(file == NULL){
		printf("Error: The text file doesn't exist \n");
		return 0;
	}
	char c[300], d[20];
	for(int z=0; z < 19; z++){
		d[z] = 0;
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
			printf("Error, the text file is empty \n");
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
	printf("%s", d);
	return 1;
}

void main(int argc, char *argv[])
{
	int day = 0, month = 0;
	char str1[20], str2[20], date[40], c;
	char *days[8] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	char *months[13] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	
	if(argc == 1){
		printf("Error: No path for text file provided \n");
		return;
	}
	scanf("%s", str1);
	scanf("%s", str2);
	fgets(date, 40, stdin);
	for(day; day < 7; day++){
		if(strcmp(str1, days[day]) == 0){
			day++;
			break;
		}else if(day == 6){
			printf("Error: Please input a valid date, using the date output format \n");
			return;
		}
	}
	for(month; month < 12; month++){
		if(strcmp(str2, months[month]) == 0){
			month++;
			break;
		}else if(month == 11){
			printf("Error: Please input a valid date, using the date output format \n");
			return;
		}
	}
	if(printNewLang(day, argv[argc-1]) == 0){
		return;
	}
	printf(" ");
	printNewLang(month + 7, argv[argc-1]);
	printf("%s", date);
}
