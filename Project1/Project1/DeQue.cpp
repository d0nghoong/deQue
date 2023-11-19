#include"DeQue.h"

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
