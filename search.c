#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

void searchbyname(Book *b, int count){
	int scount = 0;
	char keyw[20];
	printf("책제목을 입력하세요 : ");
	scanf("\n %[^\n]",keyw);
	for(int i =0 ; i<count; i++){
		if(strstr(b[i].name,keyw)){
			scount ++;
               		printf("\n%d번 상품 ",i+1);
			readbook(b[i]);}
		}
}
void searchbyauthor(Book *b, int count){
	int scount = 0;
	char keyw[20];
	printf("작가 이름을 입력하세요 : ");
	scanf("%s",keyw);
	for(int i =0 ; i<count; i++){
		if(strstr(b[i].author,keyw)){
			scount++;
                	printf("\n%d번 상품 ",i+1);
			readbook(b[i]);}
}
}
void searchbystar(Book *b, int count){
    int scount = 0;
    int star;
    printf("별점을 입력하세요 : ");
    scanf("\n %d", &star);
    for (int i=0; i<count; i++){
        if(b[i].price != -1){
if (b[i].star ==  star){
                printf("\n%d번 상품 ",i+1);
                readbook(b[i]);
                scount++;
            }
        }
    }
    if(scount == 0)printf("=> 검색된 데이터 없음!");
    printf("\n");
}



void chooseby(Book *b, int count){
	int sel = 0;
	printf("검색 방법을 선택해주세요. \n(0:취소 1:책 제목 2:작가명 3:별점): ");
	scanf("%d",&sel);
	switch (sel){
	
	case 1:
		searchbyname(b,count);
		break;

	case 2:
		searchbyauthor(b,count);
		break;

	case 3:
		searchbystar(b,count);
		break;
	case 0:
		printf("검색을 종료합니다.\n");
		break;
	default:
		printf("[잘못된 입력값입니다!]\n");
		break;
	}

};
