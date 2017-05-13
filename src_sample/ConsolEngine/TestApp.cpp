// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "TestApp.h"
#include <conio.h>
#include <time.h>

TestApp::TestApp() : Parent(100, 80)
{
	for (int y=0; y < GAME_SCREEN_HEIGHT; y++)
   {
      for (int x=0; x < GAME_SCREEN_WIDTH; x++) 
      {
         if (y==0 || 
             (y==(GAME_SCREEN_HEIGHT-1) && x>=0 && x<=GAME_POLE_WIDTH) ||
             x==0 || 
             x==GAME_POLE_WIDTH ||
             (x==(GAME_SCREEN_WIDTH-1) && y>=0 && y<=FIGURE_PREVIEW_POLE_HEIGHT) ||
             (y==FIGURE_PREVIEW_POLE_HEIGHT && x>=GAME_POLE_WIDTH && x<(GAME_SCREEN_WIDTH-1)))
                  SetChar(x, y, L'#');
         else if ((y>0 && y<(GAME_POLE_HEIGHT-1) && x>0 && x<GAME_POLE_WIDTH) ||
                  (y>0 && y<FIGURE_PREVIEW_POLE_HEIGHT && x>GAME_POLE_WIDTH && x<(GAME_SCREEN_WIDTH-1)))
                     SetChar(x, y, L'.');
      }
   }
   srand((int)time(NULL));
   mFigureNumb = rand() % 7;
   mNextFigureNumb = rand() % 7;

   mMoveRight = 0;
   mMoveLeft = 0;
   mPressDown = false;

   mOldX = GAME_POLE_WIDTH/2;
   mOldY = 1;
   mMoveLeft=100;
	mMoveRight=0;
}

void TestApp::KeyPressed(int btnCode)
{
	  if ( btnCode == 224 )
      btnCode = getch();
	switch (btnCode)
   {
   case 72: 
//		mObj1Y--;
      break;
   case 80: 
      mPressDown = true;

//		mObj1Y++;
      break;
   case 75: // ���� ���� �������� ������ �������
	if (GetChar(mOldX-1,mOldY)=='.')
	{
   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');

   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX-1 + i, mOldY + j, L'*');
   mOldX--;
	}
      break;
   case 77:
while (GetChar(mOldX+mMoveRight,mOldY)=='*')
mMoveRight++;
if(GetChar(mOldX+mMoveRight,mOldY)=='.')
{
   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');

   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX+1 + i, mOldY + j, L'*');
   mOldX++;
      break;
}
   case 32:

	   switch (mFigureNumb)
	   {
	   case 0:
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[1][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=1;
		   break;
	   case 1:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[0][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=0;
		   break;
	   case 2:
		   break;
	   case 3:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[4][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=4;
		   break;
	   case 4:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[3][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=3;
		   break;
		case 5:
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[6][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=6;
		   break;
	   case 6:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[5][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=5;
		   break;
	   case 7:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[8][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=8;
		   break;
	   case 8:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[9][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=9;
		   break;
	   case 9:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[10][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=10;
		   break;
	   case 10:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[7][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=7;
		   break;
	   case 11:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[12][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=12;
		   break;
	   case 12:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[13][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=13;
		   break;
	   case 13:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[14][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=14;
		   break;
	   case 14:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[11][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=11;
		   break;
	   case 15:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[16][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=16;
		   break;
	   case 16:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[17][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=17;
		   break;
	   case 17:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[18][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=18;
		   break;
	   case 18:
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
		  if (FIGURE[15][j][i])
			{if (GetChar(mOldX + i, mOldY + j)!='.');
			break;
			}
			for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');
			mFigureNumb=15;
		   break;
		   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX+1 + i, mOldY + j, L'*');
	   }
//	�������� ��������� �� ������ � ����� ��������� +
      break;
   case 13:
      mNextFigureNumb = rand() % 7;
      break;
   }

	//if (btnCode == 32) //w space
	//	mObj1Y--;
	//else if (btnCode == 40) //s down
	//	mObj1Y++;
	//else if (btnCode == 37) //a left
	//	mObj1X--;
	//else if (btnCode == 39) //d right
	//	mObj1X++;

	//if (mObj1X < 0)
	//	mObj1X = 0;
	//else if (mObj1X >= X_SIZE)
	//	mObj1X = X_SIZE - 1;

	//if (mObj1Y < 0)
	//	mObj1Y = 0;
	//else if (mObj1Y >=Y_SIZE)
	//	mObj1Y = Y_SIZE - 1;
}

void TestApp::UpdateF(float deltaTime) // ������ ���������, ����� �������� ������� � ����
{
	for (int i=0; i<4; i++)//������� ������������
      for (int j=0; j<4; j++)
      {
         if (FIGURE[mNextFigureNumb][j][i]) SetChar(GAME_POLE_WIDTH + 2 + i, j + 2, L'*');
         else SetChar(GAME_POLE_WIDTH + 2 + i, j + 2, L'.');
      }

   int newX = mOldX ; // �������� ������� ������� �����, ���� ���� ���-�� ���� ����� ���������� � ������� ������ ����� ������ � ������
   int newY = mOldY + 1;
  // dstop =true;
  // for (int i=0; i<4; i++)
  // {	if (FIGURE[mFigureNumb][2][i])
	//	//if (GetChar(mOldX+i,mOldY+1)=='*')
	//	//	dstop=false;
 // // }
	//if (dstop)
	//{
   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(mOldX + i, mOldY + j, L'.');

   for (int i=0; i<4; i++)
      for (int j=0; j<4; j++)
         if (FIGURE[mFigureNumb][j][i]) SetChar(newX + i, newY + j, L'*');// ��������� � �������� ����� ���� ��� �����, � �������� ��� �� ���������

   mOldX = newX;
   mOldY = newY;
	
   if(mOldY > GAME_SCREEN_HEIGHT - 4) // ���� ��������� ���� -- ������ ����� ������ ���������� ����� � �����
   {
      mOldY = 1;
	  mOldX =8;
      mFigureNumb = mNextFigureNumb;
      mNextFigureNumb = rand() % 7;
      mPressDown = false;
   }

   if(mPressDown) Sleep(40);
   else Sleep(150);
	/*}
	else
	{
		mOldY = 1;
	  mOldX =GAME_POLE_WIDTH/ 2;
      mFigureNumb = mNextFigureNumb;
      mNextFigureNumb = rand() % 7;
      mPressDown = false;
	}*/
   
	//SetChar(mObj1XOld, mObj1YOld, L' ');
	//SetChar(mObj1X, mObj1Y, L'O');

	//mObj1XOld = mObj1X;
	//mObj1YOld = mObj1Y;

	////-----------------------------

	//SetChar(mObj2X, mObj2Y, L' ');
	//if (mDirection)
	//{
	//	mObj2X++;
	//	if (mObj2X == 40)
	//		mDirection = false;
	//}
	//else
	//{
	//	mObj2X--;
	//	if (mObj2X == 10)
	//		mDirection = true;
	//}
	//SetChar(mObj2X, mObj2Y, L'F');
}
