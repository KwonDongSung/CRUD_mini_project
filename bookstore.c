#include <stdio.h>
#include <string.h>
#include "book.h"

#define MAX 100

typedef struct{
	char name[20];
	char genre[20];
	char author[20];
	int price;
	int star;
}Book;

int selectMenu(){
	int menu;
	printf("\n메뉴를 선택하세요\n");
	printf("1. 도서조회\n");
	printf("2. 도서추가\n");
	printf("3. 도서수정\n");
	printf("4. 도서삭제\n");
	printf("5. 파일저장\n");
	printf("6. 도서검색\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d",&menu);
    return menu;
}

int main(){
	Book book[MAX];

	int count = loadbook(book);
	int menu = -1;

	while(menu!=0){
		menu = selectMenu();
		switch (menu){
			case 1:
				listbook(book,count);
				break;
	
			case 2:
				addbook(&book[count]);
				break;
	
			case 3:
			{
				int sel = selectdatano(book,count);
				updatebook(&book[sel-1]);
				break;
			}
			case 4:
			{
				int sel = selectdatano(book,count);
				deletebook(&book[sel-1]);
				break;
			}
			case 5:
				savebook(book,count);
				break;

			case 6:
				chooseby(book,count);
				break;

			case 0:
				printf("프로그램을 종료합니다.\n");
				break;

			default:
				printf("알 수 없는 메뉴 입니다.\n");
				break;
		}
	}
	return 0;
}