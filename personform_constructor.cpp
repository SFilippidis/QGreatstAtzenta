// PersonForm's constructor implementation.

// Copyright (C) 2011-2015 Stavros Filippidis
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
    if (m_isNew)
    {
        setWindowTitle(QString::fromWCharArray(L"Create a new contact"));
    } // end of then
    else
    {
        setWindowTitle(QString::fromWCharArray(L"View and edit an existing contact"));
        m_mapper->setCurrentIndex(view->currentIndex().row());
    } // end if
} // end function "PersonForm::PersonForm"
