#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// struct GameParameters {
//    int length;
//    int width;
//    int **board;
//    int ;
// };

int x_value, y_value , penguin_count , player_count, difficulty, some; 

int main(int argc, char* argv[]) {

  x_value = 10;
  y_value = 10;

  // dynamic memory allocation
  int** my_fish_board = (int**)malloc(x_value * sizeof(int*));
  for (int i = 0; i < x_value; ++i) {
    my_fish_board[i] = (int*)malloc(y_value * sizeof(int));
  }

  // seed rand function
  srand(time(NULL));

  // randomly seed board values
  // 0..3 inclusive: No. of fish
  for (int i = 0; i < x_value; ++i) {
    for (int j = 0; j < y_value; ++j) {
      my_fish_board[i][j] = rand() % 4;
      printf("%d ", my_fish_board[i][j]);
    }
    printf("\n");
  }

  

  // placement loop 
  // while(penguin_count > 0){
  // take input x
  // take input y
  // validate_coordinates;
  // if validation passes
  // my_fish_board[x][y] = player_value;
  // change_player
  // }

//  int validate_coordinates(x, y, board, value) {
//   if(board[x][y] == value) {
//     return 1
//   } else 
//   return 0;
// }

  /*
    
  read_source x, y
  check_coordinates(x, y, board, penguin_value);
  read_destination x, y
  check_coordinates(x, y, board, fish_value);
  check either x is equal or y is equal
  select whether source or destination is bigger 
  check for ice flow or penguin in path
  board[x][y] = 0
  player_score = player_score + board[x][y]
  dest_board[x][y] = player_value

  

   */





  // free dynamic memory
  for (int i = 0; i < x_value; ++i) {
    free(my_fish_board[i]);
  }
  free(my_fish_board);
}


// int users_playing;                // number of users playing code handled by yifan 

// int ice_floe;                     // icfloe on board handled by anatoli 

// int fish_on_board;               // fish on board 

// int peguins_on_board = 0;          // peguins on the board 

// int length,width;                    // the inputs for the board 


// void generate_board_and_set_user_number() {         
//                                                           //purpose of this fuction is to intualize the board as a 2d array and allocate memory for it 
// }

// int are_there_any_unplaced_peguins(){           
//                                                                 // loop for unplaceds peguins
//     if (peguins_on_board< 6) return 1;
//     return 0;
// }

// int are_there_any_unplaced_peguins_for_current_player (){       
//                                                             // loop for unplaced peguins in players hand
//     return 1;
// }
// void change_current_player() {
//                                                 // loop 

// }
     
                                       

// int main() {
//     int length,width,i,j;
//     printf("Hello Players welcome to Hey, thats my fish.\n Press y or n to start or end the game: \n"); //start of the game//
//     char yes;
//     scanf("%c",&yes);
//     if(yes == 'y'){
//     printf("Enjoy the game\n");}
//     else if(yes == 'n') {
//         printf("End game");
//         return 0;
//     }
//     printf("Enter the length:\n");
//     scanf("%d",&length);
//     printf("Enter the width:\n");
//     scanf("%d",&width);
//     for(i=1;i<=length;i++)
//     {
//         for(j=1;j<=width;j++)
//         {
//             if((i+j)%2==0)

//             // printing the board//
//                 printf("[_]");
//             else printf("[_]");
//         }
//         printf("\n");
// }
//      return 0;
// }


// //Movement phase// 

// void ask_player_to_choose_peguin () {
//                                                 // player chooses their peguin 
      
// }

// void check_for_valid_coordinate_of_peguin() { 
//                                                     //  funtion checks if the coordinate is valid for the player's peguin

// }

// void movement_of_peguin (){
//                                                 //  player moves the peguin either up,down , left or right 

// }

// void is_move_valid () {
//                                             //   funtion will check if the move is valid
                                                     
// }

// void move_peguin_to_icefloe (){
//   collect_fish(final_coords);
//   remove_icefloe(initial_coords);
// //    funtion which moves the peguin to the icefloe
// }

// void remove_icefloe (){
// // funtion to remove the icflow 
// }

// void collect_fish () {
// // funtion to collect fish 
// }

// void change_to_next_player () {
// // funtion loops to next user's turn 
// }

// void checks_if_any_of_current_players_peguins_can_move () {
//                                                                // decision funtion  

// }

// void check_if_any_peguins_can_move () {
//                                                 // decision on ether to change to next player or start to end the game

// }

// void calculate_display_total_fish_earned () {   
//                                                // showing results 

// }

// void print_winner () {
//                                      // to print winner and end the game 

// }