#pragma once

#include"people.h"
#include <QObject>
#include <QFuture>
#include <QString>
#include"backword.h"

class data_process : public QObject {
    Q_OBJECT
public:
    data_process(backword* back, QWidget* parent = nullptr);
private:
    backword* Back;

};
