#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>

#define SCREEN_SIZE 79

struct GameObject
{
	int		pos;
	char	shape[20];

};

void draw(char* screen, GameObject* player, GameObject* enemy, GameObject* bullet)
{
	if (screen == NULL) return;

	if (player->shape != NULL && player->pos >= 0 && player->pos < SCREEN_SIZE)
	{
		memcpy(screen + player->pos, player->shape, strlen(player->shape));
	}
	if (enemy->shape != NULL && enemy->pos >= 0 && enemy->pos < SCREEN_SIZE)
	{
		memcpy(screen + enemy->pos, enemy->shape, strlen(enemy->shape));
	}
	if (bullet->pos != -1)
	{
		if (player->pos < enemy->pos)
		{
			memcpy(screen + bullet->pos, bullet->shape, strlen(bullet->shape));
		}
		else if (player->pos > enemy->pos)
		{
			memcpy(screen + bullet->pos, bullet->shape, strlen(bullet->shape));
		}
	}
	//strcpy(screen + player_pos, player);
}

void inputon(GameObject& player, GameObject& enemy, GameObject& bullet)
{
	if (*bullet.shape == -1) return;

	if(*bullet.shape == enemy.pos)
	{
		bullet.pos = -1;
		return;
	}
	if (bullet.pos < 0)
	{
		bullet.pos = -1;
		return;
	}
	if (bullet.pos > SCREEN_SIZE)
	{
		bullet.pos = -1;
		return;
	}
	if (player.pos < enemy.pos)
	{
		(bullet.pos)++;
	}
	if (player.pos > enemy.pos)
	{
		(bullet.pos)--;
	}
}

void playermove(GameObject& player, GameObject enemy, GameObject bullet)
{
	if (_kbhit())
	{
		char ch = getch();
		//printf("%d\n", ch);

		if (ch == 'a'&&'A')
		{
			(*player.pos)--;
		}
		else if (ch == 'd'&&'D')
		{
			(*player.pos)++;
		}
		else if (ch == ' ')
		{
			if ((*bullet.pos) == -1)
			{
				*bullet.pos = *player.pos;
			}
		}
	}
}

void playershape(int* player_pos, int* bullet_pos,int* enemy_pos,int* direct, const char* bullet_right, const char* bullet_left, char*  bullet_shape,
	const char* player_no, const char* player_yes, char*  enemy, char*  player)
{
	if (*enemy_pos + strlen(enemy) == *bullet_pos)
	{
		(*bullet_pos) = 0;
		strcpy(enemy, player_yes);
		strcpy(bullet_shape, bullet_right);
	}
	else if (*enemy_pos == *bullet_pos + strlen(bullet_shape))
	{
		(*bullet_pos) = *enemy_pos;
		*direct=1;
		strcpy(enemy, player_yes);
		strcpy(bullet_shape, bullet_left);
	}

	if (*player_pos < 0)
	{
		*player_pos = SCREEN_SIZE - strlen(player) + 1;
	}
	else if(*player_pos == SCREEN_SIZE )
	{
		*player_pos = 0;
	}
}

void scree(char* screen)
{
	memset(screen, ' ', SCREEN_SIZE);
}

void render(char* screen)
{
	screen[SCREEN_SIZE] = '\0';
	printf("%s\r", screen);
	Sleep(33);
}


int main()
{
	char screen[SCREEN_SIZE + 1];

	GameObject player;
	player.pos = rand() % SCREEN_SIZE;
	strcpy(player.shape, "<>_<>");

	GameObject enemy;
	enemy.pos = rand() % SCREEN_SIZE;
	strcpy(enemy.shape, "*____*");

	GameObject bullet;
	strcpy(bullet.shape, "-=->");
	bullet.pos = -1;


	while (1)
	{
		scree(screen);
		inputon(player, enemy, bullet);
		draw(screen, player, enemy, bullet);
		playermove(player, enemy, bullet);
		render(screen);


		//playershape(&player_pos, &bullet_pos, &enemy_pos, &direct, bullet_right, bullet_left, bullet_shape, enemy_no, enemy_yes, enemy,player);

	}

	return 0;
}