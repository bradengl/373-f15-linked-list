#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t* tempPointer = head;
	int inserted = 0;
	if( new_element->index < tempPointer->index ) {
	  new_element->next = head;
	  head = new_element;
	  inserted = 1;
	}

	while( inserted==0 && tempPointer->next != NULL ) {
	  if(new_element->index < tempPointer->next->index) {
	    new_element->next = tempPointer->next;
	    tempPointer->next = new_element;
	    inserted = 1;
	  }
	  else {
	    tempPointer = tempPointer->next;
	  }
	}
	if( inserted==0 ) {
	  tempPointer->next = new_element;
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* tempPointer = head;
	list_t* tempNext = head->next;
	list_t* tempPrev = NULL;
	tempPointer->next = tempPrev;
	tempPrev = tempPointer;
	tempPointer=tempNext;
	
	while( tempPointer->next != NULL ) {
	  tempNext = tempPointer->next;
	  tempPointer->next = tempPrev;
	  tempPrev = tempPointer;
	  tempPointer=tempNext;
	}

	tempNext = tempPointer->next;
        tempPointer->next = tempPrev;
	tempPrev = tempPointer;
        
	head = tempPointer;


	return head;
}



