#include <iostream>
using namespace std;

bool OK(int q[],int c)
{
    for (int i = 0; i < c; i++)
    {
       
        
            if (q[i] == q[c] || (c - i) == abs(q[c] - q[i]))
            
                return false;
            
        }
    return true;
}
void print (int q[])
    {
        static int solution = 1; // to count the number of solution
        // 
        int i,j,k,l; 
        // we can't just replace box with char because it will mess with the output
       typedef char box[5][7]; // intilizing each band
       box bb,wb,*board[8][8]; // we are making the board a pointer so we can point to specific boxes
       box bq, wq;//queens
       cout << "soltution # "<< solution++ << endl; 
       //fill in bb=black box and wb=whitebox
       for(i = 0; i < 5; i++) // width of the band
        for(j = 0; j < 7; j++) // lenght of the band
               {
               wb[i][j] = ' ';// prints white
               
               wq[i][j] = ' '; // white queen
               
               bb[i][j] = char(219);// black box   char(219) makes a dark box

               bq[i][j] = char(219);// black queen
               }
               // make the queen shape
               wq[1][1] = char(219);
               wq[2][1] = char(219);
               wq[3][1] = char(219);
               wq[3][2] = char(219);
               wq[3][3] = char(219);
               wq[3][4] = char(219);
               wq[3][5] = char(219);
               wq[2][3] = char(219);
               wq[1][3] = char(219);
               wq[1][5] = char(219);
               wq[2][5] = char(219);
               
               bq[1][1] = ' ';
               bq[2][1] = ' ';
               bq[3][1] = ' ';
               bq[3][2] = ' ';
               bq[3][3] = ' ';
               bq[3][4] = ' ';
               bq[3][5] = ' ';
               bq[2][3] = ' ';
               bq[1][3] = ' ';
               bq[1][5] = ' ';
               bq[2][5] = ' ';
       //prints the board, alternate position between white and black
       for(i = 0; i < 8; i++) 
        for(j = 0; j < 8; j++)
             if((i+j)%2==0) // if i+j is even then we print white box
                board[i][j] = &wb;
             else 
                board[i][j] = &bb;  // wew print black box
                
        for(i = 0; i < 8; i++)  // we print the queen
            {
                if((q[i] + i) % 2 == 0) // deciding if the queen is in even or odd box
                    board[q[i]][i] = &wq; // if even white queen
                else
                    board[q[i]][i] = &bq; // if odd, black queen
            } 
       // print the board via the pointers in array board
       // first print upper border
       cout<<"     ";
       
       for(i=0;i<7*8;i++) // the boarder for the chess board
            cout<<'_';
               cout<<endl;
               
       // now print the board
       for(i=0;i<8;i++) // outer row of the band
            for(k=0;k<5;k++)  // inner row of the band
               {cout<<"     "<<char(179); //print left border 
                for(j=0;j<8;j++) // column of the board
                       for(l=0;l<7;l++)  // column of the box
                               cout<<(*board[i][j])[k][l]; // *board is the board, k and l are the bands
                                cout<<char(179)<<endl; // at end of line print bar and then newline to complete the boarder 
               }
               
       //before exiting print lower border
       cout<<"     ";
       
       for(i=0;i<7*8;i++) // this is to make it look pretty
       
            cout<<char(196);
               cout<<endl;
    }
    

void backtrack (int q[], int &c) {
     c--;    // go back a column
  if (c == -1) // we have found all the solution 
  {
    cout << " No more solutions" << endl;
    exit(0);
    q[c]++;
  }

}
int main() {
    int q[8] = {0}, c = 0;
    q[0] = 0;

    while (c >=0) {
        c++;
        if (c == 8){
          print(q);
           
            backtrack(q,c);
        } 
        else{
          q[c] = -1;
        }
            while (c >= 0) {
              q[c]++;
              if (q[c] == 8) {
                backtrack(q,c);
                
              }
              else {
                if (OK (q,c))
                break;
              }

            }
        }
        return 0;
    
    }