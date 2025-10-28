#include "encrypthelper.h"
#include <QtGlobal> // qgetenv

EncryptHelper::EncryptHelper():
    key(qgetenv("WS_KEY").isEmpty() ? QByteArray("1234567890abcdef") : qgetenv("WS_KEY")),
    iv(qgetenv("WS_IV").isEmpty() ? QByteArray("fedcba0987654321") : qgetenv("WS_IV")),
    aes(QAESEncryption::AES_128, QAESEncryption::CBC)
{

}

QString EncryptHelper::encrypt(const QString &strValue)
{
    QByteArray encrypted = aes.encode(strValue.toUtf8(), key, iv);
    return QString::fromUtf8(encrypted.toBase64());
}
