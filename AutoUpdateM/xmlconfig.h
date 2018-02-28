#ifndef XMLCONFIG_H
#define XMLCONFIG_H

#include <QtXml>
#include <QStandardItemModel>
//自定义树节点
class treeNode
{
public:
    treeNode(QStandardItem *_node_item,QString _code,
             QString _parent_code):node_item(_node_item),code(_code),parent_code(_parent_code){}
    treeNode(){}
    //因为要放到QHash里面需要重载==
    bool operator == (const treeNode &t)const{
        return (code==t.code);
    }
public:
    QStandardItem *node_item;
    QString code;
    QString parent_code;
};


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
    void addTreeViewItem(QStandardItemModel *_tableModel);

    void getInfo(QString _xmlStr, QStandardItemModel *_tableModel);

    //存放node节点
    QHash<QString,treeNode>treeNodes;
};

#endif // XMLCONFIG_H
