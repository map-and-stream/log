#pragma once

#ifndef ENCRYPTHELPER_H
#define ENCRYPTHELPER_H

#include <QString>
#include <QByteArray>

#include "qaesencryption.h"

class EncryptHelper
{
public:
    EncryptHelper();
    QString encrypt(const QString &strValue);
private:
    QByteArray key;
    QByteArray iv;
    QAESEncryption aes;
};

#endif // ENCRYPTHELPER_H
