// Lab Work 8
/* C program to perform various Linked List implementation and functions */
#include <stdio.h>
#include <stdlib.h>
// Structure of node for link list
struct node
{
	int info;		   // Declaring an info field
	struct node *next; // next node pointer
};

// function prototypes
void insert_beg();
int insert_position();
void insert_end();
int display();
int search();
int del_beg();
int del_specified();
int del_end();

// global external pointer to point to first node
struct node *start = NULL;

// Main Function
int main(void)
{
	int choice;
	while (choice != 9)
	{
		printf("\n\t MENU");
		printf("\n\t 1: Insert at Beginning ");
		printf("\n\t 2: Insert at given position ");
		printf("\n\t 3: Insert at End ");
		printf("\n\t 4: Delete at Beginning");
		printf("\n\t 5: Delete at specified position");
		printf("\n\t 6: Delete at End");
		printf("\n\t 7: Display all nodes ");
		printf("\n\t 8: Search Item");
		printf("\n\t 9: Exit");
		printf("\n Enter your choice:\t");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insert_beg();
			break;
		case 2:
			insert_position();
			break;
		case 3:
			insert_end();
			break;
		case 4:
			del_beg();
			break;
		case 5:
			del_specified();
			break;
		case 6:
			del_end();
			break;
		case 7:
			display();
			break;
		case 8:
			search();
			break;
		case 9:
			printf("\n ******  EXITING  ****** \nend");
			break;
		default:
			printf("\n Invalid Choice please Enter again: ");
		}
	}
	return 0;
}

// Function for inserting a node at the beginning
void insert_beg()
{
	int item;
	struct node *nnode;

	printf("\n Enter the item:\t");
	scanf("%d", &item);
	nnode = (struct node *)malloc(sizeof(struct node));
	nnode->info = item;
	nnode->next = start;
	start = nnode;
}
// Function for inserting a node at specified position in the list
int insert_position()
{
	int item;
	struct node *nnode, *temp;
	int pos, i;
	printf("\n Enter the item:\t");
	scanf("%d", &item);
	printf("\n Enter the position of node to add ");
	scanf("%d", &pos);
	if (start == NULL)
	{
		printf("\n The list is empty!!!  Insufficient nodes... ");
		return 0;
	}
	else
	{
		temp = start;
		for (i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
			if (temp == NULL)
			{
				printf("\n The list has less number of node than position.");
				return 0;
			}
		}
		nnode = (struct node *)malloc(sizeof(struct node));
		nnode->info = item;
		nnode->next = temp->next;
		temp->next = nnode;
	}
}
// Function for inserting a node at the end of list
void insert_end()
{
	int item;
	struct node *nnode, *temp;
	printf("\n Enter the item:\t");
	scanf("%d", &item);
	nnode = (struct node *)malloc(sizeof(struct node));
	nnode->info = item;
	nnode->next = NULL;
	if (start == NULL)
		start = nnode;
	else
	{
		temp = start;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = nnode;
	}
}
// Function for deleting node at begining of the liked list
int del_beg()
{
	int item;
	struct node *temp;
	if (start == NULL)
	{
		printf("\n Empty List !!!");
		return 0;
	}
	else
	{
		temp = start;
		printf("\n The deleted item is %d", start->info);
		start = start->next;
		free(temp);
	}
}
// Function for deleting node at end of the liked list
int del_end()
{
	int item;
	struct node *temp;

	if (start == NULL)
	{
		printf("\n Empty List !!!");
		return 0;
	}
	else if (start->next == NULL)
	{
		temp = start;
		printf("\n Deleted item is %d", start->info);
		start = NULL;
		free(temp);
	}
	else
	{
		temp = start;
		while (temp->next != NULL)
			temp = temp->next;
		printf("\n The deleted item is %d", temp->info);
		free(temp->next);
		temp->next = NULL;
	}
}
// Function for deleting node at specified position of the liked list
int del_specified()
{
	int item;
	int pos, i;
	struct node *temp, *hold;

	printf("\n Enter the position:\t");
	scanf("%d", &pos);

	if (start == NULL)
	{
		printf("\n Empty List !!!");
		return 0;
	}
	else
	{
		temp = start;
		for (i = 1; i < pos - 1; i++)
		{
			temp = temp->next;
			if (temp == NULL)
			{
				printf("\n Not enough nodes in the list");
				return 0;
			}
		}
		hold = temp->next;
		printf("\n The deleted item is %d", hold->info);
		temp->next = hold->next;
		free(hold);
	}
}
// Function to find the given element in the like list
int search()
{
	struct node *temp;
	int key;
	if (start == NULL)
	{
		printf("\n The list is empty");
		return 0;
	}
	else
	{
		printf("\n Enter search item:\t");
		scanf("%d", &key);

		temp = start;
		while (temp != NULL)

		{
			if (temp->info == key)
			{
				printf("\n Search successful .....");
				break;
			}
			temp = temp->next;
		}
		if (temp == NULL)
			printf("\n Search Unsuccessful !!!");
	}
}
// Function to display all the element of linked list
int display()
{
	struct node *temp;
	if (start == NULL)
	{
		printf("\n The list is empty");
		return 0;
	}
	else
	{
		temp = start;
		printf("\n The list is:\t");
		while (temp != NULL)
		{
			printf("%d ", temp->info);
			temp = temp->next;
		}
	}
}
