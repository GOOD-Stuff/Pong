#include "settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent) {
    btn_ok       = new QPushButton("Ok", this);
    btn_exit     = new QPushButton("Exit", this);
    setting_file = new QFile("pong.conf");
    lne_name     = new QLineEdit(this);
    lne_name->setText("Player1");

    connect(btn_ok, SIGNAL(clicked(bool)), this, SLOT(slotSaveName()));
    connect(btn_exit, SIGNAL(clicked(bool)), this, SLOT(close()));

    grid_lay = new QGridLayout(this);
    grid_lay->addWidget(lne_name, 0, 0);
    grid_lay->addWidget(btn_ok, 0, 1);
    grid_lay->addWidget(btn_exit, 2, 1);

    this->setLayout(grid_lay);
}


Settings::~Settings() {
    delete lne_name;
    delete btn_ok;
    delete btn_exit;
    delete grid_lay;
    delete setting_file;
}

void Settings::slotSaveName() {
    if (setting_file->open(QIODevice::WriteOnly)) {
        QTextStream ss(setting_file);
        ss << "player_name=" << lne_name->text() << endl;
        setting_file->close();
    }
}
