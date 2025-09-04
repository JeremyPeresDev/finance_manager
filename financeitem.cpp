#include "financeitem.h"

FinanceItem::FinanceItem(int id, QDate date, QString description, double amount, int categoryId, QString category, QString type)
    : id(id), date(date), description(description), amount(amount), categoryId(categoryId), category(category), type(type)
{

}
