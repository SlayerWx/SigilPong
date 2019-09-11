#include "sl.h"
int main(int args, char *argv[])
{
	// set up our window and a few resources we need
	const int screenWidth = 800;
	const int screenHeight = 450;
	slWindow(screenWidth, screenHeight, "Sigil Pong - RuffoMaximiliano", false);
	enum PlayerTouched
	{
		nothing, p1, p2
	};
	PlayerTouched BallonColisionSelector;
	PlayerTouched PlayerBuffed = nothing;
	enum MenuStage
	{
		Menu, Game, EndGame, WaitMenu, WaitGame
	};
	MenuStage MenuSelector = Menu;
	enum ColorSelected
	{
		Red, Blue, Orange, Violet
	};
	ColorSelected ColorP1 = Blue;
	ColorSelected ColorP2 = Red;
	const int playerHeightSize = 100;
	const int playerWidthSize = 20;
	const float PlayersSpeed = 5.2f;
	const float normalSpeedBallon = 9.0f;
	const int RadiusBallon = 15;
	struct Player {
		int height;
		int width;
		double x;
		double y;
	};
	Player Player1;
	Player Player2;
	Player MenuPlayer1;
	Player MenuPlayer2;
	Player1.height = playerHeightSize;
	Player2.height = playerHeightSize;
	Player1.width = playerWidthSize;
	Player2.width = playerWidthSize;
	MenuPlayer1.height = playerHeightSize;
	MenuPlayer2.height = playerHeightSize;
	MenuPlayer1.width = playerWidthSize;
	MenuPlayer2.width = playerWidthSize;
	MenuPlayer1.y = ((float)screenHeight / 2) - ((float)Player1.height / 2);
	MenuPlayer2.y = ((float)screenHeight / 2) - ((float)Player2.height / 2);
	Player1.x = 3;
	Player2.x = screenWidth - Player2.width - 3;
	MenuPlayer1.x = 3;
	MenuPlayer2.x = screenWidth - Player2.width - 3;
	int GlobalScorePlayer1 = 0;
	int GlobalScorePlayer2 = 0;
	int ScorePlayer1 = 0;
	int ScorePlayer2 = 0;
	const int maxScoreSet = 7;
	struct Vector2
	{
		int x;
		int y;
	};
	Vector2 ballPosition;
	Vector2 VelBallon;
	struct Box
	{
		Vector2 Pos;
		bool isVisible;
//		Texture2D LuckBoxTexture;
		int width;
		int height;
		int buffSelected;
		int timer;
		int maxtimer;
		bool effect2player1;
		bool effect2player2;
	};
	Box luckBox;
	luckBox.Pos.x = screenWidth / 2;
	luckBox.Pos.y = screenHeight / 2;
	luckBox.width = 35;
	luckBox.height = 35;
	luckBox.isVisible = false;
	luckBox.buffSelected = 0;
	luckBox.maxtimer = 300;
	luckBox.timer = 0;
	luckBox.effect2player1 = false;
	luckBox.effect2player2 = false;
	

	bool musicStreamIsPlay = false;
	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE) &&
		(MenuSelector == Menu || MenuSelector == WaitMenu || MenuSelector == WaitGame))
	{
		if (MenuSelector != WaitGame)
		{				//w
			if (slGetKey(119) && MenuPlayer1.y > 85)
			{
				MenuPlayer1.y -= PlayersSpeed;
			}			//s
			if (slGetKey(115) && MenuPlayer1.y + MenuPlayer1.height < screenHeight - 20)
			{
				MenuPlayer1.y += PlayersSpeed;
			}
			if (slGetKey(SL_KEY_UP) && MenuPlayer2.y > 85)
			{
				MenuPlayer2.y -= PlayersSpeed;
			}
			if (slGetKey(SL_KEY_DOWN) && MenuPlayer2.y + MenuPlayer2.height < screenHeight - 20)
			{
				MenuPlayer2.y += PlayersSpeed;
			}
			if (slGetMouseY() < screenHeight - 10 && slGetMouseY() > screenHeight - 85 &&
				slGetMouseX() > (screenWidth / 2) - 85 && slGetMouseX() < (screenWidth / 2) + 50)
			{

				//		PlayColorMenu = YELLOW;
				if (slGetMouseButton(0) && MenuSelector != WaitMenu)
				{
					MenuSelector = Game;
				}

			}
			else
			{
				//			PlayColorMenu = WHITE;
			}
			slSetBackColor(0.30, 0, 0);
			slSetForeColor(1, 1, 0, 1);
			slSetFontSize(24);
			slText((screenWidth / 2) - 70, 10,"PONG");
			slRender();// draw everything
		}
	}
	slClose();// close the window and shut down SIGIL
	return 0;
	
}