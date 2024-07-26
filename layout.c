#include<stdio.h>
#include<string.h>

typedef struct{
  int x;
  int y;
  int width;
  int height;
}Rect;

//define the screen buffer
#define SCREEN_HEIGHT     25 
#define SCREEN_WIDTH      81
static char screens[SCREEN_HEIGHT +1][SCREEN_WIDTH + 1];

void screenInit(void)
{
  int i, j;
  for(i = 0; i<SCREEN_HEIGHT; i++)
    for(j = 0; j<SCREEN_WIDTH; j++){
      screens[i][j] = '.'; 
    }    
}

void printRect(const char* pstrs, Rect xrect)
{
  int i, line, strlenth;
  
  for(i = 0; i < xrect.width; i++){
    if(xrect.x + i < SCREEN_WIDTH && xrect.y < SCREEN_HEIGHT)
      screens[xrect.y][xrect.x + i] = '-';
    
    if(xrect.x + i < SCREEN_WIDTH && xrect.y + xrect.height -1 < SCREEN_HEIGHT)
      screens[xrect.y + xrect.height][xrect.x +i] = '-'; 
  } 

  for(i = 0; i < xrect.height; i++){
    if(xrect.y + i < SCREEN_HEIGHT && xrect.x < SCREEN_WIDTH)
      screens[xrect.y + i][xrect.x] = '|';

    if(xrect.y + i < SCREEN_HEIGHT && xrect.x + xrect.width -1 < SCREEN_WIDTH)
      screens[xrect.y + i][xrect.x + xrect.width] = '|';
  }

  if(xrect.x < SCREEN_WIDTH && xrect.y < SCREEN_HEIGHT)
    screens[xrect.y][xrect.x] = '+';
  if(xrect.x + xrect.width < SCREEN_WIDTH && xrect.y < SCREEN_HEIGHT)
    screens[xrect.y][xrect.x + xrect.width] = '+';
  if(xrect.x < SCREEN_WIDTH && xrect.y + xrect.height < SCREEN_HEIGHT)
    screens[xrect.y + xrect.height][xrect.x] = '+';
  if(xrect.x + xrect.width < SCREEN_WIDTH && xrect.y + xrect.height < SCREEN_HEIGHT)
    screens[xrect.y + xrect.height][xrect.x + xrect.width] = '+';
  
  line = 1;  
  strlenth = strlen(pstrs);  
  for(i = 0; i < strlenth; i++){
    if(i > xrect.width-2)
      line += 1;
    screens[xrect.y + line][xrect.x + (i>xrect.width - 2?i-xrect.width - 1:i) + 1] = *pstrs;
    pstrs++;
  }  
}

void printScreen()
{
  int i, j;

  for(i = 0; i < SCREEN_HEIGHT; i++){
    for(j = 0; j < SCREEN_WIDTH; j++){
      putchar(screens[i][j]);
    }
    putchar('\n');
  }
}


int main(void)
{
  int totalwidth = 80;
  int totalheight = 24;
  int upperHeight = totalheight *5/8;
  int lowerHeight = totalheight - upperHeight;
  int tactileHeight = upperHeight*3/4;

  Rect xMemory = {0, 0, totalwidth/4, upperHeight};
  Rect xEyes = {totalwidth/4, 0, totalwidth/2, upperHeight};
  Rect xSkins = {totalwidth*3/4, 0, totalwidth/4, tactileHeight};
  Rect xNose = {xSkins.x, tactileHeight, totalwidth/4, upperHeight/4 + 1}; 
  Rect xBodys = {0, upperHeight, totalwidth/4, lowerHeight};
  Rect xActions = {totalwidth/4, upperHeight, totalwidth/4, lowerHeight};
  Rect xEars = {totalwidth/2, upperHeight, totalwidth/2, lowerHeight};

  screenInit();
  
  printRect("Memory", xMemory);
  printRect("Eyes", xEyes);
  printRect("Skins", xSkins);
  printRect("xNose", xNose);
  printRect("xBodys", xBodys);
  printRect("xActions", xActions);
  printRect("xEars", xEars);
 
  printScreen();

  return 0;
}








 
