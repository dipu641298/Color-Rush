/******************************************************************************************************************************************************
*****************************************Project developed by Md. Shafiur Rahman , Farsheed hoque & Rizeya Rabbi Reyad ********************************/

# include "iGraphics.h"
# include <cstdio>
# include <cstdlib>
#include<cmath>

int screenwidth = 1350;
int screenheight = 680;
double r1=0;
double g1=0;
double b1=0;
double XaxisOfFloorBLock;
double YaxisOfFloorBLock;
int ColorOfFloorBlock;
int TotalPoint;
char ScoreArray[100];
char ScoreArray2[100];
char ProjectedScoreArray[100];
char levelArray[50];
char timeArray[50];
int ReduceOfYAxisOfAll;  /* For further increasement of speed we have to increase ReduceOfYAxisOfAll, and decrease SpeedOfAll and balance */
int SpeedOfAll = 100;

/******************************************variables of special feature*********************************************************/
bool ValidityOf_SpeedUp_feature = false;
bool ValidityOf_Slow_feature = false;
bool ValidityOf_RainbowBall_feature = false;
bool ValidityOf_2x_feature = false;
bool ValidityOf_life_feature = false;

/******************************************variables of extended works*********************************************************/
int menubar = 240;
bool play = false;
bool menu = true;
bool move = true ;
bool gameover = false;
bool StartNewLevel = false;
int TimerOfFloorBlock;
int TimerOfRainingBlock;
int TimerOfSetfatures;
int TimerOfMovefatures;
int TimerOfChangeBackground;
int TimerOfTimeLimit;
int Lev1ProjecScore = 150;
int Lev2ProjecScore = 350;
int Lev3ProjecScore = 600;
int Lev4ProjecScore = 900;
int Lev5ProjecScore = 1250;
int ProjectedScore ;
int TimeLimit;
int level;
int life;
int gameTime;
int minute;
int second;
int screen = 0;
int PrevHighscore;
int Highscore;
FILE *highscore;
char HighscoreArray[100];


void SetFloorBlock();
void ColorChangeOfFloorBlock();
void SetRainingBlock();
void RainingBlockMove();
void RainingBlockMove();
void SetSpecialFeatures();
void MoveSpecialFeatures();
void SetBackground();
void TimeLimitChange();

void chooseOption();
void mainMenu();
void gameoverFunc();
void pausemenu();
void ShowHighscores();
void ShowInstructions();
void ChangeBackground();
void ShowNewLevelFunc();

void SetAll(){
	TotalPoint = 0;
	SetFloorBlock();
	SetBackground();
	SetRainingBlock();

	ValidityOf_SpeedUp_feature = false;
	ValidityOf_Slow_feature = false;
	ValidityOf_RainbowBall_feature = false;
	ValidityOf_2x_feature = false;
	ValidityOf_life_feature = false;

	life = 5;
	level = 1;
	TimeLimit = 120;
	gameTime = 0;
	ReduceOfYAxisOfAll = 20;
	ProjectedScore = Lev1ProjecScore;
}

void showScreen()
{
  switch(screen){
   case  1: { play = true; break;}
   case  2: { ShowInstructions();  break;}
   case  3: { ShowHighscores(); break;}
   case  5: { play = false; pausemenu(); break;}
   case  6: { gameoverFunc(); break;}
   case  0: { SetAll(); play = false; mainMenu();}
   }
}

/*************************************************************************************************************************************
************************************************************************************************************************************
******************************************Floor Block***********Floor Block**********************************************************/

double SpeedOfFloorBlock = 40;

void SetFloorBlock()
{
	XaxisOfFloorBLock = 0;
	YaxisOfFloorBLock = 0;
	ColorOfFloorBlock= rand()%6;
	if(ColorOfFloorBlock == 0)
	{
		r1=255;
		g1=0;
		b1=0;
	}
	if(ColorOfFloorBlock == 1)
	{
		r1=0;
		g1=255;
		b1=0;
	}
	if(ColorOfFloorBlock == 2)
	{
		r1=0;
		g1=0;
		b1=255;
	}
	if(ColorOfFloorBlock == 3)
	{
		r1=255;
		g1=255;
		b1=0;
	}
	if(ColorOfFloorBlock == 4)
	{
		r1=255;
		g1=165;
		b1=0;
	}
	if(ColorOfFloorBlock == 5)
	{
		r1=255;
		g1=0;
		b1=255;
	}

	iSetColor(r1,g1,b1);
	iFilledRectangle(XaxisOfFloorBLock, YaxisOfFloorBLock, 50, 50);
}

void ColorChangeOfFloorBlock()
{
	if( play == true ){
		ColorOfFloorBlock = rand() % 6;
		if(ColorOfFloorBlock == 0)
		{
			r1=255;
			g1=0;
			b1=0;
		}
		if(ColorOfFloorBlock == 1)
		{
			r1=0;
			g1=255;
			b1=0;
		}
		if(ColorOfFloorBlock == 2)
		{
			r1=0;
			g1=0;
			b1=255;
		}
		if(ColorOfFloorBlock == 3)
		{
			r1=255;
			g1=255;
			b1=0;
		}
		if(ColorOfFloorBlock == 4)
		{
			r1=255;
			g1=165;
			b1=0;
		}
		if(ColorOfFloorBlock == 5)
		{
			r1=255;
			g1=0;
			b1=255;
		}
	}
}

/*************************************************************************************************************************************
************************************************************************************************************************************
******************************************Raining Block***********Raining Block**********************************************************/
int NumberOfRainingBlock = 5;

struct rainingBlock{
	double XaxisOfRainingBlock;
	double YaxisOfRainingBlock;
	int ColorOfRainingBlock ;

	double r2;
	double g2;
	double b2;
} RainingBlock[10];

void SetRainingBlock()
{
	RainingBlock[0].XaxisOfRainingBlock=0;
	for(int i=1;i<=NumberOfRainingBlock;i++){
		RainingBlock[i].XaxisOfRainingBlock=RainingBlock[i-1].XaxisOfRainingBlock+90+(rand()%200);
		RainingBlock[i].YaxisOfRainingBlock=350 + (rand()%150) + 350 + (rand()%150);
		RainingBlock[i].ColorOfRainingBlock= rand()%6;
		if(RainingBlock[i].ColorOfRainingBlock == 0)
		{
			RainingBlock[i].r2=255;
			RainingBlock[i].g2=0;
			RainingBlock[i].b2=0;
		}
		if(RainingBlock[i].ColorOfRainingBlock == 1)
		{
			RainingBlock[i].r2=0;
			RainingBlock[i].g2=255;
			RainingBlock[i].b2=0;
		}
		if(RainingBlock[i].ColorOfRainingBlock == 2)
		{
			RainingBlock[i].r2=0;
			RainingBlock[i].g2=0;
			RainingBlock[i].b2=255;
		}
		if(RainingBlock[i].ColorOfRainingBlock == 3)
		{
			RainingBlock[i].r2=255;
			RainingBlock[i].g2=255;
			RainingBlock[i].b2=0;
		}
		if(RainingBlock[i].ColorOfRainingBlock == 4)
		{
			RainingBlock[i].r2=255;
			RainingBlock[i].g2=165;
			RainingBlock[i].b2=0;
		}
		if(RainingBlock[i].ColorOfRainingBlock == 5)
		{
			RainingBlock[i].r2=255;
			RainingBlock[i].g2=0;
			RainingBlock[i].b2=255;
		}
	}
}


void RainingBlockMove()
{
	if( play == true ){
		for(int i=1;i<=NumberOfRainingBlock;i++){
			RainingBlock[i].YaxisOfRainingBlock -= ReduceOfYAxisOfAll;


			/********************************************************************************************************************************************
			*********************************************************************************************************************************************
			************************Collision Check********************************Collision Check*****************************************************/

			if( RainingBlock[i].YaxisOfRainingBlock <= 50 ){
				if( ValidityOf_RainbowBall_feature == false && ValidityOf_2x_feature == false) {
					if( (RainingBlock[i].XaxisOfRainingBlock>=XaxisOfFloorBLock)  &&   (RainingBlock[i].XaxisOfRainingBlock < XaxisOfFloorBLock+50) ){
						if( (RainingBlock[i].r2 == r1) && (RainingBlock[i].g2 == g1) && (RainingBlock[i].b2 == b1) ){
							TotalPoint+=10;
						}
						else{
							TotalPoint-=5;
							life -=1;
							if( life < 1){
								screen = 6;
							}
						}
					}
					else if( (RainingBlock[i].XaxisOfRainingBlock < XaxisOfFloorBLock)  &&   (RainingBlock[i].XaxisOfRainingBlock > XaxisOfFloorBLock-50) ){
						if( (RainingBlock[i].r2 == r1) && (RainingBlock[i].g2 == g1) && (RainingBlock[i].b2 == b1) ){
							TotalPoint+=10;
						}
						else{
							TotalPoint-=5;
							life -=1;
							if( life < 1){
								screen = 6;
							}
						}
					}
				}

				if( ValidityOf_RainbowBall_feature == true ) {
					if( (RainingBlock[i].XaxisOfRainingBlock>=XaxisOfFloorBLock)  &&   (RainingBlock[i].XaxisOfRainingBlock < XaxisOfFloorBLock+50) ){
						TotalPoint+=10;
					}
					else if( (RainingBlock[i].XaxisOfRainingBlock < XaxisOfFloorBLock)  &&   (RainingBlock[i].XaxisOfRainingBlock > XaxisOfFloorBLock-50) ){
						TotalPoint+=10;
					}
				}

				if( ValidityOf_2x_feature == true ) {
					if( (RainingBlock[i].XaxisOfRainingBlock>=XaxisOfFloorBLock)  &&   (RainingBlock[i].XaxisOfRainingBlock < XaxisOfFloorBLock+50) ){
						if( (RainingBlock[i].r2 == r1) && (RainingBlock[i].g2 == g1) && (RainingBlock[i].b2 == b1) ){
							TotalPoint+=20;
						}
						else{
							TotalPoint-=10;
							life -=1;
							if( life < 1){
								screen = 6;
							}
						}
					}
					else if( (RainingBlock[i].XaxisOfRainingBlock < XaxisOfFloorBLock)  &&   (RainingBlock[i].XaxisOfRainingBlock > XaxisOfFloorBLock-50) ){
						if( (RainingBlock[i].r2 == r1) && (RainingBlock[i].g2 == g1) && (RainingBlock[i].b2 == b1) ){
							TotalPoint+=20;
						}
						else{
							TotalPoint-=10;
							life -=1;
							if( life < 1){
								screen = 6;
							}
						}
					}
				}
				if( TotalPoint < 0 ){
					TotalPoint = 0;
				}
				if( TimeLimit == 0 && TotalPoint < ProjectedScore){
					screen = 6;
				}
				if( TotalPoint >= ProjectedScore ){
					level = 2;
					ProjectedScore = Lev2ProjecScore;
					StartNewLevel = true;
				}
				if( TotalPoint >= ProjectedScore ){
					level = 3;
					ProjectedScore = Lev3ProjecScore;
					StartNewLevel = true;
				}
				if( TotalPoint >= ProjectedScore ){
					level = 4;
					StartNewLevel = true;
					ProjectedScore = Lev4ProjecScore;
				}
				if( TotalPoint >= ProjectedScore ){
					level = 5;
					ProjectedScore = Lev5ProjecScore;
					StartNewLevel = true;
				}
				if(TotalPoint >= Lev5ProjecScore){
						screen = 6;
				}	
			}


			/*********************************************************************************************************************************************
			**********************************************************************************************************************************************
			******************************Renewal Of Raining Block **************************Renewal Of Raining Block*************************************/
			if ( gameover == false ){
				if( RainingBlock[i].YaxisOfRainingBlock <=50){
					RainingBlock[i].XaxisOfRainingBlock=RainingBlock[i].XaxisOfRainingBlock+(rand()%10);
					if(RainingBlock[i].XaxisOfRainingBlock+50 > 1350 ){
						RainingBlock[i].XaxisOfRainingBlock = rand()%200;
					}
					RainingBlock[i].YaxisOfRainingBlock=700 + (rand()%600);
					RainingBlock[i].ColorOfRainingBlock= rand()%6;
					if(RainingBlock[i].ColorOfRainingBlock == 0)
					{
						RainingBlock[i].r2=255;
						RainingBlock[i].g2=0;
						RainingBlock[i].b2=0;
					}
					if(RainingBlock[i].ColorOfRainingBlock == 1)
					{
						RainingBlock[i].r2=0;
						RainingBlock[i].g2=255;
						RainingBlock[i].b2=0;
					}
					if(RainingBlock[i].ColorOfRainingBlock == 2)
					{
						RainingBlock[i].r2=0;
						RainingBlock[i].g2=0;
						RainingBlock[i].b2=255;
					}
					if(RainingBlock[i].ColorOfRainingBlock == 3)
					{
						RainingBlock[i].r2=255;
						RainingBlock[i].g2=255;
						RainingBlock[i].b2=0;
					}
					if(RainingBlock[i].ColorOfRainingBlock == 4)
					{
						RainingBlock[i].r2=255;
						RainingBlock[i].g2=165;
						RainingBlock[i].b2=0;
					}
					if(RainingBlock[i].ColorOfRainingBlock == 5)
					{
						RainingBlock[i].r2=255;
						RainingBlock[i].g2=0;
						RainingBlock[i].b2=255;
					}
				}
			}
		}
	}
}



/*************************************************************************************************************************************
************************************************************************************************************************************
******************************************Special Features***********Special Features**********************************************************/

struct SpeedUp_Feature{
	int XaxisOfSpeedUp_feature;
	int YaxisOfSpeedUp_feature;
} SpeedUp_feature[10];
void SpeedUp_featureInitialize(){
	for(int i=0; i<10; i++){
		SpeedUp_feature[i].YaxisOfSpeedUp_feature = 0;
	}
}


struct Slow_Feature{
	int XaxisOfSlow_feature;
	int YaxisOfSlow_feature;
} Slow_feature[10];
void Slow_FeatureInitialize(){
	for(int i=0; i<10; i++){
		Slow_feature[i].YaxisOfSlow_feature = 0;
	}
}


struct RainbowBall_Feature{
	int XaxisOfRainbowBall_feature;
	int YaxisOfRainbowBall_feature;
} RainbowBall_feature[10];
void RainbowBall_FeatureInitialize(){
	for(int i=0; i<10; i++){
		RainbowBall_feature[i].YaxisOfRainbowBall_feature = 0;
	}
}


struct _2x_Feature{
	int XaxisOf_2x_feature;
	int YaxisOf_2x_feature;
} _2x_feature[10];
void _2x_FeatureInitialize(){
	for(int i=0; i<10; i++){
		_2x_feature[i].YaxisOf_2x_feature = 0;
	}
}


struct Life_Feature{
	int XaxisOf_life_feature;
	int YaxisOf_life_feature;
} life_feature[10];
void life_FeatureInitialize(){
	for(int i=0; i<10; i++){
		life_feature[i].YaxisOf_life_feature = 0;
	}
}


int ProbabilityOf_SpeedUp_feature;
int ProbabilityOf_Slow_Feature;
int ProbabilityOf_RainbowBall_Feature;
int ProbabilityOf_2x_feature;
int ProbabilityOf_life_feature;

int indexOf_SpeedUp_feature =0;
int indexOf_Slow_Feature =0;
int indexOf_RainbowBall_Feature = 0;
int indexOf_2x_feature = 0;
int indexOf_life_feature = 0;

void SetSpecialFeatures()
{
	if (play == true ){
		ProbabilityOf_SpeedUp_feature = rand()%80;
		ProbabilityOf_Slow_Feature = rand()%150;
		ProbabilityOf_RainbowBall_Feature = rand()%250;
		ProbabilityOf_2x_feature = rand()%250;
		ProbabilityOf_life_feature = rand()% 250;
	
		if( ProbabilityOf_SpeedUp_feature == 1 ){
			SpeedUp_feature[indexOf_SpeedUp_feature].XaxisOfSpeedUp_feature = rand()%325 + rand()%325 + rand()%325 + rand()%325 ;
			SpeedUp_feature[indexOf_SpeedUp_feature].YaxisOfSpeedUp_feature = 700 + rand()%200;
			indexOf_SpeedUp_feature++;
			if( indexOf_SpeedUp_feature > 9){
				indexOf_SpeedUp_feature = 0;
			}
		}

		if( ProbabilityOf_Slow_Feature == 1 ){
			Slow_feature[indexOf_Slow_Feature].XaxisOfSlow_feature = rand()%325 + rand()%325 + rand()%325 + rand()%325;
			Slow_feature[indexOf_Slow_Feature].YaxisOfSlow_feature = 900 + rand() % 200;
			indexOf_Slow_Feature++;
			if( indexOf_Slow_Feature > 9){
				indexOf_Slow_Feature = 0;
			}
		}

		if( ProbabilityOf_RainbowBall_Feature == 1 ){
			RainbowBall_feature[indexOf_RainbowBall_Feature].XaxisOfRainbowBall_feature = rand()%325 + rand()%325 + rand()%325 + rand()%325;
			RainbowBall_feature[indexOf_RainbowBall_Feature].YaxisOfRainbowBall_feature = 1000 + rand() % 200;
			indexOf_RainbowBall_Feature++;
			if( indexOf_RainbowBall_Feature > 9){
				indexOf_RainbowBall_Feature = 0;
			}
		}

		if( ProbabilityOf_2x_feature == 1 ){
			_2x_feature[indexOf_2x_feature].XaxisOf_2x_feature = rand()%325 + rand()%325 + rand()%325 + rand()%325;
			_2x_feature[indexOf_2x_feature].YaxisOf_2x_feature = 1100 + rand() % 200;
			indexOf_2x_feature++;
			if( indexOf_2x_feature > 9){
				indexOf_2x_feature = 0;
			}
		}

		if( ProbabilityOf_life_feature == 1 ){
			life_feature[indexOf_life_feature].XaxisOf_life_feature = rand()%325 + rand()%325 + rand()%325 + rand()%325;
			life_feature[indexOf_life_feature].YaxisOf_life_feature = 1200 + rand() % 200;
			indexOf_life_feature++;
			if( indexOf_life_feature > 9){
				indexOf_life_feature = 0;
			}
		}
	}
}


/*****************************************************************************************************************************************************
************************************Some needed functions***********************Some needed functions************************************************/

void ClashAvoid(){
	for(int i=0 ; i<=5 ; i++ ){
		for(int j=0 ; j<=7 ; j++){
			if((RainingBlock[i].YaxisOfRainingBlock < SpeedUp_feature[j].YaxisOfSpeedUp_feature)&&(RainingBlock[i].YaxisOfRainingBlock+50 > SpeedUp_feature[j].YaxisOfSpeedUp_feature)){
				if((RainingBlock[i].XaxisOfRainingBlock < SpeedUp_feature[j].XaxisOfSpeedUp_feature)&&(RainingBlock[i].XaxisOfRainingBlock+50 > SpeedUp_feature[j].XaxisOfSpeedUp_feature)){
					SpeedUp_feature[i].YaxisOfSpeedUp_feature += 100;
				}
			}
			else if((RainingBlock[i].YaxisOfRainingBlock > SpeedUp_feature[j].YaxisOfSpeedUp_feature)&&(RainingBlock[i].YaxisOfRainingBlock-50 < SpeedUp_feature[j].YaxisOfSpeedUp_feature)){
				if((RainingBlock[i].XaxisOfRainingBlock > SpeedUp_feature[j].XaxisOfSpeedUp_feature)&&(RainingBlock[i].XaxisOfRainingBlock-50 < SpeedUp_feature[j].XaxisOfSpeedUp_feature)){
					SpeedUp_feature[i].YaxisOfSpeedUp_feature += 100;
				}
			}

			if((RainingBlock[i].YaxisOfRainingBlock < Slow_feature[j].YaxisOfSlow_feature)&&(RainingBlock[i].YaxisOfRainingBlock+50 > Slow_feature[j].YaxisOfSlow_feature)){
				if((RainingBlock[i].XaxisOfRainingBlock < Slow_feature[j].XaxisOfSlow_feature)&&(RainingBlock[i].XaxisOfRainingBlock+50 > Slow_feature[j].XaxisOfSlow_feature)){
					Slow_feature[i].YaxisOfSlow_feature += 100;
				}
			}
			else if((RainingBlock[i].YaxisOfRainingBlock > Slow_feature[j].YaxisOfSlow_feature)&&(RainingBlock[i].YaxisOfRainingBlock-50 < Slow_feature[j].YaxisOfSlow_feature)){
				if((RainingBlock[i].XaxisOfRainingBlock > Slow_feature[j].XaxisOfSlow_feature)&&(RainingBlock[i].XaxisOfRainingBlock-50 < Slow_feature[j].XaxisOfSlow_feature)){
					Slow_feature[i].YaxisOfSlow_feature += 100;
				}
			}

			if((RainingBlock[i].YaxisOfRainingBlock < RainbowBall_feature[j].YaxisOfRainbowBall_feature)&&(RainingBlock[i].YaxisOfRainingBlock+50 > RainbowBall_feature[j].YaxisOfRainbowBall_feature)){
				if((RainingBlock[i].XaxisOfRainingBlock < RainbowBall_feature[j].XaxisOfRainbowBall_feature)&&(RainingBlock[i].XaxisOfRainingBlock+50 > RainbowBall_feature[j].XaxisOfRainbowBall_feature)){
					RainbowBall_feature[i].YaxisOfRainbowBall_feature += 100;
				}
			}
			else if((RainingBlock[i].YaxisOfRainingBlock > RainbowBall_feature[j].YaxisOfRainbowBall_feature)&&(RainingBlock[i].YaxisOfRainingBlock-50 < RainbowBall_feature[j].YaxisOfRainbowBall_feature)){
				if((RainingBlock[i].XaxisOfRainingBlock > RainbowBall_feature[j].XaxisOfRainbowBall_feature)&&(RainingBlock[i].XaxisOfRainingBlock-50 < RainbowBall_feature[j].XaxisOfRainbowBall_feature)){
					RainbowBall_feature[i].YaxisOfRainbowBall_feature += 100;
				}
			}

			if((RainingBlock[i].YaxisOfRainingBlock < _2x_feature[j].YaxisOf_2x_feature)&&(RainingBlock[i].YaxisOfRainingBlock+50 > _2x_feature[j].YaxisOf_2x_feature)){
				if((RainingBlock[i].XaxisOfRainingBlock < _2x_feature[j].XaxisOf_2x_feature)&&(RainingBlock[i].XaxisOfRainingBlock+50 > _2x_feature[j].XaxisOf_2x_feature)){
					_2x_feature[i].YaxisOf_2x_feature += 100;
				}
			}
			else if((RainingBlock[i].YaxisOfRainingBlock > _2x_feature[j].YaxisOf_2x_feature)&&(RainingBlock[i].YaxisOfRainingBlock-50 < _2x_feature[j].YaxisOf_2x_feature)){
				if((RainingBlock[i].XaxisOfRainingBlock > _2x_feature[j].XaxisOf_2x_feature)&&(RainingBlock[i].XaxisOfRainingBlock-50 < _2x_feature[j].XaxisOf_2x_feature)){
					_2x_feature[i].YaxisOf_2x_feature += 100;
				}
			}
		}
	}
}


/*****************************************************************************************************************************************************
***********************************************************Movement and check of special features**************************************************/

int countForSlow = 0;
int countForSpeedUp = 0;
int countForRainbowBall = 0;
int countFor_2x_feature = 0;

void MoveSpecialFeatures(){
	if ( play == true ){
		for( int i = 0; i<10; i++){
			SpeedUp_feature[i].YaxisOfSpeedUp_feature -= ReduceOfYAxisOfAll;
			Slow_feature[i].YaxisOfSlow_feature -= ReduceOfYAxisOfAll;
			RainbowBall_feature[i].YaxisOfRainbowBall_feature -= ReduceOfYAxisOfAll;
			_2x_feature[i].YaxisOf_2x_feature -= ReduceOfYAxisOfAll;
			life_feature[i].YaxisOf_life_feature -= ReduceOfYAxisOfAll;

			ClashAvoid();

			if(SpeedUp_feature[i].YaxisOfSpeedUp_feature > 0 && SpeedUp_feature[i].YaxisOfSpeedUp_feature <= 50 ){
				if( (SpeedUp_feature[i].XaxisOfSpeedUp_feature >= XaxisOfFloorBLock)  &&   (SpeedUp_feature[i].XaxisOfSpeedUp_feature < XaxisOfFloorBLock+50) ){
					if( ValidityOf_SpeedUp_feature == false && ValidityOf_Slow_feature == false ){
						ValidityOf_SpeedUp_feature = true;
						ReduceOfYAxisOfAll *= 3;
					}
				
				}
				else if ( (SpeedUp_feature[i].XaxisOfSpeedUp_feature < XaxisOfFloorBLock)  &&   (SpeedUp_feature[i].XaxisOfSpeedUp_feature > XaxisOfFloorBLock-50) ){
					if( ValidityOf_SpeedUp_feature == false && ValidityOf_Slow_feature == false ){
						ValidityOf_SpeedUp_feature = true;
						ReduceOfYAxisOfAll *= 3;
					}
				}
			}

			if(Slow_feature[i].YaxisOfSlow_feature > 0 && Slow_feature[i].YaxisOfSlow_feature <= 50 ){
				if( (Slow_feature[i].XaxisOfSlow_feature >= XaxisOfFloorBLock)  &&   (Slow_feature[i].XaxisOfSlow_feature < XaxisOfFloorBLock+50) ){
					if( ValidityOf_Slow_feature == false && ValidityOf_SpeedUp_feature == false ){
						ValidityOf_Slow_feature = true;
						ReduceOfYAxisOfAll /= 5;
					}
				
				}
				else if ( (Slow_feature[i].XaxisOfSlow_feature < XaxisOfFloorBLock)  &&   (Slow_feature[i].XaxisOfSlow_feature > XaxisOfFloorBLock-50) ){
					if( ValidityOf_Slow_feature == false && ValidityOf_SpeedUp_feature == false ){
						ValidityOf_Slow_feature = true;
						ReduceOfYAxisOfAll /= 5;
					}
				}
			}

			if(RainbowBall_feature[i].YaxisOfRainbowBall_feature > 0 && RainbowBall_feature[i].YaxisOfRainbowBall_feature <= 50 ){
				if( (RainbowBall_feature[i].XaxisOfRainbowBall_feature >= XaxisOfFloorBLock)  &&   (RainbowBall_feature[i].XaxisOfRainbowBall_feature < XaxisOfFloorBLock+50) ){
					if( ValidityOf_RainbowBall_feature == false && ValidityOf_2x_feature == false){
						ValidityOf_RainbowBall_feature = true;
					}
				
				}
				else if ( (RainbowBall_feature[i].XaxisOfRainbowBall_feature < XaxisOfFloorBLock)  &&   (RainbowBall_feature[i].XaxisOfRainbowBall_feature > XaxisOfFloorBLock-50) ){
					if( ValidityOf_RainbowBall_feature == false && ValidityOf_2x_feature == false ){
						ValidityOf_RainbowBall_feature = true;
					}
				}
			}

			if(_2x_feature[i].YaxisOf_2x_feature > 30 && _2x_feature[i].YaxisOf_2x_feature <= 50 ){
				if( (_2x_feature[i].XaxisOf_2x_feature >= XaxisOfFloorBLock)  &&   (_2x_feature[i].XaxisOf_2x_feature < XaxisOfFloorBLock+50) ){
					if( ValidityOf_2x_feature == false && ValidityOf_RainbowBall_feature == false ){
						ValidityOf_2x_feature = true;
					}
				
				}
				else if ( (_2x_feature[i].XaxisOf_2x_feature < XaxisOfFloorBLock)  &&   (_2x_feature[i].XaxisOf_2x_feature > XaxisOfFloorBLock-50) ){
					if(  ValidityOf_2x_feature == false && ValidityOf_RainbowBall_feature == false ){
						ValidityOf_2x_feature = true;
					}
				}
			}

			if(life_feature[i].YaxisOf_life_feature > 30 && life_feature[i].YaxisOf_life_feature <= 50 ){
				if( (life_feature[i].XaxisOf_life_feature >= XaxisOfFloorBLock)  &&   (life_feature[i].XaxisOf_life_feature < XaxisOfFloorBLock+50) ){
					life +=1;
					if( life > 5){
						life = 5;
					}
				}
				else if ( (life_feature[i].XaxisOf_life_feature < XaxisOfFloorBLock)  &&   (life_feature[i].XaxisOf_life_feature > XaxisOfFloorBLock-50) ){
					life +=1;
					if( life > 5){
						life = 5;
					}
				}
			}

		}

		if( ValidityOf_SpeedUp_feature == true ){
			countForSpeedUp++;
			if( countForSpeedUp == 100){
				ValidityOf_SpeedUp_feature = false;
				ReduceOfYAxisOfAll /= 3;
				countForSpeedUp = 0;
			}
		}

		if( ValidityOf_Slow_feature == true ){
			countForSlow++;
			if( countForSlow == 100){
				ValidityOf_Slow_feature = false;
				ReduceOfYAxisOfAll *= 5;
				countForSlow = 0;
			}
		}

		if( ValidityOf_RainbowBall_feature == true ){
			countForRainbowBall++;
			if( countForRainbowBall == 100){
				ValidityOf_RainbowBall_feature = false;
				countForRainbowBall = 0;
			}
		}

		if( ValidityOf_2x_feature == true ){
			countFor_2x_feature++;
			if( countFor_2x_feature == 100){
				ValidityOf_2x_feature = false;
				countFor_2x_feature = 0;
			}
		}
	}
}


/*****************************************************************************************************************************************************
***************************Background********************Background***************************Background*********************************************/

char background_image [70][20] = {"BMP files\\1.bmp","BMP files\\2.bmp","BMP files\\3.bmp","BMP files\\4.bmp","BMP files\\5.bmp","BMP files\\6.bmp","BMP files\\7.bmp","BMP files\\8.bmp","BMP files\\9.bmp","BMP files\\10.bmp","BMP files\\11.bmp","BMP files\\12.bmp","BMP files\\13.bmp","BMP files\\14.bmp",
								  "BMP files\\15.bmp","BMP files\\16.bmp","BMP files\\17.bmp","BMP files\\18.bmp","BMP files\\19.bmp","BMP files\\20.bmp","BMP files\\21.bmp","BMP files\\22.bmp","BMP files\\23.bmp","BMP files\\24.bmp","BMP files\\25.bmp","BMP files\\26.bmp","BMP files\\27.bmp","BMP files\\28.bmp",
								  "BMP files\\29.bmp","BMP files\\30.bmp","BMP files\\31.bmp","BMP files\\32.bmp","BMP files\\33.bmp","BMP files\\34.bmp","BMP files\\35.bmp","BMP files\\36.bmp","BMP files\\37.bmp","BMP files\\38.bmp","BMP files\\39.bmp","BMP files\\40.bmp","BMP files\\41.bmp","BMP files\\42.bmp",
								  "BMP files\\43.bmp","BMP files\\44.bmp","BMP files\\45.bmp","BMP files\\46.bmp","BMP files\\47.bmp","BMP files\\48.bmp","BMP files\\49.bmp","BMP files\\50.bmp","BMP files\\51.bmp","BMP files\\52.bmp","BMP files\\53.bmp","BMP files\\54.bmp","BMP files\\55.bmp","BMP files\\56.bmp",
								  "BMP files\\57.bmp","BMP files\\58.bmp","BMP files\\59.bmp","BMP files\\60.bmp","BMP files\\61.bmp","BMP files\\62.bmp","BMP files\\63.bmp","BMP files\\64.bmp","BMP files\\65.bmp","BMP files\\66.bmp","BMP files\\67.bmp","BMP files\\68.bmp","BMP files\\69.bmp","BMP files\\70.bmp",
								 };
int SpeedOfChangingBackground = 20;

struct Background{
	int Xaxis;
	int Yaxis;
} background [70];

void SetBackground() 
{
	int sum =0;
	for(  int i =0; i<70 ; i++){
		background[i].Xaxis = sum;
		background[i].Yaxis = 0;
		sum+=20;
	}
}

int countForShowingNewLevel = 0;

void ChangeBackground()
{
	for( int i=0; i<70; i++){
		background[i].Xaxis += SpeedOfChangingBackground;
		if( background[i].Xaxis >= 1390 ){
			background[i].Xaxis = 0;
		}
	}
	if (StartNewLevel == true){
		countForShowingNewLevel++;
		if(countForShowingNewLevel == 30){
			StartNewLevel = false;

			iResumeTimer(TimerOfFloorBlock);
			iResumeTimer(TimerOfRainingBlock);
			iResumeTimer(TimerOfSetfatures);
			iResumeTimer(TimerOfMovefatures);

			countForShowingNewLevel = 0;
		}
	}
}


/*****************************************************************************************************************************************************
***************************Extended works********************Extended works***************************Extended works**********************************/

void TimeLimitChange(){
	TimeLimit -=1;
	if(TimeLimit < 0){
		TimeLimit = 0;
	}
	minute = TimeLimit/60;
	second = TimeLimit%60;
}
void mainMenu()
{
 iShowBMP(0,0, "BMP files\\color_rush.bmp");

 iSetColor(200,200,200);
 iFilledRectangle(566, menubar, 120, 25);

 iSetColor(0, 200,200);

 iText(570, 245, "Start", GLUT_BITMAP_HELVETICA_18);
 iText(570, 220, "Instructions", GLUT_BITMAP_HELVETICA_18);
 iText(570, 195, "High Scores", GLUT_BITMAP_HELVETICA_18);
 iText(570, 170, "Quit", GLUT_BITMAP_HELVETICA_18);

 menu = true;
 //instruction=0; highscore=0;
}

void chooseOption()
{
	 if(menubar==240){
		screen = 1;
	 }
	 else if(menubar==215){
		screen =  2;
	 }
	 else if(menubar==190){
		screen =  3;
	 }
	 else if(menubar==165){
	   exit(0);
	 }
	 menu= false;
}

void ShowInstructions(){
	iShowBMP(0, 0, "BMP files\\instruction.bmp");
}

void pausemenu(){
	iShowBMP(0,0,"BMP files\\pause.bmp");
}

void FileWrite(){
	highscore = fopen("highscore.txt","r");
	if(highscore == NULL ){
		highscore = fopen("highscore.txt","w");
		fscanf(highscore,"%d", &TotalPoint);
	}
	if(highscore != NULL){
		fscanf(highscore,"%d",&PrevHighscore);
		if(TotalPoint > PrevHighscore ){
			highscore = fopen("highscore.txt","w");
			fprintf(highscore,"%d",TotalPoint);
		}
	}
	fclose(highscore);
}

void gameoverFunc(){
	play = false;
	gameover = true; 
	iShowBMP(0, 0, "BMP files\\gameover.bmp");
	iSetColor (255, 255, 255 );
	iText( 570, 335 ,"GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24) ;
	iText( 570, 310 ,"Your score is ", GLUT_BITMAP_TIMES_ROMAN_24 );
	iText( 700, 310 ,ScoreArray2, GLUT_BITMAP_TIMES_ROMAN_24 );
	FileWrite();
	TotalPoint = 0;
}

void ShowLife(){
	if(life == 5 ){
		iShowBMP2( 5, 625 , "BMP files\\life_5.bmp", 16777215);
	}
	if(life == 4 ){
		iShowBMP2( 5, 625 , "BMP files\\life_4.bmp", 16777215);
	}
	if(life == 3 ){
		iShowBMP2( 5, 625 , "BMP files\\life_3.bmp", 16777215);
	}
	if(life == 2 ){
		iShowBMP2( 5, 625 , "BMP files\\life_2.bmp", 16777215);
	}
	if(life == 1 ){
		iShowBMP2( 5, 625 , "BMP files\\life_1.bmp", 16777215);
	}
}

void ShowHighscores(){
	iShowBMP(0, 0, "BMP files\\HighScoreImage.bmp");
	highscore = fopen("highscore.txt","r");
	fscanf(highscore,"%d",&Highscore);
	sprintf( HighscoreArray, "%d", Highscore);
	iText ( 650, 400, HighscoreArray, GLUT_BITMAP_TIMES_ROMAN_24 );
}

void ShowNewLevelFunc(){
	if(StartNewLevel == true ){
		iPauseTimer(TimerOfFloorBlock);
		iPauseTimer(TimerOfRainingBlock);
		iPauseTimer(TimerOfSetfatures);
		iPauseTimer(TimerOfMovefatures);
		iShowBMP(350, 200, "BMP files\\new_level.bmp");
		if(level == 2){
			gameTime = 0;
			ReduceOfYAxisOfAll = 30;
			ProjectedScore = Lev2ProjecScore;
			TimeLimit = 180;
			life = 5;
		}
		if(level == 3){
			gameTime = 0;
			ReduceOfYAxisOfAll = 40;
			ProjectedScore = Lev3ProjecScore;
			TimeLimit = 180;
			life = 5;
		}
		if(level == 4){
			gameTime = 0;
			ReduceOfYAxisOfAll = 45;
			ProjectedScore = Lev4ProjecScore;
			TimeLimit = 240;
			life = 5;
		}
		if(level == 5){
			gameTime = 0;
			ReduceOfYAxisOfAll = 50;
			ProjectedScore = Lev5ProjecScore;
			TimeLimit = 240;
			life = 5;
		}
	}
}



/*
function iDraw() is called again and again by the system. 
*/             
void iDraw()
{
	//place your drawing codes here 
	showScreen();
	ClashAvoid();

	if(play == true ){
		iClear();
		
		for(int i =0; i<70; i++){
			iShowBMP( background[i].Xaxis, background[i].Yaxis, background_image[i]);
		}

		ShowLife();

		iSetColor(r1 ,g1 ,b1);
		iFilledRectangle(XaxisOfFloorBLock,YaxisOfFloorBLock,50,50);

		for(int i=1 ; i<=NumberOfRainingBlock; i++){
			if(RainingBlock[i].YaxisOfRainingBlock >= 0){
				iSetColor(RainingBlock[i].r2 ,RainingBlock[i].g2 , RainingBlock[i].b2);
				iFilledRectangle(RainingBlock[i].XaxisOfRainingBlock, RainingBlock[i].YaxisOfRainingBlock ,50 ,50);
			}
		}
		if(screen == 0){
			TotalPoint = 0;
		}
		sprintf( ScoreArray, "Score : %d ", TotalPoint);
		sprintf( ScoreArray2, " %d ", TotalPoint);
		sprintf( ProjectedScoreArray, "Projected Score : %d ", ProjectedScore);
		sprintf( levelArray, "Level : %d ", level);
		sprintf( timeArray, "Time Limit %d : %d",minute,second);
		iSetColor(255, 255, 255);
		iText(5,600,ScoreArray,GLUT_BITMAP_HELVETICA_18);
		iText(5,575,levelArray,GLUT_BITMAP_HELVETICA_18);
		iText(5,550,ProjectedScoreArray,GLUT_BITMAP_HELVETICA_18);
		iText(5,525,timeArray,GLUT_BITMAP_HELVETICA_18);
		for(int i=0; i<=7; i++){
			if( SpeedUp_feature[i].YaxisOfSpeedUp_feature >= 35 ){
				iShowBMP( SpeedUp_feature[i].XaxisOfSpeedUp_feature, SpeedUp_feature[i].YaxisOfSpeedUp_feature, "BMP files\\speed.bmp");
			}

			if( Slow_feature[i].YaxisOfSlow_feature >= 35 ){
				iShowBMP2( Slow_feature[i].XaxisOfSlow_feature, Slow_feature[i].YaxisOfSlow_feature, "BMP files\\slow.bmp", 16777215 );
			}

			if( RainbowBall_feature[i].YaxisOfRainbowBall_feature >= 35 ){
				iShowBMP2( RainbowBall_feature[i].XaxisOfRainbowBall_feature, RainbowBall_feature[i].YaxisOfRainbowBall_feature, "BMP files\\rainbow.bmp", 16777215);
			}

			if( _2x_feature[i].YaxisOf_2x_feature >= 35 ){
				iShowBMP( _2x_feature[i].XaxisOf_2x_feature, _2x_feature[i].YaxisOf_2x_feature, "BMP files\\2x.bmp");
			}

			if( life_feature[i].YaxisOf_life_feature >= 35 ){
				iShowBMP2( life_feature[i].XaxisOf_life_feature, life_feature[i].YaxisOf_life_feature, "BMP files\\life_feature.bmp", 16777215 );
			}
		}

		ShowNewLevelFunc();
	}
}

/*   
function iMouseMove() is called when the user presses and drags the mouse.  
(mx,  my) is the position where the mouse pointer is. 
*/ 
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*   

function iMouse() is called when the user presses/releases the mouse.  
(mx, my)  is the position where the mouse pointer is. 
*/ 
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here 
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{	
		//place your codes here 
	}
}

/*  
function iKeyboard() is called whenever the user hits a key in keyboard.  
key- holds the ASCII value of the key pressed.  
*/ 
void iKeyboard(unsigned char key)
{
	if(key == 'q')

	{
		//do something with 'q' 
	}
	//place your codes here 
	if(key == '\r'){
		if( gameover == false ){
			chooseOption();
		}
    }
	if(key == 'p'){
		move = false ;
		iPauseTimer(TimerOfFloorBlock);
		iPauseTimer(TimerOfRainingBlock);
		iPauseTimer(TimerOfSetfatures);
		iPauseTimer(TimerOfMovefatures);
		iPauseTimer(TimerOfChangeBackground);
		iPauseTimer(TimerOfTimeLimit);
		screen = 5;
	}
	if(key == 'l'){	
		screen = 1;
		move = true ;
		iResumeTimer(TimerOfFloorBlock);
		iResumeTimer(TimerOfRainingBlock);
		iResumeTimer(TimerOfSetfatures);
		iResumeTimer(TimerOfMovefatures);
		iResumeTimer(TimerOfChangeBackground);
		iResumeTimer(TimerOfTimeLimit);

    }
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

	if(key == GLUT_KEY_RIGHT)
	{
		if( move == true ){ 
			if(XaxisOfFloorBLock<1300){
				XaxisOfFloorBLock+=SpeedOfFloorBlock;
				if(XaxisOfFloorBLock>1300){
					XaxisOfFloorBLock = 1300;
				}
			}
		}
	}
	if(key == GLUT_KEY_LEFT)
	{
		if( move == true ){
			if(XaxisOfFloorBLock>0){
				XaxisOfFloorBLock-=SpeedOfFloorBlock;
			}
		}
	}
	if(key == GLUT_KEY_UP  && menu==true)
	{
		 menubar+=25;
        if(menubar>240) menubar = 165;
	}

	if(key == GLUT_KEY_DOWN && menu== true)
	{
		 menubar-=25;                    
        if(menubar<165) menubar = 240;
	}

	if(key == GLUT_KEY_HOME ){
		if(play == false){
			screen = 0;
		}
		if(gameover == true ){
			gameover = false;
		}
	}
}



int main()
{
	//PlaySound("Sound Effect\\F", NULL, SND_LOOP | SND_ASYNC);
	SetAll();
	TimerOfChangeBackground = iSetTimer(50, ChangeBackground);
	TimerOfFloorBlock = iSetTimer(12000, ColorChangeOfFloorBlock);
	TimerOfRainingBlock = iSetTimer(SpeedOfAll, RainingBlockMove);
	TimerOfSetfatures = iSetTimer(100, SetSpecialFeatures);
	TimerOfMovefatures = iSetTimer(SpeedOfAll, MoveSpecialFeatures);
	TimerOfTimeLimit = iSetTimer(1000,TimeLimitChange);
	iInitialize(screenwidth, screenheight, "Color Rush");
	return 0;
}
 