#include <stdio.h>
#include <stdlib.h>

int num = 0;
int Matrix[100][100];
void chessBoard(int tr, int tc, int dr, int dc, int size);
int main()
{
    int size, r, c, row, col;
    printf("index and col:");
    scanf("%d", &size);
    printf("specific index and col:");
    scanf("%d %d", &row, &col);
    chessBoard(0, 0, row, col, size);

    for (r = 0; r < size; r++)
    {
        for (c = 0; c < size; c++)
        {
            printf("%2d ", Matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}

void chessBoard(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1)
        return;
    int s = size / 2; //分割棋盘
    int t = ++num;    // L型骨牌号

    //覆盖左上角子棋盘
    if (dr < tr + s && dc < tc + s){
        //特殊方格在此棋盘中
        chessBoard(tr, tc, dr, dc, s);
    }
    else{ //此棋盘中无特殊方格
        //用t号L型骨牌覆盖右下角
        Matrix[tr + s - 1][tc + s - 1] = t;
        //覆盖其余方格
        chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
    }

    //覆盖右上角子棋盘
    if (dr < tr + s && dc >= tc + s){
        //特殊方格在此棋盘中
        chessBoard(tr, tc + s, dr, dc, s);
    }
    else{
        Matrix[tr + s - 1][tc + s] = t;
        chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
    }

    //覆盖左下角子棋盘
    if (dr >= tr + s && dc < tc + s){
        chessBoard(tr + s, tc, dr, dc, s);
    }
    else{
        //t号L型骨牌
        Matrix[tr + s][tc + s - 1] = t;
        //覆盖其余方格
        chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
    }

    //覆盖右下角子棋盘
    if (dr >= tr + s && dc >= tc + s){
        chessBoard(tr + s, tc + s, dr, dc, s);
    }
    else{
        //t号L型骨牌
        Matrix[tr + s][tc + s] = t;
        //覆盖其余方格
        chessBoard(tr + s, tc + s, tr + s, tc + s, s);
    }
}
