#include "DeQue.h"

void main() {
	DQType* DQ = createDQueue();
	element data;
	printf("*****µ¥Å© ¿¬»ê*****");
	printf("\n front »ðÀÔ A>>");
	insertFront(DQ, 'A');
	print(DQ);
	printf("\n front »ðÀÔ B>>");
	insertFront(DQ, 'B');
	print(DQ);
	printf("\n rear »ðÀÔ C>>");
	insertRear(DQ, 'C');
	print(DQ);
	printf("\n front »èÁ¦>>"); data= deleteFront(DQ); print(DQ);
	printf("\t\t »èÁ¦ µ¥ÀÌÅÍ: %c", data);
	printf("\n rear »èÁ¦>>"); data = deleteRear(DQ); print(DQ);
	printf("\t\t »èÁ¦ µ¥ÀÌÅÍ: %c", data);
	printf("\n front »ðÀÔ D>>");
	insertFront(DQ, 'D');
	print(DQ);
	printf("\n rear »ðÀÔ E>>");
	insertRear(DQ, 'E');
	print(DQ);
	data = peekFront(DQ); printf("\n peek data: %c", data);
	data = peekRear(DQ); printf("\n peek data: %c", data);
}