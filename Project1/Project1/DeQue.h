#pragma once
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