


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>
using namespace std;

int board[9], player, computer, tictactoe = 1;


void print_board() //print the board
{
    int i, j;
    cout << "\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            switch (board[3 * i + j])
            {
            case 0:
                (j == 2) ? cout << "   " : cout << "   "
                                                << "|";
                break;
            case 1:
                (j == 2) ? cout << " X " : cout << " X "
                                                << "|";
                break;
            default:
                (j == 2) ? cout << " O " : cout << " O "
                                                << "|";
                break;
            }
        }
        (i == 2) ? cout << endl : cout << endl
                                       << "------------" << endl;
    }
}

void human_move() //takes input from player
{
    int row = 0, column = 0, box_number;
    cout << "Enter the box number: ";
    cin >> box_number;
    if (((box_number-1)<0) ||((box_number-1)>8))
    {
        cout << "Enter correct value "  << endl;
        human_move();
    }
    else if (board[box_number-1] != 0)
    {
        cout << "It is already filled\n";
        human_move();
    }
    else
        board[box_number-1] = player;
}
int computer_make_move(int i)
{
    if (board[i]== 0)
    {
        board[i] = computer;
        return 1;
    }
    return 0;
}

int defense_move(int c, int p, int turn_num)
{
    if (turn_num < 3)
        return 0;
    else if (board[0]+ board[4] +board[8] == 2 * c && board[0] != p && board[4] != p && board[8]!= p)
    {
        for (int i = 0; i <=8; i=i+4)
        {
            if (computer_make_move(i))
                return 1;
        }
    }
    else if (board[2]+ board[4] +board[6] == 2 * c && board[2] != p && board[4] != p && board[6]!= p)
    {
        for (int i = 2; i <=6; i=i+2)
        {
            if (computer_make_move(i))
                return 1;
        }
    }
    else
    {
        int i, j;
        for (i = 0; i < 3; i++)
        {
            if (board[3*i] + board[3*i+1] + board[3*i+2] == 2 * c && board[3*i] != p && board[3*i+1] != p && board[3*i+2] != p)
            {
                for (j = 0; j < 3; j++)
                {
                    if (computer_make_move(3*i+j))
                        return 1;
                }
            }
            else if (board[i] + board[i+3] + board[i+6]== 2 * c && board[i]!= p && board[i+3] != p && board[i+6] != p)
            {
                for (j = 0; j < 3; j++)
                {
                    if (computer_make_move(3*j+i))
                        return 1;
                }
            }
        }
        
    }
    return 0;
}
int check_moves_row(int turn,int i){
    if (board[3*i] + board[3*i+1] + board[3*i+2] == turn && 
    (board[3*i] == turn ||board[3*i+1] == turn || board[3*i+2] == turn))
        return 1;
    return 0;
}
int check_moves_column(int turn,int i){
    if (board[i] + board[i+3] + board[i+6] == turn &&
     (board[i] == turn ||board[i+3] == turn || board[i+6] == turn))
        return 1;
    return 0;
}
int check_moves_reverse(int turn,int i){
    if((board[2-i] + board[5-i] + board[8-i] == turn) &&
    (board[2-i] == turn || board[5-i] == turn || board[8-i] == turn))
        return 1;
    return 0;
}
int control_moves_1(){
    int i,j;
    for (i = 0; i < 3; i++)
        {
            if(check_moves_row(computer,i))
            {
                if (i == 1)
                {
                    for (j = 0; j < 3; j++)
                    {
                        if (computer_make_move(3*i+j))
                            return 1;
                    }
                }
                else
                {
                    for (j = 2; j >= 0; j--)
                    {
                        if (computer_make_move(3*i+j))
                            return 1;
                    }
                }
            }
            if (check_moves_column(computer,i))
            {
                if (i == 1)
                {
                    for (j = 0; j < 3; j++)
                    {
                        if (computer_make_move(3*j+i))
                            return 1;
                    }
                }
                else
                {
                    for (j = 2; j >= 0; j--)
                    {
                        if (computer_make_move(3*j+i))
                            return 1;
                    }
                }
            }
        }
    return 0;
}
int control_moves_2(){
    int i,j;
    if (board[0] + board[4] + board[8] == computer && (board[0] == computer ||
                                                             board[4] == computer || board[8] == computer))
        {
            for (i = 2; i >= 0; i--)
            {
                if ((board[4*i] == 0) && (check_moves_row(computer,i)||check_moves_column(computer,i)))
                {
                    board[4*i] = computer;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (board[4*i] == 0)
                {
                    if (check_moves_row(player,i)&&check_moves_column(player,i))
                    {
                        board[4*i] = computer;
                        return 1;
                    }
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (computer_make_move(4*i))
                    return 1;
            }
        }
        else if (board[2]+board[4]+board[6] == computer && (board[2] == computer ||
                                                                  board[4] == computer || board[6] == computer))
        {
            for (i = 2; i >= 0; i--)
            {
                if (board[2*i+2] == 0 && (check_moves_row(computer,i)||check_moves_reverse(computer,i)))
                {
                    board[2*i+2] = computer;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (board[2*i+2] == 0)
                {
                    if (check_moves_row(player,i)&&check_moves_reverse(player,i))
                    {
                        board[2*i+2] = computer;
                        return 1;
                    }
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (computer_make_move(2*i+2))
                    return 1;
            }
        }
    return 0;
    
}
int attack_move() //takes a move as to win in future.
{
    if (board[0]+board[2]+board[6]+board[8]== player ||
        board[0]+board[2]+board[6]+board[8] == 2 * player)
    {
        if(control_moves_1())
            return 1;
        if(control_moves_2())
            return 1;        
    }
    else
    {
        if(control_moves_2())
            return 1;
        else
            if(control_moves_1())
                return 1;
    }
    return 0;
}

void computer_move(int turn_num) //controls the compter's move
{
    if (!defense_move(computer, player, turn_num))
    {
        if (!defense_move(player, computer, turn_num))
        {
            if ((board[0]+board[2]+board[6]+board[8] == player + computer ||
                 board[0]+board[2]+board[6]+board[8] == player + 2 * computer) &&
                board[4] == 0)
            {
                for (int i = 0; i < 3; i += 2)
                {
                    for (int j = 0; j < 3; j += 2)
                        if (board[3*i+j] == 0)
                        {
                            board[3*i+j] = computer;
                            goto end;
                        }
                }
            }
            else if (turn_num == 2 && board[4] == 0)
            {
                board[4] = computer;
                goto end;
            }
            if (!attack_move())
            {
                if (turn_num == 0)
                {
                    time_t seconds;
                    time(&seconds);
                    srand((unsigned int)seconds);
                    int i, j;
                    board[rand() % 9] = computer;
                }
                else if (board[4] == 0)
                    board[4] = computer;
                else
                {
                    int i, j;
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (board[3*i+j] == 0)
                            {
                                board[3*i+j] = computer;
                                goto end;
                            }
                        }
                    }
                }
            }
        }
    }
end:
    cout << endl;
}
int check_win() //checks if anyone is winning.
{
    for (int i = 0; i < 3; i++)
        if ((board[3*i] != 0 && board[3*i] == board[3*i+1] && board[3*i+1] == board[3*i+2]) ||
         (board[i] != 0 && board[i] == board[i+3] && board[i+3] == board[i+6]))
            return 1;

    if (board[0] != 0 && board[0] == board[4] && board[4] == board[8])
        return 1;
    else if (board[2] != 0 && board[2] == board[4] && board[4] == board[6])
        return 1;
    else
        return 0;
}
void print_human_win()
{
    cout << "\nCongratulations, you won ";
    exit(0);
}
void print_computer_win()
{
    cout << "\nI won, you loose. ";
}

int main()
{
    int turn_num, i, j;
    for (i = 0; i < 9; i++)
            board[i] = 0;
    if (tictactoe == 1)
    {
        cout << "\nDo you want to challenge me in Tic Tac Toe? Let'see see who wins\nBelow are the box numbers of the matrix cells\n";
        cout << "\n";
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
                (j == 2) ? cout << " " << 3 * i + j + 1 << " " : cout << " " << 3 * i + j + 1 << " "
                                                                      << "|";
            (i == 2) ? cout << endl : cout << endl
                                           << "------------" << endl;
        }
    }
        cout << "\nYou want to be the Player 1 or Player 2? ";

input:
    cin >> player;
    switch (player)
    {
    case 1:
        computer = 2;
        cout << "\nYour symbol is 'X' and mine is 'O'\nLet's start the game. ";
        for (turn_num = 0; turn_num < 9;)
        {
            human_move();
            print_board();
            turn_num++;
            if (turn_num > 4)
                if (check_win())
                {
                    print_human_win();
                    break;
                }
            if (turn_num >= 8)
                break;
            computer_move(turn_num);
            print_board();
            turn_num++;
            if (turn_num > 5)
                if (check_win())
                {
                    print_computer_win();
                    break;
                }
        }
        break;

    case 2:
        computer = 1;
        cout << "\nYour symbol is 'O' and mine is 'X'\nLet's start the game. ";
        for (turn_num = 0; turn_num < 9;)
        {
            computer_move(turn_num);
            print_board();
            turn_num++;
            if (turn_num > 4)
                if (check_win())
                {
                    print_computer_win();
                    break;
                }
            if (turn_num >= 8)
                break;
            human_move();
            print_board();
            turn_num++;
            if (turn_num > 5)
                if (check_win())
                {
                    print_human_win();
                    break;
                }
        }
        break;
    default:
        cout << "\nHey, "<< "you need to enter either 1 or 2";
        cout << "\nEnter again: ";
        goto input;
        break;
    }
    if (!check_win())
            cout << "\nIt is a tie";
    char c;
    cout << "\nDo you want to play again "
         << " y/n?";
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        tictactoe++;
        main();
    }
    else
        exit(0);
    return 0;
}
