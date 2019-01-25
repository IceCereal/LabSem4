//Hash Search
//25/Jan/19

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Node for Linked List
typedef struct node{
	int data;
	struct node *next;
}node;

void insert(int data, node *chainUnit){

	//Condition 1.1: First insertion
	if (chainUnit->data == -1){
		printf("\nFound no existing node.");
		chainUnit->data = data;
		chainUnit->next = NULL;
		return;
	}

	//Condition 1.2: Second insertion
	if (chainUnit->next != NULL){
		node *temp = (node *)malloc(sizeof(node));
		temp->data = data;
		temp->next = NULL;
		chainUnit->next = temp;
		return;
	}

	//Condition 2: Look for insertable position
	node *prev = (node *)malloc(sizeof(node));
	prev = chainUnit;
	
	while (1){
		if (data <= chainUnit->data){
			node *temp = (node *)malloc(sizeof(node));
			temp->data = data;
			temp->next = chainUnit;
			chainUnit->next = temp;	
			return;
		}
		prev = chainUnit;
		chainUnit = chainUnit->next;

		if (chainUnit == NULL)
			break;
	}

	//Condition 3: We're at the last position
	node *temp = (node *)malloc(sizeof(node));

	temp->data = data;
	temp->next = NULL;

	prev->next = temp;

	return;
}

void printTable(node *chainUnit){
	while(1){		
		if (chainUnit->data == -1){
			printf("-");
			return;
		}
		
		printf("\t%d", chainUnit->data);
		
		chainUnit = chainUnit->next;

		if (chainUnit == NULL)
			return;
	}

	return;
}

int hash(int data){
	//printf("Calculated Hash:\t%d", data % SIZE);
	return data % SIZE;	
}

int main(){
	printf("Hash Search");

	node **HashTable = (node **)malloc(sizeof(node *) * SIZE);

	int i;

	for (i = 0; i < SIZE; ++i){
		HashTable[i] = (node *)malloc(sizeof(node));
	}
		
	for (i = 0; i < SIZE; ++i){
		HashTable[i]->data = -1;
		HashTable[i]->next = NULL;
	}

	int goAhead;

	do{
		int dataValue;

		printf("\n\nEnter a number to insert:\t");
		scanf("%d", &dataValue);

		insert(dataValue, HashTable[hash(dataValue)]);
		
		printf("\nEnter More (y=1 / n=0 / print=2):\t");
		scanf("%d", &goAhead);

		if (goAhead == 2){
			for (i = 0; i < SIZE; ++i){
				printf("\n%d: ", i);
				printTable(HashTable[i]);
			}
			goAhead = 1;
		}

	}while(goAhead == 1);

	return 0;
}