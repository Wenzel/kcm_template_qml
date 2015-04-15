/* This file is part of the KDE Project
   Copyright (c) 2014 Marco Martin <mart@kde.org>
   Copyright (c) 2014 Vishesh Handa <me@vhanda.in>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "kcm.h"
#include <klauncher_iface.h>
#include <KPluginFactory>
#include <KPluginLoader>
#include <KAboutData>
#include <KLocalizedString>

K_PLUGIN_FACTORY_WITH_JSON(KCMLookandFeelFactory, "kcm_lookandfeel.json", registerPlugin<KCMLookandFeel>();)

KCMLookandFeel::KCMLookandFeel(QObject* parent, const QVariantList& args)
    : KQuickAddons::ConfigModule(parent, args)
{
    KAboutData* about = new KAboutData("kcm_lookandfeel", i18n("Configure Look and Feel details"),
                                       "0.1", QString(), KAboutLicense::LGPL);
    about->addAuthor(i18n("Marco Martin"), QString(), "mart@kde.org");
    setAboutData(about);
    setButtons(Help | Apply | Default);
}

KCMLookandFeel::~KCMLookandFeel()
{
}
