#ifndef FINANCEITEMDIALOG_H
#define FINANCEITEMDIALOG_H

#include <QDialog>
#include <qdatetime.h>
#include <qlineedit.h>
#include "ui_financeitemdialog.h"

class FinanceItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FinanceItemDialog(QDate date, QWidget *parent = nullptr);
    ~FinanceItemDialog();
public: //getters
    QString getCategory() const;
    QString getType() const;
    double getAmount() const;
    QString getDescription() const;
    QString getSubcategory() const;
    bool getRepeat() const;

private slots:
    void ItemCategoryComboboxEditingFinished();

private:
    bool LoadCategory();

private:
    Ui::FinanceItemDialog *ui;
    QDate currentDate;
};

#endif // FINANCEITEMDIALOG_H
