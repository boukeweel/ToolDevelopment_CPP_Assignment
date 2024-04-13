#ifndef JSONTOOBJFORM_H
#define JSONTOOBJFORM_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTableWidget>
#include <QTableWidgetItem>


QT_BEGIN_NAMESPACE
namespace Ui {
class JsonToObjForm;
}
QT_END_NAMESPACE

class JsonToObjForm : public QMainWindow
{
    Q_OBJECT

public:
    JsonToObjForm(QWidget *parent = nullptr);
    ~JsonToObjForm();

private slots:
    void OpenJsonFile();
    void OpenObjFilePath();
    void Cancel();
    void Ok();

private:
    Ui::JsonToObjForm *ui;
    QString jsonFilePath;
    QString OutObjPath;
    QString ObjName;
};
#endif // JSONTOOBJFORM_H
