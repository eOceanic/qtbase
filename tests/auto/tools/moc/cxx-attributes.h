/****************************************************************************
**
** Copyright (C) 2019 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef CXXATTRIBUTE_H
#define CXXATTRIBUTE_H

#include <QtCore/QObject>

class CppAttribute : public QObject
{
    Q_OBJECT
signals:
    [[deprecated]] void deprecatedSignal();

public slots:
    [[deprecated]] void deprecatedSlot() {}
    [[deprecated]] [[tst_moc::maybe_unused]] int deprecatedSlot2() { return 42; }
    [[deprecated("reason")]] void deprecatedReason() {}
    [[deprecated("reason[")]] void deprecatedReasonWithLBRACK() {}
    [[deprecated("reason[[")]] void deprecatedReasonWith2LBRACK() {}
    [[deprecated("reason]")]] void deprecatedReasonWithRBRACK() {}
    [[deprecated("reason]]")]] void deprecatedReasonWith2RBRACK() {}
    void slotWithArguments([[tst_moc::maybe_unused]] int) {}
#if !defined(_MSC_VER) || _MSC_VER >= 1912
    // On MSVC it causes:
    // moc_cxx-attributes.cpp(133): fatal error C1001: An internal error has occurred in the compiler.
    Q_INVOKABLE [[tst_moc::noreturn]] void noreturnSlot() { throw "unused"; }
    [[tst_moc::noreturn]] Q_SCRIPTABLE void noreturnSlot2() { throw "unused"; }
    [[deprecated]] int returnInt() { return 0; }
    Q_SLOT [[tst_moc::noreturn]] [[deprecated]] void noreturnDeprecatedSlot() { throw "unused"; }
    Q_INVOKABLE void noreturnSlot3() [[tst_moc::noreturn]] { throw "unused"; }
#endif
};

#endif // CXXATTRIBUTE_H
