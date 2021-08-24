//Program to implement a List using Array and develop functions to perform insertion, deletion and linear search operations.
#include <stdio.h> 
int search(int *a);
int insert(int*a1);
int delete(int*a2);
int main()  
{
    int arr1[50]; 
    int choice;
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
    	case 1:
    	printf("Search an element from the Array\n");
		search(arr1);
		break;
		case 2:
		printf("Insert an element from the Array\n");	
		insert(arr1);
		break;
		case 3:
		printf("Delete an element from the Array\n");
		delete(arr1);	
		return 0;	
	}
}
	int search(int a[])
	{
		int s,i,element,pos;
		printf("\nEnter size of array : ");
		scanf("%d",&s);
		printf("\nEnter %d elements : ",s);
		for(i=0;i<s;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("\nElements of Array are : ");
		for(i=0;i<s;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\nEnter element to search : ");
		scanf("%d",&element);
		
		for(i=0;i<s;i++)
		{
			if(a[i]==element)
			{
				pos=1;
				break;		
			}
		}
			if(pos==1)
			{
				printf("\n%d is found at %d position in the array",element,i+1);
			}
			else
			printf("\n%d is not found in the array",element);	
			return 0;
	}
	
	int insert(int a1[])
	{
		int n,s,j;
		printf("\nEnter size of Array : ");
		scanf("%d",&s);
			for(j=0;j<s;j++)
		{
			scanf("%d",&a1[j]);
		}
		printf("\nArray before insertion of element : ");
			for(j=0;j<s;j++)
		{
			printf("%d ",a1[j]);
		}
		printf("\nEnter number to insert : ");
		scanf("%d",&n);
		s=s+1;
		a1[s-1]=n;
		printf("\nArray after insertion of %d is : ",n);
		for(j=0;j<s;j++)
		{
			printf("%d ",a1[j]);
		}
	}
	
	int delete(int a2[])
	{
		int k,size,pos;
		printf("Enter size of array : ");
		scanf("%d",&size);
		for(k=0;k<size;k++)
		{
			scanf("%d",&a2[k]);
		}
		printf("Array before deletion: ");
		for(k=0;k<size;k++)
		{
			printf("%d ",a2[k]);
		}
		printf("\nEnter element to delete:");
		scanf("%d",&pos);
		size=size-1;
		for(k=pos;k<size;k++)
		{
			a2[k]=a2[k+1];
		}
			printf("\nArray after deletion of element : ");
		for(k=0;k<size;k++)
		{
			printf("%d ",a2[k]);
		}	
	}