/* Simple Chat
 * Copyright (c) 2008-2014 Alexander Sedov <imp@schat.me>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ChatCore.h"
#include "interfaces/IPlugin.h"
#include "sglobal.h"
#include "ShareButton.h"
#include "ShareChatView.h"
#include "ShareCore.h"
#include "Translation.h"
#include "ui/SendWidget.h"

IMPORT_PLUGIN(NoneProvider)
IMPORT_PLUGIN(RupProvider)
IMPORT_PLUGIN(ImgurProvider)
IMPORT_PLUGIN(GeekpicProvider)

ShareCore::ShareCore(QObject *parent)
  : ChatPlugin(parent)
{
  ChatCore::translation()->addOther(LS("share"));
}


void ShareCore::chatReady()
{
  new ShareChatView(this);

  SendWidget::add(new ShareAction(this));
}
