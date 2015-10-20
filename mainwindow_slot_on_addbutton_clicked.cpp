// MainWindow::on_addButton_clicked slot implementation.

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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personform.h"
#include "person_enum.h"

void MainWindow::on_addButton_clicked()
{
    PersonForm form(PERSON_IS_NEW, m_model, m_ui->view, this);
    form.exec();
    resetModelViewLayout();
} // end function "MainWindow::on_addButton_clicked"

