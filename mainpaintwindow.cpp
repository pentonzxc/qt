#include "mainpaintwindow.h"
#include "ui_mainpaintwindow.h"

MainPaintWindow::MainPaintWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPaintWindow),
        scene(new PaintScene()),
        timer(new QTimer())
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
       ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
        connect(timer, &QTimer::timeout, this, &MainPaintWindow::initScene);

}

MainPaintWindow::~MainPaintWindow()
{
    delete ui;
}

void MainPaintWindow::initScene()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 5, ui->graphicsView->height() - 5);
}


void MainPaintWindow::on_pushButton_clicked()
{
    scene->setAction(PaintScene::RectangleMode);
}


void MainPaintWindow::on_pushButton_2_clicked()
{
    scene->setAction(PaintScene::EllipseMode);

}


void MainPaintWindow::on_pushButton_3_clicked()
{
    scene->setAction(PaintScene::LineMode);

}


void MainPaintWindow::on_pushButton_4_clicked()
{
    scene->setAction(PaintScene::DrawMode);

}


void MainPaintWindow::on_pushButton_5_clicked()
{
    scene->setAction(PaintScene::EditMode);

}

