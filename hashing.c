#include<stdio.h>
#define size 7
int array[size];
void init()
{
	int i;
	for(i=0;i<size;i++)
	array[i]=-1;
}
void insert(int val)
{
	int key=val%size;
	if(array[key]==-1)
	{
		array[key]=val;
		printf("%d inserted at array[%d]\n",key,val);
	}
	else
	{
		printf("Collison:array[%d] already has element %d",key,array[key]);
		printf("\n unable to insert %d",val);
	}
}
void del(int val)
{
	int key=val%size;
	if (array[key]==val)
		array[key]=-1;
	else
		printf("%d not present in the hash table\n",val);
}
void search(int val)
{
	int key=val%size;
	if (array[key]==val)
	printf("\n element found");
	else
		printf("\n not found");
}
void print()
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("array[%d]=%d\n",i,array[i]);
	}
}
int main()
{
	init();
	insert(10);
	insert(4);
	insert(3);
	insert(2);
	
	printf("\n hash table");
	print();
	printf("\n");
	
	printf("\n deleting the value 10");
	del(10);
	printf("\n after deletion the hash table is\n");
	print();
	printf("\n");
	
	printf("\n deleting the value 5");
	del(5);
	printf("\n after deletion the hash table is\n");
	print();
	printf("\n");
	
	printf("\n searching value 4");
	search(4);
	printf("\n searching the value 10");
	search(10);
	printf("\n");
	
	return 0;
}
