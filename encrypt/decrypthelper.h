#ifndef DECRYPTHELPER_H
#define DECRYPTHELPER_H
#pragma once
#include <QString>
#include <QByteArray>
#include "qaesencryption.h"
class DecryptHelper
{
public:
    DecryptHelper();
    QString decrypt(const QString &encryptedBase64);

private:
    QByteArray key;
    QByteArray iv;
    QAESEncryption aes;
};

#endif // DECRYPTHELPER_H
