#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "financeitemdialog.h"
#include <QDialog>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->getAllEntriesFromDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief get all the database data
 * TODO add limit with month as parameter
 * @return true if it succeeded
 */
bool MainWindow::loadDatabaseData()
{
    QSqlQuery query;

    //
    if (!query.exec("SELECT t.id, t.date, t.description, t.amount, t.subcategory_id, t.type, sc.subcategory AS subcategory, c.category AS category "
                    "FROM transactions t "
                    "JOIN subcategories sc ON t.subcategory_id = sc.id "
                    "JOIN categories c ON sc.category_id = c.id"))
    {
        qDebug() << "Query failed:" << query.lastError().text();
        return false;
    }
    while (query.next())
    {
        //QString category = query.value(1).toString();
    }
    return true;
}

/**
 * @brief get id of category, creates it if it does not exists
 * @param categoryName
 * @return category id
 */
int MainWindow::getOrCreateCategory(QString categoryName)
{
    QSqlQuery insertCategory;
    int categoryId = -1;

    //insert category if it does not exists
    insertCategory.prepare("INSERT OR IGNORE INTO categories (category) VALUES (:category)");
    insertCategory.bindValue(":category", categoryName);
    if (!insertCategory.exec())
    {
        qDebug() << "Category Insert failed:" << insertCategory.lastError().text();
        return categoryId;
    }

    //get the id
    QSqlQuery getCategoryId;
    getCategoryId.prepare("SELECT id FROM categories WHERE category = :category");
    getCategoryId.bindValue(":category", categoryName);
    if (getCategoryId.exec() && getCategoryId.next())
    {
        categoryId = getCategoryId.value(0).toInt();
    }
    else
    {
        qDebug() << "Failed to retrieve category ID";
    }

    return categoryId;
}

/**
 * @brief get id of subcategory, creates it if it does not exists
 * @param subcategoryName
 * @param categoryId
 * @return subcategory id
 */
int MainWindow::getOrCreateSubcategory(QString subcategoryName, int categoryId)
{
    QSqlQuery insertSubcategory;
    int subcategoryId = -1;

    //insert category if it does not exists
    insertSubcategory.prepare("INSERT OR IGNORE INTO subcategories (subcategory, category_id) VALUES (:subcategory, :categoryId)");
    insertSubcategory.bindValue(":subcategory", subcategoryName);
    insertSubcategory.bindValue(":categoryId", categoryId);
    if (!insertSubcategory.exec())
    {
        qDebug() << "Subcategory Insert failed:" << insertSubcategory.lastError().text();
        return subcategoryId;
    }

    //get the id
    QSqlQuery getSubcategoryId;
    getSubcategoryId.prepare("SELECT id FROM subcategories WHERE subcategory = :subcategory AND category_id = :categoryId");
    getSubcategoryId.bindValue(":subcategory", subcategoryName);
    getSubcategoryId.bindValue(":categoryId", categoryId);
    if (getSubcategoryId.exec() && getSubcategoryId.next())
    {
        subcategoryId = getSubcategoryId.value(0).toInt();
    }
    else
    {
        qDebug() << "Failed to retrieve subcategory ID";
    }

    return subcategoryId;
}

/**
 * @brief insert new finance entry in db
 * @param date
 * @param amount
 * @param subcategoryId
 * @param type
 * @param description
 * @return true if succeeded
 */
int MainWindow::insertNewEntry(QDate date, double amount, int subcategoryId, QString type, QString description)
{
    QSqlQuery financeEntry;
    financeEntry.prepare(R"(INSERT INTO transactions (date, description, amount, subcategory_id, type)
                         VALUES (:date, :description, :amount, :subcategoryId, :type))");
    financeEntry.bindValue(":date", date);
    financeEntry.bindValue(":description", description);
    financeEntry.bindValue(":amount", amount);
    financeEntry.bindValue(":subcategoryId", subcategoryId);
    financeEntry.bindValue(":type", type);
    if (!financeEntry.exec())
    {
        qDebug() << "Finance entry Insert failed:" << financeEntry.lastError().text();
        return false;
    }

    return true;
}

/**
 * @brief return from add element dialog
 */
void MainWindow::on_buttonNewFinanceItem_clicked()
{
    QDate calendarSelectedDate = ui->calendarWidget->selectedDate();
    FinanceItemDialog fid(calendarSelectedDate);
    if (fid.exec() == QDialog::Accepted)
    {
        QString category = fid.getCategory();
        QString subcategory = fid.getSubcategory();
        QString type = fid.getType();
        double amount = fid.getAmount();
        QString description = fid.getDescription();
        bool repeat = fid.getRepeat();

        int categoryId = this->getOrCreateCategory(category);
        int subcategoryId = this->getOrCreateSubcategory(subcategory, categoryId);

        if (this->insertNewEntry(calendarSelectedDate, amount, subcategoryId, type, description) == false)
            qDebug() << "TODO display error message in creating new entry";
        else
            this->getAllEntriesFromDate(calendarSelectedDate);
    }
}

/**
 * @brief MainWindow::getAllEntriesFromDate
 * @param date
 * @return
 */
int MainWindow::getAllEntriesFromDate(QDate date)
{
    QSqlQuery query;
    query.prepare("SELECT t.date, t.description, t.amount, t.subcategory_id, t.type, sc.subcategory AS subcategory, c.category AS category "
                    "FROM transactions t "
                    "JOIN subcategories sc ON t.subcategory_id = sc.id "
                    "JOIN categories c ON sc.category_id = c.id "
                    "WHERE t.date = :date");
    query.bindValue(":date", date);
    //
    if (!query.exec())
    {
        qDebug() << "Get data Query failed:" << query.lastError().text();
        return false;
    }

    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(std::move(query));
    ui->financeItemsTableView->setModel(model);

    return true;
}

int MainWindow::getAllIncomeItemFromMonth(QDate date)
{
    QDate startOfMonth(date.year(), date.month(), 1);
    QDate endOfMonth = startOfMonth.addMonths(1).addDays(-1);
    QLocale locale(QLocale::English);

    QSqlQuery incomeQuery;
    incomeQuery.prepare(R"(
    SELECT t.date, t.description, t.amount
    FROM transactions t
    JOIN subcategories sc ON t.subcategory_id = sc.id
    JOIN categories c ON sc.category_id = c.id
    WHERE t.type = 'Income' AND t.date BETWEEN :start AND :end
)");
    incomeQuery.bindValue(":start", startOfMonth);
    incomeQuery.bindValue(":end", endOfMonth);
    incomeQuery.exec();

    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(std::move(incomeQuery));
    ui->monthIncomeTableView->setModel(model);

    double sum = 0.0;
    for (int row = 0; row < model->rowCount(); ++row)
    {
        QVariant value = model->data(model->index(row, 2)); // Adjust column index if needed
        sum += value.toDouble();
    }

    ui->incomeGroupBox->setTitle(QString("Income of %1: %2").arg(locale.monthName(date.month())).arg(sum));
    return sum;
}

int MainWindow::getAllExpenseItemFromMonth(QDate date)
{
    QDate startOfMonth(date.year(), date.month(), 1);
    QDate endOfMonth = startOfMonth.addMonths(1).addDays(-1);
    QLocale locale(QLocale::English);

    QSqlQuery expenseQuery;
    expenseQuery.prepare(R"(
    SELECT t.date, t.description, t.amount
    FROM transactions t
    JOIN subcategories sc ON t.subcategory_id = sc.id
    JOIN categories c ON sc.category_id = c.id
    WHERE t.type = 'Expense' AND t.date BETWEEN :start AND :end
)");
    expenseQuery.bindValue(":start", startOfMonth);
    expenseQuery.bindValue(":end", endOfMonth);
    expenseQuery.exec();

    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(std::move(expenseQuery));
    ui->monthExpenseTableView->setModel(model);

    double sum = 0.0;
    for (int row = 0; row < model->rowCount(); ++row)
    {
        QVariant value = model->data(model->index(row, 2)); // Adjust column index if needed
        sum += value.toDouble();
    }

    ui->expenseGroupBox->setTitle(QString("Expense of %1: %2").arg(locale.monthName(date.month())).arg(sum));

    return sum;
}

/**
 * @brief calendar date selected
 */
void MainWindow::on_calendarWidget_selectionChanged()
{
    QDate date = ui->calendarWidget->selectedDate();
    qDebug() << "Date selected:" << date.toString();

    this->getAllEntriesFromDate(date);
}

/**
 * @brief MainWindow::on_tabWidget_currentChanged
 * @param index
 */
void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 0)
    {
        qDebug() << "Daily view";
    }
    if (index == 1)
    {
        double sumExpense = 0;
        double sumIncome = 0;
        QDate date = ui->calendarWidget->selectedDate();

        qDebug() << "Monthly view";
        sumExpense = this->getAllExpenseItemFromMonth(date);
        sumIncome = this->getAllIncomeItemFromMonth(date);
        ui->totalMonthly->setText(QString("Total %1").arg(sumExpense + sumIncome));
    }
}

