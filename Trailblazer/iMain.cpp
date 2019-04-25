
# include "iGraphics.h"
# include <time.h>
# include <stdio.h>
# include <string.h>
# include "bitmap_viewer.h"

int mposx, mposy;
int width = 1280, length = 720; // For Screen Size;
int littledemonx = 900, littledemony = 70; // For fixing the initial position of the little demons of hell;
int flyingdemonhellx2 = 100, flyingdemonhelly2 = 500; // For fixing the initial position of the flying demons of hell;
int flyingdemonhellx = 1033, flyingdemonhelly = 500;
int angelx = 640 - 110, angely = 0; // For setting up the initial position of the angel as the demons will come from both sides in this level;
int imageIndex = 0; // To control the hell background images;
int littledemonsindex = 0; // To control the images of the little demons of hell;
int angelsuperindex = 0; // To control the images of the super power of the angel when it's facing the right side;
int angelsuperindex2 = 0; // To control the images of the super power of the angel when it's facing the left side;
int angelhealthbarindex = 0; // To control the health bar images of the angel;
int flyingdemonhellindex = 0; // To control the images of the flying demons of hell to the right side;
int flyingdemonhellindex2 = 0; // To control the images of the flying demons of hell to the left side;
int numoflildemonsatm1 = 1; // Number of demons at the moment from the right side;
int numoflildemonsatm2 = 1; // Number of little demons at the moment from the left side;
int luciferspearx = 250; // The x coordinate of the angel's weapon in hell level a.k.a lucifer spear;
int luciferspeary = 116; // The y coordinate of the angel's weapon in hell level a.k.a lucifer spear;
int firearrowx2 = flyingdemonhellx2 + 247, firearrowy2 = flyingdemonhelly2 + 40; // To Control the postion of the arrows coming from the flying demons of hell;
int firearrowx = flyingdemonhellx - 132, firearrowy = flyingdemonhelly + 40;
int flyingDemonAttackCount1 = 0, flyingDemonAttackCount2 = 0; // To count the total number of flying demons of hell.. will increase whenever one of them is killed;
int littledemonsatmcount = 0; // To count the little demons at the moment so that number of little demons coming at a time can be controlled;
int littledemonscount = 0; // To count the total number of little demons;
int flyingdemoncount = 0;
int flyingDemonSide = 1;
int luciferImageIndex = 0;
int luciferFireBallDownIndex = 0;
int luciferX = 880, luciferY = 300;
int luciferFireBallDownX = luciferX + 175, luciferFireBallDownY = luciferY;
int luciferFireBallForwardX = luciferX, luciferFireBallForwardY = luciferY + 150;
int luciferHealthbarIndex = 0;
int featherX = 200, featherY = 2500;
int featherScore = 0;
int totalPlayers = 0;

bool writeOnNameField = false;
bool lucifer = false;
bool luciferDead = false;
bool luciferFireBallDown = true;
bool levelearth = true;
bool levelhell = false;
bool firearrowflag = true;
bool firearrowflag2 = true;
bool luciflag = false;
bool angelflag1 = true;
bool angelflag2 = true;
bool menu = true;
bool menu2 = false;
bool play = true;
bool highscore = false;
bool instructions = false;
bool exitgame = false;
bool story = false;
bool mainmusic = false;
bool angelattackflag = false;
bool angelsuperflag = false;
bool angelforward = true;
bool angelbackwards = false;
bool angelupwards = false;
bool angeldownwards = false;
bool angelattackflag2 = false;
bool angelattackbackwards2 = false;
bool angelsuperflag2 = false;
bool luciferspearflag1 = false;
bool luciferspearflag2 = false;
bool flyingdemonlife = true;
bool gameover = false;
bool littledemonsamount = true;
bool story2 = false;
char gameScoreString[20];
char str[100], str2[100];
bool readFileOnce = false;
bool gamePause = false;

int mike_x = 50;
int mike_y = 20;
int mike_speed = 30;
int fire_speed = 5;
int fire_x = mike_x;
int fire_y = mike_y;
/*int demonBird_x = 1200;
int demonBird_y = 600;*/
int demonBird_x;
int demonBird_y;


int demonbird_index = 0;
int score = 1;
int dfire_x = 0;
int dfire_y = 0;
int demonSign1 = 1;
int demonSign2 = 1;
int demon_gap = 100;
int background_index = 0;
int demon2_x = 1200;
int demon2_y = 600;
int bat_x;
int bat_y;
int pball_x = bat_x - 30;
int pball_y = bat_y - 30;
int batHit = 0;
int demon_index2 = 0;
int demonbat_index = 0;
int lucifireearthX = luciferX, lucifireearthY = luciferY + 300;
int gameScore = 0;

//Coordinates

int screenLength = 1280;
int screenWeight = 720;
int mikeLength = 200;
int mikeHeight = 196;
int daggerLength = 60;
int daggerHeight = 42;
int birdLength = 93;
int birdHeight = 93;
int batLength = 263;
int batHeight = 155;
int fireLength = 50;
int fireHeight = 27;
int demonLength = 100;
int demonHeight = 176;
int batfireLength = 50;
int batfireHeight = 39;
int angelHealthBarIndex2 = 0;

bool round1 = true;
bool round2 = false;
bool throwDagger = false;
bool goRight = false;
bool goLeft = false;
bool goUp = false;
bool goDown = false;
bool moveBack = false;
bool demon_death = false;
bool mike_forward = false;
bool mike_backward = false;
bool mikeHurt = false;
bool showDemon2 = false;
bool showDemonBird = false;
bool showDemonBat = false;
bool batRight = false;
bool batLeft = true;
bool batUp = true;
bool batDown = false;
bool showPoisonBall = true;
bool showLuci = false;
bool showEnemy = true;
bool showFeather = true;
bool featherDown = false;

int demonCount = 1;
FILE *fp;







char demons[4][100] {"Pictures\\d1.bmp", "Pictures\\d2.bmp", "Pictures\\d3.bmp", "Pictures\\d4.bmp"};
char demonbird[3][100] {"Pictures\\db1.bmp", "Pictures\\db2.bmp", "Pictures\\db3.bmp"};
char demonbat[5][100] {"Pictures\\b1.bmp", "Pictures\\b2.bmp", "Pictures\\b3.bmp", "Pictures\\b4.bmp", "Pictures\\b5.bmp"};
char fire_Rain[4][100] {"Pictures\\fireball6.bmp", "Pictures\\fireball6.bmp", "Pictures\\fireball6.bmp", "Pictures\\fireball6.bmp"};
char storm_background[16][100] {"Pictures\\s1.bmp", "Pictures\\s2.bmp", "Pictures\\s3.bmp", "Pictures\\s4.bmp", "Pictures\\s5.bmp", "Pictures\\s6.bmp", "Pictures\\s7.bmp", "Pictures\\s8.bmp", "Pictures\\s9.bmp", "Pictures\\s10.bmp", "Pictures\\s11.bmp", "Pictures\\s12.bmp", "Pictures\\s13.bmp", "Pictures\\s14.bmp", "Pictures\\s15.bmp", "Pictures\\s16.bmp", };
char angelHealthBar2[10][100] = { "Pictures\\healthbar1.bmp", "Pictures\\healthbar2.bmp", "Pictures\\healthbar3.bmp", "Pictures\\healthbar4.bmp", "Pictures\\healthbar5.bmp", "Pictures\\healthbar6.bmp", "Pictures\\healthbar7.bmp", "Pictures\\healthbar8.bmp", "Pictures\\healthbar9.bmp", "Pictures\\healthbar10.bmp" };



char angelsuper[3][100] = {
	"Images\\angelsuper1.bmp", 
	"Images\\angelsuper2.bmp", 
	"Images\\angelsuper3.bmp" 
};

char angelsuper2[3][100] = { 
	"Images\\angelsuper12.bmp", 
	"Images\\angelsuper22.bmp", 
	"Images\\angelsuper32.bmp" 
};

char hellbackground[8][100] = {
	"BackgroundImage\\hell1.bmp", 
	"BackgroundImage\\hell2.bmp",
	"BackgroundImage\\hell3.bmp", 
	"BackgroundImage\\hell4.bmp", 
	"BackgroundImage\\hell5.bmp", 
	"BackgroundImage\\hell6.bmp", 
	"BackgroundImage\\hell7.bmp",
	"BackgroundImage\\hell8.bmp" 
};

char littledemonshell[4][50] = { 
	"Character\\littledemons11.bmp", 
	"Character\\littledemons12.bmp", 
	"Character\\littledemons13.bmp",
	"Character\\littledemons14.bmp" 
};

char littledemonshell2[4][50] = {
	"Character\\littledemons21.bmp",
	"Character\\littledemons22.bmp",
	"Character\\littledemons23.bmp", 
	"Character\\littledemons24.bmp" 
};

char flyingdemonhell2[8][50] = { 
	"Demons\\flydemonhell1.bmp",
	"Demons\\flydemonhell2.bmp",
	"Demons\\flydemonhell3.bmp",
	"Demons\\flydemonhell4.bmp",
	"Demons\\flydemonhell5.bmp",
	"Demons\\flydemonhell6.bmp",
	"Demons\\flydemonhell7.bmp",
	"Demons\\flydemonhell8.bmp" 
};

char flyingdemonhell[8][50] = {
	"Demons\\flydemonhell11.bmp",
	"Demons\\flydemonhell12.bmp",
	"Demons\\flydemonhell13.bmp",
	"Demons\\flydemonhell14.bmp",
	"Demons\\flydemonhell15.bmp",
	"Demons\\flydemonhell16.bmp",
	"Demons\\flydemonhell17.bmp",
	"Demons\\flydemonhell18.bmp" 
};

char healthbarofangel[10][50] = {
	"Images\\healthbar1.bmp",
	"Images\\healthbar2.bmp",
	"Images\\healthbar3.bmp",
	"Images\\healthbar4.bmp",
	"Images\\healthbar5.bmp",
	"Images\\healthbar6.bmp",
	"Images\\healthbar7.bmp",
	"Images\\healthbar8.bmp",
	"Images\\healthbar9.bmp",
	"Images\\healthbar10.bmp"
};

char luciferImage[31][50] = {
	"BossHell\\demon1.bmp",
	"BossHell\\demon2.bmp",
	"BossHell\\demon3.bmp",
	"BossHell\\demon4.bmp",
	"BossHell\\demon5.bmp",
	"BossHell\\demon6.bmp",
	"BossHell\\demon7.bmp",
	"BossHell\\demon8.bmp",
	"BossHell\\demon9.bmp",
	"BossHell\\demon10.bmp",
	"BossHell\\demon11.bmp",
	"BossHell\\demon12.bmp",
	"BossHell\\demon13.bmp",
	"BossHell\\demon14.bmp",
	"BossHell\\demon15.bmp",
	"BossHell\\demon16.bmp",
	"BossHell\\demon17.bmp",
	"BossHell\\demon18.bmp",
	"BossHell\\demon19.bmp",
	"BossHell\\demon20.bmp",
	"BossHell\\demon21.bmp",
	"BossHell\\demon22.bmp",
	"BossHell\\demon23.bmp",
	"BossHell\\demon24.bmp",
	"BossHell\\demon25.bmp",
	"BossHell\\demon26.bmp",
	"BossHell\\demon27.bmp",
	"BossHell\\demon28.bmp",
	"BossHell\\demon29.bmp",
	"BossHell\\demon30.bmp",
	"BossHell\\demon31.bmp"
};

char luciferFireBallDownImage[8][100] = {
	"Images\\LuciferFireBallDown1.bmp",
	"Images\\LuciferFireBallDown2.bmp",
	"Images\\LuciferFireBallDown3.bmp",
	"Images\\LuciferFireBallDown4.bmp",
	"Images\\LuciferFireBallDown5.bmp",
	"Images\\LuciferFireBallDown6.bmp",
	"Images\\LuciferFireBallDown7.bmp",
	"Images\\LuciferFireBallDown8.bmp"
};

char luciferHealthBar[23][100] = {
	"BossHell\\LuciferHealthBar1.bmp",
	"BossHell\\LuciferHealthBar2.bmp",
	"BossHell\\LuciferHealthBar3.bmp",
	"BossHell\\LuciferHealthBar4.bmp",
	"BossHell\\LuciferHealthBar5.bmp",
	"BossHell\\LuciferHealthBar6.bmp",
	"BossHell\\LuciferHealthBar7.bmp",
	"BossHell\\LuciferHealthBar8.bmp",
	"BossHell\\LuciferHealthBar9.bmp",
	"BossHell\\LuciferHealthBar10.bmp",
	"BossHell\\LuciferHealthBar11.bmp",
	"BossHell\\LuciferHealthBar12.bmp",
	"BossHell\\LuciferHealthBar13.bmp",
	"BossHell\\LuciferHealthBar14.bmp",
	"BossHell\\LuciferHealthBar15.bmp",
	"BossHell\\LuciferHealthBar16.bmp",
	"BossHell\\LuciferHealthBar17.bmp",
	"BossHell\\LuciferHealthBar18.bmp",
	"BossHell\\LuciferHealthBar19.bmp",
	"BossHell\\LuciferHealthBar20.bmp",
	"BossHell\\LuciferHealthBar21.bmp",
	"BossHell\\LuciferHealthBar22.bmp",
	"BossHell\\LuciferHealthBar23.bmp"
};


struct FlyingDemon
{
	int demon_x = 0;
	int demon_y = 0;
	int demon_index = 0;
	int demonfire_x = 0;
	int demonfire_y = 0;
	int demonHit = 0;

	bool showDemon = true;
	bool showDemonFire = true;
	bool demonDeath = false;
	bool demonRight = false;
	bool demonLeft = true;
	bool demonUp = true;
	bool demonDown = false;

};

FlyingDemon dArray[5];

struct Highscore{
	char name[100];
	int score;
}point[4];

struct little{
	int speed = (rand() % (1+1));
	int x = 1280;
	int y = 70;
	int littledemonsindex = 0;
	int index = (rand() % 4);
}littledemons[10];

struct little2{
	int speed2 = (rand() % (1+1));
	int x = 0;
	int y = 70;
	int littledemonsindex2 = 0;
	int index2 = (rand() % 4);
}littledemons2[10];




void setDemonPosition()
{
	bat_x = 600;
	bat_y = 400;

	dArray[0].demon_x = 1100;
	dArray[0].demon_y = 500;
	dArray[1].demon_x = 1160;
	dArray[1].demon_y = 200;
	dArray[2].demon_x = 1090;
	dArray[2].demon_y = 300;
	dArray[3].demon_x = 1211;
	dArray[3].demon_y = 400;
	dArray[3].demon_x = 1211;
	dArray[3].demon_y = 300;
	dArray[4].demon_x = 1000;
	dArray[4].demon_y = 300;
	dArray[5].demon_x = 1211;
	dArray[5].demon_y = 400;


	for (int i = 0; i < demonCount; i++)
	{
		srand(time(NULL));

		dArray[i].demonfire_x = dArray[i].demon_x - 40;

		dArray[i].demonfire_y = dArray[i].demon_y + 50;
		dArray[i].showDemon = true;

	}
}



void batControl()
{
	pball_x -= 30;


	if (pball_x <= 0)

	{

		pball_x = bat_x - 30;
		pball_y = bat_y - 30;

	}


	if (bat_x < 500)
	{
		batRight = true;
		batLeft = false;

	}

	if (bat_x > 1000)
	{
		batRight = false;
		batLeft = true;
	}

	if (bat_y< 100)
	{
		batUp = true;
		batDown = false;
	}

	if (bat_y > 560)
	{
		batUp = false;
		batDown = true;
	}


	if (batRight)
	{
		bat_x += 10;
	}
	if (batLeft)
	{
		bat_x -= 10;
	}
	if (batUp)
	{
		bat_y += 10;
	}
	if (batDown)
	{
		bat_y -= 10;
	}

}

void changeAR()
{

	for (int i = 0; i < demonCount; i++)
	{
		if (dArray[i].demon_x < 800)
		{
			dArray[i].demonRight = true;
			dArray[i].demonLeft = false;

		}

		if (dArray[i].demon_x > 1000)
		{
			dArray[i].demonRight = false;
			dArray[i].demonLeft = true;
		}

		else if (dArray[i].demon_y < 100)
		{
			dArray[i].demonUp = true;
			dArray[i].demonDown = false;
		}

		if (dArray[i].demon_y > 560)
		{
			dArray[i].demonUp = false;
			dArray[i].demonDown = true;
		}

		if (dArray[i].demonRight)
		{
			dArray[i].demon_x += 10;
		}
		if (dArray[i].demonLeft)
		{
			dArray[i].demon_x -= 10;
		}
		if (dArray[i].demonUp)
		{
			dArray[i].demon_y += 10;
		}
		if (dArray[i].demonDown)
		{
			dArray[i].demon_y -= 10;
		}





		dArray[i].demon_index = rand() % 4;

	}





	background_index++;

	if (background_index >= 16)
	{
		background_index = 0;
	}

	demonbird_index++;

	if (demonbird_index >= 3)
	{
		demonbird_index = 0;
	}


	demonbat_index++;

	if (demonbat_index >= 5)
	{
		demonbat_index = 0;
	}



}




/* Function showDemon()

*Collision
*DemonFire Decrement
*MikeHurt
*Score
*Appearence of the Giant Demon Bat

*/



void drawNametextBlock(){
	//iSetColor(150, 150, 150);
	iRectangle(454, 327, 250, 30);
}


void showDemon()
{

	for (int i = 0; i < demonCount; i++)
	{
		if (dArray[i].showDemon && !showLuci)
		{
			iShowBMP2(dArray[i].demon_x, dArray[i].demon_y, demons[dArray[i].demon_index], 0);

		}

		if (dArray[i].showDemonFire && !showLuci)
		{
			iShowBMP2(dArray[i].demonfire_x, dArray[i].demonfire_y, "Pictures\\fireball5.bmp", 0);
		}
	}

	for (int i = 0; i < demonCount; i++)
	{
		dArray[i].demonfire_x -= 5;

		if (dArray[i].demonfire_x < 0 || !dArray[i].showDemonFire)
		{
			dArray[i].demonfire_x = dArray[i].demon_x - 30;
			dArray[i].demonfire_y = dArray[i].demon_y;
		}
	}


	if (throwDagger)
	{
		for (int i = 0; i < demonCount; i++)
		{
			if (fire_x >= dArray[i].demon_x && fire_x <= dArray[i].demon_x + 100 && fire_y >= dArray[i].demon_y && fire_y <= dArray[i].demon_y + 100)
			{
				iShowBMP2(dArray[i].demon_x, dArray[i].demon_y, "Pictures\\skeleton.bmp", 0);
				throwDagger = false;
				gameScore++;
				
				dArray[i].demonHit++;

				if (dArray[i].demonHit >= 3)
				{
					dArray[i].demon_x = 1250 + rand() % 100;
					dArray[i].demon_y = rand() % 700;
					dArray[i].demonHit = 0;
				}

			}
		}

		printf("Score: %d\n", score);


		if ((gameScore+1) % 5 == 0)
		{
			showDemonBird = true;
		}

		if (gameScore == 2)
		{
			demonCount = 2;

		}
		if (gameScore == 10)
		{
			demonCount = 3;
		}

		if (gameScore == 15)
		{
			demonCount = 4;
		}

		if (gameScore == 30)
		{
			demonCount = 5;
		}

		if ((gameScore+1) % 20 == 0)
		{
			showDemonBat = true;
		}

		if (gameScore >= 10)
		{
			showLuci = true;
			showEnemy = false;
			//levelearth = false;
			//levelhell = true;
			
		}

		

		if (showDemonBat)
		{
			if (fire_x >= bat_x && fire_x <= bat_x + 100 && fire_y >= bat_y && fire_y <= bat_y + 100)
			{
				throwDagger = false;
				batHit++;

				if (batHit >= 5)
				{


					bat_x = 1400;
					bat_y = 900;
					batHit = 0;
					showDemonBat = false;
				}
			}

		}



	}

	for (int i = 0; i < demonCount; i++)
	{

		if (dArray[i].demonfire_x >= mike_x && dArray[i].demonfire_x <= mike_x + mikeLength && dArray[i].demonfire_y >= mike_y && dArray[i].demonfire_y <= mike_y + mikeHeight)
		{
			angelHealthBarIndex2++;
			if (angelHealthBarIndex2 >= 10)
			{
				play = false;
				gameover = true;
			}
			dArray[i].showDemonFire = false;

		}


		else
		{
			mikeHurt = false;
			dArray[i].showDemonFire = true;

		}

		int firefrontx = fire_x + daggerLength;
		int firefronty = fire_y + daggerHeight;
		int dfronty = dArray[i].demonfire_y + fireHeight;
		int dfrontx = dArray[i].demonfire_x + fireLength;

		if (dArray[i].demonfire_x >= fire_x && dArray[i].demonfire_x <= firefrontx)
		{
			if (dArray[i].demonfire_y >= fire_y && dArray[i].demonfire_y <= firefronty)
			{
				dArray[i].showDemonFire = false;
				throwDagger = false;
			}

			if (dfronty >= fire_y && dfronty <= firefronty)
			{
				dArray[i].showDemonFire = false;
				throwDagger = false;
			}
		}

		if (dfrontx >= fire_x && dfrontx <= firefrontx)
		{
			if (dArray[i].demonfire_y >= fire_y && dArray[i].demonfire_y <= firefronty)

			{
				dArray[i].showDemonFire = false;
				throwDagger = false;
			}
			if (dfronty >= fire_y && dfronty <= firefronty) {
				dArray[i].showDemonFire = false;
				throwDagger = false;
			}
		}

		if (dArray[i].demon_x >= mike_x && dArray[i].demon_x <= mike_x + mikeLength && dArray[i].demon_y >= mike_y && dArray[i].demon_y <= mike_y + mikeHeight)
		{
			mikeHurt = true;

		}


	}


	if (showDemonBird)
	{
		if (demonBird_x >= mike_x && demonBird_x <= mike_x + mikeLength && demonBird_y >= mike_y && demonBird_y <= mike_y + mikeHeight)
		{
			mikeHurt = true;
			showDemonBird = false;
			demonBird_x = 1200;
			demonBird_y = rand() % 700;
			printf("Mike Hurt by Demon Bird\n");
		}
	}



	if (showDemonBat && !showLuci)
	{
		if (bat_x >= mike_x && bat_x <= mike_x + mikeLength && bat_y >= mike_y && bat_y <= mike_y + mikeHeight)
		{
			mikeHurt = true;
		}

		if (pball_x >= mike_x && pball_x <= mike_x + mikeLength && pball_y >= mike_y && pball_y <= mike_y + mikeHeight)
		{
			mikeHurt = true;
			pball_x = bat_x - 30;
			pball_y = bat_y - 30;
		}

	}

	/*if (showPoisonBall)
	{
		if (pball_x >= mike_x && pball_x <= mike_x + mikeLength && pball_y >= mike_y && pball_y <= mike_y + mikeHeight)
		{
			mikeHurt = true;
			showPoisonBall = false;
		}
	}*/





	////MIKE HURT RELATED SHOB KICHU EIKHANE KORBO

	if (mikeHurt)
	{
		//iShowBMP2(mike_x, mike_y, "Pictures\\mikehurt.bmp", 0);
		angelHealthBarIndex2++;
		if (angelHealthBarIndex2 >= 10)
		{
			printf("Score :%d", score);
			gameover = true;
			menu = false;
			menu2 = false;
			play = false;
			highscore = false;
			instructions = false;
		}
		mikeHurt = false;
	}
}





/* This part will reset the fire arrows of the flying demons */
void firearrowreset2(){
	firearrowx2 = flyingdemonhellx2 + 247;
	firearrowy2 = flyingdemonhelly2 + 40;
	firearrowflag2 = true;
}

void firearrowreset(){
	firearrowx = flyingdemonhellx - 132;
	firearrowy = flyingdemonhelly + 40; 
	firearrowflag = true;
}

/* This part will show the health status of the angel */
void checklifeofangel(){
	if (littledemonsamount){
		for (int i = 0; i < numoflildemonsatm1; i++){
			if (littledemons[i].x >= angelx  && littledemons[i].x <= angelx + 220 && (littledemons[i].y + 116) >= angely && (littledemons[i].y + 116) <= angely + 216){
				angelhealthbarindex++;
				littledemons[i].x = 1350;
				littledemons[i].y = rand() % 161;
			}
		}
		for (int i = 0; i < numoflildemonsatm2; i++){
			if (littledemons2[i].x + 161 >= angelx && littledemons2[i].x + 161 <= angelx + 220 && (littledemons2[i].y + 116) >= angely && (littledemons2[i].y + 116) <= angely + 216){
				angelhealthbarindex++;
				littledemons2[i].x = -220;
				littledemons2[i].y = rand() % 161;
			}
		}
	}
	if (flyingdemonlife){
		if (flyingDemonSide == 0){
			if (firearrowx2 + 132 >= angelx && firearrowx2 + 132 <= angelx + 220 && firearrowy2 >= angely && firearrowy2 <= angely + 116){
				angelhealthbarindex++;
				firearrowflag2 = false;
				firearrowreset2();
			}
		}
		if (flyingDemonSide == 1){
			if (firearrowx >= angelx - 220 && firearrowx <= angelx && firearrowy >= angely && firearrowy <= angely + 116){
				angelhealthbarindex++;
				firearrowflag = false;
				firearrowreset();
			}
		}
	}

	if (lucifer){
		if (luciferFireBallDownX <= angelx && luciferFireBallDownX >= angelx + 220 && luciferFireBallDownY >= angely && luciferFireBallDownY <= angely + 216){
			angelhealthbarindex += 2;
			luciferFireBallDownX = luciferX + 175;
			luciferFireBallDownY = luciferY;
		}
		if (luciferFireBallForwardX <= angelx  && luciferFireBallForwardX >= angelx - 220 && luciferFireBallForwardY + 21 >= angely && luciferFireBallForwardY + 21 <= angely + 216){
			angelhealthbarindex += 2;
			luciferFireBallForwardX = luciferX;
			luciferFireBallForwardY = luciferY + 150;
		}

	}

	if (angelhealthbarindex >= 10){
		gameover = true;
		menu = false;
		menu2 = false;
		play = false;
		highscore = false;
		instructions = false;
	}
}


void animationfordyingdemons(){

}

// this part controls the flying demons of hell level.
int flyingdemonflag = 1;
int flyingdemonflag2 = 1;
void control_flyingdemonsofhell(){
	if (flyingDemonSide == 0){
		flyingdemonhellindex2++;
		flyingdemonhelly2 -= 10 * flyingdemonflag;
		if (flyingdemonhelly2 <= 0 || flyingdemonhelly2 >= 600){
			flyingdemonflag *= -1;
		}
		flyingdemonhellx2 -= 3 * flyingdemonflag2;
		 if (flyingdemonhellx2 >= 150 || flyingdemonhellx2 <= 5){
			flyingdemonflag2 *= -1;
		}
		 if (flyingdemonhellindex2 >= 8){
			 flyingdemonhellindex2 = 0;
		 }
		 firearrowx2 += 20;
		 if (firearrowx2 >= 1280 - 132){
			 firearrowreset2();
		 }
	}
	else if (flyingDemonSide == 1){
		flyingdemonhellindex++;
		flyingdemonhelly -= 10 * flyingdemonflag;
		if (flyingdemonhelly <= 0 || flyingdemonhelly >= 600){
			flyingdemonflag *= -1;
		}
		flyingdemonhellx -= 3 * flyingdemonflag2;
		if (flyingdemonhellx >= 1032 || flyingdemonhellx <= 532){
			flyingdemonflag2 *= -1;
		}
		firearrowx -= 20;
		if (firearrowx <= 0){
			firearrowreset();
		}
		if (flyingdemonhellindex >= 8){
			flyingdemonhellindex = 0;
		}
	}
}


void flyingdemonsideChange(){
	flyingDemonSide = rand() % 2;
}


void resetFlyingDemons1(){
	
	flyingDemonAttackCount1 = 0;
	flyingdemonsideChange();
	flyingdemoncount++;
	printf("%d\n", flyingdemoncount);
	printf("%d %d\n", flyingdemonhellx, flyingdemonhelly);
	flyingdemonhellx = 745 + (rand() % 288);
	flyingdemonhelly = rand() %( 600 - 148);
}

void resetFlyingDemons2(){
	
	flyingDemonAttackCount2 = 0;
	flyingdemonsideChange();
	flyingdemoncount++;
	printf("%d\n", flyingdemoncount);
	printf("%d %d\n", flyingdemonhellx2, flyingdemonhelly2);
	flyingdemonhellx2 = rand() % 150;
	flyingdemonhelly2 = rand() % (600 - 148);
}


/* This part will check whether the flying demon is alive or not */
void checklifeofflyingdemon(){
	if (luciferspearflag2){
		printf("Flag 2 is true\n");
		if (luciferspearx >= flyingdemonhellx2 && luciferspearx <= flyingdemonhellx2 + 247 && luciferspeary >= flyingdemonhelly2 && luciferspeary <= flyingdemonhelly2 + 148){
			luciferspearflag2 = false;
			luciferspearx = angelx + 247;
			luciferspeary = angely + 220;
			flyingDemonAttackCount2++;
			gameScore++;
			printf("%d\n", flyingDemonAttackCount2); 
		}
		if (flyingDemonAttackCount2 >= 3){
			resetFlyingDemons2();
		}
	}
	
	
	else  if (luciferspearflag1){
		printf("flag 1 is true\n");
		if ((luciferspearx+90)  >= flyingdemonhellx && (luciferspearx+90) <= (flyingdemonhellx + 247) && luciferspeary >= flyingdemonhelly && luciferspeary <= flyingdemonhelly + 148){
			luciferspearflag1 = false;
			luciferspearx = angelx;
			luciferspeary = angely + 220;
			flyingDemonAttackCount1++;
			gameScore++;
			printf("%d\n", flyingDemonAttackCount1);
			if (flyingDemonAttackCount1 >= 3){
				resetFlyingDemons1();
			}
		}
	}
	
	if (flyingdemoncount >= 20)
		flyingdemonlife = false;
}
	



/* This part will check whether the little demons are dead or not.. and if dead they will be repositioned*/
void check_life_and_index_oflittledemonofhell(){
	for (int i = 0; i < numoflildemonsatm1; i++){
		if (littledemons2[i].x >= 1280 - 161){
			littledemons2[i].x = 0;
		}
		
		else if (littledemons[i].x <= 0){
			littledemons[i].x = 1280 - 161;
		}
		
		else if (luciferspearflag1){
			if ((luciferspearx + 90) >= littledemons[i].x && (luciferspearx + 90) <= (littledemons[i].x + 161) && luciferspeary >= (littledemons[i].y) && luciferspeary <= (littledemons[i].y + 116)){
				gameScore++;
				littledemons[i].x = 1350;
				littledemons[i].y = rand() % 161;
				luciferspearflag1 = false;
				littledemonsatmcount++;
				littledemonscount++;
			}
		}
		
		else if (luciferspearflag2){
			if (luciferspearx >= littledemons2[i].x && luciferspearx  <= (littledemons2[i].x + 161) && luciferspeary >= (littledemons2[i].y) && luciferspeary <= (littledemons2[i].y + 116)){
				gameScore++;
				littledemons2[i].x = -200;
				littledemons2[i].y = rand() % 161;
				luciferspearflag2 = false;
				littledemonsatmcount++;
				littledemonscount++;
			}
		}
		if (littledemonsatmcount >= 10){
			numoflildemonsatm1++;
			numoflildemonsatm2++;
			littledemonsatmcount = 0;
			//littledemonscount++;
		}

		if (littledemonscount >= 40){
			littledemonsamount = false;
		}
	}
}



int luciferFlag1 = 1;
int luciferFlag2 = 1;
void controlLucifer(){
	luciferY -= 15 * luciferFlag1;
	if (luciferY <= 0 || luciferY >= 450){
		luciferFlag1 *= -1;
	}

	luciferX -= 15 * luciferFlag2;
	if (luciferX >= 900 || luciferX <= 550){
		luciferFlag2 *= -1;
	}

	luciferFireBallDownIndex++;
	if (luciferFireBallDownIndex >= 8){
		luciferFireBallDownIndex = 0;
	}
	if (luciferFireBallDownY <= 0){
		luciferFireBallDownX = luciferX + 175;
		luciferFireBallDownY = luciferY;
	}

	if (luciferFireBallForwardX <= 0){
		luciferFireBallForwardX = luciferX;
		luciferFireBallForwardY = luciferY + 150;
	}

	
}

void controlLuciferLife(){
	if (luciferspearflag1){
		if (luciferspearx >= luciferX+50 && luciferspearx <= luciferX + 400 && luciferspeary >= luciferY && luciferspeary <= luciferY + 372){
			luciferspearflag1 = false;
			luciferHealthbarIndex++;
			gameScore++;
			printf("%d\n", luciferHealthbarIndex);
			printf("LuciferImageIndex %d\n", luciferImageIndex);
			if (luciferHealthbarIndex >= 22){
				lucifer = false;
				luciferDead = true;
				play = false;
				gameover = true;
			}
		}
	}
	
}


void lifeOfLuciOnEarth(){
	static int countlifeofluci = 0;
	if (throwDagger){
		if (fire_x + daggerLength >= luciferX+100 && fire_x + daggerLength <= luciferX + 400 && fire_y >= luciferY && fire_y <= luciferY + 372){
			countlifeofluci++;
			gameScore++;
			throwDagger = false;
		}
		if (countlifeofluci >= 5){
			showLuci = false;
			levelearth = false;
			levelhell = true;
			story2 = true;
		}
	}
	if (lucifireearthX >= mike_x && lucifireearthX <= mike_x + (mikeLength-20) && lucifireearthY + 19 >= mike_y && lucifireearthY + 19 <= mike_y + mikeHeight){
		angelHealthBarIndex2++;
		lucifireearthX = luciferX;
		lucifireearthY = luciferY + 300;
		if (angelHealthBarIndex2 >= 10){
			gameover = true;
			play = false;
		}

	}
}


void score_reverse(char str[], int len)
{
	int start, end;
	char temp;
	for (start = 0, end = len - 1; start < end; start++, end--) {
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}

char* score_itoa(int num, char* str, int base)
{
	int i = 0;
	bool isNegative = false;

	/* A zero is same "0" string in all base */
	if (num == 0) {
		str[i] = '0';
		str[i + 1] = '\0';
		return str;
	}

	/* negative numbers are only handled if base is 10
	otherwise considered unsigned number */
	if (num < 0 && base == 10) {
		isNegative = true;
		num = -num;
	}

	while (num != 0) {
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
		num = num / base;
	}

	/* Append negative sign for negative numbers */
	if (isNegative){
		str[i++] = '-';
	}

	str[i] = '\0';

	score_reverse(str, i);

	return str;
}


void checkFeather(){
	if (featherY <= 0){
		featherX = rand() % 800;
		featherY = 2500;
	}

	if (levelhell){
		if (featherX + 35 >= angelx && featherX + 35 <= angelx + 220 && featherY >= angely && featherY <= angely + 216){
			gameScore += 10;
			angelhealthbarindex--;
			if (angelhealthbarindex < 0){
				angelhealthbarindex = 0;
			}
			featherX = rand() % 800;
			featherY = 2500;
		}
	}

	else if (levelearth){
		if (featherX + 35 >= mike_x && featherX + 35 <= mike_x + mikeLength && featherY >= mike_y && featherY <= mike_y + mikeHeight){
			gameScore += 10;
			angelHealthBarIndex2--;
			if (angelHealthBarIndex2 < 0){
				angelHealthBarIndex2 = 0;
			}
			featherX = rand() % 800;
			featherY = 2500;
		}
		
	}
}


/*
	function iDraw() is called again and again by the system.
*/

void readFile() {
	fp = fopen("score.txt", "r");
	if (fp == NULL) {
		printf("NOT FOUND");
	}

	for (int i = 0; i < 3; i++) {

		fscanf(fp, "%d %[^\n]", &point[totalPlayers].score, point[totalPlayers].name);
		printf("%d %s\n", point[totalPlayers].score, point[totalPlayers].name);

		totalPlayers++;
		if (feof(fp)) {
			break;
		}
	}

	point[totalPlayers].score = gameScore;
	strcpy(point[totalPlayers].name, str2);

	int n = 4;
	/*for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (point[j].score < point[j + 1].score) {
				struct Highscore temp;
				strcpy(temp.name, point[j].name);
				temp.score = point[j].score;
				strcpy(point[j].name, point[j + 1].name);
				point[j].score = point[j + 1].score;
				strcpy(point[j + 1].name, temp.name);
				point[j + 1].score = temp.score;
			}
		}
	}*/

	
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			if (point[i].score < point[j].score){
				struct Highscore temp;
				strcpy(temp.name, point[i].name);
				temp.score = point[i].score;
				//strcpy(point[i].scoreStr, point[j].scoreStr);
				strcpy(point[i].name, point[j].name);
				point[i].score = point[j].score;
				//strcpy(point[i].scoreStr, point[j].scoreStr);
				strcpy(point[j].name, temp.name);
				point[j].score = temp.score;
				//strcpy(point[j].scoreStr, temp.scoreStr);
			}
		}
	}
	

	fclose(fp);

	fp = fopen("score.txt", "w");

	for (int i = 0; i < 3; i++) {
		fprintf(fp, "%d %s\n", point[i].score, point[i].name);
	}


	fclose(fp);


	totalPlayers = 0;
}


void iDraw()
{
	//place your drawing codes here
	
	iClear();
	//printf("%d\n", angelsuperindex);
	if (menu){
		iShowBMP(0, 0, "Images\\mainmenu.bmp");
	}
	else if (menu2){
		iShowBMP(0, 0, "Images\\gamecover2.bmp");
	}
	else if (play){
		mainmusic = false;
		PlaySound(0, 0, 0);
		if (story){
			iShowBMP(0, 0, "Images\\story.bmp");
		}
		else{
			iSetColor(255, 0, 0);

			score_itoa(gameScore, gameScoreString, 10);
		
			if (levelearth)
			{
				if (gamePause){
					iShowBMP(0, 0, "Images\\gamecover.bmp");
					return;
				}
				iShowBMP(0, 0, storm_background[background_index]);

			
				iText(500, 680, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
				iText(569, 680, gameScoreString, GLUT_BITMAP_TIMES_ROMAN_24);
				iShowBMP2(10, 650, angelHealthBar2[angelHealthBarIndex2], 0);

					if (showEnemy)
					{
						showDemon();
					}

					if (!throwDagger)
					{

						if (mike_forward)

						{
							iShowBMP2(mike_x, mike_y, "Pictures\\mikeforward.bmp", 0);
						}

						else if (mike_backward)
						{

							iShowBMP2(mike_x, mike_y, "Pictures\\mikebackward.bmp", 0);

						}

						else
						{
							iShowBMP2(mike_x, mike_y, "Pictures\\angelrunning2.bmp", 0);
						}

						//iShowBMP2(mike_x, mike_y, "Pictures\\angelrunning2.bmp", 0);
						fire_x = mike_x + 90;
						fire_y = mike_y + 70;
					}

					if (throwDagger)
					{
						iShowBMP2(mike_x, mike_y, "Pictures\\angelattacking.bmp", 0);
						iShowBMP2(fire_x, fire_y, "Pictures\\angeldagger.bmp", 0);

						fire_x = fire_x + 80;


						if (fire_x > 1280)
						{
							//iShowBMP2(mike_x, mike_y, "Pictures\\angelrunning2.bmp", 0);
							fire_x = mike_x + 90;
							fire_y = mike_y + 70;
							throwDagger = false;
						}



					}

					if (showDemonBat && showEnemy)
					{

						iShowBMP2(bat_x, bat_y, demonbat[demonbat_index], 0);
						iShowBMP2(pball_x, pball_y, "Pictures\\poisonball.bmp", 0);

					}

					if (showLuci)
					{

						iShowBMP2(luciferX, luciferY, luciferImage[luciferImageIndex], 0);
						iShowBMP2(lucifireearthX, lucifireearthY, "Images\\luci2.bmp", 0);
						lucifireearthX -= 10;
						lifeOfLuciOnEarth();
					}

					else if (showDemonBird && showEnemy)
					{

						iShowBMP2(demonBird_x, demonBird_y, demonbird[demonbird_index], 0);

						demonBird_x = demonBird_x - 15;
						demonBird_y = demonBird_y - 8;

						if (demonBird_x < 0 && demonBird_y < 0)
						{
							/*demonBird_x = 1300 + rand() % 10;
							demonBird_y = 300 + rand() % 300;*/

							demonBird_x = 1200;
							demonBird_y = rand() % 700;

							showDemonBird = false;
						}
					}

				}

			
			if (levelhell){
				if (story2){
					iShowBMP(0, 0, "Images\\story2.bmp");
				}
				else{
					iShowBMP(0, 0, hellbackground[imageIndex]);
					iText(500, 680, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
					iText(569, 680, gameScoreString, GLUT_BITMAP_TIMES_ROMAN_24);
					
					if (flyingdemonlife){
						if (flyingDemonSide == 0){
							iShowBMP2(flyingdemonhellx2, flyingdemonhelly2, flyingdemonhell2[flyingdemonhellindex2], 0);
							if (firearrowflag2)
								iShowBMP2(firearrowx2, firearrowy2, "Images\\firearrow2.bmp", 0);
						}
						else if (flyingDemonSide == 1){
							iShowBMP2(flyingdemonhellx, flyingdemonhelly, flyingdemonhell[flyingdemonhellindex], 0);
							if (firearrowflag)
								iShowBMP2(firearrowx, firearrowy, "Images\\firearrow.bmp", 0);
						}
						checklifeofflyingdemon();
					}

					iShowBMP2(10, 650, healthbarofangel[angelhealthbarindex], 0);
					checklifeofangel();
					//printf("%d\n", angelhealthbarindex);
					if (angelforward){
						if (angelflag1)
							iShowBMP2(angelx, angely, "Images\\angelrunning.bmp", 0);
						else if (angelattackflag){
							iShowBMP2(angelx, angely, "Images\\angelattacking.bmp", 0);
							luciferspearflag1 = true;
							luciferspearflag2 = false;
							luciferspearx = angelx + 250;
							luciferspeary = angely + 116;
						}
						else if (angelsuperflag){
							iShowBMP2(angelx + 100, angely + 70, angelsuper[angelsuperindex2], 0);
						}
					}
					else if (angelbackwards){
						if (angelflag2)
							iShowBMP2(angelx, angely, "Images\\angelrunning2.bmp", 0);
						else if (angelattackflag2){
							iShowBMP2(angelx, angely, "Images\\angelattacking2.bmp", 0);
							luciferspearflag2 = true;
							luciferspearflag1 = false;
							luciferspearx = angelx - 150;
							luciferspeary = angely + 116;
						}
						else if (angelsuperflag2){
							iShowBMP2(angelx, angely + 70, angelsuper2[angelsuperindex], 0);
						}
					}
					else if (angelupwards){
						if (angelflag1)
							iShowBMP2(angelx, angely, "Images\\angelrunning.bmp", 0);
						else if (angelattackflag){
							iShowBMP2(angelx, angely, "Images\\angelattacking.bmp", 0);
							luciferspearflag1 = true;
							luciferspearflag2 = false;
							luciferspearx = angelx + 250;
							luciferspeary = angely + 116;
						}
						else if (angelsuperflag){
							iShowBMP2(angelx, angely + 70, angelsuper[angelsuperindex2], 0);
						}
						else if (angelflag2)
							iShowBMP2(angelx + 220, angely, "Images\\angelrunning2.bmp", 0);
						else if (angelattackflag2){
							iShowBMP2(angelx, angely, "Images\\angelattacking2.bmp", 0);
							luciferspearflag2 = true;
							luciferspearflag1 = false;
							luciferspearx = angelx - 150;
							luciferspeary = angely + 116;
						}
						else if (angelsuperflag2){
							iShowBMP2(angelx, angely + 70, angelsuper2[angelsuperindex], 0);
						}
					}
					else if (angeldownwards){
						if (angelflag1){
							iShowBMP2(angelx, angely, "Images\\angelrunning.bmp", 0);
						}
						else if (angelattackflag){
							iShowBMP2(angelx, angely, "Images\\angelattacking.bmp", 0);
							luciferspearflag1 = true;
							luciferspearflag2 = false;
							luciferspearx = angelx + 250;
							luciferspeary = angely + 116;
						}
						else if (angelsuperflag){
							iShowBMP2(angelx, angely + 70, angelsuper[angelsuperindex2], 0);
						}
						else if (angelflag2)
							iShowBMP2(angelx, angely, "Images\\angelrunning2.bmp", 0);
						else if (angelattackflag2){
							iShowBMP2(angelx, angely, "Images\\angelattacking2.bmp", 0);
							luciferspearflag2 = true;
							luciferspearflag1 = false;
							luciferspearx = angelx - 150;
							luciferspeary = angely + 116;
						}
						else if (angelsuperflag2){
							iShowBMP2(angelx, angely + 70, angelsuper2[angelsuperindex], 0);
						}
					}
					if (luciferspearflag1){
						iShowBMP2(luciferspearx, luciferspeary, "Images\\luciferspear.bmp", 0);
						luciferspearx += 80;
					}

					else if (luciferspearflag2){
						iShowBMP2(luciferspearx, luciferspeary, "Images\\luciferspear.bmp", 0);
						luciferspearx -= 80;
					}


					if (littledemonsamount){
						for (int i = 0; i < numoflildemonsatm1; i++){
							iShowBMP2(littledemons[i].x--, littledemons[i].y, littledemonshell[littledemons[i].index], 0);
						}

						for (int i = 0; i < numoflildemonsatm2; i++){
							iShowBMPAlternative2(littledemons2[i].x++, littledemons2[i].y, littledemonshell2[littledemons2[i].index2], 0);
							check_life_and_index_oflittledemonofhell();
						}
					}
					if (!littledemonsamount && !flyingdemonlife && !luciferDead){
						lucifer = true;
					}
					if (lucifer){
						iShowBMP2(luciferX, luciferY, luciferImage[luciferImageIndex], 0);
						iShowBMP2(luciferFireBallDownX, luciferFireBallDownY, luciferFireBallDownImage[luciferFireBallDownIndex], 0);
						iShowBMP2(luciferFireBallForwardX, luciferFireBallForwardY, "Images\\luciferFireBallForward.bmp", 0);
						controlLuciferLife();
						iShowBMP2(980, 650, luciferHealthBar[luciferHealthbarIndex], 0);
						luciferFireBallDownY -= 2;
						luciferFireBallForwardX -= 8;
					}
				}
			}
			
			if (showFeather){
				iShowBMP2(featherX, featherY, "Images\\feather.bmp", 0);
				featherY -= 5;
				checkFeather();
			}
		}
		
	}
	else if (highscore){
		iShowBMP(0, 0, "Images\\highscore.bmp");
		iSetColor(255, 0, 0);
		char str1[20], str2[20], str3[20];
		if (!readFileOnce) {
			readFile();
			readFileOnce = true;
		}
		iText(413, 460, point[0].name, GLUT_BITMAP_TIMES_ROMAN_24);
		score_itoa(point[0].score, str1, 10);
		iText(780, 452, str1, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(421, 322, point[1].name, GLUT_BITMAP_TIMES_ROMAN_24);
		score_itoa(point[1].score, str2, 10);
		iText(780, 315, str2, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(414, 181, point[2].name, GLUT_BITMAP_TIMES_ROMAN_24);
		score_itoa(point[2].score, str3, 10);
		iText(780, 175, str3, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (instructions){
		iShowBMP(0, 0, "Images\\instructions.bmp");
	}
	else if (gameover){
		iShowBMP(0, 0, "Images\\gameover.bmp");
		iText(500, 378, gameScoreString, GLUT_BITMAP_TIMES_ROMAN_24);
		
		if (writeOnNameField){
			iSetColor(255, 0, 0);
			iText(465, 334, str);
		}
		drawNametextBlock();

	}
}




/* This part will control the speed of the little demons */
void control_littledemonsspeed(){
	for (int i = 0; i < numoflildemonsatm2; i++)
		littledemons2[i].x += littledemons[i].speed;
	for (int i = 0; i < numoflildemonsatm1; i++)
		littledemons[i].x -= littledemons[i].speed;

}

/* This part will control super power movement */
void angelsuperfunc(){
	angelsuperindex++;
	if (angelsuperindex >= 3){
		angelsuperflag = false;
		angelsuperindex = 0;
	}
	angelsuperindex2++;
	if (angelsuperindex2 >= 3){
		angelsuperflag2 = false;
		angelsuperindex2 = 0;
	}
}

// This part controls the flag values of the angel's attack actions.
void angelattack(){
	int i = 0;
	while (i >= 10){
		angelattackflag = true;
		angelattackflag2 = true;
		i++;
	}
	angelattackflag = false;
	angelattackflag2 = false;
	angelflag1 = true;
	angelflag2 = true;

	angelsuperfunc();
}

void control_angelactionmovement(){

}

// This part deals with the little demons of hell
void control_littledemonsindex(){
	for (int i = 0; i < numoflildemonsatm1; i++){
		littledemons[i].index++;
		if (littledemons[i].index >= 4)
			littledemons[i].index = 0;
	}

	for (int i = 0; i < numoflildemonsatm2; i++){
		littledemons2[i].index2++;
		if (littledemons2[i].index2 >= 4)
			littledemons2[i].index2 = 0;
	}
}







/* 
This part handels the hell background directly and controls the functions
named "control_littledemonsindex" and "control_flyingdemonsofhell .
This part is getting called by the iSetTimer function from main();
*/
void change(){
	
	imageIndex++;
	if (imageIndex >= 8)
		imageIndex = 0;
	control_littledemonsindex();

	control_flyingdemonsofhell();
	
	luciferImageIndex++;
	if (luciferImageIndex >= 31){
		luciferImageIndex = 0;
	}
	controlLucifer();
	if (showLuci){
		controlLucifer();
		if (lucifireearthX <= 0){
			lucifireearthX = luciferX;
			lucifireearthY = luciferY + 300;
		}
	}
}




/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iMouse(int button, int state, int mx, int my)
{
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mposx = mx;
		mposy = my;
		printf("%d %d\n", mposx, mposy);
		if ((mx >= 120 && mx <= 356) && (my >= 429 && my <= 495)){
			play = true;
			story = true;
			menu2 = false;
		}
		else if ((mx >= 121 && mx <= 681) && (my >= 326 && my <= 391)){
			if (menu2){
				highscore = true;
				menu2 = false;
			}
		}
		else if ((mx >= 120 && mx <= 770) && (my >= 225 && my <= 288)){
			instructions = true;
			menu2 = false;
		}
		else if(menu2)
			if ((mx >= 120 && mx <= 319) && (my >= 120 && my <= 185)){
				exit(0);
		}
		 if (gameover){
			printf("Um herr\n");
			if (mx >= 455 && mx <= 701 && my >= 333 && my <= 356){
				writeOnNameField = true;
			}
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		menu2 = true;
		highscore = false;
		instructions = false;
		//place your codes here
	}
	
}
/*iPassiveMouseMove is called to detect and use															
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/

int len = 0;
int index = 0;

// point [0 - 3]  sort 0 - 2



void iKeyboard(unsigned char key)
{
	
	if (writeOnNameField){
		if (key == '\r'){
			writeOnNameField = false;
			strcpy(str2, str);

			readFile();

			for (int i = 0; i < len; i++)
				str[i] = 0;
			len = 0;

			gameover = false;
			gameScore = 0;
			angelhealthbarindex = 0;
			angelHealthBarIndex2 = 0;
			menu = true;
			levelearth = true;
			levelhell = false;
		}
		else if (key == '\b'){
			len--;
			if (len < 0)
				len = 0;
			str[len] = 0;
		}
		else
		{
			str[len] = key;
			len++;
			
		}
	}

	if (key == 27){
		if (!gamePause){
			gamePause = true;
		}
		else
			gamePause = false;
	}

	if (key == 'w')
	{

	}
	else if (key == 'a'){
		angelsuperflag = true;
		angelsuperflag2 = true;
		angelattackflag = false;
		angelattackflag2 = false;
		angelflag1 = false;
		angelflag2 = false;
	}
	else if (key == 'd'){
		  
	}
	else if (key == 's'){
		angelattackflag = true;
		angelattackflag2 = true;
		angelsuperflag = false;
		//angelupwards = false;
		//angelbackwards = false;
		angelsuperflag2 = false;
		angelflag1 = false;
		angelflag2 = false;
		throwDagger = true;
	}
	
	else if (key == ' '){
		if (menu){
			menu = false;
			menu2 = true;
			play = false;
			instructions = false;
			highscore = false;
			story = false;
		}
		else if (story){
			menu = false;
			menu2 = false;
			play = true;
			instructions = false;
			highscore = false;
			story = false;
		}
		if (story2){
			story2 = false;
		}
	}
	else if (key == 'm'){
		if (mainmusic){
			mainmusic = false;
			PlaySound(0, 0, 0);
		}
		else{
			mainmusic = true;
			PlaySound("Music\\GOT.wav", NULL, SND_ASYNC);
		}
	}
	else if (key == '\b'){

	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (levelearth){
		if (key == GLUT_KEY_UP && mike_y < 530)
		{
			mike_y = mike_y + mike_speed;
			mike_backward = false;
			mike_forward = false;


		}
		else if (key == GLUT_KEY_DOWN && mike_y > 30)
		{
			mike_y = mike_y - mike_speed;
			mike_forward = false;
			mike_backward = false;

		}
		else if (key == GLUT_KEY_LEFT && mike_x > 30)
		{
			mike_x = mike_x - mike_speed;
			mike_backward = true;
			mike_forward = false;

		}
		else if (key == GLUT_KEY_RIGHT && mike_x <1080)
		{
			mike_x = mike_x + mike_speed;
			mike_forward = true;
			mike_backward = false;

		}
	}
	else if (levelhell){
		if (key == GLUT_KEY_END)
		{
			exit(0);
		}

		else if (key == GLUT_KEY_RIGHT){
			angelforward = true;
			angelbackwards = false;
			angelflag1 = true;
			angelattackflag = false;
			angelsuperflag = false;
			//angelattackflag = false;
			angelx += 30;
			if (angelx >= 1280 - 220){
				angelx = 1280 - 220;
			}
		}

		else if (key == GLUT_KEY_LEFT){
			angelbackwards = true;
			angelforward = false;
			angelflag2 = true;
			angelattackflag2 = false;
			angelsuperflag2 = false;
			angelx -= 30;
			if (angelx <= 0){
				angelx = 0;
			}

			//angelattackflag = false;
		}

		else if (key == GLUT_KEY_UP){
			angelupwards = true;
			angeldownwards = false;
			//angelbackwards = false; 
			//angelforward = false;
			angely += 30;
			if ((angely + 216) >= 720){
				angely = 720 - 216;
			}

		}

		else if (key == GLUT_KEY_DOWN){
			angelupwards = false;
			angeldownwards = true;
			//angelforward = false;
			angely -= 30;
			if (angely <= 0){
				angely = 0;
			}
		}
	}
	//place your codes for other keys here
}
//


int main()
{
	//place your own initialization codes here.
	srand(time(NULL));
	iSetTimer(100, change);
	iSetTimer(200, angelattack);
	iSetTimer(100, control_littledemonsspeed);
	setDemonPosition();
	iSetTimer(100, batControl);
	iSetTimer(100, changeAR);
	str[0] = 0;
	if (mainmusic)
		PlaySound("Music\\GOT.wav", NULL, SND_ASYNC);
	else
		PlaySound(0, 0, 0);
	iInitialize(width, length, "Trailblazer");
	return 0;
}












//Hey
