#ifndef MYCLIENT_H
#define MYCLIENT_H
#include <QWidget>
#include <QTcpSocket>
#include <iostream>
#include <QTextEdit>
#include <QTimeEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
class QTextEdit;
class QLineEdit;
// ======================================================================
class MyClient : public QWidget {
Q_OBJECT
private:
 QTcpSocket* m_pTcpSocket;
 QTextEdit* m_ptxtInfo;
 QLineEdit* m_ptxtInput;
 quint16 m_nNextBlockSize;
public:
 MyClient(const QString& strHost, int nPort, QWidget* pwgt = 0) ;
private slots:
 void slotReadyRead ( );
 void slotError (QAbstractSocket::SocketError err);
 void slotSendToServer( );
 void slotConnected ( );
};
#endif // MYCLIENT_H
