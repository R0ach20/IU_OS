#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
	int value;
	struct LinkedList *next;
};

typedef struct LinkedList LinkedList;

void print_list(LinkedList* head){
	while(head != NULL){
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void instert_node(LinkedList **list, int x, int at){
	LinkedList* head = *list;
	//New Node
	LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
	temp->value = x;
	temp->next = NULL;

	if(at == 0){
		temp->next = head;
		*list = temp;
	}else{
		for(int i=1; i<at; i++)
			head = head->next;


		temp->next = head->next;
		head->next = temp;
	}	
}

int delete_node(LinkedList **list, int x){
	LinkedList* head = *list;
	int deleted = 0;
	LinkedList* prev = NULL;//previous node

	while(head != NULL){
		if(head->value == x){			
			if(prev != NULL){
				prev->next = head->next;
			}else{
				*list = head->next;
			}
			free(head);
		}else{//goto next
			prev = head;
			head = head->next;
		}
	}
}


int main(int argc, char const *argv[]){
	LinkedList* head = NULL;

	instert_node(&head, 1, 0);
	print_list(head);//1

	instert_node(&head, 0, 0);
	print_list(head);//0 1

	instert_node(&head, 3, 2);
	print_list(head);//0 1 3

	instert_node(&head, 2, 2);
	print_list(head);//0 1 2 3

	print_list(head);//0 1 2 3

	delete_node(&head, 0);
	print_list(head);//1 2 3

	delete_node(&head, 5);
	print_list(head);//1 2 3

	delete_node(&head, 1);
	print_list(head);//2 3

	delete_node(&head, 3);
	print_list(head);//2

	return 0;
}