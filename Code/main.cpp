#include <iostream>
using namespace std;
// counter variable for point 2 used in function multmat
int counter =0;

//Naive function to calculate n*n matrices multiplication
void multiplyNaive(int **A, int **B, int **C,int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
}
// Matrix multiplication using recursive way " Partitioning"
void MatrixMul(int **a, int **b, int **result , int rowA ,int colA,int rowB,int colB ,int n,int Matsize){
    if(n==1){
        if (counter <= (Matsize*2 - 1)){
            result[rowA][colB] += a[rowA][colA]*b[rowB][colB];
            counter++;
        }
    }
    else{
        MatrixMul(a,b,result,rowA,colA,rowB,colB,n/2,Matsize);
        MatrixMul(a,b,result,rowA,colA+(n/2),rowB+(n/2),colB,n/2,Matsize);
        MatrixMul(a,b,result,rowA,colA,rowB,colB+(n/2),n/2,Matsize);
        MatrixMul(a,b,result,rowA,colA+(n/2),rowB+(n/2),colB+(n/2),n/2,Matsize);
        MatrixMul(a,b,result,rowA+(n/2),colA,rowB,colB,n/2,Matsize);
        MatrixMul(a,b,result,rowA+(n/2),colA+(n/2),rowB+(n/2),colB,n/2,Matsize);
        MatrixMul(a,b,result,rowA+(n/2),colA,rowB,colB+(n/2),n/2,Matsize);
        MatrixMul(a,b,result,rowA+(n/2),colA+(n/2),rowB+(n/2),colB+(n/2),n/2,Matsize);
}
}

// Strassen method to calculate the matrix multiplication of 2*2 matrices in lower time complexity
void strassen2x2(int **a, int **b,int **c){

    int m1,m2,m3,m4,m5,m6,m7;

     m1= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
     m2= (a[1][0]+a[1][1])*b[0][0];
     m3= a[0][0]*(b[0][1]-b[1][1]);
     m4= a[1][1]*(b[1][0]-b[0][0]);
     m5= (a[0][0]+a[0][1])*b[1][1];
     m6= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
     m7= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
     c[0][0]=m1+m4-m5+m7;
     c[0][1]=m3+m5;
     c[1][0]=m2+m4;
     c[1][1]=m1-m2+m3+m6;

}

int main()
{   int n=0;

     cout<<"Enter the size of n*n Matrices :\n";
     cin >> n;
     //Create matrices
     int ** a;
     int ** b;
     int ** c;

     a = new int *[n];
     b = new int *[n];
     c = new int *[n];

     for(int i = 0; i <n; i++){
        a[i] = new int[n];
        b[i] = new int[n];
        c[i] = new int[n];
     }
    // Let the user initialize matrices
     cout<<"Enter the elements of n*n Matrix 1:\n";
        int i,j;
         for(i=0;i<n;i++)
         {
          for(j=0;j<n;j++)
          {
           cin>>a[i][j];
          }
         }

    cout<<"Enter the elements of 2x2 Matrix 2:\n";
     for(i=0;i<n;i++)
     {
      for(j=0;j<n;j++)
      {
       cin>>b[i][j];
      }
     }
    // Display Matrices entered
    cout<<"\nFirst matrix is:\n";
     for(i=0;i<n;i++)
     {
      for(j=0;j<n;j++)
      {
       cout<<a[i][j]<< " ";
      }
      cout<<"\n";
     }
    cout<<"\nSecond matrix is\n";
         for(i=0;i<n;i++)
         {
          for(j=0;j<n;j++)
          {
           cout<<b[i][j]<<" ";
          }
          cout<<"\n";
         }
    // Choose which way of multiplication you prefer and read carefully for requirement to be valid way of multiplication
    cout << "Choose way of multiplication :\n";
    cout << "1-Naive :\n";
    cout << "2-Partitioning for n powers of 2:\n";
    cout << "3-Strassen only 2x2 matrices :\n";
    int order=0;
    cin>>order;
    if (order ==1){

        multiplyNaive(a,b,c,n);
    }
    else if(order ==2)
        MatrixMul(a,b,c,0,0,0,0,n,n*n);
    else if(order == 3)
        strassen2x2(a,b,c);
    // Display output
    cout<<"\n Output from multiplication is\n";
         for(i=0;i<n;i++)
         {
          for(j=0;j<n;j++)
          {
           cout<<c[i][j]<<" ";
          }
          cout<<"\n";
         }
	return 0;
}
