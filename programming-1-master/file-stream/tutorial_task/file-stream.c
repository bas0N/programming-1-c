#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	double data;
	struct node* next;
} node;

typedef struct {
	node* top;
} stack;

void printArray(const char* filename);
int isEmpty(const stack* s);
void push(stack* s, double data);
double pop(stack* s);
void print_stack(const stack* s);
stack build_stack(const char* filename);
void dump_stack(stack* s, const char* filename);
stack build_stack_n(const char* filename, int n);

void printArray(const char* filename){
    FILE *f =fopen(filename,"r");
    if(f==NULL){
        puts("Cannot open the file!");
        return;
    }
    double object;
    while(fread(&object,sizeof(double),1,f)==1)
    {
        printf("%.2lf\n",object);  //.2  how many digits after the point
    }
    //fread returns the total numbe of succesfully returned elements
    if(feof(f)!=1){
        puts("File has not been read properly!");
    }
    /*
    feof(f) checks if the functionnhas been read till the end properly
    0 means that the end has been reached
    */
      fclose(f);

}
int isEmpty(const stack* s){
if(s->top==NULL){
    return 1;
}else{
    return 0;
}
}

void push(stack* s, double data){
    node * el = calloc(1,sizeof(node));
    if(el==NULL){
        return NULL;
    }
    el->data=data;
    if(isEmpty(s)==1){
        s->top=el;

    }else{
        el->next=s->top;
        s->top=el;
    }
}

double pop(stack* s){
    double k;
    if(isEmpty(s)==1){
        printf("isEmpty");
        return 0;
    }else{
        node *temp = s->top;
        k=s->top->data;
        s->top=s->top->next;
        free(temp);
    }
    return k;
}

void print_stack(const stack* s){
    if(s->top==NULL){
        return;
    }
    for(node * tmp=s->top; tmp!=NULL;tmp=tmp->next){
        printf("%.2lf",tmp->data);
    }
}

stack build_stack(const char* filename){
    stack st;
    st.top==NULL;
    FILE *f =fopen(filename,"r");
    if(f==NULL){
        puts("Cannot open the file!");
        return;
    }
    double object;
    while(fread(&object,sizeof(double),1,f)==1)
    {
        push(&st,object);
    }
    //fread returns the total numbe of succesfully returned elements
    if(feof(f)!=1){
        puts("File has not been read properly!");
    }
    /*
    feof(f) checks if the functionnhas been read till the end properly
    0 means that the end has been reached
    */
   fclose(f);
}



int main()
{
	// Part 1 
	
	puts("********** Part 1 **********");
	printArray("array.bin");
	

	// Part 2
	/*
	puts("\n\n********** Part 2 **********");
	stack s = { NULL };
	push(&s, 2);
	push(&s, 4);
	push(&s, 6);
	print_stack(&s);
	putchar('\n');
	double data = pop(&s);
	print_stack(&s);
	putchar('\n');
	data = pop(&s);
	print_stack(&s);
	putchar('\n');
	data = pop(&s);
	print_stack(&s);
	*/

	// Part 3
	/*
	puts("\n********** Part 3 **********");
	s = build_stack("array.bin");
	print_stack(&s);
	*/

	// Part 4
	/*
	puts("\n********** Part 4 **********");
	dump_stack(&s, "stack.txt");
	print_stack(&s);
	*/

	// Part 5
	/*
	puts("\n********** Part 5 **********");
	s = build_stack_n("array.bin", 2);
	print_stack(&s);
	*/

	return 0;
}