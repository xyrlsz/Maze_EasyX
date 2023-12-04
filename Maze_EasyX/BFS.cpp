#include "BFS.h"

struct DataType {
    int x;
    int y;
    int d;
};

std::queue<DataType> createEmptyQueue() {
    std::queue<DataType> Q;
    return Q;
}

bool isEmptyQueue(const std::queue<DataType>& Q) {
    return Q.empty();
}

void Enqueue(std::queue<DataType>& Q, DataType x) {
    Q.push(x);
}

bool Dequeue(std::queue<DataType>& Q) {
    if (isEmptyQueue(Q)) {
        return false;
    }
    Q.pop();
    return true;
}

DataType Front(const std::queue<DataType>& Q) {
    return Q.front();
}

std::queue<std::pair<int, int>> BFS(std::vector<std::vector<int>> maze, int x1, int y1, int x2, int y2) {
    int derection[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    int i, j, k;
    int g, h;
    DataType term;
    std::queue<DataType> Q = createEmptyQueue();
    term.x = x1;
    term.y = y1;
    term.d = 0;
    std::queue<std::pair<int, int>> path;
    path.push(std::make_pair(x1, y1));
    Enqueue(Q, term);
    while (!isEmptyQueue(Q)) {
        term = Front(Q);
        i = term.x;
        j = term.y;
        k = term.d;
        Dequeue(Q);
        maze[i][j] = 2;
        while (k <= 3) {
            g = i + derection[k][0];
            h = j + derection[k][1];
            if (g == x2 && h == y2) {
                path.push(std::make_pair(g, h));
                return path;
            }
            if (g >= maze.size() || g < 0 || h >= maze[0].size() || h < 0 || maze[g][h] == 0 || maze[g][h] == 2) {
                k++;
            }
            else {
                term.x = g;
                term.y = h;
                term.d = 0;
                path.push(std::make_pair(g, h));
                maze[g][h] = 2;
                Enqueue(Q, term);
                k++;
            }
        }
    }
    if (!isEmptyQueue(Q))
        printf("No path found.\n");
    return path;
}
