#include<iostream>
#include <cstdio>
using namespace std;
#include<math.h>
#include<time.h>
#define MAX 25
int takeInput(int sudoku[MAX][MAX])
{
    int size = 0;
    do
    {
        cout<<"Choose the size of board from\nEnter 1 for 4 X 4\nEnter 2 for 9 X 9\nEnter 3 for 16 X 16\n";
        cout<<"Your Selection:\t";
        cin>>size;
        switch(size)
        {
            case 1:
                size = 4;
                break;
            case 2:
                size = 9;
                break;
            case 3:
                size = 16;
                break;
            default:
                cout<<"Invalid Selection"<<endl;
                break;
        }
    }while(!size);
    cout<<"Enter the Initial "<<size<<" X "<<size<<" Sudoku Board:"<<endl;
    cout<<"Instruction: Enter 0 for blank"<<endl;
    for(int i=0;i<size;i++)
        for(int j=0;j<size; j++)
            cin>>sudoku[i][j];

    return size;
}
void displaySolution(int sudoku[MAX][MAX], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size; j++)
            printf("%4d", sudoku[i][j]);
        cout<<endl;
    }
    cout<<"\n\n*************************************************\n\n";
}
bool isFull(int sudoku[MAX][MAX], int size)
{
    int i,j;
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            if(!sudoku[i][j])
                return false;
    return true;
}
int findPossibleValues(int sudoku[MAX][MAX], int size, int a[], int r, int c)
{
    int n=0;
    int i,j;
    int s=(int)(sqrt(size));
    int b[MAX+1]={0};
    for(i=0; i<size; i++)
        b[sudoku[r][i]]=1;
    for(i=0; i<size; i++)
        b[sudoku[i][c]]=1;
    r=(r/s)*s, c=(c/s)*s;
    for(i=r; i<r+s; i++)
        for(j=c; j<c+s;j++)
            b[sudoku[i][j]]=1;
    for(i=1;i<=size; i++)
        if(!b[i])
            a[n++]=i;
            return n;
}
void SolveSudoku(int sudoku[MAX][MAX], int size, int &solution_num, bool &solved_flag, bool &enough)
{
    int i,j, a[MAX+1]={0}, n=0;
    if(enough)
        return;
    if(isFull(sudoku, size))
    {
        if(!solved_flag)
            cout<<"Sudoku Solved Successfully!"<<endl;
        solved_flag = 1;
        cout<<"\n\nSolution no. "<<(solution_num++)<<endl;
        displaySolution(sudoku, size);
        char more;
        cout<<"Do you want more solutions?"<<endl;
        cout<<"Press 1 for 'YES', anything OTHERWISE:\t";
        cin>>more;
        cout<<"\n\n*************************************************\n\n";
        if(more != '1')
            enough = true;
        return;
    }
    int break_flag = 0;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            if(!sudoku[i][j])
            {
                break_flag = 1;
                break;
            }
        if(break_flag)
            break;
    }
    n = findPossibleValues(sudoku, size, a, i, j);
    for(int l=0;l<n;l++)
    {
        sudoku[i][j]=a[l];
        SolveSudoku(sudoku, size, solution_num, solved_flag, enough);
    }
    sudoku[i][j]=0;
}
int main()
{
    clock_t start,end;
	double d;
	start=clock();
    int sudoku[MAX][MAX] = {0}, size;
    size = takeInput(sudoku);
    int solution_num = 1;
    bool solved_flag = 0;
    bool enough = false;
    cout<<"Finding Solutions!\n\n"<<endl;
    SolveSudoku(sudoku, size, solution_num, solved_flag, enough);
    if(!solved_flag)
        cout<<"Invalid Board!"<<endl;
    cout<<"Exiting!\n\n"<<endl;
    end=clock();
	d=d+(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"Time complexity:"<<d;
	return 0;
}
