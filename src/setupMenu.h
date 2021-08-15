#include "globals.h"

#include "DisplayButton.h"
#include "DisplayPage.h"
#include "DisplayMenu.h"
#include "editpagesetup.h"

#define EDIT_TEXT_HOT_VALVE "Hot valve opening"
#define EDIT_TEXT_COLD_VALVE "Cold valve opening"
#define EDIT_TEXT_DRAIN_VALVE "DRAIN valve opening"
#define EDIT_TEXT_DESIRED_TEMPAERATE_VALVE "Desired temperature"

#define PAGE_INDEX_MAINMENU 0
#define PAGE_INDEX_CONNECTION 1
#define PAGE_INDEX_START 2
#define PAGE_INDEX_EDITVALUE 3
#define PAGE_INDEX_VALVES 4
#define PAGE_INDEX_SYSTEM 5

void onDrawLabelLinkedFloat(DisplayLabel *pLabelToBeDrawn)
{
  String val = String(*pLabelToBeDrawn->getLinkedValue(), 2);

  pLabelToBeDrawn->setText(val);
}

void onDrawHotValveButton(DisplayButton *pButton)
{
  String str = String(water.getHotValveFlow(), 3);
  pButton->setText(str);
}

void onDrawFillButton(DisplayButton *pButton)
{
  String text = pButton->getText();
  bool fillingText = water.isStopped() || water.isDraining();
  pButton->_values.fillColor = fillingText? TFT_GREEN : TFT_YELLOW;
  pButton->_values.textColor = fillingText? TFT_GOLD: TFT_RED;
  if (fillingText)
  {
    if (text != "Fill")
    {
      pButton->setText("Fill", true);
    }
  }
  else
  {
    if (text != "Stop")
    {
      pButton->setText("Stop", true);
    }
  }

}

void onDrawColdValveButton(DisplayButton *pButton)
{
  String str = String(water.getColdValveFlow(), 3);
  pButton->setText(str);
}

void onDrawDrainValveButton(DisplayButton *pButton)
{
  String str = String(water.getDrainValveFlow(), 3);
  pButton->setText(str);
}


void onButtonFillPressed(DisplayButton *btn)
{
  
  if (water.isFlowing()){
    water.stop();
    //btn->setText("Fill",true);
  } else {
    
    water.fillDesired();
    //btn->setText("Stop", true);
  }
}

void onButtonDrainPressed(DisplayButton *btn)
{
  DisplayPage *pPage = btn->getPage();
  water.drain();
  DisplayButton *btnFill = pPage->getButtonByText("Stop");
  //check if the fill button has the correct text
  if (btnFill) {
    btnFill->setText("Fill", true);
  }

}



void onEditedValue(DisplayButton *btn)
{
  Serial.printf("onEditedValue -> %s: %.3f", btn->getLinkedValueName().c_str(), *btn->getLinkedValue());

  if (btn->getLinkedValueName() == EDIT_TEXT_HOT_VALVE)
  {
    water.setHotValveFlow(*btn->getLinkedValue());
    btn->getPage()->getMenu()->showPage(btn->getPageToOpen());
  }
  else if (btn->getLinkedValueName() == EDIT_TEXT_COLD_VALVE)
  {
    water.setColdValveFlow(*btn->getLinkedValue());
    btn->getPage()->getMenu()->showPage(btn->getPageToOpen());
  }
  else if (btn->getLinkedValueName() == EDIT_TEXT_DRAIN_VALVE)
  {
    water.setDrainValveFlow(*btn->getLinkedValue());
    btn->getPage()->getMenu()->showPage(btn->getPageToOpen());
  }
  else if (btn->getLinkedValueName() == EDIT_TEXT_DESIRED_TEMPAERATE_VALVE)
  {
    water.setDesiredTemperature(*btn->getLinkedValue());
    btn->getPage()->getMenu()->showPage(btn->getPageToOpen());
  }
}

void onButtonChangeHotValveOpening(DisplayButton *btn)
{
  DisplayMenu *pMenu = btn->getPage()->getMenu();
  DisplayButton *valueButton = pMenu->getPage(PAGE_INDEX_EDITVALUE)->getLastButton();
  valueButton->setPageToOpen(pMenu->getPage(PAGE_INDEX_VALVES));
  editTempValue = water.getHotValveFlow();
  valueButton->setLinkToValue(&editTempValue, EDIT_TEXT_HOT_VALVE);
  valueButton->registerOnButtonPressedEvent(onEditedValue);
  pMenu->showPage(PAGE_INDEX_EDITVALUE);
}

void onButtonChangeColdValveOpening(DisplayButton *btn)
{
  DisplayMenu *pMenu = btn->getPage()->getMenu();
  DisplayButton *valueButton = pMenu->getPage(PAGE_INDEX_EDITVALUE)->getLastButton();
  valueButton->setPageToOpen(pMenu->getPage(PAGE_INDEX_VALVES));
  editTempValue = water.getColdValveFlow();
  valueButton->setLinkToValue(&editTempValue, EDIT_TEXT_COLD_VALVE);
  valueButton->registerOnButtonPressedEvent(onEditedValue);
  pMenu->showPage(PAGE_INDEX_EDITVALUE);
}
void onButtonChangeDrainValveOpening(DisplayButton *btn)
{
  DisplayMenu *pMenu = btn->getPage()->getMenu();
  DisplayButton *valueButton = pMenu->getPage(PAGE_INDEX_EDITVALUE)->getLastButton();
  valueButton->setPageToOpen(pMenu->getPage(PAGE_INDEX_VALVES));
  editTempValue = water.getDrainValveFlow();
  valueButton->setLinkToValue(&editTempValue, EDIT_TEXT_DRAIN_VALVE);
  valueButton->registerOnButtonPressedEvent(onEditedValue);
  pMenu->showPage(PAGE_INDEX_EDITVALUE);
}
void onButtonChangeDesiredTemperature(DisplayButton *btn)
{
  DisplayMenu *pMenu = btn->getPage()->getMenu();
  DisplayButton *valueButton = pMenu->getPage(PAGE_INDEX_EDITVALUE)->getLastButton();
  valueButton->setPageToOpen(pMenu->getPage(PAGE_INDEX_START));
  editTempValue = water.getDesiredTemperature();
  valueButton->setLinkToValue(&editTempValue, EDIT_TEXT_DESIRED_TEMPAERATE_VALVE);
  valueButton->registerOnButtonPressedEvent(onEditedValue);
  pMenu->showPage(PAGE_INDEX_EDITVALUE);
}


void onButtonStartScan(DisplayButton *btn)
{
  bool startScan = btn->getText() == "Scan system";
  DisplayPage *pPage = btn->getPage();
  DisplayButton *pMenuBtn = pPage->getButtonByText("Menu");
  if (startScan)
  {
    water.startRecordingSystem();
    // should disable the menu button when running system scan
    pMenuBtn->hide();
    btn->setText("Stop scan", true);
    pPage->getLastLabel()->setText("Scanning system", true);
  }
  else
  {
    // should enable the menu button when not running system scan
    water.stopRecordingSystem();
    pMenuBtn->show();
    btn->setText("Scan system", true);
    pPage->getLastLabel()->setText("Scanning system canceled", true);
  }
}

void onShowStartPage(DisplayPage *pPage)
{
  String str = String(water.getDesiredTemperature(), 3);
  DisplayButton *pBtn = pPage->getLastButton();
  pBtn->setText(str);
}


void setupMenu()
{
  const uint16_t buttonWidth = 100;
  const uint16_t buttonMarginX = 10;
  const uint16_t buttonHeight = 50;
  const uint16_t centerHorizontal = (tft.width() - buttonWidth) / 2;
  const uint16_t centerVertical = (tft.height() - buttonHeight) / 2;

  DisplayPage *pMainMenu, *pConnectionPage, *pStartPage, *pValvesPage, *pEditValuePage, *pSystemPage;
  DisplayLabel *pLabel;
  DisplayButton *pButton;
  pMainMenu = menu.addPage();               //adding main menu page  at index 0  = PAGE_INDEX_MAINMENU
  pConnectionPage = menu.addPage();         //adding connection page at index 1  = PAGE_INDEX_CONNECTION
  pStartPage = menu.addPage();              //adding start page page at index 2  = PAGE_INDEX_START
  pEditValuePage = addPageEditValue(&menu); //adding edit value page at index 3  = PAGE_INDEX_EDITVALUE
  pValvesPage = menu.addPage();             //adding valves     page at index 4  = PAGE_INDEX_VALVES
  pSystemPage = menu.addPage();             //adding start page page at index 5  = PAGE_INDEX_SYSTEM

  // Adding labels to pages
  pMainMenu->addPageLabel(centerHorizontal, 0, buttonWidth, buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_YELLOW, 1, "Main menu");
  pMainMenu->addPageLabel(centerHorizontal, tft.height() - buttonHeight, buttonWidth, buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_ORANGE, 1, "Hello world demo");

  //Connection Page
  pConnectionPage->addPageLabel(0, 0, tft.width(), buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_YELLOW, 1, "Connecting to VoffCon", ALIGN_CENTER);
  pConnectionPage->addPageLabel(0, buttonHeight * 1, tft.width(), buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_RED, 1, "", ALIGN_CENTER);
  pConnectionPage->addPageLabel(0, buttonHeight * 2, tft.width(), buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_RED, 1, "yyyy", ALIGN_CENTER);

  //Starting page
  pStartPage->addPageLabel(centerHorizontal, 0, buttonWidth, buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_YELLOW, 1, "Hot tub");
  pStartPage->addPageButton(0, tft.height()-buttonHeight, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Menu", pMainMenu);
  pButton = pStartPage->addFunctionButton(110, tft.height() - buttonHeight, buttonWidth, buttonHeight, TFT_WHITE, TFT_GREEN, TFT_GOLD, 1, "Fill", onButtonFillPressed);
  pButton->registerOnDrawEvent(onDrawFillButton);

  pStartPage->addFunctionButton(110+buttonWidth+10, tft.height() - buttonHeight, buttonWidth, buttonHeight, TFT_WHITE, TFT_GREEN, TFT_GOLD, 1, "Drain", onButtonDrainPressed);
  pStartPage->addPageLabel(15, 103, 60, buttonHeight, pStartPage->getFillColor(), pStartPage->getFillColor(), TFT_GOLD, 1, "Temperature");
  pLabel = pStartPage->addPageLabel(140, 103, 75, buttonHeight, pStartPage->getFillColor(), pStartPage->getFillColor(), TFT_GOLD, 1, "xx");
  pLabel->setLinkToValue(&currentTemperature, "Temperature");
  pLabel->registerOnDrawEvent(onDrawLabelLinkedFloat);
  pStartPage->addPageLabel(15, 139, 139, buttonHeight, pStartPage->getFillColor(), pStartPage->getFillColor(), TFT_GOLD, 1, "Pressure");
  pLabel = pStartPage->addPageLabel(140, 136, 75, buttonHeight, pStartPage->getFillColor(), pStartPage->getFillColor(), TFT_GOLD, 1, "xx");
  pLabel->setLinkToValue(&currentPressure, "Pressure");
  pLabel->registerOnDrawEvent(onDrawLabelLinkedFloat);
  pStartPage->addPageLabel(15, 49, 150, buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_YELLOW, 1, "Desired temperature");
  pButton = pStartPage->addFunctionButton(230, 49, 80,  buttonHeight, pStartPage->getFillColor(), pStartPage->getFillColor(), TFT_RED, 1, "XXXX", onButtonChangeDesiredTemperature);
  pStartPage->registerOnShowEvent(onShowStartPage);

  //add a open page buttons to main menu;
  pMainMenu->addPageButton(30, 50, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Start", menu.getPage(PAGE_INDEX_START));
  pMainMenu->addPageButton(210, 50, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Valves", menu.getPage(PAGE_INDEX_VALVES));
  pMainMenu->addPageButton(210, 150, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "System", menu.getPage(PAGE_INDEX_SYSTEM));

  //Valves page
  pValvesPage->addPageButton(0, tft.height() - buttonHeight, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Menu", pMainMenu);
  pValvesPage->addFunctionButton(1 * (buttonWidth + buttonMarginX), tft.height() - buttonHeight, buttonWidth, buttonHeight, TFT_WHITE, TFT_GREEN, TFT_GOLD, 1, "Fill", onButtonFillPressed);
  pValvesPage->addFunctionButton(2 * (buttonWidth + buttonMarginX), tft.height() - buttonHeight, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Drain", onButtonDrainPressed);
  pValvesPage->addPageLabel(45, 103, 60, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_GOLD, 1, "Temperature");
  pLabel = pValvesPage->addPageLabel(140, 103, 75, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_GOLD, 1, "xx");
  pLabel->setLinkToValue(&currentTemperature, "Temperature");
  pLabel->registerOnDrawEvent(onDrawLabelLinkedFloat);
  pValvesPage->addPageLabel(27, 139, 60, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_GOLD, 1, "Pressure");
  pLabel = pValvesPage->addPageLabel(140, 136, 75, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_GOLD, 1, "xx");
  pLabel->setLinkToValue(&currentPressure, "Pressure");
  pLabel->registerOnDrawEvent(onDrawLabelLinkedFloat);
  pValvesPage->addPageLabel(150, 0, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_GOLD, 1, "Valves");
  pValvesPage->addPageLabel(26, 35, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_WHITE, 1, "Hot");
  pValvesPage->addPageLabel(140, 35, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_WHITE, 1, "Cold");
  pLabel = pValvesPage->addPageLabel(240, 35, 50, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_WHITE, 1, "Drain");
  pButton = pValvesPage->addFunctionButton(0, 67, 100, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_RED, 1, "50.00", onButtonChangeHotValveOpening);
  pButton->registerOnDrawEvent(onDrawHotValveButton);
  pButton = pValvesPage->addFunctionButton(115, 67, 100, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_RED, 1, "100", onButtonChangeColdValveOpening);
  pButton->registerOnDrawEvent(onDrawColdValveButton);
  pButton = pValvesPage->addFunctionButton(215, 67, 100, buttonHeight, pValvesPage->getFillColor(), pValvesPage->getFillColor(), TFT_RED, 1, "0", onButtonChangeDrainValveOpening);
  pButton->registerOnDrawEvent(onDrawDrainValveButton);

  //System page
  pSystemPage->addPageButton(0, 50 - buttonHeight, buttonWidth, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Menu", pMainMenu);
  pSystemPage->addFunctionButton(160, 50 - buttonHeight, buttonWidth * 1.5, buttonHeight, TFT_WHITE, TFT_RED, TFT_GOLD, 1, "Scan system", onButtonStartScan);
  pSystemPage->addPageLabel(0, centerVertical, tft.width(), buttonHeight, pMainMenu->getFillColor(), pMainMenu->getFillColor(), TFT_GOLD, 1, "");

  //this button should be disabled when system scan is on

  //Connect temperature variable to first label

  menu.showPage(pConnectionPage);
}
