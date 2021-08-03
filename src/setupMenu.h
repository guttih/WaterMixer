#include "globals.h"

#include "DisplayButton.h"
#include "DisplayPage.h"
#include "DisplayMenu.h"
#include "editpagesetup.h"

#define EDIT_TEXT_HOT_VALVE "Hot valve opening"
#define EDIT_TEXT_COLD_VALVE "Cold valve opening"
#define EDIT_TEXT_DRAIN_VALVE "DRAIN valve opening"

void onDrawLabelLinkedFloat(DisplayLabel *pLabelToBeDrawn)
{
  String val = String(*pLabelToBeDrawn->getLinkedValue(), 2);
  
  pLabelToBeDrawn->setText(val);
}

void onDrawHotValveButton(DisplayButton *pButton) {
    String str = String( water.getHotValve()->getFlow(), 3 );
    //Serial.printf("onDrawHotValveButton:%s", str.c_str());
    pButton->setText( str );
}

void onDrawColdValveButton(DisplayButton *pButton) {
   String str = String( water.getColdValve()->getFlow(), 3 );
    //Serial.printf(" onDrawColdValveButton:%s", str.c_str());
    pButton->setText( str );
}

void onDrawDrainValveButton(DisplayButton *pButton) {
    String str = String( water.getDrainValve()->getFlow(), 3 );
    //Serial.printf(" onDrawDrainValveButton:%s\n", str.c_str());
    pButton->setText( str );
}

void onButtonFillPressed(DisplayButton *btn) {
  water.fill(50, 100);
}

void onButtonDrainPressed(DisplayButton *btn) {
  water.drain();
}

void onEditedValue(DisplayButton *btn) {
  Serial.printf("onEditedValue -> %s: %.3f",btn->getLinkedValueName().c_str(), *btn->getLinkedValue()) ;

  if (btn->getLinkedValueName() == EDIT_TEXT_HOT_VALVE)
  {
    Serial.println(" - Hot - ");
    water.getHotValve()->setFlow(*btn->getLinkedValue());
    btn->getPage()->getMenu()->showPage(btn->getPageToOpen());
  }
  else if (btn->getLinkedValueName() == EDIT_TEXT_COLD_VALVE)
  {
    Serial.println(" - Cold - ");
    water.getColdValve()->setFlow(*btn->getLinkedValue());
    btn->getPage()->getMenu()->showPage(btn->getPageToOpen());
  }
  else if (btn->getLinkedValueName() == EDIT_TEXT_DRAIN_VALVE)
  {
    Serial.println(" - Drain - ");
    water.getDrainValve()->setFlow(*btn->getLinkedValue());
    btn->getPage()->getMenu()->showPage(btn->getPageToOpen());
  }
}

void onButtonChangeHotValveOpening(DisplayButton *btn)
{
  DisplayMenu *pMenu = btn->getPage()->getMenu();
  DisplayButton *valueButton = pMenu->getPage(3)->getLastButton();
  valueButton->setPageToOpen(pMenu->getPage(4));
  editTempValue = water.getHotValve()->getFlow();
  valueButton->setLinkToValue(&editTempValue, EDIT_TEXT_HOT_VALVE);
  valueButton->_values.buttonPressedFunction = onEditedValue;
  pMenu->showPage(3);
}

void onButtonChangeColdValveOpening(DisplayButton *btn) {
  DisplayMenu *pMenu = btn->getPage()->getMenu();
  DisplayButton *valueButton = pMenu->getPage(3)->getLastButton();
  valueButton->setPageToOpen(pMenu->getPage(4));
  editTempValue = water.getColdValve()->getFlow();
  valueButton->setLinkToValue(&editTempValue, EDIT_TEXT_COLD_VALVE);
  valueButton->_values.buttonPressedFunction = onEditedValue;
  pMenu->showPage(3);
}
void onButtonChangeDrainValveOpening(DisplayButton *btn) {
  DisplayMenu *pMenu = btn->getPage()->getMenu();
  DisplayButton *valueButton = pMenu->getPage(3)->getLastButton();
  valueButton->setPageToOpen(pMenu->getPage(4));
  editTempValue = water.getDrainValve()->getFlow();
  valueButton->setLinkToValue(&editTempValue, EDIT_TEXT_DRAIN_VALVE);
  valueButton->_values.buttonPressedFunction = onEditedValue;
  pMenu->showPage(3);
}

void setupMenu() {
  const uint16_t buttonWidth = 100;
  const uint16_t buttonMarginX = 10;
  const uint16_t buttonHeight = 50;
  const uint16_t centerHorizontal = (tft.width() - buttonWidth)/2;
  const uint16_t centerVertical   = (tft.height() - buttonHeight)/2;

  
  DisplayPage *pMainMenu, *pConnectionPage, *pStartPage, *pValvesPage, *pEditValuePage;
  DisplayLabel *pLabel;
  DisplayButton *pButton;
  pMainMenu   = menu.addPage();              //adding page at index 0
  pConnectionPage = menu.addPage();          //adding page at index 1
  pStartPage  = menu.addPage();              //adding page at index 2
  pEditValuePage  = addPageEditValue(&menu); //adding page at index 3
  pValvesPage  = menu.addPage();             //adding page at index 4

  // Adding labels to pages
  pMainMenu->addPageLabel(centerHorizontal, 0, buttonWidth, buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_YELLOW, 1, "Main menu");
  pMainMenu->addPageLabel(centerHorizontal, tft.height()-buttonHeight, buttonWidth, buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_ORANGE, 1, "Hello world demo");
  pConnectionPage->addPageLabel(0, 0, tft.width(), buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_YELLOW, 1, "Connecting to VoffCon");
  pConnectionPage->addPageLabel(0, buttonHeight*1, tft.width(), buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_RED, 1, "");
  pConnectionPage->addPageLabel(0, buttonHeight*2, tft.width(), buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_RED, 1, "yyyy");
  pStartPage->addPageLabel(centerHorizontal, 0, buttonWidth, buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_YELLOW, 1, "Values");


  //add a open page buttons to main menu;
  pMainMenu->addPageButton(centerHorizontal, centerVertical - buttonHeight/1.5, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "StartPage",  menu.getPage(2));
  pMainMenu->addPageButton(centerHorizontal, centerVertical + buttonHeight/1.5, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Valves",  menu.getPage(4));

 
  //add a open main menu button to third page
  pStartPage->addPageButton(centerHorizontal, 50, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Menu",  menu.getPage(0));

  //Valve page
  pValvesPage->addPageButton(0                           ,       tft.height() - buttonHeight, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED,   TFT_GOLD, 1, "Menu",  pMainMenu);
  pValvesPage->addFunctionButton(1*(buttonWidth+buttonMarginX) , tft.height() - buttonHeight, buttonWidth, buttonHeight, TFT_WHITE, TFT_GREEN, TFT_GOLD, 1, "Fill", onButtonFillPressed);
  pValvesPage->addFunctionButton(2*(buttonWidth+buttonMarginX) , tft.height() - buttonHeight, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED,   TFT_GOLD, 1, "Drain", onButtonDrainPressed);
  
  pLabel = pValvesPage->addPageLabel(44, 104, 60, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_GOLD, 1, "Temperature" );
  pLabel = pValvesPage->addPageLabel(140, 104, 60, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_GOLD, 1, "xx" );
  pLabel->setLinkToValue(&currentTemperature, "Temperature");
  pLabel->registerOnDrawEvent(onDrawLabelLinkedFloat);
  
  pLabel =pValvesPage->addPageLabel (26, 139, 60, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_GOLD, 1, "Pressure" );  
  pLabel = pValvesPage->addPageLabel (140, 136, 60, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_GOLD, 1, "xx" );
  pLabel->setLinkToValue(&currentPressure, "Pressure");
  pLabel->registerOnDrawEvent(onDrawLabelLinkedFloat);

  pLabel =pValvesPage->addPageLabel (150 , 0, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_GOLD, 1, "Valves" );  
  pLabel =pValvesPage->addPageLabel (26  , 35, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_WHITE, 1, "Hot" );  
  pLabel =pValvesPage->addPageLabel (140 , 35, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_WHITE, 1, "Cold" );  
  pLabel =pValvesPage->addPageLabel (240 , 35, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_WHITE, 1, "Drain" );  


  pButton =pValvesPage->addFunctionButton (0  , 67, 100, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_RED, 1, "50.00", onButtonChangeHotValveOpening);  
  pButton->registerOnDrawEvent(onDrawHotValveButton);
  pButton =pValvesPage->addFunctionButton (115 , 67, 100, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_RED, 1, "100", onButtonChangeColdValveOpening);  
  pButton->registerOnDrawEvent(onDrawColdValveButton);
  pButton =pValvesPage->addFunctionButton (215 , 67, 100, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_RED, 1, "0", onButtonChangeDrainValveOpening);  
  pButton->registerOnDrawEvent(onDrawDrainValveButton);
  //pLabel =pValvesPage->addPageLabel (26  , 77, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_RED, 1, "0.00" );  
  //pLabel =pValvesPage->addPageLabel (140 , 77, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_RED, 1, "100" );  
  //pLabel =pValvesPage->addPageLabel (240 , 77, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_RED, 1, "50" );  





  //Connect temperature variable to first label



  menu.showPage(pConnectionPage);
}
