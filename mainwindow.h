#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    bool loadDatabaseData();
    int getOrCreateCategory(QString categoryName);
    int getOrCreateSubcategory(QString subcategoryName, int categoryId);
    int insertNewEntry(QDate date, double amount, int subcategoryId, QString type, QString description);
    int getAllEntriesFromDate(QDate date);
    int getAllIncomeItemFromMonth(QDate date);
    int getAllExpenseItemFromMonth(QDate date);
private slots:
    void on_buttonNewFinanceItem_clicked();

    void on_calendarWidget_selectionChanged();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
