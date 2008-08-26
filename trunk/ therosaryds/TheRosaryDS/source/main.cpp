// The RosaryDS v1.2.3.0
// TheRosaryDS.googlecode.com
// TODO:	- 
//			- 
// Copyright 2008 Joseph Socoloski. All Rights Reserved. 
////////////////////////////////////////////////////////
// Includes
#include <PA9.h>    // Include for PA_Lib
#include <n3d.h>	// Include for lib3d
#include <nds.h>	//Include for libnds
#include <fat.h>	// C:\devkitPro\libnds\include
#include <string.h>	//Include for string support
#include <stdio.h>	//Include for string support
#include <iostream>	//Include for string support
#include <fstream>	//Include for string support
#include <sstream>	//Include for cvs support
#include <vector>	//Include for cvs support
#include<stdio.h>
using namespace std;//Include for string support
#include "transition.h"
#include "scrollsprites.h"
#include "collision.h"
#include "gfx/all_gfx.h"
#include "gfx/all_gfx.c"
#include "jsds_intro.h"
#include "TheApostlesCreed.h"
#include "step1.h"
#include "step2.h"
#include "step3.h"
#include "step4.h"
#include "step5.h"
#include "step6.h"
#include "step7.h"
#include "step8.h"
#include "step9.h"
#include "step10.h"
#include "step11.h"
#include "step12.h"
#include "step13.h"
#include "step14.h"
#include "step15.h"
#include "step16.h"
#include "step17.h"
#include "step18.h"
#include "step19.h"
#include "GlorybeTotheFather.h"
#include "OurFather.h"
#include "SignoftheCross.h"
#include "click.h"
#include "HailMary.h"
#include "HymnMyMothersPrayer.h"
#include "HymnForAlltheSaints.h"
#include "HymnWhatGrace.h"
#include "TheRosaryIs.h"
bool finished = FALSE;
int leap (int year);
//384 count

std::string txtApostlesC_1 = "The Apostles' Creed: I believe  in God, the Father almighty,    creator of heaven and earth;    and in Jesus Christ, His only   Son, our Lord, who was conceivedby the Holy Spirit, born of the Virgin Mary, suffered under     Pontius Pilate, was crucified,  died,and was buried;he descendedinto hell.On the third day he rose again;he ascended into";
std::string txtApostlesC_2 = "heaven, sits at the right hand  of God,The Father Almighty, fromthence he shall come to judge   the quick and the dead. I       believe in the Holy Spirit,the  Holy Catholic Church,the        communion of saints, the        forgiveness of sins, the        resurrection of the body, and   the life everlasting. Amen.";
std::string txtOurFather_1 = "The Our Father:Our Father, Who  art in heaven Hallowed be Thy   Name;Thy kingdom come,Thy will  be done,on earth as it is in    heaven.Give us this day our     daily bread,and forgive us our  trespasses,as we forgive those  who trespass against us;and leadus not into temptation,but      deliver us from evil. Amen.";
std::string txtHailMary_1  = "Hail Mary, full of grace.Our    Lord is with thee.Blessed art   thou among women,and blessed    is the fruit of thy womb Jesus. Holy Mary, Mother of God,pray   for us sinners,now and at the   hour of our death.";
std::string txtGloryBe_1   = "Glory be to the Father,and to   the Son, and to the Holy Spirit.As it was in the beginning,is   now, and ever shall be,world    without end.";
							 
u8 menu_index = 0;//Holds current selection	
u8 menu_extras_index = 0;
u8 score = 0;
u8 health = 100;
u8 lives = 3;
std::string GetDate();

std::string ConvertDayNumToString(int daynum);
std::string GetDayOfWeek();
std::string GetMystery(int indexOfFive);
void StopAllSound();
void wait(int sec);
int GetDayNum(const string &data);
int Room_splash();
int Room_TitleMenu();
int Room_01();
int Room_02();
int Room_03();
int Room_04();
int Room_05();
int Room_06();//fade transition
int Room_07();
int Room_08();
int Room_09();
int Room_10();
int Room_11();
int Room_12();
int Room_13();
int Room_14();
int Room_15();
int Room_16();//Glorybe
int Room_17();
int Room_18();
int Room_19();
int Room_WhatIs();
int Room_Extras();
void DrawMenuButtons();
void FadeAllbgIn();
void FadeAllbgOut();
void RunCredits();
void RunCredits()
{
	//TODO: Calculate center. get string length, /2 - 16
	string credits[22];//(16-(credits[0].length()/2))
	credits[0] = "The RosaryDS";
	credits[1] = "";
	credits[2] = "TheRosaryDS.googlecode.com";
	credits[3] = "";
	credits[4] = "Producer: J.P.Socoloski III";
	credits[5] = "";
	credits[6] = "Lead Designer: J.P.Socoloski III";//32
	credits[7] = "";
	credits[8] = "Programmed by: J.P.Socoloski III";
	credits[9] = "";
	credits[10] = "Title Image: Praying Hands and";
	credits[11] = "Rosary by Gail Rein";
	credits[12] = "";
	credits[13] = "Title Song: My Mother's Prayer";

    int max = 22;
	int i=0;
	for(i=0;i<max;i++)
	{
		PA_InitText(0, 0);
		PA_SetTextCol(1, 0, 0, 0);//Black
		PA_SetTextCol(0, 0, 0, 0);//Black
		for(int x=0;x<max;x++)
		{
			PA_OutputSimpleText(0, (16-(credits[x].length()/2)), (23-i)+x, credits[x].data());
		}
		wait(1);
		PA_WaitForVBL();
	}
	wait(4);
}
void FadeAllbgIn()
{
	// Transition to normal visible background
	for(s8 i = -31; i <= 0; i++)
	{
		PA_SetBrightness(0, i); 
		PA_SetBrightness(1, i); 
		PA_WaitForVBL();		   
	}
}

void FadeAllbgOut()
{
	// Transition to black
	for(s8 i = 0; i > -32; i--)
	{
		PA_SetBrightness(0, i); 
		PA_SetBrightness(1, i); 
		PA_WaitForVBL();		   
	} 
}

void DrawMenuButtons()
{
	PA_DeleteSprite(0,0);
	PA_DeleteSprite(0,1);
	PA_DeleteSprite(0,2);
	PA_DeleteSprite(0,3);
	PA_DeleteSprite(0,4);
	PA_DeleteSprite(0,5);
	//Now DISPLAY the current index
	if(menu_index == 0)
	{
		PA_CreateSprite(0, 1, (void*)startbuttone_Sprite, OBJ_SIZE_64X32, 1, 1, 99, 18);//enabled...
		PA_CreateSprite(0, 2, (void*)whatis_Sprite, OBJ_SIZE_64X32, 1, 2, 99, 63);//disabled...
		PA_CreateSprite(0, 4, (void*)extrasbutton_Sprite, OBJ_SIZE_64X32, 1, 4, 99, 111);//disabled...

	}
	if(menu_index == 1)
	{
		PA_CreateSprite(0, 0, (void*)startbutton_Sprite, OBJ_SIZE_64X32, 1, 0, 99, 18);//disabled...
		PA_CreateSprite(0, 3, (void*)whatise_Sprite, OBJ_SIZE_64X32, 1, 3, 99, 63);//enabled...
		PA_CreateSprite(0, 4, (void*)extrasbutton_Sprite, OBJ_SIZE_64X32, 1, 4, 99, 111);//disabled...
	}
	if(menu_index == 2)
	{
		PA_CreateSprite(0, 0, (void*)startbutton_Sprite, OBJ_SIZE_64X32, 1, 0, 99, 18);//disabled...
		PA_CreateSprite(0, 2, (void*)whatis_Sprite, OBJ_SIZE_64X32, 1, 2, 99, 63);//disabled...
		PA_CreateSprite(0, 5, (void*)extrasbuttone_Sprite, OBJ_SIZE_64X32, 1, 5, 99, 111);//enabled...
	}

}
std::string GetMystery(int indexOfFive)
{
	std::string mystery   = "";
	int daynum = 0;
	daynum = GetDayNum(GetDate());

	if(daynum == 0 || daynum == 3)
	{
		//mystery.append();//(Wednesdays and Sundays)
		switch(indexOfFive)
		{
		case 1:
			mystery.append("The Glorious Mysteries:         The Resurrection                (Matthew 28:1-8, Mark 16:1-18,  Luke 24:1-12, John 20:1-29)     [Faith]");
			break;
		case 2:
			mystery.append("The Glorious Mysteries:         The Ascension                   (Mark 16:19-20, Luke 24:50-53,  Acts 1:6-11) [Christian Hope]");
			break;
		case 3:
			mystery.append("The Glorious Mysteries:         The Descent of the Holy Ghost   (Acts 2:1-13)                   [Gifts of the Holy Spirit]");
			break;
		case 4:
			mystery.append("The Glorious Mysteries:         The Assumption                  [To Jesus through Mary]");
			break;
		case 5:
			mystery.append("The Glorious Mysteries:         The Coronation                  [Grace of Final Perseverance]");
			break;
		}
	}

	if(daynum == 4)
	{
		//mystery.append("The Luminous Mysteries or Mysteries of Light: ");//(Thursdays)
		switch(indexOfFive)
		{
		case 1:
			mystery.append("The Mysteries of Light:         Jesus' Baptism in the Jordan    (II Corinthians 5:21,Matthew 3:17and parallels)                 [Gratitude for the gift of Faith]");
			break;
		case 2:
			mystery.append("The Mysteries of Light:         Jesus' self-manifestation at    the wedding of Cana (John 2:1- 12)[Fidelity]");
			break;
		case 3:
			mystery.append("The Mysteries of Light:         Jesus' proclamation of the      Kingdom of God, with His call to conversion (Mark 1:15,         Mark 2:3-13; Luke 7:47- 48,     John 20:22-23)                  [Desire for Holiness]");
			break;
		case 4:
			mystery.append("The Mysteries of Light:         Jesus' Transfiguration          (Luke 9:35 and parallels)         [Spiritual Courage]");
			break;
		case 5:
			mystery.append("The Mysteries of Light:         Jesus' institution of the       Eucharist, as the sacramental   expression of the Paschal       Mystery. (Luke 24:13-35 and     parallels, 1 Corinthians        11:24-25) [Love of our          Eucharistic Lord]");
			break;
		}
	}
	if(daynum == 2 || daynum == 5)
	{
		//mystery.append("The Sorrowful Mysteries: ");//(Tuesdays and Fridays)
		switch(indexOfFive)
		{
		case 1:
			mystery.append("The Sorrowful Mysteries:        The Agony in the Garden         (Matthew 26:36-46,Luke 22:39-46) [God's will be done]");
			break;
		case 2:
			mystery.append("The Sorrowful Mysteries:        The Scourging at the Pillar     (Matthew 27:26,Mark 15:15,John19:1)                             [Mortification of the senses]");
			break;
		case 3:
			mystery.append("The Sorrowful Mysteries:        The Crowning with Thorns        (Matthew 27:27-30,Mark 15:16-20,John 19:2) [Reign of Christ     in our heart]");
			break;
		case 4:
			mystery.append("The Sorrowful Mysteries:        The Carrying of the Cross       (Matthew 27:31-32, Mark 15:21,  Luke 23:26-32, John 19:17)      [Patient bearing of trials]");
			break;
		case 5:
			mystery.append("The Sorrowful Mysteries:        The Crucifixion                 (Matthew 27:33-56,Mark 15:22-39,Luke 23:33-49, John 19:17-37)   [Pardoning of Injuries]");
			break;
		}
	}
	if(daynum == 1 || daynum == 6)
	{
		//mystery.append("The Joyful Mysteries: ");//(Mondays and Saturdays)
		switch(indexOfFive)
		{
		case 1:
			mystery.append("The Joyful Mysteries:           The Annunciation                (Luke 1:26-38) [Humility]");
			break;
		case 2:
			mystery.append("The Joyful Mysteries:           The Visitation                  (Luke 1: 39-56)                  [Love of Neighbor]");
			break;
		case 3:
			mystery.append("The Joyful Mysteries:           The Nativity                    (Luke 2:1-20)                    [Poverty of Spirit]");
			break;
		case 4:
			mystery.append("The Joyful Mysteries:           The Presentation                (Luke 2:21-38)                   [Purity of mind & body]");
			break;
		case 5:
			mystery.append("The Joyful Mysteries:           The Finding of Jesus in the     Temple (Luke 2:41-52)            [Obedience ]");
			break;
		}
	}
	//mystery = ConvertDayNumToString(daynum);
	return mystery;
}
std::string GetDayOfWeek()
{
	return ConvertDayNumToString(GetDayNum(GetDate()));
}
int GetDayNum(const string &data)
{
	int month,day,year,dm,dn,leap;

	stringstream buffer(data.substr(0,2));
	buffer >> month;

	stringstream buffer2(data.substr(3,5));
	buffer2 >> day;

	stringstream buffer3(data.substr(6,8));
	buffer3 >> year;
	//PA_OutputText(1, 2, 18, "%02d/%02d/%02d", month, day, year);
     int CalendarSystem = 1; //1 for Gregorian Calendar//0=Julian Calendar//http://everything2.com
     if (month < 3)
     {
           month = month + 12;
           year = year - 1;
     }
     return (
             day
             + (2 * month)
             + int(6 * (month + 1) / 10)
             + year
             + int(year / 4)
             - int(year / 100)
             + int(year / 400)
             + CalendarSystem
            ) % 7;
}                  

int leap (int year)
{
	if((year%100== 0 && year%400==0)||  (year%4==0))

		return 1;
	else
		return 0;
}

std::string GetDate(void)
{
	// convert MM/DD/YY into a string
    std::string Date = "";
	char datechar[9];
	sprintf(datechar, "%02d/%02d/%02d", PA_RTC.Month, PA_RTC.Day, PA_RTC.Year);
	Date.append(datechar);
	return Date;
}

std::string ConvertDayNumToString(int daynum)
{
	std::string DayOfWeek = "";
	switch(daynum)
	{
	case 0:
		DayOfWeek = "Sunday";
		break;
	case 1:
		DayOfWeek = "Monday";
		break;
	case 2:
		DayOfWeek = "Tuesday";
		break;
	case 3:
		DayOfWeek = "Wednesday";
		break;
	case 4:
		DayOfWeek = "Thursday";
		break;
	case 5:
		DayOfWeek = "Friday";
		break;
	case 6:
		DayOfWeek = "Saturday";
		break;
	}
	return DayOfWeek;
}
void wait(int sec)
{
	int time=0;
	for(time=0;time<60*sec;time++)
	{
		PA_WaitForVBL();
	}
}

int main (void)
{
	PA_Init();
	PA_InitVBL();
	PA_InitText(0, 0);
	PA_InitText(1, 0);
	Room_splash();
}
void ChkForStart()
{
	//This should be called in a loop to go back to Room_TitleMenu
	if(Pad.Newpress.Start)
	{
		StopAllSound();
		Room_TitleMenu();
	}
}
void StopAllSound()
{
	for(int channel = 0; channel < 16; channel++)
	{			
		PA_StopSound(channel);
	}
	PA_WaitForVBL();
}

void ReloadRosaryRoom()
{
	//Reset both screens and the sprites to redraw anything
	PA_ResetBgSys();
	PA_ResetSpriteSys();
	PA_LoadSpritePal(1, 3, (void*)praywithme_Pal);
	PA_LoadSpritePal(0, 3, (void*)praywithme_Pal);
	PA_LoadSpritePal(1, 4, (void*)next_Pal);
	PA_LoadSpritePal(0, 4, (void*)next_Pal);
	PA_EasyBgLoad(1, 2, RosaryTop);
	PA_EasyBgLoad(0, 2, RosaryBottom);
	PA_CreateSprite(0, 0, (void*)praywithme_Sprite, OBJ_SIZE_64X32, 1, 3, 13, 50);
	PA_CreateSprite(0, 1, (void*)next_Sprite, OBJ_SIZE_64X32, 1, 4, 192, 50);
	PA_InitText(0, 0);
	PA_InitText(1, 0);
}
void ReloadRosaryRoomRev()
{
	//Reset both screens and the sprites to redraw anything
	PA_ResetBgSys();
	PA_ResetSpriteSys();
	PA_LoadSpritePal(1, 3, (void*)praywithme_Pal);
	PA_LoadSpritePal(0, 3, (void*)praywithme_Pal);
	PA_LoadSpritePal(1, 4, (void*)next_Pal);
	PA_LoadSpritePal(0, 4, (void*)next_Pal);
	PA_EasyBgLoad(1, 2, RosaryTop);
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_CreateSprite(0, 0, (void*)praywithme_Sprite, OBJ_SIZE_64X32, 1, 3, 13, 50);
	PA_CreateSprite(0, 1, (void*)next_Sprite, OBJ_SIZE_64X32, 1, 4, 192, 50);
	PA_InitText(0, 0);
	PA_InitText(1, 0);
}
int Room_splash(void) 
{
	PA_ResetBgSys();
	PA_ResetSpriteSys();

	AS_SetDefaultSettings(AS_PCM_8BIT, 11025,AS_NO_DELAY);
	PA_InitASLibForMP3(AS_MODE_MP3 | AS_NO_DELAY | AS_MODE_8CH);
	//PA_InitCustomText(1, 0, newfont); 
	//PA_InitCustomText(0, 0, newfont); 

	PA_SetBrightness(0, -31); // all black
	PA_SetBrightness(1, -31); // all black	

	PA_EasyBgLoad(1, 2, JSDSSplash);
	PA_EasyBgLoad(0, 2, JSDSCopyright);

	// Transition to normal visible background
	FadeAllbgIn();

	//== PLAY SPLASH SOUND ==//
	if (finished == FALSE) 
	{
		PA_PlaySimpleSound(jsds_intro);
		finished = TRUE;
	}

	//== WAIT 8 BEFORE MOVING ON ==//
	wait(5);

	// Transition to black
	FadeAllbgOut();

	// Now that it's all black, clean all that and you're ready to go !
	PA_ResetBgSys();
	PA_SetBrightness(0, 0); // normal
	PA_SetBrightness(1, 0); // normal	
	//========= END OF SPLASH SCREEN ===========//

	Room_TitleMenu();
	//Room_18();//DEBUG LINE
	PA_CheckLid();
	PA_WaitForVBL();
	return 0;
}
int Room_TitleMenu(void) 
{
	PA_ResetBgSys();
	PA_ResetSpriteSys();
	//PA_InitCustomText(1, 0, newfont); 
	//PA_InitCustomText(0, 0, newfont); 
	PA_LoadSpritePal(1, 0, (void*)startbutton_Pal);
	PA_LoadSpritePal(0, 0, (void*)startbutton_Pal);
	PA_LoadSpritePal(1, 1, (void*)startbuttone_Pal);
	PA_LoadSpritePal(0, 1, (void*)startbuttone_Pal);
	PA_LoadSpritePal(1, 2, (void*)whatis_Pal);
	PA_LoadSpritePal(0, 2, (void*)whatis_Pal);
	PA_LoadSpritePal(1, 3, (void*)whatise_Pal);
	PA_LoadSpritePal(0, 3, (void*)whatise_Pal);
	PA_LoadSpritePal(1, 4, (void*)extrasbutton_Pal);
	PA_LoadSpritePal(0, 4, (void*)extrasbutton_Pal);
	PA_LoadSpritePal(1, 5, (void*)extrasbuttone_Pal);
	PA_LoadSpritePal(0, 5, (void*)extrasbuttone_Pal);
	PA_LoadSpritePal(1, 6, (void*)creditsbutton_Pal);
	PA_LoadSpritePal(0, 6, (void*)creditsbutton_Pal);
	PA_LoadSpritePal(1, 7, (void*)creditsbuttone_Pal);
	PA_LoadSpritePal(0, 7, (void*)creditsbuttone_Pal);

	PA_EasyBgLoad(1, 2, RosaryDSTitle);
	PA_EasyBgLoad(0, 2, RosaryDSMenuBkg);
	PA_CreateSprite(0, 1, (void*)startbuttone_Sprite, OBJ_SIZE_64X32, 1, 1, 99, 18);
	PA_CreateSprite(0, 2, (void*)whatis_Sprite, OBJ_SIZE_64X32, 1, 2, 99, 63);
	PA_CreateSprite(0, 4, (void*)extrasbutton_Sprite, OBJ_SIZE_64X32, 1, 4, 99, 111);
	menu_index = 0;//must reset

	//Start room all black and fade in
	PA_SetBrightness(0, -31); // all black
	PA_SetBrightness(1, -31); // all black	
	FadeAllbgIn();

	PA_PlaySimpleSound(HymnMyMothersPrayer);

	while(1) 
	{
		///////////////////////////////////////////////////////////////////////////////////
		//Select the first sprite
		if(Pad.Newpress.Down)
		{
			PA_PlaySimpleSound(click);
			//OBJ_SIZE_64X32
			if(menu_index != 2)
			{
				menu_index = menu_index + 1;
			}
			else
			{
				//menu_index = x so go back to 0
				menu_index = 0;
			}
			DrawMenuButtons();
		}
		if(Pad.Newpress.Up)
		{
			PA_PlaySimpleSound(click);
			if(menu_index != 0)
			{
				menu_index = menu_index - 1;
			}
			else
			{
				if(menu_index == 0)
				{
					//menu_index = 0 so advance to 2
					menu_index = 2;
				}
				else
					menu_index = menu_index - 1;
			}
			DrawMenuButtons();
		}
		///////////////////////////////////////////////////////////////////////////////////
		//Make selection by Stylus...
		if (PA_SpriteTouched(0) || PA_SpriteTouched(1)) 
		{	//menu_index == 0
			StopAllSound();
			// Transition to black
			FadeAllbgOut();
			Room_01();
		}
		if (PA_SpriteTouched(2) || PA_SpriteTouched(3)) 
		{	//menu_index == 1
			StopAllSound();
			Room_WhatIs();
		}
		if (PA_SpriteTouched(4) || PA_SpriteTouched(5)) 
		{	//menu_index == 2
			StopAllSound();
			Room_Extras();
		}

		/////Make selection by A button...
		if(Pad.Newpress.A)
		{
			//Get the menu_index
			if(menu_index == 0)
			{
				StopAllSound();
				// Transition to black
				FadeAllbgOut();
				Room_01();
			}
			if(menu_index == 1)
			{
				StopAllSound();
				Room_WhatIs();
			}
			if(menu_index == 2)
			{
				StopAllSound();
				Room_Extras();
			}
		}

		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_01(void) 
{
	ReloadRosaryRoom();
	int touched = 0;
	// Transition to visible
	FadeAllbgIn();

	//Step1
	PA_PlaySimpleSound(step1);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,5,19,"START->");//First part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtApostlesC_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(TheApostlesCreed);
		}
		
		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			touched = touched + 1;
			//PA_OutputText(0,0,1,"touched : %d", touched);//DEBUGGING
			if(touched >= 2)
			{
				StopAllSound();
				Room_02();
			}
			else
			{
				//Draw RosaryTopMix and new text
				PA_ResetBgSysScreen(1);
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_InitText(1, 0);
				PA_OutputSimpleText(1,0,12, txtApostlesC_2.data());
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_02(void) 
{
	ReloadRosaryRoom();

	//Step2
	PA_PlaySimpleSound(step2);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,12,15,"2->");//2nd part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtOurFather_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(OurFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_03();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_03(void) 
{
	ReloadRosaryRoom();
	int touched = 0;

	//Step3
	PA_PlaySimpleSound(step3);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,13,13,"3->");//3rd part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			//3 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,13,12,"3->");//3rd part of rosary
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,13,10,"3->");//3rd part of rosary
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				Room_04();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_04(void) 
{
	ReloadRosaryRoom();

	//Step4
	PA_PlaySimpleSound(step4);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,13,9,"4->");//2nd part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_05();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}


int Room_05(void) 
{
	ReloadRosaryRoom();
	int touched = 0;

	//Step5
	PA_PlaySimpleSound(step5);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,12,8,"5->");//5th part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, GetDayOfWeek().data());
	PA_OutputSimpleText(1,0,13, GetMystery(1).data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			//Draw RosaryTopMix and new text
			PA_EasyBgLoad(1, 2, RosaryTopMix);
			PA_OutputSimpleText(1,0,12, txtOurFather_1.data());
			PA_PlaySimpleSound(OurFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			touched = touched + 1;
			if(touched == 1)
			{
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtOurFather_1.data());
			}
			if(touched == 2)
			{
				Room_06();
			}

		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_06(void) 
{
	ReloadRosaryRoom();
	int touched = 0;

	//Step5
	PA_PlaySimpleSound(step6);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,8,5,"6->");//6th part of rosary [1/10]
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			//10 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,7,4,"6->");//5th part of rosary[2/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,6,3,"6->");//6th part of rosary[3/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,5,2,"6->");//6th part of rosary[4/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 4)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,4,1,"6->");//6th part of rosary[5/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 5)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,3,0,"6->");//6th part of rosary[6/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			//TOP SCREEN! 
			if(touched == 6)
			{
				//===TRANSITION===//
				// Transition to black
				FadeAllbgOut();
				PA_ResetBgSys();
				PA_ResetSpriteSys();
				//Redraw everything with textbox on bottom
				ReloadRosaryRoomRev();

				// Transition to normal visible background
				FadeAllbgIn();
				//===TRANSITION===//
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,3,23,"6->");//6th part of rosary[7/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 7)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,2,22,"6->");//6th part of rosary[8/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 8)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,1,21,"6->");//6th part of rosary[9/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 9)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,1,20,"6->");//6th part of rosary[10/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 10)
			{
				StopAllSound();//Stop duplicate plays
				Room_07();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_07(void) 
{
	ReloadRosaryRoomRev();
	//Step7
	PA_PlaySimpleSound(step7);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,1,19,"7->");//7th part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_OutputSimpleText(0,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_08();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_08(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step8
	PA_PlaySimpleSound(step8);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,0,18,"8->");//8th part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_OutputSimpleText(0,0,12, GetDayOfWeek().data());
	PA_OutputSimpleText(0,0,13, GetMystery(2).data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			//Draw RosaryTopMix and new text
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			PA_PlaySimpleSound(OurFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			touched = touched + 1;
			if(touched == 1)
			{
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			}
			if(touched == 2)
			{
				Room_09();
			}

		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_09(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step9
	PA_PlaySimpleSound(step9);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,0,17,"9->");//9th part of rosary [1/10]
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			//10 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,16,"9->");//9th part of rosary[2/10]
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,14,"9->");//9th part of rosary[3/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,13,"9->");//9th part of rosary[4/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 4)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,12,"9->");//9th part of rosary[5/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 5)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,10,"9->");//9th part of rosary[6/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			//TOP SCREEN! 
			if(touched == 6)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,9,"9->");//9th part of rosary[7/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 7)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,0,8,"9->");//9th part of rosary[8/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 8)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,1,7,"9->");//9th part of rosary[9/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 9)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,1,6,"9->");//9th part of rosary[10/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 10)
			{
				StopAllSound();//Stop duplicate plays
				Room_10();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_10(void) 
{
	ReloadRosaryRoomRev();

	//Step10
	PA_PlaySimpleSound(step10);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,1,5,"10->");//10th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_11();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_11(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step10
	PA_PlaySimpleSound(step11);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,1,4,"11->");//11th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, GetDayOfWeek().data());
	PA_OutputSimpleText(0,0,13, GetMystery(3).data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			//Draw RosaryBottomMix and new text
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			PA_PlaySimpleSound(OurFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			touched = touched + 1;
			if(touched == 1)
			{
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			}
			if(touched == 2)
			{
				Room_12();
			}

		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_12(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step9
	PA_PlaySimpleSound(step12);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,2,3,"12->");//12th part of rosary [1/10]
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			//10 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,4,2,"12->");//9th part of rosary[2/10]
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryTopMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,6,2,"12->");//9th part of rosary[3/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,8,1,"12->");//9th part of rosary[4/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 4)
			{
				//Finished with prayers
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,10,0,"12->");//9th part of rosary[5/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 5)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,13,0,"12->");//9th part of rosary[6/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			//TOP SCREEN! 
			if(touched == 6)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,20,1,"<-12");//9th part of rosary[7/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 7)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,22,1,"<-12");//9th part of rosary[8/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 8)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,24,2,"<-12");//9th part of rosary[9/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 9)
			{
				StopAllSound();//Stop duplicate plays
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,26,3,"<-12");//9th part of rosary[10/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 10)
			{
				StopAllSound();//Stop duplicate plays
				Room_13();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_13(void) 
{
	ReloadRosaryRoomRev();
	//Step13
	PA_PlaySimpleSound(step13);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,26,3,"<-13");//13th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_14();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_14(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step14
	PA_PlaySimpleSound(step14);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,28,4,"<-14");//11th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, GetDayOfWeek().data());
	PA_OutputSimpleText(0,0,13, GetMystery(4).data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			//Draw RosaryBottomMix and new text
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			PA_PlaySimpleSound(OurFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			touched = touched + 1;
			if(touched == 1)
			{
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			}
			if(touched == 2)
			{
				Room_15();
			}

		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_15(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step15
	PA_PlaySimpleSound(step15);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,28,5,"<-15");//12th part of rosary [1/10]
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			//10 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,7,"<-15");//15th part of rosary[2/10]
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				//Draw RosaryTopMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,8,"<-15");//15th part of rosary[3/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,9,"<-15");//15th part of rosary[4/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 4)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,10,"<-15");//15th part of rosary[5/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 5)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,11,"<-15");//15th part of rosary[6/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 6)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,13,"<-15");//15th part of rosary[7/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 7)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,14,"<-15");//15th part of rosary[8/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 8)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,15,"<-15");//15th part of rosary[9/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 9)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,16,"<-15");//15th part of rosary[10/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 10)
			{
				StopAllSound();//Stop duplicate plays
				Room_16();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_16(void) 
{
	ReloadRosaryRoomRev();
	//Step16
	PA_PlaySimpleSound(step16);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,28,17,"<-16");//16th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_17();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}


int Room_17(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step17
	PA_PlaySimpleSound(step17);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,28,18,"<-17");//17th part of rosary
	wait(5);

	//Draw RosaryBottomMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, GetDayOfWeek().data());
	PA_OutputSimpleText(0,0,13, GetMystery(5).data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			//Draw RosaryBottomMix and new text
			PA_EasyBgLoad(0, 2, RosaryBottomMix);
			PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			PA_PlaySimpleSound(OurFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			touched = touched + 1;
			if(touched == 1)
			{
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtOurFather_1.data());
			}
			if(touched == 2)
			{
				Room_18();
			}

		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}

int Room_18(void) 
{
	ReloadRosaryRoomRev();
	int touched = 0;

	//Step18
	PA_PlaySimpleSound(step18);
	PA_SetTextCol(1, 31, 0, 0);//Red
	PA_OutputSimpleText(1,28,19,"<-18");//18th part of rosary [1/10]
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(0, 2, RosaryBottomMix);
	PA_OutputSimpleText(0,0,12, txtHailMary_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y)) 
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(HailMary);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A)) 
		{
			StopAllSound();//Stop duplicate plays
			//10 Hail Marys here
			touched = touched + 1;
			if(touched == 1)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,21,"<-18");//18th part of rosary[2/10]
				//Draw RosaryBottomMix and new text
				PA_EasyBgLoad(0, 2, RosaryBottomMix);
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 2)
			{
				//Draw RosaryTopMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,22,"<-18");//18th part of rosary[3/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 3)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoomRev();
				PA_SetTextCol(1, 31, 0, 0);//Red
				PA_OutputSimpleText(1,28,23,"<-18");//18th part of rosary[4/10]
				PA_OutputSimpleText(0,0,12, txtHailMary_1.data());
			}
			if(touched == 4)
			{
				//===TRANSITION===//
				// Transition to black
				FadeAllbgOut();
				PA_ResetBgSys();
				PA_ResetSpriteSys();
				//Redraw everything with textbox on bottom
				ReloadRosaryRoom();

				// Transition to normal visible background
				FadeAllbgIn();
				//===TRANSITION===//

				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,28,0,"<-18");//18th part of rosary[5/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 5)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,27,1,"<-18");//18th part of rosary[6/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 6)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,26,2,"<-18");//18th part of rosary[7/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 7)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,25,3,"<-18");//18th part of rosary[8/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 8)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,24,4,"<-18");//18th part of rosary[9/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 9)
			{
				//Draw RosaryBottomMix and new text
				ReloadRosaryRoom();
				PA_SetTextCol(0, 31, 0, 0);//Red
				PA_OutputSimpleText(0,23,5,"<-18");//18th part of rosary[10/10]
				//Draw RosaryTopMix and new text
				PA_EasyBgLoad(1, 2, RosaryTopMix);
				PA_OutputSimpleText(1,0,12, txtHailMary_1.data());
			}
			if(touched == 10)
			{
				StopAllSound();//Stop duplicate plays
				Room_19();
			}
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
int Room_19(void) 
{
	ReloadRosaryRoom();
	//Step19
	PA_PlaySimpleSound(step19);
	PA_SetTextCol(0, 31, 0, 0);//Red
	PA_OutputSimpleText(0,22,5,"<-19");//19th part of rosary
	wait(5);

	//Draw RosaryTopMix and new text
	PA_EasyBgLoad(1, 2, RosaryTopMix);
	PA_OutputSimpleText(1,0,12, txtGloryBe_1.data());

	while(1) 
	{
		//If Pray with me touched
		if ((PA_SpriteTouched(0)) || (Pad.Newpress.Y))
		{
			StopAllSound();//Stop duplicate plays
			PA_PlaySimpleSound(GlorybeTotheFather);
		}

		//If Next touched
		if ((PA_SpriteTouched(1)) || (Pad.Newpress.A))
		{
			StopAllSound();//Stop duplicate plays
			Room_TitleMenu();
		}
		ChkForStart();
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}


int Room_WhatIs(void)
{
	//===TRANSITION===//
	// Transition to black
	FadeAllbgOut();
	PA_ResetBgSys();
	PA_ResetSpriteSys();
	//Redraw 
	PA_EasyBgLoad(1, 2, RosaryDSMenuBkg);
	PA_EasyBgLoad(0, 2, RosaryDSMenuBkg);
	PA_InitText(1, 0);
	PA_InitText(0, 0);
	PA_SetTextCol(1, 0, 0, 0);//Black
	PA_SetTextCol(0, 0, 0, 0);//Black

	// Transition to normal visible background
	FadeAllbgIn();
	//===TRANSITION===//

	PA_PlaySimpleSound(TheRosaryIs);
	PA_OutputSimpleText(1, 5, 2, "What is the Rosary?");
	PA_OutputSimpleText(1, 3, 16, "The Rosary is made up of twenty \"mysteries\" (significant events or moments in the life of Jesus and Mary), which, following the Apostolic Letter Rosarium Virginis Mariae, are grouped into four series.");
	PA_OutputSimpleText(0,0,2,"The first contains joyful mysteries (recited on Mondays and Saturdays); the second, the mysteries of light (Thursdays); the third, the sorrowful mysteries (Tuesdays and Fridays); and the fourth, the glorious mysteries (Wednesdays and Sundays).\"This indication is not intended to limit a rightful freedom in personal and community prayer, where account needs to be taken of spiritual and pastoral needs and of the occurrence of particular liturgical celebrations which might call for suitable adaptations.\" (Rosarium Virginis Mariae, 38).");
	PA_OutputSimpleText(0,3,23, "*touch screen to go back*");

	while(1) 
	{
		if(Pad.Newpress.B || Stylus.Newpress)
		{
			StopAllSound();//Stop duplicate plays
			Room_TitleMenu();
		}
	}
}


void DrawExtrasMenu()
{
		if(menu_index == 0)
		{
			PA_OutputSimpleText(1, 6, 6, "* Quotes about the Rosary");
			PA_OutputSimpleText(1, 6, 8, "  Hymns");
			PA_OutputSimpleText(1, 6, 10, "  Credits");
		}
		if(menu_index == 1)
		{
			PA_OutputSimpleText(1, 6, 6, "  Quotes about the Rosary");
			PA_OutputSimpleText(1, 6, 8, "* Hymns");
			PA_OutputSimpleText(1, 6, 10, "  Credits");
		}
		if(menu_index == 2)
		{
			PA_OutputSimpleText(1, 6, 6, "  Quotes about the Rosary");
			PA_OutputSimpleText(1, 6, 8, "  Hymns");
			PA_OutputSimpleText(1, 6, 10, "* Credits");
		}
		PA_OutputSimpleText(1, 0, 23, "(press Up/Down then A to select)");//directions
		//PA_WaitForVBL();//causes delays
}
void DrawHymnsMenu()
{
		if(menu_extras_index == 0)
		{
			PA_OutputSimpleText(0, 6, 6,  "* For All the Saints");
			PA_OutputSimpleText(0, 6, 8,  "  My Mother's Prayer");
			PA_OutputSimpleText(0, 6, 10, "  What Grace, O Lord, and          Beauty Shone");
		}
		if(menu_extras_index == 1)
		{
			PA_OutputSimpleText(0, 6, 6,  "  For All the Saints");
			PA_OutputSimpleText(0, 6, 8,  "* My Mother's Prayer");
			PA_OutputSimpleText(0, 6, 10, "  What Grace, O Lord, and          Beauty Shone");
		}
		if(menu_extras_index == 2)
		{
			PA_OutputSimpleText(0, 6, 6,  "  For All the Saints");
			PA_OutputSimpleText(0, 6, 8,  "  My Mother's Prayer");
			PA_OutputSimpleText(0, 6, 10, "* What Grace, O Lord, and          Beauty Shone");
		}
		PA_WaitForVBL();
}
void DrawQuotesMenu()
{
		PA_InitText(0, 0);
		PA_SetTextCol(0, 0, 0, 0);//Black
		//Quotes about the Rosary
		if(menu_extras_index == 0)
		{
			PA_OutputSimpleText(0, 6, 1,  "* Sister Lucia");
			PA_OutputSimpleText(0, 6, 3,  "  Bishop Hugh Doyle");
			PA_OutputSimpleText(0, 6, 5,  "  Lacordaire");
		}
		if(menu_extras_index == 1)
		{
			PA_OutputSimpleText(0, 6, 1,  "  Sister Lucia");
			PA_OutputSimpleText(0, 6, 3,  "* Bishop Hugh Doyle");
			PA_OutputSimpleText(0, 6, 5,  "  Lacordaire");
		}
		if(menu_extras_index == 2)
		{
			PA_OutputSimpleText(0, 6, 1,  "  Sister Lucia");
			PA_OutputSimpleText(0, 6, 3,  "  Bishop Hugh Doyle");
			PA_OutputSimpleText(0, 6, 5,  "* Lacordaire");
		}
		PA_WaitForVBL();
}
int Room_Extras(void)
{
	//===TRANSITION===//
	// Transition to black
	FadeAllbgOut();
	PA_ResetBgSys();
	PA_ResetSpriteSys();
	//Redraw 
	PA_EasyBgLoad(1, 2, RosaryDSMenuBkg);
	PA_EasyBgLoad(0, 2, RosaryDSMenuBkg);
	PA_InitText(1, 0);
	PA_InitText(0, 0);
	PA_SetTextCol(1, 0, 0, 0);//Black
	PA_SetTextCol(0, 0, 0, 0);//Black

	// Transition to normal visible background
	FadeAllbgIn();
	//===TRANSITION===//
	menu_index = 0;
	string cntrstrs[10];//(16-(cntrstrs[0].length()/2))
	cntrstrs[0] = "EXTRAS";
	//cntrstrs[1] = ;

	while(1) 
	{
		PA_InitText(1, 0);
		PA_InitText(0, 0);
		PA_SetTextCol(1, 0, 0, 0);//Black
		PA_SetTextCol(0, 0, 0, 0);//Black
		PA_OutputSimpleText(1, (16-(cntrstrs[0].length()/2)), 2, cntrstrs[0].data());//Extras
		DrawExtrasMenu();

		///////////////////////////////////////////////////////////////////////////////////
		//Go back to mainmenu
		if(Pad.Newpress.B || Pad.Newpress.Start)
		{
			StopAllSound();//Stop duplicate plays
			Room_TitleMenu();
		}
		//Select the first sprite
		if(Pad.Newpress.Down)
		{
			PA_PlaySimpleSound(click);
			if(menu_index != 2)
			{
				menu_index = menu_index + 1;
			}
			else
			{
				//menu_index = x so go back to 0
				menu_index = 0;
			}
			DrawExtrasMenu();
		}
		if(Pad.Newpress.Up)
		{
			PA_PlaySimpleSound(click);
			if(menu_index != 0)
			{
				menu_index = menu_index - 1;
			}
			else
			{
				if(menu_index == 0)
				{
					//menu_index = 0 so advance to 2
					menu_index = 2;
				}
				else
					menu_index = menu_index - 1;
			}
			DrawExtrasMenu();
		}
		if(Pad.Newpress.A)
		{
			PA_PlaySimpleSound(click);
			if(menu_index == 0)
			{
				//=======Quotes about the Rosary
				DrawQuotesMenu();
				menu_extras_index = 0;
				//Stay in this menu
				while(1)
				{
					if(Pad.Newpress.Down)
					{
						PA_PlaySimpleSound(click);
						if(menu_extras_index != 2)
						{
							menu_extras_index = menu_extras_index + 1;
						}
						else
						{
							//menu_extras_index = x so go back to 0
							menu_extras_index = 0;
						}
						DrawQuotesMenu();
					}
					if(Pad.Newpress.Up)
					{
						PA_PlaySimpleSound(click);
						if(menu_extras_index != 0)
						{
							menu_extras_index = menu_extras_index - 1;
						}
						else
						{
							if(menu_extras_index == 0)
							{
								//menu_extras_index = 0 so advance to 2
								menu_extras_index = 2;
							}
							else
								menu_extras_index = menu_extras_index - 1;
						}
						DrawQuotesMenu();
					}
					if(Pad.Newpress.A)
					{
						StopAllSound();
						if(menu_extras_index == 0)
						{
							//Sister Lucia
							PA_OutputSimpleText(0, 0, 8,  "--------------------------------");
							PA_OutputSimpleText(0, 0, 9,"\"My impression is that the      Rosary is of the greatest value not only according to the words of Our Lady of Fatima, but      according to the effects of the Rosary one sees throughout      history. My impression is that  Our Lady wanted to give ordinarypeople, who might not know how  to pray, this simple  method of getting closer to God.\" -Sister Lucia, one of the seers of      Fatima");
						}
						if(menu_extras_index == 1)
						{
							//Bishop Hugh Doyle
							PA_OutputSimpleText(0, 0, 8,  "--------------------------------");
							PA_OutputSimpleText(0, 0, 9,"\"No one can live continually in sin and continue to say the     Rosary: either they will give upsin or they will give up the    Rosary.\" -Bishop Hugh Doyle");
						}
						if(menu_extras_index == 2)
						{
							//Lacordaire
							PA_OutputSimpleText(0, 0, 8,  "--------------------------------");
							PA_OutputSimpleText(0, 0, 9,"\"For Christians, the first of   books is the Gospel and the     Rosary is actually the          abridgement of the Gospel.\"     -Lacordaire");
						
						}
					}
					//Go back to mainmenu
					if(Pad.Newpress.B || Pad.Newpress.Start)
					{
						StopAllSound();//Stop duplicate plays
						//erase menu text
						PA_InitText(0, 0);
						PA_SetTextCol(0, 0, 0, 0);//Black
						break;
					}
				}
			}
			if(menu_index == 1)
			{
				//========Hymns
				menu_extras_index = 0;
				DrawHymnsMenu();
				//Stay in this menu
				while(1)
				{
					if(Pad.Newpress.Down)
					{
						PA_PlaySimpleSound(click);
						if(menu_extras_index != 2)
						{
							menu_extras_index = menu_extras_index + 1;
						}
						else
						{
							//menu_extras_index = x so go back to 0
							menu_extras_index = 0;
						}
						DrawHymnsMenu();
					}
					if(Pad.Newpress.Up)
					{
						PA_PlaySimpleSound(click);
						if(menu_extras_index != 0)
						{
							menu_extras_index = menu_extras_index - 1;
						}
						else
						{
							if(menu_extras_index == 0)
							{
								//menu_extras_index = 0 so advance to 2
								menu_extras_index = 2;
							}
							else
								menu_extras_index = menu_extras_index - 1;
						}
						DrawHymnsMenu();
					}
					if(Pad.Newpress.A)
					{
						StopAllSound();
						if(menu_extras_index == 0)
						{
							//PA_OutputSimpleText(0, 6, 6,  "* For All the Saints");
							PA_PlaySimpleSound(HymnForAlltheSaints);
						}
						if(menu_extras_index == 1)
						{
							//PA_OutputSimpleText(0, 6, 8,  "* My Mother's Prayer");
							PA_PlaySimpleSound(HymnMyMothersPrayer);
						}
						if(menu_extras_index == 2)
						{
							//PA_OutputSimpleText(0, 6, 10, "* What Grace, O Lord, and Beauty Shone");
							PA_PlaySimpleSound(HymnWhatGrace);
						}
					}
					//Go back to mainmenu
					if(Pad.Newpress.B || Pad.Newpress.Start)
					{
						StopAllSound();//Stop duplicate plays
						//erase menu text
						PA_InitText(0, 0);
						PA_SetTextCol(0, 0, 0, 0);//Black
						break;
					}
				}
			}
			if(menu_index == 2)
			{	//======Credits
				PA_PlaySimpleSound(HymnWhatGrace);
				RunCredits();
			}
		}
		PA_CheckLid();
		PA_WaitForVBL();
	}
	return 0;
}
