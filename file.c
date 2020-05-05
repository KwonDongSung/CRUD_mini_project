#include <stdio.h>
#include "book.h"

typedef struct{
	char name[20];
	char genre[20];
	char author[20];
	int price;
	int star;
}Book;

int loadbook(Book *b){
	FILE *fp = NULL;
	fp = fopen("","r");
	int i = 0;

	if(fp==NULL){
		printf("\t[FILE NOT FOUND]");
		return 0;
	}
	while(!feof(fp)){
		fscanf(fp,"%d %d %s %s %[^\n]s\n",&b[i].price,&b[i].star,b[i].author,b[i].genre,b[i].name);
		i++;
	}
	printf("\t[FILE LOADED]");
	fclose(fp);
	return i-1;
}

void savebook(Book *b, int count){
	FILE *fp = NULL;
	fp = fopen("","w");

	for(int i = 0; i<count; i++){
		if(b[i].star!=-1)
			fprintf(fp,"%d %d %s %s %[^\n]s\n",b[i].price,b[i].star,b[i].author,b[i].genre,b[i].name);
	}
	
	printf("\t[FILE SAVED]");
	fclose(fp);
}