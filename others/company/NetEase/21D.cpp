#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;
bool check_x(int x, int y, vector<vector<int> > &fruit) {
    if (y == 0) {
        if (fruit[x][y] == fruit[x][y+1] && fruit[x][y] == fruit[x][y+2])
            return true;
    } else if (y == fruit[0].size() - 1) {
        if (fruit[x][y] == fruit[x][y-1] && fruit[x][y] == fruit[x][y-2])
            return true;
    } else {
        if (fruit[x][y] == fruit[x][y-1] && fruit[x][y] == fruit[x][y+1])
            return true;
    }
    return false;
}

bool check_y(int x, int y, vector<vector<int> > &fruit) {
    if (x == 0) {
        if (fruit[x][y] == fruit[x+1][y] && fruit[x][y] == fruit[x+2][y])
            return true;
    } else if (x == fruit.size() - 1) {
        if (fruit[x][y] == fruit[x-1][y] && fruit[x][y] == fruit[x-2][y])
            return true;
    } else {
        if (fruit[x][y] == fruit[x+1][y] && fruit[x][y] == fruit[x-1][y])
            return true;
    }
    return false;
}

struct point{
    int x;
    int y;
    int val;
    point():x(0),y(0),val(-1){};
    point(int x, int y, int val):x(x),y(y),val(val){};
};

void step_1(vector<vector<int> > &fruit) {
    vector<point> del_x;
    vector<point> del_y;
    do {
        for (int i = 0; i < fruit.size(); ++i) {
            for (int j = 0; j < fruit[0].size(); ++j) {
                point item(i, j, fruit[i][j]);
                if (check_x(i, j, fruit)) {
                    del_x.push_back(item);
                }
                if (check_y(i, j, fruit)) {
                    del_y.push_back(item);
                }
            }
        }
        if (del_x.empty() && del_y.empty()) {
            break;
        }
        for (int i = 0; i < del_x.size(); ++i) {
            int tmp = del_x[i].y;
            while (tmp < fruit[0].size() && (fruit[del_x[i].x][tmp] == del_x[i].val || fruit[del_x[i].x][tmp] == 0)) {
                if (fruit[del_x[i].x][tmp] == 0 && (tmp + 1 == fruit[0].size() || fruit[del_x[i].x][tmp + 1] != del_x[i].val)) {
                    break;
                }
                fruit[del_x[i].x][tmp++] = 0;
            }
            while (tmp >= 0 && (fruit[del_x[i].x][tmp] == del_x[i].val || fruit[del_x[i].x][tmp] == 0)) {
                if (fruit[del_x[i].x][tmp] == 0 && (tmp == 0 || fruit[del_x[i].x][tmp - 1] != del_x[i].val)) {
                    break;
                }
                fruit[del_x[i].x][tmp--] = 0;
            }
        }
        for (int i = 0; i < del_y.size(); ++i) {
            int tmp = del_y[i].x;
            while (tmp < fruit.size() && (fruit[tmp][del_y[i].y] == del_y[i].val || fruit[tmp][del_y[i].y] == 0)) {
                if (fruit[tmp][del_y[i].y] == 0 && (tmp + 1 == fruit.size() || fruit[tmp + 1][del_y[i].y] != del_y[i].val)) {
                    break;
                }
                fruit[tmp++][del_y[i].y] = 0;
            }
            while (tmp >= 0 && (fruit[tmp][del_y[i].y] == del_y[i].val || fruit[tmp][del_y[i].y] == 0)) {
                if (fruit[tmp][del_y[i].y] == 0 && (tmp == 0 || fruit[tmp - 1][del_y[i].y] != del_y[i].val)) {
                    break;
                }
                fruit[tmp--][del_y[i].y] = 0;
            }
        }
        for (int i = fruit.size() - 1; i > 0; --i) {
            for (int j = 0; j < fruit[0].size(); ++j) {
                if (fruit[i][j] == 0) {
                    fruit[i][j] = fruit[i-1][j];
                    fruit[i-1][j] = 0;
                }
            }
        }
        vector<point>().swap(del_x);
        vector<point>().swap(del_y);
    } while (true);
}

void step_2(vector<vector<int> > &fruit, queue<int> &exat) {
    for (int i = fruit.size() - 1; i >= 0; --i) {
        for (int j = 0; j < fruit[0].size(); ++j) {
            if (exat.empty())
                return;
            if (fruit[i][j] == 0) {
                fruit[i][j] = exat.front();
                exat.pop();
            }
        }
    }
}

int main() {
    int M, N;
    cin >> M >> N;
    getchar();
    vector<vector<int> > fruit(M, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            fruit[i][j] = getchar() - '0';
        }
    }
    getchar();
    char in = getchar();
    queue<int> exat;
    while (in != '\n') {
        exat.push(in - '0');
        in = getchar();
    }
    int len = 0;
    do {
        len = exat.size();
        step_1(fruit);
        step_2(fruit, exat);
    } while(!exat.empty() && len != exat.size());
    step_1(fruit);
    for (int i = 0; i<N; i++) {
        cout << fruit[0][i];
    }
    cout << endl;
    return 0;
}