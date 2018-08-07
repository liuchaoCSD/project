#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define FOOD "□"

void SetPos(int x, int y)
{
	HANDLE hOutput = NULL;
	COORD pos;

	pos.X = x;
	pos.Y = y;

	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}

void CreateMap(void) {
	int i;
	SetPos(0, 0);
	for (i = 0; i < 58; i += 2){
		SetPos(i, 0);
		printf(FOOD);
		SetPos(i, 26);
		printf(FOOD);
	}
	for (i = 1; i < 26; i++) {
		SetPos(0, i);
		printf(FOOD);
		SetPos(56, i);
		printf(FOOD);
	}
}

// 蛇身体的节点
typedef struct node_ {
	int x;
	int y;
	struct node_ *next;
}SnakeNode, *pSnakeNode;

enum DIRECTION { UP, LEFT, RIRHT, DOWN };
enum GAME_STATUS {
	OK,          // 正常
	KILL_BY_SELF, // 咬死自己
	KILL_BY_WALL, // 撞死自己
	KILL_NORMAL   // 正常死亡
};

typedef struct Snake {
	pSnakeNode _pSnake;      // 维护整条蛇
	pSnakeNode _pFood;       // 食物
	enum DIRECTION _Dir;     // 蛇的运动方向
	int _SleepTime;          // 每走一步休息的时间
	enum GAME_STATUS _Status; // 游戏状态
}Snake, *pSnake;

#define INIT_X 24
#define INIT_Y 5

void InitSnake(pSnake ps)
{
	pSnakeNode cur = NULL;

	cur = malloc(sizeof(SnakeNode));
	cur->x = INIT_X;
	cur->y = INIT_Y;
	cur->next = NULL;

	for (int i = 1; i <= 4; i++) {
		ps->_pSnake = malloc(sizeof(SnakeNode));
		ps->_pSnake->next = cur;
		ps->_pSnake->x = INIT_X + 2 * i;
		ps->_pSnake->y = INIT_Y;
		cur = ps->_pSnake;
	}

	while ( cur != NULL ) {
		SetPos(cur->x, cur->y);
		printf(FOOD);
		cur = cur->next;
	}

	ps->_Dir = RIRHT;
	ps->_SleepTime = 500;
	ps->_Status = OK;
}

// 创建食物
void CreateFood(pSnake ps)
{
	pSnakeNode pFood = NULL;
	pSnakeNode cur = NULL;
	
	pFood = malloc(sizeof(SnakeNode));

Again:
	cur = ps->_pSnake;
	do {
		pFood->x = rand() % 53 + 2;
	} while (pFood->x % 2 != 0);
	pFood->y = rand() % 25 + 1;

	while (cur != NULL) {
		if (cur->x == pFood->x && cur->y == pFood->y)
			goto Again;
		cur = cur->next;
	}

	SetPos(pFood->x, pFood->y);
	printf(FOOD);

	ps->_pFood = pFood;
}

void Welcome(void)
{
	system("mode con: cols=100 lines=30");
	SetPos(20, 5);
	printf("欢迎来到李氏版贪吃蛇");
	SetPos(20, 10);
	printf("↑ ↓ ← → 控制方向\n");
	system("pause");
	system("cls");
}

void GameStart(pSnake ps)
{
	Welcome();
	srand(time(NULL));
	CreateMap();
	InitSnake(ps);
	CreateFood(ps);
}

int NextHasFood(pSnakeNode psn, pSnake ps)
{
	return psn->x == ps->_pFood->x &&
		psn->y == ps->_pFood->y;
}
void EatFood(pSnakeNode psn, pSnake ps)
{
	pSnakeNode cur = NULL;
	psn->next = ps->_pSnake;
	ps->_pSnake = psn;
	cur = ps->_pSnake;

	while (cur != NULL) {
		SetPos(cur->x, cur->y);
		printf(FOOD);
		cur = cur->next;
	}
	free(ps->_pFood);
	CreateFood(ps);
}

void NoFood(pSnakeNode psn, pSnake ps)
{
	pSnakeNode cur = psn;
	psn->next = ps->_pSnake;
	ps->_pSnake = psn;
	
	while ( cur->next->next != NULL )
	{
		SetPos(cur->x, cur->y);
		printf(FOOD);
		cur = cur->next;
	}
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;
}

void SnakeMove(pSnake ps)
{
	pSnakeNode nextNode = malloc(sizeof(SnakeNode));
	nextNode->x = ps->_pSnake->x;
	nextNode->y = ps->_pSnake->y;
	switch (ps->_Dir)
	{
	case UP:
		nextNode->y -= 1;
		break;
	case DOWN:
		nextNode->y += 1;
		break;
	case LEFT:
		nextNode->x -= 2;
		break;
	case RIRHT:
		nextNode->x += 2;
		break;
	default:
		break;
	}

	if (NextHasFood(nextNode, ps))
		EatFood(nextNode, ps);
	else
		NoFood(nextNode, ps);
}

int KillByWall(pSnake ps)
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 || ps->_pSnake->y == 26 ) {
		ps->_Status = KILL_BY_WALL;
		return 1;
	}
	
	return 0;
}

int KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur != NULL) {
		if ( cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y) {
			ps->_Status = KILL_BY_SELF;
			break;
		}
		cur = cur->next;
	}
	return 0;
}

void GameRun(pSnake ps)
{
	do 
	{
		if (GetAsyncKeyState(VK_UP) && ps->_Dir!=DOWN )
			ps->_Dir = UP;
		if (GetAsyncKeyState(VK_DOWN) && ps->_Dir != UP)
			ps->_Dir = DOWN;
		if (GetAsyncKeyState(VK_LEFT) && ps->_Dir != RIRHT)
			ps->_Dir = LEFT;
		if (GetAsyncKeyState(VK_RIGHT) && ps->_Dir != LEFT)
			ps->_Dir = RIRHT;
		
		SnakeMove(ps);
		KillBySelf(ps);
		KillByWall(ps);

		Sleep(ps->_SleepTime);
	} while (ps->_Status == OK);

	if (ps->_Status == KILL_BY_SELF) {
		printf("竟然能把自己咬死，太佩服你了\n");
	}
	else if (ps->_Status == KILL_BY_WALL) {
		printf("你撞墙了\n");
	}
}

int main(void)
{
	Snake s;
	
	GameStart(&s);
	GameRun(&s);

	system("pause");
	return 0;
}