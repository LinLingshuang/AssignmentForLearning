#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test7.h"

class test7 : public QMainWindow
{
    Q_OBJECT

public:
    test7(QWidget *parent = nullptr);
    ~test7();

private:
    Ui::test7Class ui;
};

