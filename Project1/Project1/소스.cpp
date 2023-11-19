#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct DQNode {
	element data;
	struct DQNode* rlink;
	struct DQNode* llink;
}DQNode;

typedef struct DQType {
	DQNode* front, * rear;
}DQType;

DQType* createDQueue();
int isDQEmpty(DQType* DQ);
void insertFront(DQType* DQ, element item);
void insertRear(DQType* DQ, element item);
element deleteFront(DQType* DQ);
element deleteRear(DQType* DQ);
element peekFront(DQType* DQ);
element peekRear(DQType* DQ);
void print(DQType* DQ);

DQType* createDQueue() {
	DQType* DQ;
	DQ = (DQType*)malloc(sizeof(DQType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

int isDQEmpty(DQType* DQ) {
	if (DQ->front) return 0;
	else {
		return 1;
	}
}

void insertFront(DQType* DQ, element item) {
	DQNode* newNode;
	newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDQEmpty(DQ)) {
		newNode->llink = NULL;
		newNode->rlink = NULL;
		DQ->front = newNode;
		DQ->rear = newNode;
	}
	else {
		newNode->llink = NULL;
		newNode->rlink = DQ->front;
		DQ->front->llink = newNode;
		DQ->front = newNode;
	}
}

void insertRear(DQType* DQ, element item) {
	DQNode* newNode;
	newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (isDQEmpty(DQ)) {
		newNode->llink = NULL;
		newNode->rlink = NULL;
		DQ->front = newNode;
		DQ->rear = newNode;
	}
	else {
		newNode->rlink = NULL;
		newNode->llink = DQ->rear;
		DQ->rear->rlink = newNode;
		DQ->rear = newNode;
	}
}

element deleteFront(DQType* DQ) {
	if (isDQEmpty(DQ)) {
		printf("데크 비었다");
		return NULL;
	}
	DQNode* old = DQ->front;
	element result = old->data;
	DQ->front = DQ->front->rlink;
	if (DQ->front == NULL) {
		DQ->rear = NULL;
	}
	DQ->front->llink = NULL;
	free(old);
	return result;
}

element deleteRear(DQType* DQ) {
	if (isDQEmpty(DQ)) {
		printf("데크 비었다");
		return NULL;
	}
	DQNode* old = DQ->rear;
	element result = old->data;
	DQ->rear = DQ->rear->llink;
	if (DQ->rear == NULL) {
		DQ->front = NULL;
	}
	DQ->rear->rlink = NULL;
	free(old);
	return result;
}

element peekFront(DQType* DQ) {
	if (isDQEmpty(DQ)) {
		printf("데크 비었다");
		return NULL;
	}
	return DQ->front->data;
}

element peekRear(DQType* DQ) {
	if (isDQEmpty(DQ)) {
		printf("데크 비었다");
		return NULL;
	}
	return DQ->rear->data;
}

void print(DQType* DQ) {
	printf("DeQueue:[");
	DQNode* temp;
	temp = DQ->front;
	while (temp) {
		printf("%c", temp->data);
		temp = temp->rlink;
	}
	printf("]");
}

void main() {
	DQType* DQ = createDQueue();
	element data;
	printf("*****데크 연산*****");
	printf("\n front 삽입 A>>");
	insertFront(DQ, 'A');
	print(DQ);
	printf("\n front 삽입 B>>");
	insertFront(DQ, 'B');
	print(DQ);
	printf("\n rear 삽입 C>>");
	insertRear(DQ, 'C');
	print(DQ);
	printf("\n front 삭제>>"); data= deleteFront(DQ); print(DQ);
	printf("\t\t 삭제 데이터: %c", data);
	printf("\n rear 삭제>>"); data = deleteRear(DQ); print(DQ);
	printf("\t\t 삭제 데이터: %c", data);
	printf("\n front 삽입 D>>");
	insertFront(DQ, 'D');
	print(DQ);
	printf("\n rear 삽입 E>>");
	insertRear(DQ, 'E');
	print(DQ);
	data = peekFront(DQ); printf("\n peek data: %c", data);
	data = peekRear(DQ); printf("\n peek data: %c", data);
}