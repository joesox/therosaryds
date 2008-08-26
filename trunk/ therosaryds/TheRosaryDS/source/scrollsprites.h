#ifndef __SCROLLSPRI__
#define __SCROLLSPRI__

#include <PA9.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4


int spritescrollx[50];
int spritescrolly[50];

void intscrollsprite(int sprite,int xpos,int ypos){

	//sets sprites off screen
	if(xpos>256)PA_SetSpriteX(0,sprite,288);
	else if(xpos<-32)PA_SetSpriteX(0,sprite,-32);
	if(ypos>192)PA_SetSpriteY(0,sprite,192);
	else if(ypos<-32)PA_SetSpriteY(0,sprite,-32);
	spritescrollx[sprite]=xpos;
	spritescrolly[sprite]=ypos;
	

}


void scrollsprite(int sprite,int direction,int speed){
	int speedx;
	int speedy;
	s32 ypos;
	s32 xpos;

	xpos=spritescrollx[sprite];
	ypos=spritescrolly[sprite];
	

	switch(direction){
		case 0://when bg isn't moving
			if(ypos>=-32 && ypos <=192 && xpos>=-32 && xpos<=256){
				PA_SetSpriteXY(0,sprite,xpos,ypos);
			}
		break;
		case UP:
			speedy=-speed;
			
			if(ypos>=-32 && ypos <=192 && xpos>=-32 && xpos<=256){	
				ypos-=speedy;
				spritescrolly[sprite]=ypos;
				PA_SetSpriteXY(0,sprite,xpos,ypos+2);
			}	
			else{
				ypos-=speedy;
				spritescrolly[sprite]=ypos;
			}
		break;

		case DOWN:
		 	speedy=speed;
			
			if(ypos>=-32 && ypos <=192 && xpos>=-32 && xpos<=256){	
				ypos-=speedy;
				spritescrolly[sprite]=ypos;
				PA_SetSpriteXY(0,sprite,xpos,ypos-2);
			}	
			else{
				ypos-=speedy;
				spritescrolly[sprite]=ypos;
			}
		break;

		case LEFT:
			speedx=-speed;
			
			if(ypos>=-32 && ypos <=192 && xpos>=-32 && xpos<=256){
				xpos-=speedx;
				spritescrollx[sprite]=xpos;
				PA_SetSpriteXY(0,sprite,xpos+2,ypos);
			}
			else {
				xpos-=speedx;
				spritescrollx[sprite]=xpos;
			}
		break;

		case RIGHT:
			speedx=speed;
			
			if(ypos>=-32 && ypos <=192 && xpos>=-32 && xpos<=256){
				xpos-=speedx;
				spritescrollx[sprite]=xpos;
				PA_SetSpriteXY(0,sprite,xpos-2,ypos);
			}
			else {
				xpos-=speedx;
				spritescrollx[sprite]=xpos;
			}
		break;
	}

	direction=0;

}





#endif


