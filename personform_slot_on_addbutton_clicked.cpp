// PersonForm::on_addButton_clicked slot implementation.

// Copyright (C) 2011-2020 Stavros Filippidis
// Contact: sfilippidis@gmail.com

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

#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDataWidgetMapper>
#include "personform.h"
#include "ui_personform.h"
#include "atzenta_enum.h"

void PersonForm::on_addButton_clicked()
{
    if (m_isNew)
    {
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
    } // if (m_isNew)
    else // if (m_isNew)
        m_mapper->submit();
    close();
} // void PersonForm::on_addButton_clicked()
