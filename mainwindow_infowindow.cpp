// MainWindow::infoWindow method implementation.

// Copyright (C) 2011-2018 Stavros Filippidis
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

void MainWindow::infoWindow(QString infoText, QString title, QMessageBox::Icon icon) {
    QMessageBox msgBox;
#if defined(Q_OS_WIN)
    msgBox.setWindowTitle(title);
    msgBox.setText(infoText);
#else
    msgBox.setText(title);
    msgBox.setInformativeText(infoText);
#endif
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setButtonText(QMessageBox::Ok, QString::fromWCharArray(L"Ok"));
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setIcon(icon);
    msgBox.exec();
} // end function "infoWindow"
