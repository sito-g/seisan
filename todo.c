#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct todo
{
    int count;
    char data[100];
    struct  todo *link;  
};

struct todo *head=NULL;

//function defination
void create_todo();
void display_todo();
void counter();
void update();
void in_between_update();
void d_todo();
void delete_in_between();
void completion();
void expot();
void wlc();


int main(){
    int x,z,p;
    wlc();
    system("pause");
    while (1)
    {
    
    system("cls");
    printf("\t\t\t\tEnter 1 for creating list\n");
    printf("\n");
    printf("\t\t\t\tEnter 2 for displaying list\n");
    printf("\n");
    printf("\t\t\t\tEnter 3 for update list\n");
    printf("\n");
    printf("\t\t\t\tEnter 4 for deleting  list\n");
    printf("\n");
    printf("\t\t\t\tEnter 5 for marking completion\n");
    printf("\n");
    printf("\t\t\t\tEnter 6 for exporting list\n");
    printf("\n");
    printf("\t\t\t\tEnter 7 for exit\n");
    printf("\n");
    printf("\t\t\t\t------------------------------\n");
    printf("\n");
    printf("\t\t\t\tEnter the choice: ");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        create_todo();
        break;
     case 2:
        display_todo();
        break;
    case 3:
    system("cls");
        printf("\t\t\t\tEnter 1 for serially update\n");
         printf("\n");
        printf("\t\t\t\tEnter 2 for inserting in between\n");
         printf("\n");
         printf("\t\t\t\t------------------------------\n");
        printf("\n");
        printf("\t\t\t\tEnter the choice");
        scanf("%d",&z);
        if(z==1){
            update();
        }
        if(z==2){
            in_between_update();
        }
        break;
    case 4:
    system("cls");
    printf("\t\t\t\tEnter 1 for deleting all\n");
    printf("\n");
    printf("\t\t\t\tEnter 2 specific delete\n");
    printf("\n");
    printf("\t\t\t\t------------------------------\n");
    printf("\n");
    printf("\t\t\t\tEnter the choice:");
    scanf("%d",&p);
    if(p==1){
         d_todo();
    }
    else{
        delete_in_between();
    }
     break;

    case 5:
        completion();
        break;
        
    case 6:
        expot();
        break;

    case 7:
        exit(0);
    }
    }  
}
void create_todo(){
     char a;

    struct todo *pt1, *pt2;
    system("cls");

     while(1){
        printf("\t\t\t\tWant to add? y/n\n\t\t\t\t");
        fflush(stdin);
        scanf("\t\t\t\t%c",&a);
        if (a =='n'){
            break;
        }
    else
        {
         if(head==NULL){
        
            pt1=(struct todo *)calloc(1,sizeof(struct todo));
            head=pt1;
            printf("\t\t\t\tBegin list\n\t\t\t\t");
            fflush(stdin);
            gets(head->data);
            pt1->count=1;
            head->link=NULL;
            }
            else{
                pt2=(struct todo *)calloc(1,sizeof(struct todo));
                printf("\t\t\t\tWrite another lsit here\n\t\t\t\t");
                fflush(stdin);
                gets(pt2->data);
                pt2->link=NULL;
                pt1->link=pt2;   //linking the memory address
                pt1=pt1->link;  //pt1 will point to the give node by user shifting

            }      
            counter();
        
        }
  
    }   
     
}

void counter(){
    struct todo *pt1;
    int i=1;
    pt1=head;
    while (pt1!=NULL)
    {
        pt1->count=i;
        i++;
        pt1=pt1->link;
    }
    
}

void display_todo(){  //remaing for empty list 
    struct todo *pt1;
    system("cls");
    if(head==NULL){
        printf("\t\t\t\tEmpty list\n");
        
    }
    else{
    pt1=head;
    while (pt1!=NULL)
    {
        printf("\t\t\t\t%d) %s",pt1->count,pt1->data);
        printf("\n");
        
        pt1=pt1->link;
    }
    }
    system("pause");

}


void update(){
    
    struct todo *pt1,*pt2;
    char a;
    if(head==NULL){
        printf("\t\t\t\tfirst create list.");
        system("pause");
    }
    else{
    
    while(1){
        printf("\t\t\t\tWant to add? y/n\n\t\t\t\t");
        fflush(stdin);
        scanf("\t\t\t\t%c",&a);
        
        if(a=='n'){
            break;
        }
        printf("\t\t\t\twrite here\n\t\t\t\t");
        pt1=(struct todo *)calloc(1,sizeof(struct todo));
        fflush(stdin);
        gets(pt1->data);
        pt1->link=NULL;
        pt2=head;
        while(pt2->link!=NULL){
            pt2=pt2->link;
        }
        pt2->link=pt1;
        counter();
    }
    }
}

        
void in_between_update(){
    struct todo *pt1,*pt2;
    char a;
    int len,i;
    while(1){
        printf("\t\t\t\tWant to add? y/n\n\t\t\t\t");
        fflush(stdin);
        scanf("\t\t\t\t%c",&a);
        
        if(a=='n'){
            break;
        }
        printf("\t\t\t\tenter the number where you want to add:");
        scanf("%d",&len);
        printf("\t\t\t\twrite here\n\t\t\t\t");
        pt1=(struct todo *)calloc(1,sizeof(struct todo));
        fflush(stdin);
        gets(pt1->data);
        pt1->link=NULL;
        pt2=head;
        if(len==1){
            pt1->link=head;
            head=pt1;
        }
        else{
        for(i=1; i<(len-1); i++){
            pt2=pt2->link;         
        }
        pt1->link=pt2->link;
        pt2->link=pt1;
        }
        counter();

    }

}
void d_todo(){
    head=NULL;
    printf("\t\t\t\tdeleted all");
    system("pause");

}
void delete_in_between(){
    struct todo *pt1,*pt2;
    char a;
    int len,i;
    while(1){
        printf("\t\t\t\tWant to delete? y/n\n\t\t\t\t");
        fflush(stdin);
        scanf("\t\t\t\t%c",&a);
        
        if(a=='n'){
            break;
        }
        printf("\t\t\t\tenter the number which you want to delete:");
        scanf("%d",&len);
        
        pt1=pt2=head;
        
         if(len==1){
             head=head->link;
             
         }
         else{
        for(i=1; i<(len); i++){
            pt2=pt2->link;         
        }
        for(i=1; i<(len-1); i++){
            pt1=pt1->link;         
        }
         pt1->link=pt2->link;
        pt2->link=NULL;

         }
       
        counter();
    }
}

void completion(){
    struct todo *pt1;
    char a;
   
    int len,i;
    while(1){
        printf("\t\t\t\tWant to mark completion? y/n\n\t\t\t\t");
        fflush(stdin);
        scanf("\t\t\t\t%c",&a);
        
        if(a=='n'){
            break;
        }
        printf("\t\t\t\tEnter the number which you want to mark:");
        scanf("%d",&len);
        
        pt1=head;
        
        
       
        for(i=1; i<(len); i++){         
            pt1=pt1->link;  
        }
        
        strcat(pt1->data,"| Completed");
         }
    }


    void expot(){
        system("cls");
        struct todo *pt1;
        FILE *fp;
        char a[10];
        

    if(head==NULL){
        printf("\t\t\t\tNo list to export\n");
        
    }
    
    else{
        printf("\t\t\t\tEnter file name. Must contain .txt extension.\n\t\t\t\t");
        scanf("%s",a);
        printf("\t\t\t\tExporting.....\n");
    fp=fopen(a,"w+");
    pt1=head;
    while (pt1!=NULL)
    {
        fprintf(fp, "%d) %s\n",pt1->count,pt1->data);
        pt1=pt1->link;
    }
    fclose(fp);
    }
    printf("\t\t\t\tExpoted\n");
    system("pause");
    }


void wlc(){
    printf("\n");
    printf("\n");
    printf("\t\t\t\t---------------------------------------------\n");
    printf("\t\t\t\t         Welcome to the project Seisan.\n");
    printf("\t\t\t\t---------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t->Stay productive with our TODO list app.\n");
    printf("\n");
    printf("\t\t\t\t->Create, Edit, refine your day.\n");
    printf("\n");
    printf("\t\t\t\t->Set your goals and expot it to your system.\n");
    printf("\n");
    printf("\t\t\t\t->Many more to come.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\tDeveloped by->Sitto   github->sito-g   instagram->Si_tto_\n");

}


    