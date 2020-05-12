#include <stdio.h>
#include <stdlib.h>
#include "book.h"

void searchbyname(Book *b, int count){
	char keyw[20];
	printf("키워드를 입력하세요 : ");
	scanf("%s",keyw);
	for(int i =0 ; i<count; i++)
		if(strset(b[i].name,keyw))
			readbook(b[i]);
}
void searchbyauthor(Book *b, int count){
	char keyw[20];
	printf("키워드를 입력하세요 : ");
	scanf("%s",keyw);
	for(int i =0 ; i<count; i++)
		if(strset(b[i].author,keyw))
			readbook(b[i]);
}

void chooseby(Book *b, int count){
	printf("검색 방법을 선택해주세요. \n(0:취소 1:책 제목 2:작가명 3:별점): ");
	int sel = scanf("%d",&sel);
	
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


void searchbystar(Book *b, int count){
    int scount = 0;
    int star;
    printf("원하는 별점은? ");
    scanf("\n %d", &star);
    for (int i=0; i<count; i++){
        if(b[i].price != -1){
if (b[i].star ==  star){
                printf("%d번 상품 ",i+1);
                readproduct(b[i]);
                scount++;
            }
        }
    }
    if(scount == 0)printf("=> 검색된 데이터 없음!");
    printf("\n");
}

