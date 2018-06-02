#include "dialog.h"
#include "ui_dialog.h"

#include <QGridLayout>

const static double PI = 3.14159;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    label1 = new QLabel(this);
    label1->setText(tr("请输入圆的半径："));
    lineEdit = new QLineEdit(this);
    label2 = new QLabel(this);
    label2->setText(tr(""));
    button = new QPushButton(this);
    button->setText(tr("显示对应圆的面积"));

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(lineEdit,0,1);
    mainLayout->addWidget(label2,1,0);
    mainLayout->addWidget(button,1,1);

    connect(button, SIGNAL(clicked(bool)),this,SLOT(showArea()));
    //connect(lineEdit, SIGNAL(textChanged(QString)),this, SLOT(showArea()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::showArea()
{
    bool ok;
    QString tempStr;
    QString valueStr = lineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * PI;
    label2->setText(tempStr.setNum(area));
}
