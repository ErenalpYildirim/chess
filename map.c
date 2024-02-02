#include <stdio.h>

void show_map(int map[8][8]);

int main()
{
    //k=1 q=2 r=3 b=4 n=5 p=6

//                  h   g  f  e  d  c  b  a
    int map[8][8]={{ 3, 5, 4, 2, 1, 4, 5, 3}//1 file 
                  ,{ 6, 6, 6, 6, 6, 6, 6, 6}//2 file 
                  ,{ 0, 0, 0, 0, 0, 0, 0, 0}//3 file
                  ,{ 0, 0, 0, 0, 0, 0, 0, 0}//4 file 
                  ,{ 0, 0, 0, 0, 0, 0, 0, 0}//5 file
                  ,{ 0, 0, 0, 0, 0, 0, 0, 0}//6 file
                  ,{-6,-6,-6,-6,-6,-6,-6,-6}//7 file
                  ,{-3,-5,-4,-2,-1,-4,-5,-3}//8 file
                   };

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            switch (map[i][j])
            {
                case 6:
            
                    if (map[i+1][j+1]==0 && j!=7){
                        map[i+1][j+1]=7;}
                

                    if( map[i+1][j-1]==0 && j!=0){
                        map[i+1][j-1]=7;}
                    break;

                case -6:
                    if (map[i-1][j-1]==0 && j!=0){
                        map[i-1][j-1]=-7;}
                    if( map[i-1][j+1]==0 && j!=7){
                        map[i-1][j+1]=-7;}
                    break;
                
                case 5:
                    
                

            default: 
                break;
                
            }
        }
        
        
    }
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
        
    }

    show_map(map[8][8]);

    printf("Erenalp\n");


}

void show_map(int map[8][8]){

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
        
    }






}