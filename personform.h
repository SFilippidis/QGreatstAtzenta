// Header file for the form for contact's data.

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

#ifndef PERSONFORM_H
#define PERSONFORM_H

#include <QDialog>

namespace Ui {
    class PersonForm;
} // end namespace

class QSqlTableModel;
class QTableView;
class QDataWidgetMapper;

class PersonForm : public QDialog
{
    Q_OBJECT
public:
    explicit PersonForm(bool isNew, QSqlTableModel *model, QTableView *view, QWidget *parent = 0);
    ~PersonForm();
private slots:
    void on_addButton_clicked();
    void on_cancelButton_clicked();
private:
    Ui::PersonForm *m_ui;
    QSqlTableModel *m_model;
    QTableView *m_view;
    bool m_isNew;
    QDataWidgetMapper *m_mapper;
}; // end class

#endif // PERSONFORM_H
