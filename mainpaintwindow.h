#ifndef MAINPAINTWINDOW_H
#define MAINPAINTWINDOW_H

#include <QMainWindow>
#include "paintscene.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainPaintWindow; }
QT_END_NAMESPACE

class MainPaintWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainPaintWindow(QWidget *parent = nullptr);
    ~MainPaintWindow();

public slots:
    void initScene();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainPaintWindow *ui;
    PaintScene *scene;
    QTimer *timer;
};
#endif // MAINPAINTWINDOW_H
