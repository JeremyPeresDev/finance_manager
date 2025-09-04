#ifndef FINANCEITEM_H
#define FINANCEITEM_H

#include <QDate>


class FinanceItem
{
public:
    FinanceItem(int id = -1, QDate date = QDate::currentDate(), QString description = "", double amount = 0,
                int categoryId = -1, QString category = "", QString type = "");
private:
    int id;
    QDate date;
    QString description;
    double amount;
    int categoryId;
    QString category;
    QString type;
};

#endif // FINANCEITEM_H
