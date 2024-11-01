// Header file for the main window.

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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDir>
#include <QHeaderView>

namespace Ui {
    class MainWindow;
} // namespace Ui

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_quitButton_clicked();
    void on_addButton_clicked();
    void on_editOrViewButton_clicked();
    void on_deleteButton_clicked();
    void on_searchButton_clicked();
    void about();
private:
    Ui::MainWindow *m_ui;
    QSqlTableModel *m_model;
    QHeaderView *m_header;
    void infoWindow(QString infoText, QString title, QMessageBox::Icon icon);
    void resetModelViewLayout();
    void createOrLoadDb(QString databaseFileName);
    void useDb();
}; // class MainWindow

#endif
