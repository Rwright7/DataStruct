#include <stdio.h>
#include <stdlib.h>

//Write a program to convert a binary search tree into a linked list

struct node
{
	int key;
	struct node *left, *right;
};

struct linkedlist
{
	int val;
	struct linkedlist *next;
};


struct node *newNode(int item)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> key = item; 
	temp -> left = temp ->right = NULL;
	return temp;
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL)
	{
		return newNode(key);
	}

	if (key < node -> key)
	{
		node -> left = insert(node -> left, key);
	}
	else if (key > node -> key)
	{
		node -> right = insert(node -> right, key);
	}
	return node;
}
struct linkedlist* newListNode(int key)
{
	struct linkedlist *temp = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	temp -> val = key;
	temp -> next = NULL;
	return temp;
}

	struct linkedlist* head = NULL;
	struct linkedlist* tail = NULL;

void inorder(struct node* root)
{
	if (root == NULL)
	{
		return;
	}
	
	inorder(root -> left);
	printf("%d ", root -> key);
	
	struct linkedlist* temp = newListNode(root -> key);
	if (head == NULL)
	{
		head = tail = temp;
	}
	else
	{
		tail -> next = temp;
		tail = temp;
	}
	inorder(root -> right);
}

void printListData()
{
	struct linkedlist *curr = head;
	printf("List: ");
	while (curr != NULL)
	{
	printf("[%d]->", curr->val);
	curr = curr->next;
	}
	printf("NULL\n");
}

void freeList()
{
	struct linkedlist *curr = head;

	while(curr != NULL)
	{
		struct linkedlist *next = curr -> next;
		free(curr);
		curr = next;
	}
	head = NULL;
}

int main(void)
{
	struct node* root = NULL;
	
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	
	printf("BST: ");
	inorder(root);
	printf("\n");
	printListData();
	freeList();
	
	return 0;
}

