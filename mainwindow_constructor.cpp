// MainWindow's constructor implementation.

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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    setUnifiedTitleAndToolBarOnMac(true);
    resetModelViewLayout();
    connect(m_ui->view, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_editOrViewButton_clicked()));
    setWindowTitle(QString::fromWCharArray(L"QGreatstAtzenta"));
    connect(m_ui->actionAbout_QGreatstAtzenta, SIGNAL(triggered()), this, SLOT(about()));
    connect(m_ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    MainWindow::useDb();
}
