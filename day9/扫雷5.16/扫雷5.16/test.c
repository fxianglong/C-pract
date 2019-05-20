#include "game.h"

void menu()
{
    printf("********************************\n");
    printf("*****  1.play      0.exit ******\n");
    printf("********************************\n");

}
void game()
{
    char mine[ROWS][COLS] = { 0 };
    char show[ROWS][COLS] = { 0 };
    InitBoard(mine, ROWS, COLS,'0');
    InitBoard(show, ROWS, COLS,'*');
    SetMine(mine, ROW, COL);
    DisplayBoard(mine, ROW, COL);
    DisplayBoard(show, ROW, COL);
    Safe(mine, show, ROW, COL); 
    FindMine(mine, show, ROW, COL);

}
void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("ÇëÑ¡Ôñ:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("ÍË³öÓÎÏ·\n");
            break;
        default:
            printf("Ñ¡Ôñ´íÎó\n");
            break;
        }

    } while (input);

}
int main()
{
    test();
    system("pause");
    return 0;
}
