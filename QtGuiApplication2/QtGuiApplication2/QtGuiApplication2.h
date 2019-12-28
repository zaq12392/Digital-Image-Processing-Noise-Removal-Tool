#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication2.h"
#include <iostream>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <QMainWindow>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFileDialog>


using namespace cv;
using namespace std;

class QtGuiApplication2 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication2(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApplication2Class ui;
	QImage *image;
	//傳遞訊息 設定案件函式
private slots:
	void on_Upload_clicked();
	void on_Method1_clicked();
	void on_Method2_clicked();
	void on_Method3_clicked();
	void on_Finish_clicked();
	void on_KernelCheck_clicked();
};
