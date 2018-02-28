#ifndef XMLCONFIG_H
#define XMLCONFIG_H

#include <QtXml>
#include <QStandardItemModel>

class XmlConfig
{
public:
    XmlConfig();

    static void createXml(QStandardItemModel *treemodel, QStandardItemModel *tablemodel,QString softname);
    //处理WebServices返回的xml数据
    void getUpdateInfo(QString _xmlStr, QStandardItemModel *_tableModel);
    QString getOneQueryData(QString _xmlStr);
signals:
    void parseComplete();
private:
    static XmlConfig *m_pXmlConfig;

};

#endif // XMLCONFIG_H
