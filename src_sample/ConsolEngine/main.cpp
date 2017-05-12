// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "TestApp.h"

void main ()
{
	BaseBuild app;
	for (int iX = 0; iX <= 24; iX++)
	{
		for (int iY = 0; iY <= 17; iY++)
		{
			if (iX<=17)
			app.SetChar(iX,iY,'.');
			else if (iY<=8)
				app.SetChar(iX,iY,'.');
		}
	}
	 for (int i = 0; i <= 17; i++)
    {
		app.SetChar(0,i,'#');
    }
	 for (int i = 0; i <= 24; i++)
    {
		app.SetChar(i,0,'#');
    }
	 for (int i = 1; i <= 16; i++)
    {
		app.SetChar(17,i,'#');
    }
	 for (int i = 1; i <= 17; i++)
    {
		app.SetChar(i,17,'#');
    }

	
	app.Run();
}
