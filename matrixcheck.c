#include<stdio.h>
#include<stdlib.h>
int main()
{
	int c;

	printf("\n1.SKEWSYMMETRIC OR SYMMETRIC \n2.DIAGONAL MATRIX \n3.UPPER OR LOWER TRIANGLE \n4.IDENTITY OR NULL OR UNITY \n5.INVERSE MATRIX \n6.EXIT");
   
	while(1)
	{
		 printf("\nenter the case");
	     scanf("%d",&c);
		switch(c)
		{
			case 1: symmetricskew();
					break;
			case 2: diagonal();
					break;
			case 3: triangle();
					break;
			case 4: unitynullidentity();
					break;
			case 5: inverse();
					break;
			case 6: goto XX;
					break;
					

		    default:printf("\n enter the correct case");
		}
	}
	XX:return 0;
}
int symmetricskew()
{
	int A[100][100],B[100][100],i,j,n,m,c1=0,c2=0;
	printf("enter the rows and coloumns");
	scanf("%d%d",&n,&m);
	printf("enter the elements");
	if(m==n)
	{
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		  B[j][i]=A[i][j];
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(B[i][j]==0&&A[i][j]==0)
			{
				c1++;
				c2++;
			}
		  else if(B[i][j]==A[i][j])
		  {
		  	c1++;
		  }
		  else if(B[i][j]==-A[i][j])
		  {
		  	c2++;
		  }
		  else{
		  	break;
		  }
		}
	}
	printf("%d%d",c1,c2);
		if(c1==(n*m))
			printf("\n the matrix is symmetric");
		else if(c2==(n*m))
		printf("\n the matrix is skew symmetric");
		else
		printf("\n the matrix is neither skew symmetric nor symmetric");
	
	
}
	else
		printf("the matrix is not square matrix");
	
}
int diagonal()
{
	int A[100][100],n,i,j,c=0;
	printf("enter the no of rows and coloumns");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	//to check whtr it is a diagonal matrix
	for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		
		
		if(i!=j&&A[i][j]==0)
		{
			c++;
		}
	}
	}	
	if(c==(n*n)-n)
	printf("diagonal matrix");
	else
	printf("non-diagonal matrix");
}
int triangle()
{
	int A[100][100],B[100][100],i,j,n,m,c1=0,c2=0;
	printf("enter the rows and coloumns");
	scanf("%d%d",&n,&m);
	printf("enter the elements");
	if(m==n)
	{
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
		for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i!=j)
			{
				if(i>j &&A [i][j]==0)
				   c1++;
				else if(i<j&&A[i][j]==0)
					c2++;
			
			
			}
			}
		}
						    printf("%d",c2);

			if(c1+c2==(n*m)-n)
				printf("\n both upper and lower triangular ");
			else if(c1==((n*m)-n)/2)
				{
				printf("\n upper triangular matrix");
		     }
			else if(c2==((n*m)-n)/2)
				printf("\n lower triangular matrix");
			else
				printf("\n neither upper nor lower ");
}
	else
		printf("\n it is not a square matrix");
}
int unitynullidentity()
{
		int A[100][100],B[100][100],i,j,n,m,c1=0,c2=0;
	printf("enter the rows and coloumns");
	scanf("%d%d",&n,&m);
	printf("enter the elements");
	if(m==n)
	{
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
		for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(A[i][j]==0)
			c1++;
			else if(A[i][i]==1)
			c2++;
			else
			    break;
		}
	}
	if(c1==(n*m))
	printf("\n null matrix");
	else if(c1==(n*m)-n&&c2==n)
	printf("\n identity matrix");
	else if(c2==(n*m))
	printf("\n unity matrix");
	else
	printf("\n neither null nor identity");
	
	
}
	else
		printf("\n not a square matrix");
}
int inverse()
{
int A[100][100],B[100][100],i,j,n,m,p,q,sum=0,C[100][100],k,c1=0,c2=0;
	printf("enter the rows and coloumnsof A");
	scanf("%d%d",&n,&m);
	printf("\n enter the elements of A");

	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
		printf("\n enter the rows and coloumns of B");
	scanf("%d%d",&p,&q);
	printf("\n enter the elements");

	
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	if(m==p)
	{
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<q;j++)
		{
			
			for(k=0;k<m;k++)
			{
				sum=sum+A[i][k]*B[k][j];
			}
			printf("%d",sum);
			C[i][j]=sum;
			printf("%d",C[i][j]);
			sum=0;
		}
	}
	printf("\n the multiplied matrix is");
		for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<q;j++)
		{
			printf("%d",C[i][j]);
		}
	}
}
	if(n==q)
	{

		for(i=0;i<n;i++)
	{
		for(j=0;j<q;j++)
		{
			if( i!=j&&C[i][j]==0)
			c1++;
			if(i==j&&C[i][j]==1)
			c2++;	
		}
	}

	if(c1+c2==(n*q))
		printf("\n B is an inverse matrix of A");
	else
		printf("\n B is not an inverse matrix of A");
}
else
	printf("\n AXB is not a square matrix ");
		
}