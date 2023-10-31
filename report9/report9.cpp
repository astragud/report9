#include <stdio.h>
#include <stdbool.h>

#define SIZE 11

// 그래프의 인접 행렬 표현
int graph[SIZE][SIZE] =
{
    {0,0,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,1,0,0,1,0,0,0},
    {1,0,0,1,1,0,0,0,0,0,0},
    {1,0,1,0,1,1,0,0,0,0,0},
    {1,1,1,1,0,0,1,1,1,0,0},
    {1,0,0,1,0,0,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,1,0},
    {0,1,0,0,1,0,0,0,0,0,1},
    {0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0}
};

bool visited[SIZE];

// 큐의 구현
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int v)
{
    if (rear == SIZE - 1) return;
    queue[++rear] = v;
}

int dequeue()
{
    if (front == rear) return -1;
    return queue[++front];
}

bool isEmpty()
{
    return front == rear;
}

// 깊이 우선 탐색 (DFS)
void DFS(int start, int target)
{
    int stack[SIZE], top = -1;
    for (int i = 0; i < SIZE; i++) visited[i] = false;

    stack[++top] = start;
    while (top != -1)
    {
        int v = stack[top--];
        if (!visited[v])
        {
            printf("%d ", v);
            visited[v] = true;
            if (v == target)
            {
                printf("\nTarget found! Visited nodes: %d\n", v + 1);
                return;
            }

            for (int i = SIZE - 1; i >= 0; i--)
            {
                if (graph[v][i] && !visited[i])
                {
                    stack[++top] = i;
                }
            }
        }
    }
}

// 너비 우선 탐색 (BFS)
void BFS(int start, int target)
{
    for (int i = 0; i < SIZE; i++) visited[i] = false;
    front = rear = -1;

    enqueue(start);
    while (!isEmpty())
    {
        int v = dequeue();
        if (!visited[v])
        {
            printf("%d ", v);
            visited[v] = true;
            if (v == target)
            {
                printf("\nTarget found! Visited nodes: %d\n", v + 1);
                return;
            }

            for (int i = 0; i < SIZE; i++)
            {
                if (graph[v][i] && !visited[i])
                {
                    enqueue(i);
                }
            }
        }
    }
}

int main()
{
    int choice;
    int start, target;

    printf("-----------------------\n");
    printf("| 1. 깊이 우선 탐색   |\n");
    printf("| 2. 너비 우선 탐색   |\n");
    printf("| 3. 종료             |\n");
    printf("-----------------------\n");

    while (1)
    {
        printf("\n메뉴 선택: ");
        scanf_s("%d", &choice);

        if (choice == 1)
        {
            printf("시작 노드와 목표 노드를 입력하세요 (0-10): ");
            scanf_s("%d %d", &start, &target);
            DFS(start, target);
        }

        else if (choice == 2)
        {
            printf("시작 노드와 목표 노드를 입력하세요 (0-10): ");
            scanf_s("%d %d", &start, &target);
            BFS(start, target);
        }

        else if (choice == 3)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        else
        {
            printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}