# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int det(int **p,int n);
int **cofactor(int **p,int n,int k);

int main()
{	
	//
	int n;
	printf("Enter the order of matrix:\n");
	scanf("%d",&n);
	

	//We are creating an 2D array to store the elments
	printf("Enter the elements of the matrix row wise:\n");
	int **a;
	a=(int **)malloc((n)*sizeof(int *));
	for(int i=0;i<n;i++){
		a[i]=(int *)malloc((n)*sizeof(int));
	}
   	for(int i=0;i<n;i++){
   	   	for(int j=0;j<n;j++){
           	scanf("%d",&a[i][j]);
   	   	}
   	}


   	printf("Determinant = %d\n",det(a,n));

return 0;
}

int det(int **p,int n)
{
	if(n==1){return p[0][0];}//Base condition
	int t=0;
	for(int j=0;j<n;j++){
		t+=((pow(-1,j))*(p[0][j])*det(cofactor(p,n,j),n-1));
	}
return t;
}

int **cofactor(int **p,int n,int k)
{
	int **q;
	q=(int **)malloc((n-1)*sizeof(int *));
	for(int i=0;i<n-1;i++){
		q[i]=(int *)malloc((n-1)*sizeof(int));
	}
	for(int j=0;j<(k);j++){
		for(int i=1;i<=n-1;i++){
	    	q[i-1][j]=p[i][j];
		}
	}
	for(int j=k+1;j<=n-1;j++){
		for(int i=1;i<=n-1;i++){
	    	q[i-1][j-1]=p[i][j];
		}
	}

return q;
}