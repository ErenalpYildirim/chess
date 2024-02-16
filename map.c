#include <stdio.h>

const int WHITE_PAWN = 6;
const int WHITE_KNIGHT = 5;
const int WHITE_BISHOP = 4;
const int WHITE_ROOK = 3;
const int WHITE_QUEEN = 2;
const int WHITE_KING =1;

const int WHITE_DOM_SQ=7;
const int BLACK_DOM_SQ=-7;
const int EMPTY_SQ=0;
const int GREY_SQ=10;

const int BLACK_PAWN = -6;
const int BLACK_KNIGHT = -5;
const int BLACK_BISHOP = -4;
const int BLACK_ROOK = -3;
const int BLACK_QUEEN = -2;
const int BLACK_KING =-1;



void show_map(int chessBoard[8][8]);

void processPawnMoves(int color,int chessBoard[8][8],int row,int column);

void processKnightMoves(int color,int chessBoard[8][8],int row,int column);

int main()
{
    //k=1 q=2 r=3 b=4 n=5 p=6

//                  h   g  f  e  d  c  b  a
    int chessBoard[8][8]={{ 3, 5, 4, 2, 1, 4, 5, 3}//1 file 
                        , { 6, 6, 6, 6, 6, 6, 6, 6}//2 file 
                         ,{ 0, 0, 0, 0, 0, 0, 0, 0}//3 file
                         ,{ 0, 0, 0, 0, 0, 0, 0, 0}//4 file 
                         ,{ 0, 0, 0, 0, 0, 0, 0, 0}//5 file
                         ,{ 0, 0, 0, 0, 0, 0, 0, 0}//6 file
                         ,{-6,-6,-6,-6,-6,-6,-6,-6}//7 file
                         ,{-3,-5,-4,-2,-1,-4,-5,-3}//8 file
                   };

    for(int row=0;row<8;row++){
        for(int column=0;column<8;column++){
            switch (chessBoard[row][column])
            {
                case WHITE_PAWN:
            
                    
                    break;

                case -6:
                    if (map[i-1][j-1]==0 && j!=0){
                        map[i-1][j-1]=-7;}
                    if( map[i-1][j+1]==0 && j!=7){                      //sadece 0'a bakması için ayarlandı. +7 çarpışması eklenecek                        
                        map[i-1][j+1]=-7;}
                    break;
                
                case WHITE_KNIGHT:
                    processKnightMoves(WHITE_KNIGHT,chessBoard,row,column);
                    break;

                case BLACK_KNIGHT:
                    processKnightMoves(BLACK_KNIGHT,chessBoard,row,column);
                    break;
                             
                    
                

            default: 
                break;
                
            }
        }
        
        
    }
    
    
    displayBoard(chessBoard);

    return 0;

}

void displayBoard(int chessBoard[8][8]){
    printf("\nh  g  f  e  d  c  b  a\n______________________\n");

    for(int row=0;row<8;row++){
        for(int column=0;column<8;column++){
            printf("%d  ",chessBoard[row][column]);
        }
        printf("    | %d\n",row+1);
        
    }






}

void processKnightMoves(int color,int chessBoard[8][8],int row,int column){

    
        if(color==BLACK_KNIGHT){
            if(column!=0 && row<6){
                if(chessBoard[row+2][column-1]==WHITE_DOM_SQ){
                    chessBoard[row+2][column-1]=GREY_SQ;
                }
                else if(chessBoard[row+2][column-1]==EMPTY_SQ){ 
                    chessBoard[row+2][column-1]=BLACK_DOM_SQ;
                }

            }
            if (column != 7 && row < 6) {
                if(chessBoard[row + 2][column + 1] == WHITE_DOM_SQ){
                    chessBoard[row + 2][column + 1] =GREY_SQ;
                }
                else if (chessBoard[row + 2][column + 1] == EMPTY_SQ) {
                    chessBoard[row + 2][column + 1] = BLACK_DOM_SQ;
                }
            }
            
            if (column != 0 && row > 1) {
                if (chessBoard[row - 2][column - 1] == EMPTY_SQ) {
                    chessBoard[row - 2][column - 1] = BLACK_DOM_SQ;
                }
                else if(chessBoard[row - 2][column - 1] == WHITE_DOM_SQ){
                    chessBoard[row - 2][column - 1] =GREY_SQ;
                }
            }
            if (column != 7 && row > 1) {
                if (chessBoard[row - 2][column + 1] == EMPTY_SQ) {
                    chessBoard[row - 2][column + 1] = BLACK_DOM_SQ;
                }
                else if(chessBoard[row - 2][column + 1] == WHITE_DOM_SQ){
                    chessBoard[row - 2][column + 1] =GREY_SQ;
                }
            }
            if (column > 1 && row != 7) {
                if (chessBoard[row + 1][column - 2] == EMPTY_SQ) {
                    chessBoard[row + 1][column - 2] = BLACK_DOM_SQ;
                }
                else if(chessBoard[row + 1][column - 2] == WHITE_DOM_SQ){
                    chessBoard[row + 1][column - 2] =GREY_SQ;
                }
            }
            if (column < 6 && row != 7) {
                if (chessBoard[row + 1][column + 2] == EMPTY_SQ) {
                    chessBoard[row + 1][column + 2] = BLACK_DOM_SQ;
                }
                else if(chessBoard[row + 1][column + 2] == WHITE_DOM_SQ){
                    chessBoard[row + 1][column + 2] =GREY_SQ;
                }
            }

            if (column < 6 && row != 0) {
                if (chessBoard[row - 1][column + 2] == EMPTY_SQ) {
                    chessBoard[row - 1][column + 2] = BLACK_DOM_SQ;
                }
                else if(chessBoard[row - 1][column + 2] ==WHITE_DOM_SQ){
                    chessBoard[row - 1][column + 2] =GREY_SQ;
                }
            }
            if (column > 1 && row != 0) {
                if (chessBoard[row - 1][column - 2] == EMPTY_SQ) {
                    chessBoard[row - 1][column - 2] = BLACK_DOM_SQ;
                }
                else if(chessBoard[row - 1][column - 2] ==WHITE_DOM_SQ){
                    chessBoard[row - 1][column - 2] =GREY_SQ;
                }
            }
        }
        else if(color==WHITE_KNIGHT){
            if(column!=0 && row<6){
                if(chessBoard[row+2][column-1]==BLACK_DOM_SQ){
                    chessBoard[row+2][column-1]=GREY_SQ;
                }
                else if(chessBoard[row+2][column-1]==EMPTY_SQ){ 
                    chessBoard[row+2][column-1]=WHITE_DOM_SQ;
                }

            }
            if (column != 7 && row < 6) {
                if(chessBoard[row + 2][column + 1] == BLACK_DOM_SQ){
                    chessBoard[row + 2][column + 1] =GREY_SQ;
                }
                else if (chessBoard[row + 2][column + 1] == EMPTY_SQ) {
                    chessBoard[row + 2][column + 1] = WHITE_DOM_SQ;
                }
            }
            
            if (column != 0 && row > 1) {
                if (chessBoard[row - 2][column - 1] == EMPTY_SQ) {
                    chessBoard[row - 2][column - 1] = WHITE_DOM_SQ;
                }
                else if(chessBoard[row - 2][column - 1] == BLACK_DOM_SQ){
                    chessBoard[row - 2][column - 1] =GREY_SQ;
                }
            }
            if (column != 7 && row > 1) {
                if (chessBoard[row - 2][column + 1] == EMPTY_SQ) {
                    chessBoard[row - 2][column + 1] = WHITE_DOM_SQ;
                }
                else if(chessBoard[row - 2][column + 1] == BLACK_DOM_SQ){
                    chessBoard[row - 2][column + 1] =GREY_SQ;
                }
            }
            if (column > 1 && row != 7) {
                if (chessBoard[row + 1][column - 2] == EMPTY_SQ) {
                    chessBoard[row + 1][column - 2] = WHITE_DOM_SQ;
                }
                else if(chessBoard[row + 1][column - 2] == BLACK_DOM_SQ){
                    chessBoard[row + 1][column - 2] =GREY_SQ;
                }
            }
            if (column < 6 && row != 7) {
                if (chessBoard[row + 1][column + 2] == EMPTY_SQ) {
                    chessBoard[row + 1][column + 2] = WHITE_DOM_SQ;
                }
                else if(chessBoard[row + 1][column + 2] == BLACK_DOM_SQ){
                    chessBoard[row + 1][column + 2] =GREY_SQ;
                }
            }

            if (column < 6 && row != 0) {
                if (chessBoard[row - 1][column + 2] == EMPTY_SQ) {
                    chessBoard[row - 1][column + 2] = WHITE_DOM_SQ;
                }
                else if(chessBoard[row - 1][column + 2] ==BLACK_DOM_SQ){
                    chessBoard[row - 1][column + 2] =GREY_SQ;
                }
            }
            if (column > 1 && row != 0) {
                if (chessBoard[row - 1][column - 2] == EMPTY_SQ) {
                    chessBoard[row - 1][column - 2] = WHITE_DOM_SQ;
                }
                else if(chessBoard[row - 1][column - 2] ==BLACK_DOM_SQ){
                    chessBoard[row - 1][column - 2] =GREY_SQ;
                }
            }

        }
        
    
}

void processPawnMoves(int color,int chessBoard[8][8],int row,int column){

    if(color==WHITE_PAWN){
        if (chessBoard[row+1][column+1]==EMPTY_SQ){
            chessBoard[row+1][column+1]=WHITE_DOM_SQ;
        }
        else if(chessBoard[row+1][column+1]==BLACK_DOM_SQ){                                                         //piyonlar tamamlanacak.
            chessBoard[row+1][column+1]=GREY_SQ;
        }
    }
}
