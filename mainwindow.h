// Header file for the main window.

// Copyright (C) 2011-2024 Stavros Filippidis
// Contact: stavros@filippidis.name

// This file is part of QGreatstWeightCalculator.

// QGreatstWeightCalculator is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// QGreatstWeightCalculator is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with QGreatstWeightCalculator.  If not, see <http://www.gnu.org/licenses/>.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QDir>

void displayInformationMessage(QString infoText, QString title);

namespace Ui
{
    class MainWindow;
} // namespace Ui

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QString m_name ="";
    double m_weight = 80.0;
    double m_height = 180.0;
    double m_age = 40.0;
    int m_gender_index = 0;
    int m_actividy_index = 0;
    Ui::MainWindow *m_ui;
    bool m_doesDataFileExist;
    void populate_history();
    void create_history();
private slots:
    void on_pushButtonExit_clicked();
    void about();
    void on_pushButtonSave_clicked();
    void on_pushButtonCalculate_clicked();
    void on_pushButtonResetData_clicked();
}; // class MainWindow

#endif
