#  Project file for QGreatstAtzenta.
#
#  Copyright (C) 2011-2020 Stavros Filippidis
#  Contact: sfilippidis@gmail.com
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
    mainwindow.cpp \
    personform.cpp \
    searchform.cpp
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
