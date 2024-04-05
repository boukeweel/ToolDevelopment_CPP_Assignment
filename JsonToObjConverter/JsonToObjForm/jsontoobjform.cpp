#include "jsontoobjform.h"
#include "./ui_jsontoobjform.h"

JsonToObjForm::JsonToObjForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JsonToObjForm)
{
    ui->setupUi(this);
}

JsonToObjForm::~JsonToObjForm()
{
    delete ui;
}
