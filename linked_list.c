#include<stdio.h>
#include<stdlib.h>
struct node {
  int value;
  struct node*next; //struct node* next;: هذا هو الجزء الأهم. هو عبارة عن مؤشر (Pointer) يشير إلى العنوان البريدي للعقدة التالية في الذاكرة. نوعه هو نفس نوع الهيكل نفسه (struct node) لأنه سيشير إلى "صندوق" آخر من نفس النوع.
 
};
typedef struct node node;//من كتابة struct node في كل مرة تريد فيها تعريف متغير جديد، يمكنك الآن كتابة كلمة nod
typedef node* list; //the head
list l;
void init(list*l){
  *l=NULL;

}

void insertt(list *l, int x){
  node* newnode=(node*)malloc(sizeof(node));
  if(newnode==NULL){
    printf("error");
  }else{
    newnode->value=x;
    newnode->next=*l;
    *l=newnode;
  }

  }



 node* search(list l, int x, int *position){
  node* current=l;
  int pos=0;
  while(current!=NULL){
    current=current->next;
    pos++;
    if(current->value==x){
      *position=pos;
      return current;
    }
    
    
  }
  return NULL;
  }
  void dele(list*l,int position ){
    int pos_counter=0;
    node*prev=NULL;
    node*del= *l;
    if (*l == NULL) {
        printf("List is empty. Cannot delete.\n");
        
    }
    if (position == 0) {
        *l = del->next;
        free(del);
        return;
    }
    while(del!=NULL && pos_counter < position){
      prev=del;
      del=del->next;
      pos_counter++;

    }
    if (del == NULL) {
        printf("Position not found. Cannot delete.\n");
        return;
    }
    prev->next=del->next;
    free(del);
  }
  void print(list l){
    node* current=l;
    if (current == NULL) {
      printf("List is empty");
  }else{
    while(current!=NULL){
      printf("%d",current->value);
      current=current->next;

    }
  }
}
  int main(){
    list l;
    int a ,b,c,x;
    
printf("Enter 3 values to fill the list:\n");
    scanf("%d %d %d", &a, &b, &c);
    insertt(&l, a);
    insertt(&l, b);
    insertt(&l, c);
    printf("Current list: ");
    print(l);
    printf("enter the value to search and delete: ");
    scanf("%d",&x);
    int position ;
    node* found=search(l,x,&position);
    if(found!=NULL){
      printf("value found at position %d", position);
       dele(&l,position);
      printf("the list after deletion");
    print(l);
    }else {
      printf("value not found");
    }
       
   return 0;

  }



 
  
  



     

