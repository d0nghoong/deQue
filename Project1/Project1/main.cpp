#include "DeQue.h"

void main() {
	DQType* DQ = createDQueue();
	element data;
	printf("*****��ũ ����*****");
	printf("\n front ���� A>>");
	insertFront(DQ, 'A');
	print(DQ);
	printf("\n front ���� B>>");
	insertFront(DQ, 'B');
	print(DQ);
	printf("\n rear ���� C>>");
	insertRear(DQ, 'C');
	print(DQ);
	printf("\n front ����>>"); data= deleteFront(DQ); print(DQ);
	printf("\t\t ���� ������: %c", data);
	printf("\n rear ����>>"); data = deleteRear(DQ); print(DQ);
	printf("\t\t ���� ������: %c", data);
	printf("\n front ���� D>>");
	insertFront(DQ, 'D');
	print(DQ);
	printf("\n rear ���� E>>");
	insertRear(DQ, 'E');
	print(DQ);
	data = peekFront(DQ); printf("\n peek data: %c", data);
	data = peekRear(DQ); printf("\n peek data: %c", data);
}