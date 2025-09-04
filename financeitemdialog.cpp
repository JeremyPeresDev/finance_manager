#include "financeitemdialog.h"
#include "ui_financeitemdialog.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QDate>

FinanceItemDialog::FinanceItemDialog(QDate date, QWidget *parent)
    : QDialog(parent), ui(new Ui::FinanceItemDialog), currentDate(date)
{
    ui->setupUi(this);
    ui->ItemTypeCombobox->addItem("Income");
    ui->ItemTypeCombobox->addItem("Expense");
    connect(ui->ItemCategoryCombobox->lineEdit(), &QLineEdit::editingFinished, this, &FinanceItemDialog::ItemCategoryComboboxEditingFinished);
    this->setWindowTitle(currentDate.toString());
}

FinanceItemDialog::~FinanceItemDialog()
{
    delete ui;
}

// getters
QString FinanceItemDialog::getCategory() const
{
    return ui->ItemCategoryCombobox->currentText();
}

QString FinanceItemDialog::getType() const
{
    return ui->ItemTypeCombobox->currentText();
}

double FinanceItemDialog::getAmount() const
{
    return ui->ItemAmountDoubleSpinbox->value();
}

QString FinanceItemDialog::getDescription() const
{
    return ui->itemDescriptionTextEdit->toPlainText();
}

QString FinanceItemDialog::getSubcategory() const
{
    return ui->ItemSubcategoryCombobox->currentText();
}

bool FinanceItemDialog::getRepeat() const
{
    return ui->ItemRepeatCheckbox->isChecked();
}
// end getters

void FinanceItemDialog::ItemCategoryComboboxEditingFinished()
{
    QString text = ui->ItemCategoryCombobox->currentText();
    qDebug() << "ComboBox editing finished. Text is:" << text;
}

/**
 * @brief load categories inside the combobox
 * @return true if load is without error
 */
bool FinanceItemDialog::LoadCategory()
{
    QSqlQuery query;

    if (!query.exec("SELECT id, category FROM categories")) {
        qDebug() << "Query failed:" << query.lastError().text();
        return false;
    }
    while (query.next())
    {
        QString category = query.value(1).toString();
        ui->ItemCategoryCombobox->addItem(category);
    }

    return true;
}



