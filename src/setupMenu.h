#include "globals.h"

#include "DisplayButton.h"
#include "DisplayPage.h"
#include "DisplayMenu.h"


void setupMenu() {
  const uint16_t buttonWidth = 120;
  const uint16_t buttonHeight = 50;
  const uint16_t centerHorizontal = (tft.width() - buttonWidth)/2;
  const uint16_t centerVertical   = (tft.height() - buttonHeight)/2;

  
  DisplayPage *pMainMenu, *pConnectionPage, *pStartPage;
  pMainMenu   = menu.addPage();   //adding page at index 0
  pConnectionPage = menu.addPage();   //adding page at index 1
  pStartPage  = menu.addPage();   //adding page at index 2

  // Adding labels to pages
  pMainMenu->addPageLabel(centerHorizontal, 0, buttonWidth, buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_YELLOW, 1, "Main menu");
  pMainMenu->addPageLabel(centerHorizontal, tft.height()-buttonHeight, buttonWidth, buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_ORANGE, 1, "Hello world demo");
  pConnectionPage->addPageLabel(0, 0, tft.width(), buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_YELLOW, 1, "Connecting to VoffCon");
  pConnectionPage->addPageLabel(0, buttonHeight*1, tft.width(), buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_RED, 1, "xxxxxxxx");
  pConnectionPage->addPageLabel(0, buttonHeight*2, tft.width(), buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_RED, 1, "yyyy");
  pStartPage->addPageLabel(centerHorizontal, 0, buttonWidth, buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_YELLOW, 1, "Values");


  //add a open page buttons to main menu;
  pMainMenu->addPageButton(centerHorizontal, centerVertical - buttonHeight/1.5, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Page 1",  menu.getPage(1));
  pMainMenu->addPageButton(centerHorizontal, centerVertical + buttonHeight/1.5, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Page 2",  menu.getPage(2));

 
  //add a open main menu button to third page
  pStartPage->addPageButton(centerHorizontal, 50, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Main menu",  menu.getPage(0));
  menu.showPage(pConnectionPage);
}
