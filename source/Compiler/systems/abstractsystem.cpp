#include "abstractsystem.h"
#include <QProcess>

QMap<SystemLabel::Type, QColor> AbstractSystem::m_labelColors;

AbstractSystem::AbstractSystem(AbstractSystem *a) {
}

void AbstractSystem::StartProcess(QString file, QStringList params, QString& output) {
   // qDebug() << params;
    QProcess process;
    process.start(file, params);
    process.waitForFinished();
//    qDebug() << process.readAllStandardOutput();;
//    qDebug() << process.readAllStandardError();
//        output+= process.readAllStandardOutput();
    output+= process.readAllStandardError();

}

void AbstractSystem::InitLabelColors() {
    m_labelColors[SystemLabel::IO] = QColor(255,128,50);
    m_labelColors[SystemLabel::SID] = QColor(255,255,128);
    m_labelColors[SystemLabel::VIC] = QColor(64,128,255);
    m_labelColors[SystemLabel::FREE] = QColor(128,192,128);
    m_labelColors[SystemLabel::ROM] = QColor(64,192,200);
    m_labelColors[SystemLabel::BASIC] = QColor(64,64,255);
    m_labelColors[SystemLabel::STACK] = QColor(255,128,64);
    m_labelColors[SystemLabel::COLOUR] = QColor(255,64,255);
    m_labelColors[SystemLabel::KERNAL] = QColor(64,64,64);
    m_labelColors[SystemLabel::SCREEN] = QColor(64,255,255);
    m_labelColors[SystemLabel::ZEROPAGE] = QColor(64,255,128);


}

void AbstractSystem::AcceptDispatcherTick(QString val)
{
    emit EmitTick(val);
}
