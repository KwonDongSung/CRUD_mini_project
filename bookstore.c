#include "book.h"

#define MAX 100


int main(){
	Book book[MAX];

	int count = loadbook(book);
	int menu = -1;

	while(menu!=0){
		menu = selectMenu();
		switch (menu){
			case 1:
				if(count>0)
				listbook(book,count);
				else 
				printf("데이터가 없습니다");
				break;
			case 2:
				count+= addbook(&book[count]);
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
