#ifndef SEEKSHORTESTPATH_H_INCLUDED
#define SEEKSHORTESTPATH_H_INCLUDED

#include<iostream>

using namespace std;

const int dir_count = 4;//ǰ�����������
const int pathmark = -1;//�Թ�ͨ·�ı�ʶֵ
const int n = 10;//�Թ���������
const int m=n+2;//����һȦΧǽ



//��ʼ���Թ�
int Maze[m][m] =
{
    { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
    { 2, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 2 },
    { 2, 1, 0, 1, 0, 0, 0, 0, 0, 1 ,1, 2 },
    { 2, 1, 0, 0, 0, 1, 1, 0, 1, 1 ,1, 2 },
    { 2, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2 },
    { 2, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 2 },
    { 2, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 2 },
    { 2, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 2 },
    { 2, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 2 },
    { 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 2 },
    { 2, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 2 },
    { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
};



//λ�������ǰ��������ŵ���Ԫ��ṹ����
struct items
{
    int x;//λ�õ�x����
    int y;//λ�õ�y����
};

items entry = { 1, 1 };//�Թ������������
items exitus = { 10, 10 };//�Թ�������������

//ǰ�������Ľṹ����
struct offfsets
{
    int a;//x�����ƫ��
    int b;//y�����ƫ��
    char *dir;//�ƶ��ķ�������
};


//���������ƫ�Ʊ���
offfsets moves[dir_count] =
{
    { 0, 1, "Right" },
    { 1, 0, "Down" },
    { 0, -1, "Left" },
    { -1, 0, "Up" }
};

//��ӡ�Թ�
void print_maze()
{
    cout << "======>MazePath" << endl;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (Maze[i][j] == pathmark)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
            }
            cout.width(4);  //�����ֶο��Ϊnλ
            cout << Maze[i][j];
        }
        cout << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
}


void MarkPath()
{
    int PathLen = Maze[exitus.x][exitus.y];
    cout << "�Թ����·�����ȣ�" << PathLen << endl;
    items *path = new items[PathLen];
    items cur = exitus;
    items tmp, next;
    for (int j = PathLen - 1; j > 0; j--)
    {
        tmp = path[j] = cur;
        Maze[tmp.x][tmp.y] = pathmark;
        for (int i = 0; i < dir_count; i++)
        {
            next.x = cur.x + moves[i].a;
            next.y = cur.y + moves[i].b;
            if (Maze[next.x][next.y] == j)
            {
                break;
            }
        }
        cur = next;
    }
     Maze[entry.x][entry.y] = pathmark;
}

/*
bool SeekShortestPath()
{
    linkqueue<items> linkedQueue;
    items cur = entry;
    items next = entry;
    Maze[entry.x][entry.y] = 1;
    while ((next.x != exitus.x) || (next.y != exitus.y))
    {
        int d;
        for (d = 0; d < dir_count; d++)
        {
            next.x = cur.x + moves[d].a;
            next.y = cur.y + moves[d].b;
            if (Maze[next.x][next.y] == 0)
            {
                Maze[next.x][next.y] = Maze[cur.x][cur.y] + 1;
                if ((next.x == exitus.x) && (next.y == exitus.y))
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                    cout << "======>SeekShortestPath Success" << endl;
                    break;
                }


                //**************************************************************************************************************************************
  linkedQueue.enqueue(next);
               // ***************************************************************************************************************************************


               if(!linkedQueue.isempty()) cout<<"*"<<linkedQueue.gethead().x<<"*"<<linkedQueue.gethead().y<<"*"<<endl;
            }
        }
        if ((true == linkedQueue.isempty())&&(d==dir_count))
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "======>SeekPath Fail" << endl;

            return false;
        }
        cur=linkedQueue.dequeue();
         if(!linkedQueue.isempty())cout<<"*"<<linkedQueue.gethead().x<<"*"<<linkedQueue.gethead().y<<"*"<<endl;
    }
    MarkPath();

    return true;
}
*/



bool SeekShortestPath()
{
    LinkedQueue<items>* linkedQueue = new LinkedQueue<items>;
    items cur = entry;
    items next = entry;
    Maze[entry.x][entry.y] = 1;
    while ((next.x != exitus.x) || (next.y != exitus.y))
    {
        for (int d = 0; d < dir_count; d++)
        {
            next.x = cur.x + moves[d].a;
            next.y = cur.y + moves[d].b;
            if (Maze[next.x][next.y] == 0)
            {
                Maze[next.x][next.y] = Maze[cur.x][cur.y] + 1;
                if ((next.x == exitus.x) && (next.y == exitus.y))
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                    cout << "======>SeekShortestPath Success" << endl;
                    break;
                }
                linkedQueue->EnQueue(next);
            }
        }
        if (true == linkedQueue->IsEmpty())
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout << "======>SeekPath Fail" << endl;
            delete linkedQueue;
            return false;
        }
        linkedQueue->DeQueue(cur);
    }
    MarkPath();
    delete linkedQueue;
    return true;
}




#endif // SEEKSHORTESTPATH_H_INCLUDED
