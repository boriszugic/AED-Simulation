#include "aedwindow.h"
#include "ui_aedwindow.h"


AEDWindow::AEDWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::AEDWindow){
    ui->setupUi(this);
    controller = new AEDController(this);


    initializeConnects();
}


void AEDWindow::initializeConnects(){

}


AEDController* AEDWindow::getController(){
    return controller;
}
//void AEDWindow::setTestController(TestController *controller){
   // this->controlSystem->setController(controller);
//}

AEDWindow::~AEDWindow(){
    delete ui;
}

