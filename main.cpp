#include <iostream>
#include <fstream>
#include <istream>

using namespace std;

int A[11][11],n=9;

void Show()
{
    cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

bool isSafe(int num,int row,int col)
{
    for(int i=1;i<=n;i++)
        if(A[i][col]==num)
            return false;
    for(int j=1;j<=n;j++)
        if(A[row][j]==num)
            return false;
    int startRow;
    if(row<4)
        startRow=1;
    else if(row<7)
        startRow=4;
    else startRow=7;

    int startCol;
    if(col<4)
        startCol=1;
    else if(col<7)
        startCol=4;
    else startCol=7;

    for (int i = startRow; i <= startRow+2; i++)
        for(int j=startCol;j<=startCol+2;j++)
            if(A[i][j]==num)
                return false;
    return true;
}

bool SolveSudoku(int row,int col)
{
    if(row==9 && col==10)
        return true;
    if(col==10)
    {
        row++;
        col=1;
    }
    if(A[row][col]>0)
        return SolveSudoku(row,col+1);
    for(int val=1;val<=9;val++)
    {
        if(isSafe(val,row,col))
        {
            A[row][col]=val;
            if(SolveSudoku(row,col+1))
                return true;
        }
        A[row][col]=0;
    }
    return false;
}

ifstream in("sudoku.in");

void Read(int A[11][11])
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            in>>A[i][j];
}

int main()
{
    Read(A);
    if(SolveSudoku(1,1))
        Show();
    else cout<<"There are no solutions";
    return 0;
}


/*
0 1 2 7 5 3 6 4 9
9 4 0 0 8 2 1 7 5
6 0 5 4 0 1 0 8 3
1 0 4 2 3 0 8 9 6
3 6 9 8 0 0 0 2 1
2 8 7 0 6 9 5 0 4
5 2 0 9 7 4 3 0 0
4 3 0 0 2 6 9 0 7
7 0 6 3 1 8 0 5 2
*/


