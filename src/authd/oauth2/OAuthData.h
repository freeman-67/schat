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

#ifndef OAUTHDATA_H_
#define OAUTHDATA_H_

#include <QString>
#include <QVariant>

#include "schat.h"

class OAuthData
{
public:
  OAuthData(const QByteArray &provider = QByteArray());
  virtual ~OAuthData() {}
  virtual bool isValid() const;
  virtual bool read();
  virtual QVariantList toList() const;
  virtual QVariantMap toJSON(const QByteArray &state) const;

  QByteArray id;        ///< Client ID.
  QByteArray htmlName;  ///< HTML имя провайдера.
  QByteArray name;      ///< Имя провайдера.
  QByteArray provider;  ///< Кодовое имя OAuth2 провайдера.
  QByteArray redirect;  ///< Redirect URI.
  QByteArray secret;    ///< Client secret.
  QByteArray type;      ///< Тип провайдера.
  QByteArray publicKey; ///< Публичный ключ приложения.

protected:
  virtual QByteArray toUrl(const QByteArray &state) const = 0;
};

#endif /* OAUTHDATA_H_ */
