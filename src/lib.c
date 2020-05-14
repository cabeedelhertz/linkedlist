#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


// Initialize an empty list
void initList(List* list_pointer){
	list_pointer->head = NULL;
	list_pointer->tail = NULL;

}
	
// Create node containing item, return reference of it.
Node* createNode(void* item){
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->item = item;
	new_node->next = NULL;
	return new_node;
}

// Insert new item at the end of list.
void insertAtTail(List* list_pointer, void* item){
	Node* new_tail = createNode(item);
	if(list_pointer->head == NULL){
		list_pointer->head = new_tail;
		list_pointer->tail = new_tail;
	}
	
	list_pointer->tail->next = new_tail;
	list_pointer->tail = new_tail;
}

// Insert item at start of the list.
void insertAtHead(List* list_pointer, void* item){
	Node* new_head = createNode(item);
	if(list_pointer->head == NULL){
		list_pointer->head = new_head;
		list_pointer->tail = new_head;
	}
	new_head->next = list_pointer->head;
	list_pointer->head = new_head;
}
// Insert item at a specified index.
void insertAtIndex(List* list_pointer, int index, void* item){
	Node* new_node = createNode(item);
	Node* current = list_pointer->head;
	if(index == 0){
		insertAtHead(list_pointer, item);
	}
	else{
		for(int i=0;i<index-1;i++){
			current = current->next;
		}
		Node* left_node = current;
		Node* right_node = current->next;
		new_node->next = right_node;
		left_node->next = new_node;
	}
}

// Remove item from the end of list and return a reference to it
void* removeTail(List* list_pointer){
	if(list_pointer->head == NULL){
		return list_pointer->head->item;
	}
	Node* current = (Node*) list_pointer->head;
	Node* after_current = current->next;
	while(after_current->next != NULL){
		current = current->next;
		after_current = current->next;
	}
	void* removed = after_current->item;
	free(current->next);
	list_pointer->tail = current;
	return removed;
}

// Remove item from start of list and return a reference to it
void* removeHead(List* list_pointer){
	Node* current = (Node*)list_pointer->head;
	void* removed = current->item;
	current = current->next;
	free(list_pointer->head);
	list_pointer->head = current;
	return removed;
}

// Insert item at a specified index and return a reference to it
void* removeAtIndex(List* list_pointer, int index){
	Node* current = list_pointer->head;
	if(index == 0){
		void* removed = removeHead(list_pointer);
		return removed;
	}
	else{
		for(int i=0;i<index-1;i++){
			current = current->next;
		}
		Node* left_node = current;
		Node* remove_node = current->next;
		Node* right_node = remove_node->next;
		void* removed = remove_node->item;
		free(remove_node);
		left_node->next = right_node;
		return removed;
	}

}

// Return item at index
void* itemAtIndex(List* list_pointer, int index){
	Node* current = list_pointer->head;
	if(index == 0){
		return current->item;;
	}
	else{
		for(int i=0;i<index;i++){
			current = current->next;
		}
		return current->item;
	}
}


void printList(List* list) {
	Node* node;

  // Handle an empty node. Just print a message.
	if(list->head == NULL) {
		printf("\nEmpty List");
		return;
	}
	
  // Start with the head.
	node = (Node*) list->head;

	printf("\nList: \n\n\t"); 
	while(node != NULL) {
		printf("[ %p ]", node->item);

    // Move to the next node
		node = (Node*) node->next;

		if(node !=NULL) {
			printf("-->");
    }
	}
	printf("\n\n");
}