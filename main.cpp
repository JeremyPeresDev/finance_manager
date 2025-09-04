#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

/**
 * @brief setupDatabase creates and verifies that the database is in a correct state
 * @return true if the database is usable
 */
bool setupDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("financeManager.db");

    if (!db.open()) {
        qDebug() << "Failed to open database:" << db.lastError();
        return false;
    }

    //category table
    QSqlQuery queryCreateCategoriesTable;
    QString createTableCategories = R"(
        CREATE TABLE IF NOT EXISTS categories (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            category TEXT UNIQUE NOT NULL
        );
    )";

    if (!queryCreateCategoriesTable.exec(createTableCategories)) {
        qDebug() << "Failed to create categories table:" << queryCreateCategoriesTable.lastError();
        return false;
    }

    //subcategory table
    QSqlQuery queryCreateSubcategoriesTable;
    QString createTableSubcategories = R"(
        CREATE TABLE IF NOT EXISTS subcategories (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            subcategory TEXT UNIQUE NOT NULL,
            category_id INTEGER NOT NULL,
            FOREIGN KEY (category_id) REFERENCES categories(id) ON DELETE CASCADE
        );
    )";

    if (!queryCreateSubcategoriesTable.exec(createTableSubcategories)) {
        qDebug() << "Failed to create subcategories table:" << queryCreateSubcategoriesTable.lastError();
        return false;
    }

    //transactions table
    QSqlQuery queryCreateTransactionsTable;
    QString createTableTransactions = R"(
        CREATE TABLE IF NOT EXISTS transactions (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            date TEXT NOT NULL,
            description TEXT,
            amount REAL NOT NULL,
            subcategory_id INTEGER NOT NULL,
            type TEXT CHECK(type IN ('Income', 'Expense')) NOT NULL,
            FOREIGN KEY (subcategory_id) REFERENCES subcategories(id) ON DELETE CASCADE
        );
    )";

    if (!queryCreateTransactionsTable.exec(createTableTransactions)) {
        qDebug() << "Failed to create transactions table:" << queryCreateTransactionsTable.lastError();
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!setupDatabase())
        return -1;

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Finance_Manager_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
