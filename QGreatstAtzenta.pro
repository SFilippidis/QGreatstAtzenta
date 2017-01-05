#  Project file for QGreatstAtzenta.
#
#  Copyright (C) 2011-2017 Stavros Filippidis
#  Contact: stavros@filippidis.name
#
#  This file is part of QGreatstAtzenta.
#
#  QGreatstAtzenta is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  QGreatstAtzenta is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with QGreatstAtzenta.  If not, see <http://www.gnu.org/licenses/>.

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = QGreatstAtzenta
TEMPLATE = app
SOURCES += main.cpp\
    mainwindow_infowindow.cpp \
    mainwindow_usedb.cpp \
    mainwindow_createorloaddb.cpp \
    mainwindow_resetmodelviewlayout.cpp \
    mainwindow_destructor.cpp \
    mainwindow_constructor.cpp \
    personform_constructor.cpp \
    personform_destructor.cpp \
    searchform_constructor.cpp \
    searchform_destructor.cpp \
    mainwindow_slot_about.cpp \
    mainwindow_slot_on_addbutton_clicked.cpp \
    mainwindow_slot_on_deletebutton_clicked.cpp \
    mainwindow_slot_on_editorviewbutton_clicked.cpp \
    mainwindow_slot_on_quitbutton_clicked.cpp \
    mainwindow_slot_on_searchbutton_clicked.cpp \
    personform_slot_on_addbutton_clicked.cpp \
    personform_slot_on_cancelbutton_clicked.cpp \
    searchform_slot_on_cancelbutton_clicked.cpp \
    searchform_slot_on_searchbutton_clicked.cpp
HEADERS  += mainwindow.h \
    personform.h \
    searchform.h \
    atzenta_enum.h \
    person_enum.h
FORMS    += mainwindow.ui \
    personform.ui \
    searchform.ui
mac {
    ICON = QGreatstAtzenta.icns
}
win32-g++ {
    RC_FILE = QGreatstAtzenta.rc
}
