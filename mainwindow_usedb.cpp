// MainWindow::useDb method implementation.

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

#include <QDir>
#include "mainwindow.h"

void MainWindow::useDb()
{
    QString databaseFileName;
    databaseFileName = QDir::homePath() + QString::fromWCharArray(L"/QGreatstAtzenta.database");
    createOrLoadDb(databaseFileName);
    resetModelViewLayout();
} // end function "MainWindow::useDb"
