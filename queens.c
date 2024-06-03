// program on the queens
#include<stdio.h> // to use inbult functions like printf and scanf
#include<math.h> // to use the matmatical functions like squ and abs
int a[100],count=0; // globle varibles
int place(int pos) // subfunction to keep the queen position
{//place function starts 
	int i; // lookle varible to controle the loop
	for (i=1;i<pos;i++)// for loop starts
	{
		if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos)))) // checking the condition whather
//															// we can place the queen at that position or not		                                                
		return 0;// no need to return any thing
	}
	return 1; 
}//place function ends
void print_sol(int n) //to print the matrix 
{//print sol function starts
	int i,j; // loop controle variables 
	count++;// to count the solutions
	printf("\n\nSolution #%d:\n",count); //printing the count
	for (i=1;i<=n;i++) //printing the solution matrix 
	{
		for (j=1;j<=n;j++) 
		{
			if(a[i]==j)
			    printf("Q\t"); 
			else
			    printf("*\t");
		}
		printf("\n");
	}
}//print sol function ends
void queen(int n) //queen function starts 
{                  // back tracking  
	int k=1;  // seting the queen on the top left that is at the 1 part of the array
	a[k]=0;
	while(k!=0) //forming the loop to repeat the steps untile k not = 0 
	 {
		a[k]=a[k]+1;// moving the place of the queen 
		while((a[k]<=n)&&!place(k))  // the loop will be repeat until the queen is placecd safe
		   a[k]++;     // increment the k value 
		if(a[k]<=n)   //checking erather the k value is less than or equal to the entered n value
		 {
			if(k==n)  // if the k value is equal to n then print the solution
			    print_sol(n);
			 else
			{
				k++;  //else incremnt the k value 
				a[k]=0;
			}
		} else    //if the queen is not safe we reduse the k value 
		   k--;
	}
}// queen function ends
void main() 
{// main function starts
	int i,n;
	printf("Enter the number of Queens\n");
	scanf("%d",&n);
	queen(n);
	printf("\nTotal solutions=%d",count);
	
}// end of the main function
