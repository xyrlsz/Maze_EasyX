#include "DFS.h"

struct DataType {
    int x;
    int y;
    int d;
};

typedef struct {
    DataType* data;
    int top;
    int stacksize;
} SeqStack, * PSeqStack;

PSeqStack createEmptyStack_seq(int m) {
    PSeqStack S = (PSeqStack)malloc(sizeof(SeqStack));
    if (S) {
        S->data = (DataType*)malloc(m * sizeof(DataType));
        if (!S->data) {
            free(S);
            return 0;
        }
        S->top = -1;
        S->stacksize = m;
    }
    return S;
}

int isEmptyStack_seq(PSeqStack S) {
    return (S->top == -1 ? 1 : 0);
}

void Push_Seq(PSeqStack S, DataType x) {
    S->top++;
    S->data[S->top] = x;
}

int Pop_Seq(PSeqStack S) {
    if (isEmptyStack_seq(S)) {
        printf("\n Stack is free!");
        return 0;
    }
    S->top--;
    return 1;
}

DataType Top_Seq(PSeqStack S) {
    DataType e;
    if (isEmptyStack_seq(S)) {
        e.x = e.y = e.d = -1;
        printf("\n Stack is free!");
    }
    else {
        e = S->data[S->top];
    }
    return e;
}


std::queue<std::pair<int, int>> DFS(std::vector<std::vector<uint32_t>> maze, int x1, int y1, int x2, int y2) {
    int derection[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    int i, j, k;
    int g, h;
    DataType term;
    PSeqStack S = NULL;
    if (S)
        free(S);
    S = createEmptyStack_seq(512);

    maze[x1][y1] = 2;
    term.x = x1;
    term.y = y1;
    term.d = -1;
    std::queue<std::pair<int, int>> q;
    Push_Seq(S, term);
    while (!isEmptyStack_seq(S)) {
        term = Top_Seq(S);
        Pop_Seq(S);
        i = term.x;
        j = term.y;
        k = term.d + 1;
        while (k <= 3) {
            g = i + derection[k][0];
            h = j + derection[k][1];
            if (g == x2 && h == y2) {
                q.push(std::make_pair(g, h));
                return q;
                while (!isEmptyStack_seq(S)) {
                    term = Top_Seq(S);
                    Pop_Seq(S);
                }
            }
            if (g >= maze.size() || g < 0 || h >= maze[0].size() || h < 0 || maze[g][h] == 0 || maze[g][h] == 2) {
                k++;
            }
            else {
                term.x = i;
                term.y = j;
                term.d = k;
                q.push(std::make_pair(i, j));
                maze[g][h] = 2;
                Push_Seq(S, term);
                i = g;
                j = h;
                k = 0;
            }
        }
    }
    if (!isEmptyStack_seq(S))
        printf("没找到路径\n");
    return q;
}



