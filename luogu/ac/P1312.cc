#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;


#define MAX_X 5
#define MAX_Y 7
#define MAX_STEP 5


int game[MAX_STEP + 2][MAX_X][MAX_Y], step_num;


struct Step {
    int x;
    int y;
    int direction;
};

Step ans_step[MAX_STEP + 1];


void copy(int step) {
    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            game[step][i][j] = game[step - 1][i][j];
        }
    }
}


void fall(int step) {
    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            if (game[step][i][j] == 0)
                continue;
            
            int fall_row, row;
            fall_row = 0;
            row = j - 1;

            while (row >= 0 && game[step][i][row] == 0) {
                row--;
                fall_row++;
            }

            swap(game[step][i][j], game[step][i][j - fall_row]);
        }
    }
}


bool del(int step) {
    bool is_del = false;
    fall(step);

    bool flag[MAX_X][MAX_Y];

    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            flag[i][j] = false;
        }
    }

    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            if (game[step][i][j] == 0)
                continue;

            if (i < MAX_X - 2 && game[step][i][j] == game[step][i + 1][j] && game[step][i][j] == game[step][i + 2][j]) {
                flag[i][j] = flag[i + 1][j] = flag[i + 2][j] = true;
            }

            if (j < MAX_Y - 2 && game[step][i][j] == game[step][i][j + 1] && game[step][i][j] == game[step][i][j + 2]) {
                flag[i][j] = flag[i][j + 1] = flag[i][j + 2] = true;
            }
        }
    }

    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            if (flag[i][j]) {
                game[step][i][j] = 0;
                is_del = true;
            }
        }
    }

    return is_del;
}


void refresh(int step) {
    while (del(step)) {}
}


bool is_win(int step) {
    for (int i = 0; i < MAX_X; i++) {
        if (game[step][i][0])
            return false;
    }

    return true;
}


void save_step(int step, int x, int y, int dir) {
    ans_step[step].x = x;
    ans_step[step].y = y;
    ans_step[step].direction = dir;
}


bool play(int step) {
    copy(step);
    refresh(step);

    if (step == step_num + 1) {
        return is_win(step);
    }

    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            if (game[step][i][j] == 0)
                continue;

            if (i < MAX_X - 1) {
                save_step(step, i, j, 1);
                swap(game[step][i][j], game[step][i + 1][j]);
                if (play(step + 1))
                    return true;
                swap(game[step][i][j], game[step][i + 1][j]);
            }

            if (i - 1 >= 0 && game[step][i - 1][j] == 0) {
                save_step(step, i, j, -1);
                swap(game[step][i][j], game[step][i - 1][j]);
                if (play(step + 1))
                    return true;
                swap(game[step][i][j], game[step][i - 1][j]);
            }
        }
    }
    
    return false;
}


int main() {
    cin >> step_num;
    for (int i = 0; i < MAX_X; i++) {
        int y = 0;
        while (true) {
            int color;
            cin >> color;
            if (color == 0)
                break;
            game[0][i][y++] = color;
        }
    }

    if (play(1)) {
        for (int i = 1; i <= step_num; i++) {
            cout << ans_step[i].x << " " << ans_step[i].y << " " << ans_step[i].direction << endl;
        }
    } else {
        cout << -1 << endl;
    }
}