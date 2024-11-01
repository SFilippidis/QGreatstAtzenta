// Source code for the form for contact's data.

// Copyright (C) 2011-2024 Stavros Filippidis
// Contact: stavros@filippidis.name

// This file is part of QGreatstAtzenta.

// QGreatstAtzenta is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// QGreatstAtzenta is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with QGreatstAtzenta.  If not, see <http://www.gnu.org/licenses/>.

#include <QtSql>
#include <QDataWidgetMapper>
#include <QTableView>
#include "atzenta_enum.h"
#include "personform.h"
#include "ui_personform.h"

PersonForm::PersonForm(bool isNew, QSqlTableModel *model, QTableView *view, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::PersonForm),
    m_model(model),
    m_view(view),
    m_isNew(isNew),
    m_mapper(new QDataWidgetMapper(this))
{
    m_ui->setupUi(this);
    m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    m_mapper->setModel(model);
    m_mapper->addMapping(m_ui->nameEdit, ATZENTA_NAME);
    m_mapper->addMapping(m_ui->sirnameEdit, ATZENTA_SIRNAME);
    m_mapper->addMapping(m_ui->jobTitleEdit, ATZENTA_JOB_TITLE);
    m_mapper->addMapping(m_ui->companyEdit, ATZENTA_COMPANY);
    m_mapper->addMapping(m_ui->homePhone1Edit, ATZENTA_HOME_PHONE_1);
    m_mapper->addMapping(m_ui->homePhone2Edit, ATZENTA_HOME_PHONE_2);
    m_mapper->addMapping(m_ui->workPhone1Edit, ATZENTA_WORK_PHONE_1);
    m_mapper->addMapping(m_ui->workPhone2Edit, ATZENTA_WORK_PHONE_2);
    m_mapper->addMapping(m_ui->mobilePhone1Edit, ATZENTA_MOBILE_PHONE_1);
    m_mapper->addMapping(m_ui->mobilePhone2Edit, ATZENTA_MOBILE_PHONE_2);
    m_mapper->addMapping(m_ui->otherPhone1Edit, ATZENTA_OTHER_PHONE_1);
    m_mapper->addMapping(m_ui->otherPhone2Edit, ATZENTA_OTHER_PHONE_2);
    m_mapper->addMapping(m_ui->homeFaxEdit, ATZENTA_HOME_FAX);
    m_mapper->addMapping(m_ui->workFaxEdit, ATZENTA_WORK_FAX);
    m_mapper->addMapping(m_ui->homeEmailEdit, ATZENTA_HOME_EMAIL);
    m_mapper->addMapping(m_ui->workEmailEdit, ATZENTA_WORK_EMAIL);
    m_mapper->addMapping(m_ui->homeUrlEdit, ATZENTA_HOME_URL);
    m_mapper->addMapping(m_ui->workUrlEdit, ATZENTA_WORK_URL);
    m_mapper->addMapping(m_ui->homeAddressEdit, ATZENTA_HOME_ADDRESS);
    m_mapper->addMapping(m_ui->homeCityEdit, ATZENTA_HOME_CITY);
    m_mapper->addMapping(m_ui->homeZipCodeEdit, ATZENTA_HOME_ZIP_CODE);
    m_mapper->addMapping(m_ui->homeCountryEdit, ATZENTA_HOME_COUNTRY);
    m_mapper->addMapping(m_ui->workAddressEdit, ATZENTA_WORK_ADDRESS);
    m_mapper->addMapping(m_ui->workCityEdit, ATZENTA_WORK_CITY);
    m_mapper->addMapping(m_ui->workZipCodeEdit, ATZENTA_WORK_ZIP_CODE);
    m_mapper->addMapping(m_ui->workCountryEdit, ATZENTA_WORK_COUNTRY);
    m_mapper->addMapping(m_ui->notesEdit, ATZENTA_NOTES);
    if (m_isNew) {
        setWindowTitle(QString::fromWCharArray(L"Create a new contact"));
    } else {
        setWindowTitle(QString::fromWCharArray(L"View and edit an existing contact"));
        m_mapper->setCurrentIndex(view->currentIndex().row());
    } // end if
} // end PersonForm::PersonForm

PersonForm::~PersonForm()
{
    delete m_ui;
} // end PersonForm::~PersonForm()

void PersonForm::on_addButton_clicked()
{
    if (m_isNew) {
        QSqlRecord record = m_model->record();
        record.setValue(ATZENTA_NAME, QVariant(m_ui->nameEdit->text()));
        record.setValue(ATZENTA_SIRNAME, QVariant(m_ui->sirnameEdit->text()));
        record.setValue(ATZENTA_JOB_TITLE, QVariant(m_ui->jobTitleEdit->text()));
        record.setValue(ATZENTA_COMPANY, QVariant(m_ui->companyEdit->text()));
        record.setValue(ATZENTA_HOME_PHONE_1, QVariant(m_ui->homePhone1Edit->text()));
        record.setValue(ATZENTA_HOME_PHONE_2, QVariant(m_ui->homePhone2Edit->text()));
        record.setValue(ATZENTA_WORK_PHONE_1, QVariant(m_ui->workPhone1Edit->text()));
        record.setValue(ATZENTA_WORK_PHONE_2, QVariant(m_ui->workPhone2Edit->text()));
        record.setValue(ATZENTA_WORK_PHONE_2, QVariant(m_ui->workPhone2Edit->text()));
        record.setValue(ATZENTA_MOBILE_PHONE_1, QVariant(m_ui->mobilePhone1Edit->text()));
        record.setValue(ATZENTA_MOBILE_PHONE_2, QVariant(m_ui->mobilePhone2Edit->text()));
        record.setValue(ATZENTA_OTHER_PHONE_1, QVariant(m_ui->otherPhone1Edit->text()));
        record.setValue(ATZENTA_OTHER_PHONE_2, QVariant(m_ui->otherPhone2Edit->text()));
        record.setValue(ATZENTA_HOME_FAX, QVariant(m_ui->homeFaxEdit->text()));
        record.setValue(ATZENTA_WORK_FAX, QVariant(m_ui->workFaxEdit->text()));
        record.setValue(ATZENTA_HOME_EMAIL, QVariant(m_ui->homeEmailEdit->text()));
        record.setValue(ATZENTA_WORK_EMAIL, QVariant(m_ui->workEmailEdit->text()));
        record.setValue(ATZENTA_HOME_URL, QVariant(m_ui->homeUrlEdit->text()));
        record.setValue(ATZENTA_WORK_URL, QVariant(m_ui->workUrlEdit->text()));
        record.setValue(ATZENTA_HOME_ADDRESS, QVariant(m_ui->homeAddressEdit->text()));
        record.setValue(ATZENTA_HOME_CITY, QVariant(m_ui->homeCityEdit->text()));
        record.setValue(ATZENTA_HOME_ZIP_CODE, QVariant(m_ui->homeZipCodeEdit->text()));
        record.setValue(ATZENTA_HOME_COUNTRY, QVariant(m_ui->homeCountryEdit->text()));
        record.setValue(ATZENTA_WORK_ADDRESS, QVariant(m_ui->workAddressEdit->text()));
        record.setValue(ATZENTA_WORK_CITY, QVariant(m_ui->workCityEdit->text()));
        record.setValue(ATZENTA_WORK_ZIP_CODE, QVariant(m_ui->workZipCodeEdit->text()));
        record.setValue(ATZENTA_WORK_COUNTRY, QVariant(m_ui->workCountryEdit->text()));
        record.setValue(ATZENTA_NOTES, QVariant(m_ui->notesEdit->toPlainText()));
        m_model->insertRecord(-1,record);
    } else {
        m_mapper->submit();
    } // end if
    close();
} // end PersonForm::on_addButton_clicked

void PersonForm::on_cancelButton_clicked()
{
    close();
} // end PersonForm::on_cancelButton_clicked
