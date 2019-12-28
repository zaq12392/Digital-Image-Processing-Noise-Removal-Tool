#include "QtGuiApplication2.h"
#include <iostream>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QDebug>
#include <QValidator>

using namespace cv;
using namespace std;

int kernel = 5;
QString fileName;
QImage result;
QImage cvMat2QImage(const cv::Mat& mat)
{
	// 8-bits unsigned, NO. OF CHANNELS = 1
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		qDebug() << "CV_8UC4";
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}
}
QtGuiApplication2::QtGuiApplication2(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->image = new QImage();

	//連結按鍵
	connect(ui.upload_Bot, SIGNAL(clicked()), this, SLOT(on_Upload_clicked()));
	connect(ui.method1, SIGNAL(clicked()), this, SLOT(on_Method1_clicked()));
	connect(ui.method2, SIGNAL(clicked()), this, SLOT(on_Method2_clicked()));
	connect(ui.method3, SIGNAL(clicked()), this, SLOT(on_Method3_clicked()));
	connect(ui.finish_Bot, SIGNAL(clicked()), this, SLOT(on_Finish_clicked()));
	connect(ui.kernel_Check, SIGNAL(clicked()), this, SLOT(on_KernelCheck_clicked()));
}

//上傳圖片
void QtGuiApplication2::on_Upload_clicked() {
	//上傳檔案的FUN getOpenFileName(this , "視窗名稱" , "." , "檔案格式 多重個就用::隔開")
	fileName = QFileDialog::getOpenFileName(
		this, "open image file",
		".",
		"Image files (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
	//LOAD檔案名
	image->load(fileName);
	//QQGraphicsView顯示圖片的用法
	QGraphicsScene *scene = new QGraphicsScene;
	scene->addPixmap(QPixmap::fromImage(*image));
	ui.img_src->setScene(scene);
	ui.img_src->resize(531, 501);
	ui.img_src->show();
}
//方法1  medianBlur
void QtGuiApplication2::on_Method1_clicked() {
	std::string name = fileName.toLocal8Bit().constData();
	Mat src = imread(name, IMREAD_COLOR);
	Mat blurImg;
	medianBlur(src, blurImg, kernel);
	result = cvMat2QImage(blurImg);
	QGraphicsScene *scene2 = new QGraphicsScene;
	scene2->addPixmap(QPixmap::fromImage(result));
	ui.img_after->setScene(scene2);
	ui.img_after->resize(531, 501);
	ui.img_after->show();
}
//方法2 GaussianBlur
void QtGuiApplication2::on_Method2_clicked() {
	std::string name = fileName.toLocal8Bit().constData();
	Mat src = imread(name, IMREAD_COLOR);
	Mat blurImg;
	GaussianBlur(src, blurImg, Size(kernel, kernel), 0, 0);
	result = cvMat2QImage(blurImg);
	QGraphicsScene *scene2 = new QGraphicsScene;
	scene2->addPixmap(QPixmap::fromImage(result));
	ui.img_after->setScene(scene2);
	ui.img_after->resize(531, 501);
	ui.img_after->show();
}

//方法3 Blur
void QtGuiApplication2::on_Method3_clicked() {
	std::string name = fileName.toLocal8Bit().constData();
	Mat src = imread(name, IMREAD_COLOR);
	Mat blurImg;
	blur(src, blurImg, Size(kernel, kernel));
	result = cvMat2QImage(blurImg);
	QGraphicsScene *scene2 = new QGraphicsScene;
	scene2->addPixmap(QPixmap::fromImage(result));
	ui.img_after->setScene(scene2);
	ui.img_after->resize(531, 501);
	ui.img_after->show();
}
//輸出檔案
void QtGuiApplication2::on_Finish_clicked() {

	QString file_path = QFileDialog::getSaveFileName(this, tr("Save File"),
		"/home/jana/untitled.png",
		tr("Images (*.png *.xpm *.jpg)"));
	if (!file_path.isEmpty())
	{
		//如果沒有寫字尾就自動加上
		if (QFileInfo(file_path).suffix().isEmpty())
			file_path.append(".png");
		result.save(file_path);
	}
	
}
//change kernel
void QtGuiApplication2::on_KernelCheck_clicked() {
	QString input = ui.kernel_Input->text();
	kernel = ui.kernel_Input->text().toInt();
}




