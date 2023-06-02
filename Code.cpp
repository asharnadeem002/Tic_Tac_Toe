#include<iostream>
#include"help.h"

using namespace std;

void cross(int x, int y, int cell_size) {
    int x2 = x + cell_size;
    int y2 = y + cell_size;    
    myLine(x + 20, y + 20, x2 - 20, y2 - 20, 255, 0, 0);
    myLine(x + 24, y + 20, x2 - 16, y2 - 20, 255, 0, 0);
    myLine(x2 - 20, y + 20, x + 20, y2 - 20, 255, 0, 0);
    myLine(x2 - 16, y + 20, x + 24, y2 - 20, 255, 0, 0);
    myLine(x + 22, y + 20, x2 - 18, y2 - 20, 255, 192, 203);
    myLine(x2 - 18, y + 20, x + 22, y2 - 20, 255, 192, 203);
}

void circle(int x, int y, int i, int j, int cell_size) {
    int x2 = x + cell_size;
    int y2 = y + cell_size;

    myEllipse(x + 20, y + 20, x2 - 20, y2 - 20, 0, 0, 255);
    myEllipse(x + 22, y + 22, x2 - 22, y2 - 22, 255, 255, 255);
    if (i % 2 == j % 2)
        myFilledEllipse(x + 24, y + 24, x2 - 24, y2 - 24, 0, 0, 255, 180, 180, 180);
    else
        myFilledEllipse(x + 24, y + 24, x2 - 24, y2 - 24, 0, 0, 255, 140, 140, 140);
}

void printShapes(int a[10][10], int cell_size, int i, int j, int start_x, int start_y) {
    int x = (j * cell_size) + start_x;
    int y = (i * cell_size) + start_y;
    if (a[i][j] == 1)
        cross(x, y, cell_size);
    if (a[i][j] == 2)
        circle(x, y, i, j, cell_size);
}

void printTable(int board_size, int cell_size, int start_x, int start_y) {
    int x1 = start_x, y1 = start_y;

    for (int i = 0;i < board_size;i++) {
        if (i % 2 == 0)
            for (int j = 0;j < board_size;j++) {
                int x2 = x1 + cell_size, y2 = y1 + cell_size;
                myFilledRect(x1, y1, x2, y2, 180, 180, 180, 180, 180, 180);

                j++;
                x1 += cell_size;

                x2 = x1 + cell_size, y2 = y1 + cell_size;

                if (j < board_size)
                    myFilledRect(x1, y1, x2, y2, 140, 140, 140, 140, 140, 140);
                x1 += cell_size;
            }
        else
            for (int j = 0;j < board_size;j++) {
                int x2 = x1 + cell_size, y2 = y1 + cell_size;
                myFilledRect(x1, y1, x2, y2, 140, 140, 140, 140, 140, 140);

                j++;
                x1 += cell_size;

                x2 = x1 + cell_size, y2 = y1 + cell_size;

                if (j < board_size)
                    myFilledRect(x1, y1, x2, y2, 180, 180, 180, 180, 180, 180);
                x1 += cell_size;
            }
        y1 += cell_size;
        x1 = start_x;
    }
}

void make_pointer(int& x, int& y, int& i, int& j, int cell_size, int board_size, int start_x, int start_y, int R, int G, int B) {

    int end_x = (board_size * cell_size) + start_x;
    int end_y = (board_size * cell_size) + start_y;
    if (x < start_x)
        x = end_x - cell_size, j = board_size - 1;
    if (x > end_x - cell_size)
        x = start_x, j = 0;
    if (y < start_y)
        y = end_y - cell_size, i = board_size - 1;
    if (y > end_y - cell_size)
        y = start_y, i = 0;

    int x2 = x + cell_size, y2 = y + cell_size;
    int mid_x = (cell_size / 2) + x, mid_y = (cell_size / 2) + y;
    myLine(x + 10, y + 10, mid_x - 10, y + 10, R, G, B);
    myLine(x2 - 10, y + 10, mid_x + 10, y + 10, R, G, B);

    myLine(x + 10, y2 - 10, mid_x - 10, y2 - 10, R, G, B);
    myLine(x2 - 10, y2 - 10, mid_x + 10, y2 - 10, R, G, B);

    myLine(x + 10, y + 10, x + 10, mid_y - 10, R, G, B);
    myLine(x + 10, y2 - 10, x + 10, mid_y + 10, R, G, B);

    myLine(x2 - 10, y + 10, x2 - 10, mid_y - 10, R, G, B);
    myLine(x2 - 10, y2 - 10, x2 - 10, mid_y + 10, R, G, B);
}

void previous_cursor_dissolve(int x, int y, int i, int j, int cell_size, int board_size, int start_x, int start_y) {

    if (i % 2 == j % 2)
        make_pointer(x, y, i, j, cell_size, board_size, start_x, start_y, 180, 180, 180);
    else
        make_pointer(x, y, i, j, cell_size, board_size, start_x, start_y, 140, 140, 140);

}

void pointer(int board_size, int cell_size, int& i, int& j, int& x, int& y, int start_x, int start_y) {

    int key = 0;

    while (key != 10)         //loop will terminate when user press enter//
    {
        make_pointer(x, y, i, j, cell_size, board_size, start_x, start_y, 0, 0, 0);
        key = 0;
        isCursorKeyPressed(key);
        if (key == 1)
        {
            previous_cursor_dissolve(x, y, i, j, cell_size, board_size, start_x, start_y);
            x -= cell_size;
            j--;
        }
        if (key == 2)
        {
            previous_cursor_dissolve(x, y, i, j, cell_size, board_size, start_x, start_y);
            y -= cell_size;
            i--;
        }
        if (key == 3)
        {
            previous_cursor_dissolve(x, y, i, j, cell_size, board_size, start_x, start_y);
            x += cell_size;
            j++;
        }
        if (key == 4)
        {
            previous_cursor_dissolve(x, y, i, j, cell_size, board_size, start_x, start_y);
            y += cell_size;
            i++;
        }
    }
}

void matching_line(float x1, float y1, float x2, float y2) {
    int line;
    if (y1 == y2) {
        line = x1 + 5;
        while (line <= x2 - 5) {
            myLine(x1, y1, line, y2, 0, 0, 0);
            myLine(x1, y1 + 2, line, y2 + 2, 250, 180, 0);
            myLine(x1, y1 - 2, line, y2 - 2, 250, 180, 0);
            line += 5;
            Sleep(3);
        }
    }
    else if (y1 == y2) {
        line = y1 + 5;
        while (line < y2 - 5) {
            myLine(x1, y1, x2, line, 0, 0, 0);
            myLine(x1 - 2, y1, x2 - 2, line, 250, 180, 0);
            myLine(x1 + 2, y1, x2 + 2, line, 250, 180, 0);
            line += 5;
            Sleep(3);
        }
    }
    else {
        line = y1 + 5;
        while (line < y2 - 5) {
            myLine(x1, y1, line, line, 0, 0, 0);
            myLine(x1 - 2, y1, line - 2, line, 250, 180, 0);
            myLine(x1 + 2, y1, line + 2, line, 250, 180, 0);
            line += 5;
            Sleep(3);
        }
    }
}

bool checkWinner(int b[10][10], int& who, int board_size, int cell_size, int st_x, int st_y) {
    int x = st_x, y = st_y;
    bool check;

    for (int i = 0;i < board_size;i++) {

        check = 1;
        for (int j = 0;j < board_size - 1 && check == 1;j++)
            if (b[i][j] != b[i][j + 1] || b[i][j] == 0)
                check = 0;
        if (check == 1) {
            who = b[i][0];
            matching_line(st_x + 10, ((i + 1) * cell_size) + st_y - (cell_size / 2), st_x + (board_size * cell_size) - 10, ((i + 1) * cell_size) + st_y - (cell_size / 2));
            return true;
        }
        check = 1;
        for (int j = 0;j < board_size - 1 && check == 1;j++)
            if (b[j][i] != b[j + 1][i] || b[j][i] == 0)
                check = 0;
        if (check == 1) {
            who = b[0][i];
            matching_line(((i + 1) * cell_size) + st_x - (cell_size / 2), st_y + 10, ((i + 1) * cell_size) + st_x - (cell_size / 2), st_y + (board_size * cell_size) - 10);
            return true;
        }
    }

    check = 1;

    for (int i = 0;i < board_size - 1 && check == 1;i++) {
        if (b[i][i] != b[i + 1][i + 1] || b[i][i] == 0)
            check = 0;
    }
    if (check == 1) {
        who = b[0][0];
        matching_line(st_x + 10, st_y + 10, st_x + (board_size * cell_size) - 10, st_y + (board_size * cell_size) - 10);
        return true;
    }

    check = 1;
    int last_idx = board_size - 1;

    for (int i = 0;i < board_size - 1 && check == 1;i++, last_idx--)
        if (b[i][last_idx] != b[i + 1][last_idx - 1] || b[i][last_idx] == 0)
            check = 0;
    if (check == 1) {
        who = b[0][board_size - 1];
        matching_line(st_x + (board_size * cell_size) - 10, st_y + 10, st_x + 10, st_y + (board_size * cell_size) - 10);
        return true;
    }
    return false;

}

void auto_player(int b[10][10], int board_size, int& row, int& col) {
    int empty, no_2, e_i, e_j;
    bool stop = 0;
    for (int x = 1;x < board_size && stop == 0;x++) {
        if (x == board_size - 1) 
            if (b[board_size / 2][board_size / 2] == 0) {
                row = board_size / 2;
                col = board_size / 2;
                stop = 1;
            }
        for (int y = 2;y >= 1 && stop == 0;y--) {
            for (int i = 0;i < board_size && stop == 0;i++) {
                empty = 0;
                no_2 = 0;
                for (int j = 0;j < board_size && stop == 0;j++) {
                    if (b[i][j] == 0) {
                        empty++;
                        e_i = i;
                        e_j = j;
                    }
                    if (b[i][j] == y)
                        no_2++;
                }
                if (empty == x && no_2 == board_size - x) {
                    row = e_i;
                    col = e_j;
                    stop = 1;
                }
                empty = 0;
                no_2 = 0;
                for (int j = 0;j < board_size && stop == 0;j++) {
                    if (b[j][i] == 0) {
                        empty++;
                        e_i = j;
                        e_j = i;
                    }
                    if (b[j][i] == y)
                        no_2++;
                }
                if (empty == x && no_2 == board_size - x) {
                    row = e_i;
                    col = e_j;
                    stop = 1;
                }
            }

            empty = 0;
            no_2 = 0;
            for (int i = 0;i < board_size && stop == 0;i++) {
                if (b[i][i] == 0) {
                    empty++;
                    e_i = i;
                    e_j = i;
                }
                if (b[i][i] == y)
                    no_2++;
            }
            if (empty == x && no_2 == board_size - x) {
                row = e_i;
                col = e_j;
                stop = 1;
            }
            empty = 0;
            no_2 = 0;
            for (int i = 0, j = board_size - 1;i < board_size && stop == 0;i++, j--) {
                if (b[i][j] == 0) {
                    empty++;
                    e_i = i;
                    e_j = j;
                }
                if (b[i][j] == y)
                    no_2++;
            }
            if (empty == x && no_2 == board_size - x) {
                row = e_i;
                col = e_j;
                stop = 1;
            }
        }
    }
    if (stop == 0)
        for (int i = 0;i < board_size;i++)
            for (int j = 0;j < board_size;j++)
                if (b[i][j] == 0) {
                    row = i;
                    col = j;
                }


}

void input(int& mode, int& board_size, int& cell_size, int& start_x, int& start_y) {
    int max_cell_size = 150;
    bool settings;
    while (mode != 1 && mode != 2) {
        system("cls");
        cout << "Which MODE would you want to play?\n 1. Single Player\n 2. MultiPlayer\n";
        cin >> mode;
    }
    system("cls");
    cout << "Do you want your own costumized settings or default?\n(Press 1 for costumized or 0 for default) :";
    cin >> settings;
    if (settings == 1) {
        while (board_size < 3 || board_size>9) {
            system("cls");
            cout << "\nEnter the Dimensions of the Game Board (from 3 to 9): ";
            cin >> board_size;
        }
        if (board_size > 5)
            max_cell_size = 100;
        if (board_size > 7)
            max_cell_size = 80;
        while (cell_size < 50 || cell_size>max_cell_size) {
            system("cls");
            cout << "\nEnter the Size of one Cell of Board (from 50 to " << max_cell_size << ") :";
            cin >> cell_size;
        }

        while (start_y < 100) {
            system("cls");
            cout << "Enter the x-y cordinates from where you want to start the table (y-axis must be more than 100) :\n";
            cin >> start_x >> start_y;
        }
    }
    else 
        board_size = 3, cell_size = 120, start_x = 100, start_y = 100;
}
int main() {

    int auto_r,auto_c;
    int board[10][10] = { 0 }, player = 1, row = 0, col = 0, who;
    int start_x, start_y = 0, mode=0;
    bool winner = 0;
    int board_size = 0, cell_size = 0, pressed_row, pressed_col;

    input(mode, board_size, cell_size, start_x, start_y);

    int x = start_x, y = start_y;

    system("cls");

    printTable(board_size, cell_size, start_x, start_y);
    pointer(board_size, cell_size, row, col, x, y, start_x, start_y);
    for (int i = 1; i <= board_size * board_size && winner == 0; i++)
    {
        if (player == 1)
        {
            gotoxy(70, 2);
            cout << "Player 1's turn:\n";

            pointer(board_size, cell_size, row, col, x, y, start_x, start_y);
            pressed_row = row, pressed_col = col;
            while (board[row][col] != 0) {
                pointer(board_size, cell_size, row, col, x, y, start_x, start_y);
                pressed_row = row, pressed_col = col;
            }

            board[pressed_row][pressed_col] = 1;
            player = 2;
        }
        else {          
            
            if (mode == 1) {
                auto_player(board, board_size, auto_r, auto_c);
                pressed_row = auto_r, pressed_col = auto_c;
            }
            else {
                gotoxy(70, 2);
                cout << "Player 2's turn:\n";

                pointer(board_size, cell_size, row, col, x, y, start_x, start_y);

                pressed_row = row, pressed_col = col;
                while (board[row][col] != 0) {
                    pointer(board_size, cell_size, row, col, x, y, start_x, start_y);
                    pressed_row = row, pressed_col = col;
                }
            }
            board[pressed_row][pressed_col] = 2;
            player = 1;
        }
        printShapes(board, cell_size, pressed_row, pressed_col, start_x, start_y);
        winner = checkWinner(board, who, board_size, cell_size, start_x, start_y);
    }
    Sleep(2000);
    system("cls");
    gotoxy(60, 7);
    if (winner == 1)
        cout << "\" Player " << who << " is the WINNER! \"\n\n\n";
    else
        cout << "\" Oooops! it's a DRAW! \"\n\n\n";

    system("pause");
    return 0;
}