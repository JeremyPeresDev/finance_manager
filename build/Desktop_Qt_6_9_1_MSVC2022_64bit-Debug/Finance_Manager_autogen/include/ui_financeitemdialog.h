/********************************************************************************
** Form generated from reading UI file 'financeitemdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINANCEITEMDIALOG_H
#define UI_FINANCEITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FinanceItemDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *ItemCategoryCombobox;
    QComboBox *ItemTypeCombobox;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QTextEdit *itemDescriptionTextEdit;
    QDoubleSpinBox *ItemAmountDoubleSpinbox;
    QComboBox *ItemSubcategoryCombobox;
    QCheckBox *ItemRepeatCheckbox;
    QLabel *label_5;
    QLabel *label_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FinanceItemDialog)
    {
        if (FinanceItemDialog->objectName().isEmpty())
            FinanceItemDialog->setObjectName("FinanceItemDialog");
        FinanceItemDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(FinanceItemDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(FinanceItemDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        ItemCategoryCombobox = new QComboBox(FinanceItemDialog);
        ItemCategoryCombobox->setObjectName("ItemCategoryCombobox");
        ItemCategoryCombobox->setEditable(true);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, ItemCategoryCombobox);

        ItemTypeCombobox = new QComboBox(FinanceItemDialog);
        ItemTypeCombobox->setObjectName("ItemTypeCombobox");
        ItemTypeCombobox->setEditable(false);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, ItemTypeCombobox);

        label_3 = new QLabel(FinanceItemDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        label_2 = new QLabel(FinanceItemDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_2);

        label_4 = new QLabel(FinanceItemDialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_4);

        itemDescriptionTextEdit = new QTextEdit(FinanceItemDialog);
        itemDescriptionTextEdit->setObjectName("itemDescriptionTextEdit");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, itemDescriptionTextEdit);

        ItemAmountDoubleSpinbox = new QDoubleSpinBox(FinanceItemDialog);
        ItemAmountDoubleSpinbox->setObjectName("ItemAmountDoubleSpinbox");
        ItemAmountDoubleSpinbox->setMaximum(999999999.000000000000000);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, ItemAmountDoubleSpinbox);

        ItemSubcategoryCombobox = new QComboBox(FinanceItemDialog);
        ItemSubcategoryCombobox->setObjectName("ItemSubcategoryCombobox");
        ItemSubcategoryCombobox->setEditable(true);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, ItemSubcategoryCombobox);

        ItemRepeatCheckbox = new QCheckBox(FinanceItemDialog);
        ItemRepeatCheckbox->setObjectName("ItemRepeatCheckbox");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, ItemRepeatCheckbox);

        label_5 = new QLabel(FinanceItemDialog);
        label_5->setObjectName("label_5");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_5);

        label_6 = new QLabel(FinanceItemDialog);
        label_6->setObjectName("label_6");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_6);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(FinanceItemDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(ItemCategoryCombobox, ItemSubcategoryCombobox);
        QWidget::setTabOrder(ItemSubcategoryCombobox, ItemTypeCombobox);
        QWidget::setTabOrder(ItemTypeCombobox, ItemAmountDoubleSpinbox);
        QWidget::setTabOrder(ItemAmountDoubleSpinbox, ItemRepeatCheckbox);
        QWidget::setTabOrder(ItemRepeatCheckbox, itemDescriptionTextEdit);

        retranslateUi(FinanceItemDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, FinanceItemDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, FinanceItemDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(FinanceItemDialog);
    } // setupUi

    void retranslateUi(QDialog *FinanceItemDialog)
    {
        FinanceItemDialog->setWindowTitle(QCoreApplication::translate("FinanceItemDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FinanceItemDialog", "Category", nullptr));
        label_3->setText(QCoreApplication::translate("FinanceItemDialog", "Type", nullptr));
        label_2->setText(QCoreApplication::translate("FinanceItemDialog", "Amount", nullptr));
        label_4->setText(QCoreApplication::translate("FinanceItemDialog", "Description", nullptr));
        ItemRepeatCheckbox->setText(QString());
        label_5->setText(QCoreApplication::translate("FinanceItemDialog", "Subcategory", nullptr));
        label_6->setText(QCoreApplication::translate("FinanceItemDialog", "Repeat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinanceItemDialog: public Ui_FinanceItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINANCEITEMDIALOG_H
