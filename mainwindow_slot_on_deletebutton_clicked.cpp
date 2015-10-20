// MainWindow::on_deleteButton_clicked slot implementation.

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

#include <QSqlTableModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_deleteButton_clicked()
{
    if (!(m_ui->view->selectionModel()->isSelected(m_ui->view->currentIndex())))
    {
        QString title = QString::fromWCharArray(L"No chosen contacts");
        QString text = QString::fromWCharArray(L"You did not choose a contact to delete.\n\nNo contacts were deleted.");
        this->infoWindow(text, title, QMessageBox::Critical);
        return;
    } // end if
    QMessageBox msgBox;
#if defined(Q_OS_WIN)
    msgBox.setWindowTitle(QString::fromWCharArray(L"Delete a contact"));
    msgBox.setText(QString::fromWCharArray(L"You are deleting the chosen contact. Are you sure?"));
#else
    msgBox.setText(QString::fromWCharArray(L"Delete a contact."));
    msgBox.setInformativeText(QString::fromWCharArray(L"You are deleting the chosen contact. Are you sure?"));
#endif
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, QString::fromWCharArray(L"Yes"));
    msgBox.setButtonText(QMessageBox::No, QString::fromWCharArray(L"No"));
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setIcon(QMessageBox::Warning);
    int ret = msgBox.exec();
    if ( ret == QMessageBox::Yes )
    {
        m_model->removeRow(m_ui->view->currentIndex().row());
        m_model->select();
        m_ui->view->resizeColumnsToContents();
        m_header->setStretchLastSection(true);
    } // end if
} // end function "MainWindow::on_deleteButton_clicked"
