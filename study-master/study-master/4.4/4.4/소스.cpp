#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>

#define SCREEN_SIZE 79

struct GameObject
{
	int		pos;
	char	shape[20];

	//함수 뒤 const 읽기만 하겟다
	GameObject(char *s, int p)
	{
		pos = p;
		strcpy(shape, "---");
	}

};

struct Bullet
{
	GameObject myData;

	void draw(char* screen, const GameObject *player, const GameObject* enemy)
	{
		if (myData.pos != -1)
		{
			if (player->pos < enemy->pos)
			{
				memcpy(screen + myData.pos, ">", strlen(">"));
			}
			else if (player->pos > enemy->pos)
			{
				memcpy(screen + myData.pos, "<", strlen("<"));
			}
		}
	}
};

void draw(char* screen, const GameObject* player, const GameObject* enemy,const Bullet bullet[], int bullets_len)
{
	if (screen == NULL) return;

	//static_cast, dynamic_cast, const_cast, reinterpret_cast
	//const_cast<GameObject*>(player)->draw(screen);

	//((GameObject*)player)->draw(screen);

	//if (player->pos >= 0 && player->pos < SCREEN_SIZE)
	//{
		//memcpy(screen + player->pos, player->shape, strlen(player->shape));
	//}

	player->draw(screen);  //함수뒤 const 사용
	enemy->draw(screen);

	for (int i = 0; i < bullets_len; i++) {
		bullet->myData.draw(screen);




		//if (bullet[i].pos != -1)
		//{
		//	if (player->pos < enemy->pos)
		//	{
		//		memcpy(screen + bullet[i].pos, ">", strlen(">"));
		//	}
		//	else if (player->pos > enemy->pos)
		//	{
		//		memcpy(screen + bullet[i].pos, "<", strlen("<"));
		//	}
		}
	}
	//strcpy(screen + player_pos, player);
}

void inputon(GameObject* player, GameObject* enemy, Bullet bullet[], int bullets_len)
{
	for (int i = 0; i < bullets_len; i++) {
		if (bullet[i].myData.pos == -1) continue;

		if (bullet[i].myData.pos == enemy->pos)
		{
			bullet[i].myData.pos = -1;
			continue;
		}
		if (bullet[i].myData.pos < 0)
		{
			bullet[i].myData.pos = -1;
			continue;
		}
		if (bullet[i].myData.pos > SCREEN_SIZE)
		{
			bullet[i].myData.pos = -1;
			continue;
		}
		if (player->pos < enemy->pos)
		{
			bullet[i].myData.pos++;
		}
		if (player->pos > enemy->pos)
		{
			bullet[i].myData.pos--;
		}
	}
}

void playermove(GameObject* player, GameObject* enemy, Bullet bullet[], int bullets_len)
{
	if (_kbhit())
	{
		int ch = getch();
		//printf("%d\n", ch);
		if (ch == 224) {
			ch = getch();
			if (ch == 75)
			{
				player->pos--;
			}
			else if (ch == 77)
			{
				player->pos++;
			}
			if (ch == 80)
			{
				enemy->pos--;
			}
			else if (ch == 72)
			{
				enemy->pos++;
			}
		}
		else if (ch == ' ')
		{
			int i = 0;
			for (; i < bullets_len; i++) 
			{
				if (myData.pos == -1)
					break;
			}
			if (i == bullets_len)
			{
				
			}
			else if (i < bullets_len)
			{
				myData.pos = player->pos;
			}
		}
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
	const int bullets_len = 30;

	strucr GameObject player{"^_^",30};

	strucr GameObject enemy{"<_>", 60};

	int i-0;
	int j{2};
	int k(30);


	strucr Bullet bullet[bullets_len];

	for (int i = 0; i < bullets_len; i++)
	{
		strcpy(myData.shape, "-=->");
		bullet[i].myData.pos = -1;
	}


	while (1)
	{
		scree(screen);
		inputon(&player, &enemy, bullet, bullets_len);
		draw(screen, &player, &enemy, bullet, bullets_len);
		playermove(&player, &enemy, bullet, bullets_len);
		render(screen);


		//playershape(&player_pos, &bullet_pos, &enemy_pos, &direct, bullet_right, bullet_left, bullet_shape, enemy_no, enemy_yes, enemy,player);

	}

	return 0;
}