#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../WarungBude/Models.h"
#include "../WarungBude/utils.h"

Node *createNode(int value) {
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->value = value;
  temp->next = temp->prev = NULL;
  return temp;
}

void pushHead(int value){
    Node *temp = createNode(value);
    if(!head){
        head = tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void pushTail(int value){
    Node *temp = createNode(value);
    if(!head){
        head = tail = temp;
    } else {
        temp->next = temp;
        head = temp;
    }
}
void pushMid(int value) {
  if(!head) { // tidak ada node
    Node *temp = createNode(value);
    head = tail = temp;
  } else if(value < head->value) { // nilai kurang dari head
    pushHead(value);
  } else if(value > tail->value) { // nilai lebih dari tail
    pushTail(value);
  } else { // nilai di antara head dan tail
    Node *temp = createNode(value);
    curr = head;

    // selama nilainya kurang dari value
    while(curr->value < value) {
      curr = curr->next;
    }

    temp->prev = curr->prev;
    temp->next = curr;

    curr->prev->next = temp;
    curr->prev = temp; 
  }
}

void popHead(){
    if (!head){
        return;
    } else if (head == tail){
        head = tail = NULL;
        free(head);
    } else {
        Node *newHead = head->next;
        head->next = NULL;
        free(head);
        head = newHead;
    }
}

void popTail(){
    if (!head){ 
        return;
    } else if (head == tail){
        head = tail = NULL;
        free(head);
    } else {
        Node *newTail = tail->prev; // A -><- B (newTail) -><- C (tail)
        tail->prev = newTail->next = NULL; // A -><- B (newTail) C (tail)
        free(tail); // A -><- B (newTail)
        tail = newTail; // A -><- B (tail)
    }
}

void popMid(int value) {
  if(!head) {
    return;
  } else if(head->value == value) {
    popHead(); // jika nilai head adalah yang mau kita hapus
  } else if(tail->value == value) {
    popTail(); // jika nilai tail adalah yang mau kita hapus
  } else { // jika nilai yang mau kita hapus ada di tengah2
    curr = head;

    while(curr && curr->value != value) {
      curr = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    curr->prev = curr->next = NULL;
    free(curr);
  }
}