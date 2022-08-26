#include "window.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QString configfile, std::string additional_device_dir,
		const std::string host, const std::string port, bool overwrite_integrated_devices, QWidget *parent) : QMainWindow(parent) {
	setWindowTitle("MainWindow");

	central = new Central(configfile, additional_device_dir, host, port, overwrite_integrated_devices, this);
	setCentralWidget(central);
}

void MainWindow::resizeEvent(QResizeEvent *e) {
	setFixedSize(central->width(), central->height());
}

MainWindow::~MainWindow() {
	delete central;
}