// MainWindow::about slot implementation.

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

#include "mainwindow.h"

void MainWindow::about()
{
    QString licenceAndInfoText = QString::fromWCharArray(L"QGreatstAtzenta. Version 1.3.4+. A program for organizing your contacts.<BR>"
                                                         "<BR>Copyright (C) "
                                                         "2011-2020 Stavros Filippidis<BR>"
                                                         "email: <A HREF='mailto:sfilippidis"
                                                         "@gmail.com'>sfilippidis@gmail.com"
                                                         "</A><BR>www: <A HREF='https://blogs"
                                                         ".sch.gr/sfil/'>https://blogs.sch.gr"
                                                         "/sfil/</A><BR><BR>QGreatstAtzenta is"
                                                         " free software: you can redistribute"
                                                         " it and/or modify<BR>it under the terms"
                                                         " of the GNU General Public License as "
                                                         "published by<BR>the Free Software "
                                                         "Foundation, either version 3 of the "
                                                         "License, or<BR>(at your option) any "
                                                         "later version.<BR><BR>QGreatstAtzenta"
                                                         " is distributed in the hope that it "
                                                         "will be useful,<BR>but WITHOUT ANY "
                                                         "WARRANTY; without even the implied "
                                                         "warranty of<BR>MERCHANTABILITY or FITNESS"
                                                         " FOR A PARTICULAR PURPOSE.  See the<BR>GNU"
                                                         " General Public License for more details."
                                                         "<BR><BR>You should have received a copy "
                                                         "of the GNU General Public License<BR>along "
                                                         "with QGreatstAtzenta.  If not, see <A HREF"
                                                         "='http://www.gnu.org/licenses/'>http://www."
                                                         "gnu.org/licenses/</A>.<BR>");
    QString licenceTitle = QString::fromWCharArray(L"About QGreatstAtzenta");
    infoWindow(licenceAndInfoText, licenceTitle, QMessageBox::NoIcon);
}
