#include <stdio.h>
#include "book.h"

int loadbook(Book *b){
	FILE *fp;
	fp = fopen("bookstore.txt","r");
	int i = 0;

	if(fp==NULL){
		printf("\t[FILE NOT FOUND]");
		return 0;
	}
	while(!feof(fp)){
		fscanf(fp,"%d %d %s %s %[^\n]\n",&b[i].price,&b[i].star,b[i].author,b[i].genre,b[i].name);
		i++;
	}
	printf("\t[FILE LOADED]");
	fclose(fp);
	return i;
}

void savebook(Book *b, int count){
	FILE *fp;
	fp = fopen("bookstore.txt","w");

	for(int i = 0; i<count; i++){
		if(b[i].star!=-1)
		fprintf(fp,"%d %d %s %s %s \n",b[i].price,b[i].star,b[i].author,b[i].genre,b[i].name);
	}
	
	printf("\t[FILE SAVED]");
	fclose(fp);
}


