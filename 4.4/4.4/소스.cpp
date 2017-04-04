#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>

#define SCREEN_SIZE 79

int main()
{
	int bullet_pos = 30;
	char screen[SCREEN_SIZE + 1];
	int player_pos = 20;
	int enemy_pos = 60;
	char bullet_shape = '>';
	char player[4] = "^_^";
	char enemy[] = "*____*";

	while (1)
	{
		memset(screen, ' ', SCREEN_SIZE);

		int ch = getch();


		enemy_pos = enemy_pos + (rand() % 2);
		if (enemy_pos >= SCREEN_SIZE - 6)
		{
			enemy_pos = 0;
		}
		else if (enemy_pos <= 0)
		{
			enemy_pos = SCREEN_SIZE-6;
		}
		else if (enemy_pos + 6 == player_pos)
		{
			player_pos++;
		}
		else if (enemy_pos == player_pos + 3)
		{
			player_pos--;
		}

		screen[bullet_pos] = bullet_shape;

		screen[SCREEN_SIZE] = '\0';

		memcpy(screen + player_pos, player, 3);
		memcpy(screen + enemy_pos, enemy, 6);
		//strcpy(screen + player_pos, player);


		printf("%s\r", screen);
		Sleep(100);
	}



	return 0;
}