#include<stdio.h>
#include<stdlib.h>

/*
3-3. [3] Give an algorithm to reverse the direction of a given singly linked list. In other words, after the reversal all pointers should now point backwards. Your algorithm should take linear time.
*/

struct ListNode
{
	int data;
	struct ListNode *next;
};

static void reverse(struct ListNode** ptrToHead)
{
	struct ListNode* prevNode = NULL;
	struct ListNode* currNode = *ptrToHead;
	struct ListNode* next = NULL;

	while (currNode != NULL)
	{
		next = currNode -> next;
		currNode -> next = prevNode;
		prevNode = currNode;
		currNode = next;
	}
	*ptrToHead = prevNode;
}

void addFirst(struct ListNode** ptrToHead, int value)
{
	struct ListNode* newNode =(struct ListNode*) malloc(sizeof(struct ListNode));
	newNode -> data = value;
	newNode -> next = (*ptrToHead);
	(*ptrToHead) = newNode;
}

void printListData(struct ListNode* head)
{
	struct ListNode* current = head;

	printf("List: ");
	while (current != NULL)
	{
		printf("[%d] -> ", current -> data);
		current = current -> next;
	}
	printf("NULL\n");
}

void freeList(struct ListNode* head)
{
	struct ListNode* current = head;

	while (current != NULL)
	{
		struct ListNode *next = current -> next;
		free(current);
		current = next;
	}
	head = NULL;
}

int main(void)
{
	struct ListNode* head = {NULL};
	addFirst(&head, 10);
	addFirst(&head, 20);
	addFirst(&head, 30);

	printf("Given linked list\n");
	printListData(head);
	reverse(&head);
	printf("\nReversed linked list \n");
	printListData(head);
	freeList(head);
	return 0;
}
