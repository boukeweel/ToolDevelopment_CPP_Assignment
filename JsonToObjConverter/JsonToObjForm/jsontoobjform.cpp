#include "jsontoobjform.h"
#include "./ui_jsontoobjform.h"

JsonToObjForm::JsonToObjForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JsonToObjForm)
{
    ui->setupUi(this);

    connect(ui->OpenJsonFile, &QPushButton::clicked, this, &JsonToObjForm::OpenJsonFile);
    connect(ui->OpenobjPath, &QPushButton::clicked, this, &JsonToObjForm::OpenObjFilePath);
    connect(ui->CancelButton, &QPushButton::clicked, this, &JsonToObjForm::Cancel);
    connect(ui->OkButton, &QPushButton::clicked, this, &JsonToObjForm::Ok);
}

void JsonToObjForm::OpenJsonFile()
{
    QString jsonPath = QFileDialog::getOpenFileName(this, tr("Open Json File"),"",tr("Json Files (*.json)"));

    if(!jsonPath.isEmpty()){

        ui->JsonFile->setText(jsonPath);

        jsonFilePath = jsonPath;
    }


}

void JsonToObjForm::OpenObjFilePath()
{
    QString directoryPath = QFileDialog::getExistingDirectory(this, tr("Select Directory"), "", QFileDialog::ShowDirsOnly);

    // Check if a directory was selected
    if (!directoryPath.isEmpty()) {

        ui->OutputPathText->setText(directoryPath);

        OutObjPath = directoryPath;
    }
}

void JsonToObjForm::Ok()
{
    ObjName = ui->NameObj->toPlainText();

    if(OutObjPath.isEmpty()){
        ui->CreationOk->setText("creation failed please set a output path");
    }
    if(jsonFilePath.isEmpty()){
        ui->CreationOk->setText("creation failed please Select a input file");
    }

    //creation of file
}

void JsonToObjForm::Cancel(){
    OutObjPath = "";
    jsonFilePath = "";
    ObjName = "";

    ui->OutputPathText->setText("Output Path");
    ui->JsonFile->setText("Input path");
    ui->NameObj->setText("obj_Name");
}

JsonToObjForm::~JsonToObjForm()
{
    delete ui;
}
