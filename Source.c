#include<stdio.h>
#include<stdlib.h>

// for an example usage of the que i included some code to diplay how it could be used 
// to check it out set below value to of #define UsageExample to 1
// to see debug messages set define #debugMode to 1


  #define UsageExample 0
  #define DebugMode 1


#ifndef DebugMode
#define DebugMode 0
#endif // !debugMode
#ifndef UsageExample
#define UsageExample 0
#endif // !UsageExample

#if UsageExample == 1
#define DisplayQueFunction 1
#endif // UsageExample == 1
#ifndef DisplayQueFunction
#define DisplayQueFunction 0
#endif // !DisplayStackFunktion


struct dataNode
{
	int nodeData;
	struct dataNode* pointerToNextDataNode;
};

struct dataNode * pointerToRearDataNode = NULL;
struct dataNode * pointerToFrontDataNode = NULL;

void enqueue(int dataToInsertIntoQue) {
	struct dataNode * pointerToCurrentNode;
	pointerToCurrentNode = (struct dataNode*)malloc(sizeof(struct dataNode));
	pointerToCurrentNode -> nodeData = dataToInsertIntoQue;
	pointerToCurrentNode -> pointerToNextDataNode = NULL;
	if ((pointerToFrontDataNode == NULL) && (pointerToRearDataNode == NULL))
	{
		pointerToFrontDataNode = pointerToRearDataNode = pointerToCurrentNode;
	}
	else
	{
		pointerToRearDataNode -> pointerToNextDataNode = pointerToCurrentNode;
		pointerToRearDataNode = pointerToCurrentNode;
	}
	#if DebugMode == 1
		printf("DBGMSG | Created a new node at the end of the Que\n");
	#endif // DebugMode == 1
}
int dequeue(void) {
	int temporaryNodeData = 0;
	if (pointerToFrontDataNode == NULL)
	{
		#if DebugMode == 1
				printf("DBGMSG | Cant deque a Value as Que is Empty\n");
		#endif // DebugMode == 1
		return -1;
	}
	else 
	{
		struct dataNode* pointerToTemporaryDataNode;
		pointerToTemporaryDataNode = pointerToFrontDataNode;
		temporaryNodeData = pointerToTemporaryDataNode->nodeData;
		pointerToFrontDataNode = pointerToFrontDataNode->pointerToNextDataNode;
		free(pointerToTemporaryDataNode);
		return temporaryNodeData;
	}
}
void display() {
	#if DisplayQueFunction == 1
		struct dataNode* pointerToTemporaryDataNode;
		if ((pointerToFrontDataNode == NULL) && (pointerToRearDataNode == NULL)) {
			printf("\nQueue is Empty\n");
		}
		else {
			printf("The queue is \n");
			pointerToTemporaryDataNode = pointerToFrontDataNode;
			while (pointerToTemporaryDataNode) {
				printf("+    %d     +", pointerToTemporaryDataNode->nodeData);

				pointerToTemporaryDataNode = pointerToTemporaryDataNode->pointerToNextDataNode;
			}
			printf("NULL\n\n");
		}
	#endif // 0
}

int main() {
	#if UsageExample == 1
		int choice = 0, value = 0;
		printf("\nImplementation of Queue using Linked List\n");
		while (choice != 4) {
			printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
			printf("\nEnter your choice : ");
			scanf_s("%d", &choice);
			switch (choice) {
			case 1:
				printf("\nEnter the value to add to the Que: ");
				scanf_s("%d", &value);
				enqueue(value);
				break;
			case 2:
				printf("Dequed element is :%d\n", dequeue());
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\nWrong Choice\n");
			}
		}
	#endif // UsageExample == 1
	#if UsageExample == 0 && DebugMode == 1
			printf("DBGMSG | Example Code for the ''Linked List que'' is defined as 0 therfor the example will not run.\nALL other debugMessages for This Linked List que will still be executed");
	#endif // UsageExample == 0;
	return ;
}