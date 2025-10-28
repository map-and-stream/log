#include <QtTest/QtTest>
#include "encrypthelper.h"
#include "decrypthelper.h"

class EncryptRoundTripTest : public QObject
{
    Q_OBJECT

private slots:
    void basic()
    {
        EncryptHelper enc;
        DecryptHelper dec;
        QString src = "hello world";
        QString encrypted = enc.encrypt(src);
        QString decrypted = dec.decrypt(encrypted);
        QCOMPARE(decrypted, src);
    }
};

QTEST_MAIN(EncryptRoundTripTest)

#include "encrypt_roundtrip.moc"
