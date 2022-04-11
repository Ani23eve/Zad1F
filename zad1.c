#include <pthread.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <float.h>

struct node *start = NULL;

typedef struct {
    uint16_t number;
    char name[250];
    double weight;
    double price;
} product;

typedef struct node{
    product p;
    node* next;
} node;

void copyProduct(product* pr1, product* pr2){
    pr1->number = pr2->number;
    pr1->name = pr2 -> name;
    pr1->weight = pr2->weight;
    pr1->price = pr2->price;
};

void push(node** head, product* val){
    node* new = (node*) malloc(sizeof(node));
    copyProduct(&(new->p), val);
    new->next = *head;
    *head = new;
}

int pop(node** head, product* result){
    if(*head == NULL){
        return -1;
    }
    else{
        node* current = *head;
        *head = current->next;
        copyProduct(result, &(current->p));
        free(current);
        return 0;
    }
}



void display()
{
    node *temp;
    temp = start;
    if (temp == NULL)
    {
        printf("link list is empty");
    } 
    while (temp != NULL)
    {
        printf("%d : ", temp->p);
        temp = temp->next;
    }
}

double totalItemsWeight(node* products){
    double sum = 0.0;
    node *temp;
    temp = products;
    while (temp != NULL)
    {
        sum += temp->p.weight;
        temp = temp->next;
    }
    return sum;
}

node *minPriceItem(node* products){
    double min =__DBL_MAX__;
    node *head;
    head=products;
    while(head !=NULL){
        if (min > head->p.price)
            min = head->p.price;
  
        head = head->next;
    }
    printf("%lf", min);
}
int randInRange(int start, int end){
    return start + rand() % (end - start);
} 

double randForDBL(double min, double max){
     return min + ((double)rand() / RAND_MAX) * (max - min);
}

uint randForUint (uint16_t a, uint16_t b){
    return randInRange(a,b);
}

char randLetter(){
    return randInRange('A','Z' + 1) + randInRange(0, 2) * ('a' - 'A');
}

void randName(char* name, size_t len){
   for(int i=0; i < len; i++){
       name[i] = randLetter();
   }
   name[len] = 0;
}


int main (){

}

