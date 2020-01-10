// MainWindow::resetModelViewLayout method implementation.

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
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "atzenta_enum.h"

void MainWindow::resetModelViewLayout()
{
    m_model = new QSqlTableModel(this);
    m_model->setTable(QString::fromWCharArray(L"atzenta"));
    m_model->setHeaderData(ATZENTA_NAME, Qt::Horizontal, QString::fromWCharArray(L"First name"));
    m_model->setHeaderData(ATZENTA_SIRNAME, Qt::Horizontal, QString::fromWCharArray(L"Last name"));
    m_model->setHeaderData(ATZENTA_COMPANY, Qt::Horizontal, QString::fromWCharArray(L"Company"));
    m_model->setHeaderData(ATZENTA_HOME_PHONE_1, Qt::Horizontal, QString::fromWCharArray(L"Home phone"));
    m_model->setHeaderData(ATZENTA_WORK_PHONE_1, Qt::Horizontal, QString::fromWCharArray(L"Work phone"));
    m_model->setHeaderData(ATZENTA_MOBILE_PHONE_1, Qt::Horizontal, QString::fromWCharArray(L"Mobile phone"));
    m_model->select();
    m_ui->view->setModel(m_model);
    m_ui->view->setSelectionMode(QAbstractItemView::SingleSelection);
    m_ui->view->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_ui->view->setColumnHidden(ATZENTA_ID, true);
    m_ui->view->setColumnHidden(ATZENTA_JOB_TITLE, true);
    m_ui->view->setColumnHidden(ATZENTA_HOME_PHONE_2, true);
    m_ui->view->setColumnHidden(ATZENTA_WORK_PHONE_2, true);
    m_ui->view->setColumnHidden(ATZENTA_MOBILE_PHONE_2, true);
    m_ui->view->setColumnHidden(ATZENTA_OTHER_PHONE_1, true);
    m_ui->view->setColumnHidden(ATZENTA_OTHER_PHONE_2, true);
    m_ui->view->setColumnHidden(ATZENTA_HOME_FAX, true);
    m_ui->view->setColumnHidden(ATZENTA_WORK_FAX, true);
    m_ui->view->setColumnHidden(ATZENTA_HOME_EMAIL, true);
    m_ui->view->setColumnHidden(ATZENTA_WORK_EMAIL, true);
    m_ui->view->setColumnHidden(ATZENTA_HOME_URL, true);
    m_ui->view->setColumnHidden(ATZENTA_WORK_URL, true);
    m_ui->view->setColumnHidden(ATZENTA_HOME_ADDRESS, true);
    m_ui->view->setColumnHidden(ATZENTA_HOME_CITY, true);
    m_ui->view->setColumnHidden(ATZENTA_HOME_ZIP_CODE, true);
    m_ui->view->setColumnHidden(ATZENTA_HOME_COUNTRY, true);
    m_ui->view->setColumnHidden(ATZENTA_WORK_ADDRESS, true);
    m_ui->view->setColumnHidden(ATZENTA_WORK_CITY, true);
    m_ui->view->setColumnHidden(ATZENTA_WORK_ZIP_CODE, true);
    m_ui->view->setColumnHidden(ATZENTA_WORK_COUNTRY, true);
    m_ui->view->setColumnHidden(ATZENTA_NOTES, true);
    m_ui->view->setSortingEnabled(true);
    m_ui->view->sortByColumn(ATZENTA_NAME, Qt::AscendingOrder);
    m_ui->view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_header = m_ui->view->horizontalHeader();
    m_ui->view->resizeColumnsToContents();
    m_header->setStretchLastSection(true);
    m_ui->searchButton->setText(QString::fromWCharArray(L"Search..."));
}

