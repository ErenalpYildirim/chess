#include <stdio.h>
#include <string.h>

/*                                                        CHESS

        INSTRUCTIONS:    
        
        1-READ MOVE 
        2-CHECK MOVE IF ITS POSSIBLE    
        2.1-IF PIECE_MOVE_DIRECTION IS NOT CORRECT ITS NOT.
        2.2-IF PIECE_MOVE_DIRECTION IS CORRECT CHECK AFTERWARDS.
        2.2.1-IF PLAYER_IN_CHECK TAKE BACK THE MOVE AND STATE.
        2.2.1.1-IF PLAYER_IN_CHECK AND POSSIBLE_MOVES==0 ==>GAME OVER!
        2.2.1.2-IF PLAYER_IN_CHECK AND POSSIBLE_MOVES!=0 ==>READ AGAIN...
        2.2.2-IF PLAYER_NOT_IN_CHECK CONFIRM MOVE.
        3-SAVE THE CHANGES
        4-DISPLAY THE BOARD
        5-CHANGE TURNS
        6-REPEAT!

        TO DO:
        1-CREATE POSSIBLE_MOVE 
        2-CREATE PIECE_MOVE_DIRECTION
        
        
        3-CREATE PIECES

        
                                                                                                                                                                                                        */

const int WHITE_PAWN = 6;
const int WHITE_KNIGHT = 5;
const int WHITE_BISHOP = 4;
const int WHITE_ROOK = 3;
const int WHITE_QUEEN = 2;
const int WHITE_KING =1;

const int BLACK_PAWN = -6;
const int BLACK_KNIGHT = -5;
const int BLACK_BISHOP = -4;
const int BLACK_ROOK = -3;
const int BLACK_QUEEN = -2;
const int BLACK_KING =-1;


const int EMPTY_SQ=0;

void displayBoard(int chessBoard[8][8]);

int processPawnMoves(int color,int chessBoard[8][8],int row_i,int column_i,int row_f,int column_f);

int processKnightMoves(int color,int chessBoard[8][8],int row,int column,int row_f,int column_f);

int white_in_check(int chessBoard[8][8]);
int black_in_check(int chessBoard[8][8]);

int main()
{   
    int game_on=1;
        //k=1 q=2 r=3 b=4 n=5 p=6

        //                  h  g  f  e  d  c  b  a
    int chessBoard[8][8]={{ 3, 5, 4, 2, 1, 4, 5, 3}//1 file 
                         ,{ 6, 6, 6, 6, 6, 6, 6, 6}//2 file 
                         ,{ 0, 0, 0, 0, 0, 0, 0, 0}//3 file
                         ,{ 0, 0, 0, 0, 0, 0, 0, 0}//4 file 
                         ,{ 0, 0, 0, 0, 0, 0, 0, 0}//5 file
                         ,{ 0, 0, 0, 0, 0, 0, 0, 0}//6 file
                         ,{-6,-6,-6,-6,-6,-6,-6,-6}//7 file
                         ,{-3,-5,-4,-2,-1,-4,-5,-3}//8 file
                   };
    int turn;

    displayBoard(chessBoard);


    while(game_on){
        int restore[8][8];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                restore[i][j]=chessBoard[i][j];
            }
        }
        

        if(turn%2==0){
            printf("White's turn!\n");
            int init;
            scanf("%d",&init);
            int column_i=init%8;
            int row_i=(init-column_i)/8;
            if(chessBoard[row_i][column_i]<=0){
                printf("Wrong piece! Try again.\n"); 
                continue;
            }
            else{
                int final;
                scanf("%d",&final);
                int column_f=final%8;
                int row_f=(final-column_f)/8;

                if(chessBoard[row_i][column_i]==WHITE_PAWN && processPawnMoves(WHITE_PAWN,chessBoard,row_i,column_i,row_f,column_f)){
                    chessBoard[row_i][column_i]=0;
                    chessBoard[row_f][column_f]=WHITE_PAWN;
                    
                    if(white_in_check(chessBoard)){
                        printf("Illegal move! Try again.\n");
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                chessBoard[i][j]=restore[i][j];
                            }
                        }
                        continue;
                    }


                }
                else if(chessBoard[row_i][column_i]==WHITE_KNIGHT && processKnightMoves(WHITE_KNIGHT,chessBoard,row_i,column_i,row_f,column_f)){
                    chessBoard[row_i][column_i]=0;
                    chessBoard[row_f][column_f]=WHITE_KNIGHT;

                    if(white_in_check(chessBoard)){
                        printf("Illegal move! Try again.\n");
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                chessBoard[i][j]=restore[i][j];
                            }
                        }
                        continue;
                    }
                }

            }

            }
        else{
            printf("Black's turn!\n");
            int init;
            scanf("%d",&init);
            int column_i=init%8;
            int row_i=(init-column_i)/8;

            if(chessBoard[row_i][column_i]>=0){
                printf("Wrong piece! Try again.\n");
                continue;

                }
            else{
                int final;
                scanf("%d",&final);
                int column_f=final%8;
                int row_f=(final-column_f)/8;

                if(chessBoard[row_i][column_i]==BLACK_PAWN && processPawnMoves(BLACK_PAWN,chessBoard,row_i,column_i,row_f,column_f)){
                    chessBoard[row_i][column_i]=0;
                    chessBoard[row_f][column_f]=BLACK_PAWN;
                    if(black_in_check(chessBoard)){
                        printf("Illegal move! Try again.\n");
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                chessBoard[i][j]=restore[i][j];
                            }
                        }
                        continue;
                    }

                }
                else if(chessBoard[row_i][column_i]==BLACK_KNIGHT && processKnightMoves(BLACK_KNIGHT,chessBoard,row_i,column_i,row_f,column_f)){
                    chessBoard[row_i][column_i]=0;
                    chessBoard[row_f][column_f]=BLACK_KNIGHT;

                    if(white_in_check(chessBoard)){
                        printf("Illegal move! Try again.\n");
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                chessBoard[i][j]=restore[i][j];
                            }
                        }
                        continue;
                    }

                }

                }
            }
        
        
        
        
        
        displayBoard(chessBoard);
        
        turn++;

    }

        
        
    
    
    return 0;

}

void displayBoard(int chessBoard[8][8]){
    printf("\n h   g   f   e   d   c   b   a\n______________________________\n");

    for(int row=0;row<8;row++){
        for(int column=0;column<8;column++){
            if(chessBoard[row][column]>=0){
                printf("+%d  ",chessBoard[row][column]);
                }
            else{
                printf("%d  ",chessBoard[row][column]);
            }
        }
        printf("| %d\n",row+1);
        
    }
}

int processKnightMoves(int color,int chessBoard[8][8],int row_i,int column_i,int row_f,int column_f){

    
        if(color==BLACK_KNIGHT){
            if(column_i!=0 && row_i<6){
                if(chessBoard[row_i+2][column_i-1]>=0 && chessBoard[row_i+2][column_i-1]==chessBoard[row_f][column_f]){
                    return 1;
                }
            }
            if (column_i != 7 && row_i < 6) {
                if(chessBoard[row_i + 2][column_i + 1] >=0 && chessBoard[row_i + 2][column_i + 1]==chessBoard[row_f][column_f]){
                    return 1;
                }
                
            }
            
            if (column_i != 0 && row_i > 1) {
                if (chessBoard[row_i - 2][column_i - 1] >=0 && chessBoard[row_i - 2][column_i - 1]==chessBoard[row_f][column_f] ) {
                    return 1;
                }
                
            }
            if (column_i != 7 && row_i > 1) {
                if (chessBoard[row_i - 2][column_i + 1] >=0 && chessBoard[row_i - 2][column_i + 1]==chessBoard[row_f][column_f]) {
                    return 1;
                }
                
            }
            if (column_i > 1 && row_i != 7) {
                if (chessBoard[row_i + 1][column_i - 2] >=0 && chessBoard[row_i + 1][column_i - 2]==chessBoard[row_f][column_f] ) {
                    return 1;
                }
                
            }
            if (column_i < 6 && row_i != 7) {
                if (chessBoard[row_i + 1][column_i + 2] >=0 && chessBoard[row_i + 1][column_i + 2]==chessBoard[row_f][column_f]) {
                    return 1;
                }
                else if(chessBoard[row_i + 1][column_i + 2]>=0 && chessBoard[row_i + 1][column_i + 2]==chessBoard[row_f][column_f] ){
                    return 1;
                }
            }

            if (column_i < 6 && row_i != 0) {
                if (chessBoard[row_i - 1][column_i + 2] >=0 && chessBoard[row_i - 1][column_i + 2]==chessBoard[row_f][column_f] ) {
                    return 1;
                }
                
            }
            if (column_i > 1 && row_i != 0) {
                if (chessBoard[row_i - 1][column_i - 2]>=0 && chessBoard[row_i - 1][column_i - 2]==chessBoard[row_f][column_f] ) {
                    return 1;
                }
                
            }
        }
        else if(color==WHITE_KNIGHT){
            if(column_i!=0 && row_i<6){
                if(chessBoard[row_i+2][column_i-1]<=0 && chessBoard[row_i+2][column_i-1]==chessBoard[row_f][column_f]){
                    return 1;
                }
            }
            if (column_i != 7 && row_i < 6) {
                if(chessBoard[row_i + 2][column_i + 1] <=0 && chessBoard[row_i + 2][column_i + 1]==chessBoard[row_f][column_f]){
                    return 1;
                }
                
            }
            
            if (column_i != 0 && row_i > 1) {
                if (chessBoard[row_i - 2][column_i - 1] <=0 && chessBoard[row_i - 2][column_i - 1]==chessBoard[row_f][column_f] ) {
                    return 1;
                }
                
            }
            if (column_i != 7 && row_i > 1) {
                if (chessBoard[row_i - 2][column_i + 1] <=0 && chessBoard[row_i - 2][column_i + 1]==chessBoard[row_f][column_f]) {
                    return 1;
                }
                
            }
            if (column_i > 1 && row_i != 7) {
                if (chessBoard[row_i + 1][column_i - 2] <=0 && chessBoard[row_i + 1][column_i - 2]==chessBoard[row_f][column_f] ) {
                    return 1;
                }
                
            }
            if (column_i < 6 && row_i != 7) {
                if (chessBoard[row_i + 1][column_i + 2] <=0 && chessBoard[row_i + 1][column_i + 2]==chessBoard[row_f][column_f]) {
                    return 1;
                }
                else if(chessBoard[row_i + 1][column_i + 2]<=0 && chessBoard[row_i + 1][column_i + 2]==chessBoard[row_f][column_f] ){
                    return 1;
                }
            }

            if (column_i < 6 && row_i != 0) {
                if (chessBoard[row_i - 1][column_i + 2] <=0 && chessBoard[row_i - 1][column_i + 2]==chessBoard[row_f][column_f] ) {
                    return 1;
                }
                
            }
            if (column_i > 1 && row_i != 0) {
                if (chessBoard[row_i - 1][column_i - 2]<=0 && chessBoard[row_i - 1][column_i - 2]==chessBoard[row_f][column_f] ) {
                    return 1;
                }
                
            }

        }
        
    
}

int processPawnMoves(int color,int chessBoard[8][8],int row_i,int column_i,int row_f,int column_f){

    if(color==WHITE_PAWN){
        if (chessBoard[row_i+1][column_i]==EMPTY_SQ&&row_i!=7 &&(row_f-row_i==1) &&(column_f==column_i)){
            return 1;
            }
        else if(chessBoard[row_i+1][column_i+1]<0 && row_i!=7 && column_i!=7 &&(row_f-row_i==1) &&(column_f-column_i)==1){
            return 1;
        }
        else if(chessBoard[row_i+1][column_i-1]<0 && row_i!=7 && column_i!=0 &&(row_f-row_i==1) &&(column_f-column_i)==-1){
            return 1;
        }
       }
    else if(color==BLACK_PAWN){
        if (chessBoard[row_i-1][column_i]==EMPTY_SQ &&row_i!=0 &&(row_f-row_i==-1) &&(column_f==column_i)){
            return 1;
            }
        else if(chessBoard[row_i-1][column_i+1]>0 &&row_i!=0 && column_i!=7 &&(row_f-row_i==-1) && (column_f-column_i)==1){
            return 1;
        }
        else if(chessBoard[row_i-1][column_i-1]>0 &&row_i!=0 && column_i!=0 &&(row_f-row_i==-1) && (column_f-column_i)==-1){
            return 1;
        }

    }
    return 0;
}


int white_in_check(int chessBoard[8][8]){
    return 0;
    for(int row=0;row<8;row++){
            for(int column=0;column<8;column++){
                if((chessBoard[row][column])==WHITE_PAWN){
                    processPawnMoves(WHITE_PAWN,chessBoard,row,column,row,column);
                }
                else if((chessBoard[row][column])==BLACK_PAWN){


                }
                
                }
                
            }
        }





int black_in_check(int chessBoard[8][8]){
    return 0;
}