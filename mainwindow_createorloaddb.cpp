// MainWindow::createOrLoadDb method implementation.

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

#include <QFile>
#include <QSqlQuery>
#include "mainwindow.h"

void MainWindow::createOrLoadDb(QString databaseFileName)
{
    bool databaseDidNotExistWhenAppStarted = !QFile::exists(databaseFileName);
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(databaseFileName);
    if (!database.open())
    {
        QString databaseErrorInfoText = QString::fromWCharArray(L"There was an error with the file <b>QGreatstAtzenta.database</b> in your home directory! Please rename the file QGreatstAtzenta.database in your home directory (or delete it if you are sure you do not need it) and run the application again!");
        QString databaseErrorTitle = QString::fromWCharArray(L"Error with the contacts' file");
        infoWindow(databaseErrorInfoText, databaseErrorTitle, QMessageBox::Critical);
        exit(0);
    } // end if
    if ((!databaseDidNotExistWhenAppStarted) && (!database.tables().contains("atzenta")))
    {
        QString databaseErrorInfoText = QString::fromWCharArray(L"File <b>QGreatstAtzenta.database</b> in your home directory is not a contacts' file! Please rename the file QGreatstAtzenta.database in your home directory (or delete it if you are sure you do not need it) and run the application again!");
        QString databaseErrorTitle = QString::fromWCharArray(L"Wrong contacts' file");
        infoWindow(databaseErrorInfoText, databaseErrorTitle, QMessageBox::Critical);
        exit(0);
    } // end if
    if (databaseDidNotExistWhenAppStarted)
    {
        QSqlQuery query;
        query.exec(QString::fromWCharArray(L"CREATE TABLE atzenta (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(30), sirname VARCHAR(40), jobtitle VARCHAR(60), company VARCHAR(80), homephone1 VARCHAR(20), homephone2 VARCHAR(20), workphone1 VARCHAR(20), workphone2 VARCHAR(20), mobilephone1 VARCHAR(20), mobilephone2 VARCHAR(20), otherphone1 VARCHAR(20), otherphone2 VARCHAR(20), homefax VARCHAR(20), workfax VARCHAR(20), homeemail VARCHAR(60), workemail VARCHAR(60), homeurl VARCHAR(150), workurl VARCHAR(150), homeaddress VARCHAR(60), homecity VARCHAR(30), homezipcode VARCHAR(20), homecountry VARCHAR(40), workaddress VARCHAR(60), workcity VARCHAR(30), workzipcode VARCHAR(20), workcountry VARCHAR(40), notes VARCHAR(256) )"));
        QString helloText = QString::fromWCharArray(L"A file named <b>QGreatstAtzenta.database</b> has been created in your home directory. The contacts will be saved there. <BR><BR>If you would like to delete your contacts, you should manualy delete this file yourself.<BR><BR>The location of the file is:<BR><BR>");
        helloText += databaseFileName;
        QString helloTitle = QString::fromWCharArray(L"About the file QGreatstAtzenta.database");
        infoWindow(helloText, helloTitle, QMessageBox::Information);
    } // end if
} // end function "MainWindow::createOrLoadDb"
