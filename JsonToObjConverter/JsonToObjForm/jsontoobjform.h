#ifndef JSONTOOBJFORM_H
#define JSONTOOBJFORM_H

#include <QMainWindow>

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

private:
    Ui::JsonToObjForm *ui;
};
#endif // JSONTOOBJFORM_H
