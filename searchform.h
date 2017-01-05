// Header file for the search form.

// Copyright (C) 2011-2017 Stavros Filippidis
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

#ifndef SEARCHFORM_H
#define SEARCHFORM_H

#include <QDialog>

class QSqlTableModel;

namespace Ui {
class SearchForm;
} // end namespace

class SearchForm : public QDialog
{
    Q_OBJECT
public:
    explicit SearchForm(QSqlTableModel *model, bool *cancel, QWidget *parent = 0);
    ~SearchForm();
private slots:
    void on_cancelButton_clicked();
    void on_searchButton_clicked();
private:
    Ui::SearchForm *m_ui;
    QSqlTableModel *m_model;
    bool *m_cancel;
    QString m_searchString;
}; // end class

#endif // SEARCHFORM_H
