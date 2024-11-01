// Source code for the search form.

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

#include "searchform.h"
#include "ui_searchform.h"

SearchForm::SearchForm(QSqlTableModel *model, bool *cancel, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::SearchForm),
    m_model(model),
    m_cancel(cancel),
    m_searchString("")
{
    m_ui->setupUi(this);
    setWindowTitle(QString::fromWCharArray(L"Search within all fields of all contacts"));
} // end SearchForm::SearchForm

SearchForm::~SearchForm()
{
    delete m_ui;
} // end SearchForm::~SearchForm()

void SearchForm::on_cancelButton_clicked()
{
    *m_cancel = true;
    close();
} // end SearchForm::on_cancelButton_clicked

void SearchForm::on_searchButton_clicked()
{
    m_searchString = QString::fromWCharArray(L"name LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR sirname LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR jobtitle LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR company LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR homephone1 LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR homephone2 LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR workphone1 LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR workphone2 LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR mobilephone1 LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR mobilephone2 LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR otherphone1 LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR otherphone2 LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR homefax LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR workfax LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR homeemail LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR workemail LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR homeurl LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR workurl LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR homeaddress LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR homecity LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR homezipcode LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR homecountry LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR workaddress LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR workcity LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR workzipcode LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR workcountry LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%' OR notes LIKE '%");
    m_searchString += m_ui->searchEdit->text();
    m_searchString += QString::fromWCharArray(L"%'");
    m_model->setFilter(m_searchString);
    close();
} // end SearchForm::on_searchButton_clicked
