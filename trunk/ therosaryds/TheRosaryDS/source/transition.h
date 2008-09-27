#ifndef __TRANSITIONS__
#define __TRANSITIONS__
#define UPDOWN 0
#define FROMCENTER 1
#define DIAGONAL 2
#define LEFTRIGHT 3
#define STARS 4
#define DIAMONDS 0
#define LINES 3



#include <PA9.h>

void transitionin(bool screen, int transtype,int direction,int hflip,int vflip,int speed){//fades back to game

	PA_InitBgTrans(screen);//initialize the screens
	int i;
	switch(direction){
		case 0:
			
			for (i = TRANS_LENGTH; i >= 0; i--) { // Fade length...
				PA_BgTransUpDown(screen,transtype,1, i);
				PA_WaitForVBL(); // To slow down the fades, we wait a frame...
			}
		break;
		case 1:

			for (i = TRANS_LENGTH; i >= 0; i--) { // Fade length...
				PA_BgTransCenter(screen,transtype,1, i);
				PA_WaitForVBL(); // To slow down the fades, we wait a frame...
			}
		break;
		case 2:

			for (i = TRANS_LENGTH; i >= 0; i--) { // Fade length...
				PA_BgTransDiag(screen,transtype,hflip,vflip,i); 
				PA_WaitForVBL(); 
			}
		break;
		case 3:

			for (i = TRANS_LENGTH; i >= 0; i--) { // Fade length...
				PA_BgTransLeftRight(0, transtype, hflip, i);
				PA_WaitForVBL(); 
			}
		break;
	}
		
}
void transitionout(bool screen, int transtype,int direction,int hflip,int vflip,int speed){//fades to black screen

	PA_InitBgTrans(screen);//initialize the screens
	int i;
	switch(direction){
		case 0:

			for (i = 0; i <= TRANS_LENGTH; i++) { 
				PA_BgTransUpDown(screen,transtype,0, i);
				PA_WaitForVBL(); // To slow down the fades, we wait a frame...
			}
		break;
		case 1:

			for (i = 0; i <= TRANS_LENGTH; i++) { 
				PA_BgTransCenter(screen,transtype,0, i);
				PA_WaitForVBL(); // To slow down the fades, we wait a frame...
			}
		break;
		case 2:

			for (i = 0; i <= TRANS_LENGTH; i++) { 
				PA_BgTransDiag(screen,transtype,hflip,vflip,i); 
				PA_WaitForVBL(); 
			}
		break;
		case 3:
			for (i = 0; i <= TRANS_LENGTH; i++) { 
				PA_BgTransLeftRight(0, transtype, hflip, i);
				PA_WaitForVBL(); 
			}
		break;
	}
		
}
#endif
