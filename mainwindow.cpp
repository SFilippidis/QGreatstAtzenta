// Source code for the main window of the application.

// Copyright (C) 2011-2021 Stavros Filippidis
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
#include "atzenta_enum.h"
#include "personform.h"
#include "person_enum.h"
#include "searchform.h"

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
} // MainWindow::MainWindow(QWidget *parent)

MainWindow::~MainWindow()
{
    delete m_ui;
} // MainWindow::~MainWindow()

void MainWindow::createOrLoadDb(QString databaseFileName)
{
    bool databaseDidNotExistWhenAppStarted = !QFile::exists(databaseFileName);
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(databaseFileName);
    if (!database.open()) {
        QString databaseErrorInfoText = QString::fromWCharArray(L"There was an error with the file <b>QGreatstAtzenta.database</b> in y"
                                                                "our home directory! Please rename the file QGreatstAtzenta.database in"
                                                                " your home directory (or delete it if you are sure you do not need it)"
                                                                " and run the application again!");
        QString databaseErrorTitle = QString::fromWCharArray(L"Error with the contacts' file");
        infoWindow(databaseErrorInfoText, databaseErrorTitle, QMessageBox::Critical);
        exit(0);
    } // if (!database.open())
    if ((!databaseDidNotExistWhenAppStarted) && (!database.tables().contains("atzenta"))) {
        QString databaseErrorInfoText = QString::fromWCharArray(L"File <b>QGreatstAtzenta.database</b> in your home directory is not a "
                                                                "contacts' file! Please rename the file QGreatstAtzenta.database in you"
                                                                "r home directory (or delete it if you are sure you do not need it) and"
                                                                " run the application again!");
        QString databaseErrorTitle = QString::fromWCharArray(L"Wrong contacts' file");
        infoWindow(databaseErrorInfoText, databaseErrorTitle, QMessageBox::Critical);
        exit(0);
    } // if ((!databaseDidNotExistWhenAppStarted) && (!database.tables().contains("atzenta")))
    if (databaseDidNotExistWhenAppStarted) {
        QSqlQuery query;
        query.exec(QString::fromWCharArray(L"CREATE TABLE atzenta (id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                                                   "name VARCHAR(30), "
                                                                   "sirname VARCHAR(40), "
                                                                   "jobtitle VARCHAR(60), "
                                                                   "company VARCHAR(80), "
                                                                   "homephone1 VARCHAR(20), "
                                                                   "homephone2 VARCHAR(20), "
                                                                   "workphone1 VARCHAR(20), "
                                                                   "workphone2 VARCHAR(20), "
                                                                   "mobilephone1 VARCHAR(20), "
                                                                   "mobilephone2 VARCHAR(20), "
                                                                   "otherphone1 VARCHAR(20), "
                                                                   "otherphone2 VARCHAR(20), "
                                                                   "homefax VARCHAR(20), "
                                                                   "workfax VARCHAR(20), "
                                                                   "homeemail VARCHAR(60), "
                                                                   "workemail VARCHAR(60), "
                                                                   "homeurl VARCHAR(150), "
                                                                   "workurl VARCHAR(150), "
                                                                   "homeaddress VARCHAR(60), "
                                                                   "homecity VARCHAR(30), "
                                                                   "homezipcode VARCHAR(20), "
                                                                   "homecountry VARCHAR(40), "
                                                                   "workaddress VARCHAR(60), "
                                                                   "workcity VARCHAR(30), "
                                                                   "workzipcode VARCHAR(20), "
                                                                   "workcountry VARCHAR(40), "
                                                                   "notes VARCHAR(256) )"));
        QString helloText = QString::fromWCharArray(L"A file named <b>QGreatstAtzenta.database</b> has been created in your home direct"
                                                    "ory. The contacts will be saved there. <BR><BR>If you would like to delete your co"
                                                    "ntacts, you should manualy delete this file yourself.<BR><BR>The location of the f"
                                                    "ile is:<BR><BR>");
        helloText += databaseFileName;
        QString helloTitle = QString::fromWCharArray(L"About the file QGreatstAtzenta.database");
        infoWindow(helloText, helloTitle, QMessageBox::Information);
    } // if (databaseDidNotExistWhenAppStarted)
} // void MainWindow::createOrLoadDb(QString databaseFileName)

void MainWindow::infoWindow(QString infoText, QString title, QMessageBox::Icon icon)
{
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
} // void MainWindow::infoWindow(QString infoText, QString title, QMessageBox::Icon icon)

void MainWindow::about()
{
    QString licenceAndInfoText = QString::fromWCharArray(L"QGreatstAtzenta. Version 1.3.5. A program for organizing your contacts.<BR>"
                                                         "<BR>Copyright (C) 2011-2021 Stavros Filippidis<BR>email: <A HREF='mailto:sfil"
                                                         "ippidis@gmail.com'>sfilippidis@gmail.com</A><BR>www: <A HREF='https://blogs.s"
                                                         "ch.gr/sfil/'>https://sfil.mysch.gr/</A><BR><BR>QGreatstAtzenta is free so"
                                                         "ftware: you can redistribute it and/or modify<BR>it under the terms of the GN"
                                                         "U General Public License as published by<BR>the Free Software Foundation, eit"
                                                         "her version 3 of the License, or<BR>(at your option) any later version.<BR><B"
                                                         "R>QGreatstAtzenta is distributed in the hope that it will be useful,<BR>but W"
                                                         "ITHOUT ANY WARRANTY; without even the implied warranty of<BR>MERCHANTABILITY "
                                                         "or FITNESS FOR A PARTICULAR PURPOSE.  See the<BR>GNU General Public License f"
                                                         "or more details.<BR><BR>You should have received a copy of the GNU General Pu"
                                                         "blic License<BR>along with QGreatstAtzenta.  If not, see <A HREF='http://www."
                                                         "gnu.org/licenses/'>http://www.gnu.org/licenses/</A>.<BR>");
    QString licenceTitle = QString::fromWCharArray(L"About QGreatstAtzenta");
    infoWindow(licenceAndInfoText, licenceTitle, QMessageBox::NoIcon);
} // void MainWindow::about()

void MainWindow::on_addButton_clicked()
{
    PersonForm form(PERSON_IS_NEW, m_model, m_ui->view, this);
    form.exec();
    resetModelViewLayout();
} // void MainWindow::on_addButton_clicked()

void MainWindow::on_deleteButton_clicked()
{
    if (!(m_ui->view->selectionModel()->isSelected(m_ui->view->currentIndex()))) {
        QString title = QString::fromWCharArray(L"No chosen contacts");
        QString text = QString::fromWCharArray(L"You did not choose a contact to delete.\n\nNo contacts "
                                               "were deleted.");
        infoWindow(text, title, QMessageBox::Critical);
        return;
    } // if (!(m_ui->view->selectionModel()->isSelected(m_ui->view->currentIndex())))
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
    if (ret == QMessageBox::Yes) {
        m_model->removeRow(m_ui->view->currentIndex().row());
        m_model->select();
        m_ui->view->resizeColumnsToContents();
        m_header->setStretchLastSection(true);
    } // if (ret == QMessageBox::Yes)
} // void MainWindow::on_deleteButton_clicked()

void MainWindow::on_editOrViewButton_clicked()
{
    if (!( m_ui->view->selectionModel()->isSelected(m_ui->view->currentIndex()))) {
        QString title = QString::fromWCharArray(L"No chosen contacts");
        QString text = QString::fromWCharArray(L"You did not choose a contact to view and/or edit.");
        infoWindow(text, title, QMessageBox::Critical);
        return;
    } // if (!( m_ui->view->selectionModel()->isSelected(m_ui->view->currentIndex())))
    PersonForm form(PERSON_IS_OLD, m_model, m_ui->view, this);
    form.exec();
    m_ui->view->resizeColumnsToContents();
    m_header->setStretchLastSection(true);
} // void MainWindow::on_editOrViewButton_clicked()

void MainWindow::on_quitButton_clicked()
{
    close();
} // void MainWindow::on_quitButton_clicked()

void MainWindow::on_searchButton_clicked()
{
    if (m_ui->searchButton->text()==QString::fromWCharArray(L"Show all")) {
        resetModelViewLayout();
        setWindowTitle(QString::fromWCharArray(L"QGreatstAtzenta"));
        m_ui->searchButton->setText(QString::fromWCharArray(L"Search..."));
        return;
    } // if (m_ui->searchButton->text()==QString::fromWCharArray(L"Show all"))
    bool *isCancelChosen = new(bool);
    *isCancelChosen = false;
    SearchForm form(m_model, isCancelChosen, this);
    form.exec();
    if(!*isCancelChosen) {
        setWindowTitle(QString::fromWCharArray(L"QGreatstAtzenta - showing selected contacts"));
        m_ui->searchButton->setText(QString::fromWCharArray(L"Show all"));
    } // if(!*isCancelChosen)
} // void MainWindow::on_searchButton_clicked()

void MainWindow::useDb()
{
    QString databaseFileName;
    databaseFileName = QDir::homePath() + QString::fromWCharArray(L"/QGreatstAtzenta.database");
    createOrLoadDb(databaseFileName);
    resetModelViewLayout();
} // void MainWindow::useDb()

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
} // void MainWindow::resetModelViewLayout()