// MainWindow::on_searchButton_clicked slot implementation.

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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "searchform.h"

void MainWindow::on_searchButton_clicked()
{
    if (m_ui->searchButton->text()==QString::fromWCharArray(L"Show all"))
    {
        resetModelViewLayout();
        setWindowTitle(QString::fromWCharArray(L"QGreatstAtzenta"));
        m_ui->searchButton->setText(QString::fromWCharArray(L"Search..."));
        return;
    } // end if

    bool *isCancelChosen = new(bool);
    *isCancelChosen = false;
    SearchForm form(m_model, isCancelChosen, this);
    form.exec();

    if(!*isCancelChosen)
    {
        setWindowTitle(QString::fromWCharArray(L"QGreatstAtzenta - showing selected contacts"));
        m_ui->searchButton->setText(QString::fromWCharArray(L"Show all"));
    }
} // end function "MainWindow::on_searchButton_clicked"
