#include "decrypthelper.h"
#include <QtGlobal> // qgetenv

DecryptHelper::DecryptHelper() :
    key(qgetenv("WS_KEY").isEmpty() ? QByteArray("1234567890abcdef") : qgetenv("WS_KEY")),
    iv(qgetenv("WS_IV").isEmpty() ? QByteArray("fedcba0987654321") : qgetenv("WS_IV")),
    aes(QAESEncryption::AES_128, QAESEncryption::CBC)
{}

QString DecryptHelper::decrypt(const QString &encryptedBase64)
{
    QByteArray encrypted = QByteArray::fromBase64(encryptedBase64.toUtf8());
    QByteArray decrypted = aes.decode(encrypted, key, iv);
    decrypted = QAESEncryption::RemovePadding(decrypted);
    return QString::fromUtf8(decrypted);
}
