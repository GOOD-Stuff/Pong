#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QLineEdit>
#include <QFile>
#include <QPushButton>
#include <QTextStream>
#include <QGridLayout>

class Settings : public QWidget {
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
signals:

public slots:

private slots:
    void slotSaveName();

private:
    QPushButton *btn_ok;
    QPushButton *btn_exit;
    QLineEdit   *lne_name;
    QFile       *setting_file;
    QGridLayout *grid_lay;
};

#endif // SETTINGS_H
