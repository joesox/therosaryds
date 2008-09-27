#ifndef __COLLISIONS__
#define __COLLISIONS__
#include <PA9.h>

bool spritecollide(bool screen,int sprite1,int sprite2){
//grab sprite demensions (center positions and length and width)
  u8 w1=PA_GetSpriteLx(screen, sprite1);
  u8 h1=PA_GetSpriteLy(screen, sprite1);
  u8 x1=(PA_GetSpriteX(screen, sprite1)+(w1/2));
  u8 y1=(PA_GetSpriteY(screen, sprite1)+(h1/2));
  
  u8 w2=PA_GetSpriteLx(screen, sprite2);
  u8 h2=PA_GetSpriteLy(screen, sprite2);
  u8 x2=(PA_GetSpriteX(screen, sprite2)+(w2/2));
  u8 y2=(PA_GetSpriteY(screen, sprite2)+(h2/2));
  
  return (((x2 >= x1 - (w1 + w2)/2) && (x2 <= x1 + (w1 + w2)/2) && (y2 >= y1 - (h1 + h2)/2) && (y2 <= y1 + (h1 + h2)/2)));   
}
void spritebgcollide(bool screen,int bglayer,s32 sprite){

  s8 playerwidth=PA_GetSpriteLx(screen, sprite);
  s8 playerheight=PA_GetSpriteLy(screen, sprite);
  s16 playerx=PA_GetSpriteX(screen, sprite);
  s16 playery=PA_GetSpriteY(screen, sprite);
  int y;
  int x;
  for(y=0;y<playerheight;y++){ 
    for(x=1;x<playerwidth-1;x++){
      if(PA_EasyBgGetPixel(screen,bglayer,playerx+x,playery))playery++;//top of sprite
      else if(PA_EasyBgGetPixel(screen,bglayer,playerx+x,playery+playerheight))playery--;//bottom of sprite
      else if(PA_EasyBgGetPixel(screen,bglayer,playerx,playery+y))playerx++; //left side of sprite
      else if(PA_EasyBgGetPixel(screen,bglayer,playerx+playerwidth,playery+y))playerx--;//right side of sprite
    }
  }   
  PA_SetSpriteXY(screen,sprite,playerx,playery);
}
  
#endif
