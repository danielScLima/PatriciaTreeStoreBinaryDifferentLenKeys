#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "patriciatreestorebinarydifferentlenkeys.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow
     * \param parent
     */
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    /*!
     * \brief on_pushButtonOfInsert_clicked
     */
    void on_pushButtonOfInsert_clicked();

    /*!
     * \brief on_pushButtonOfSearch_clicked
     */
    void on_pushButtonOfSearch_clicked();

    /*!
     * \brief on_pushButtonOfRemove_clicked
     */
    void on_pushButtonOfRemove_clicked();

private:
    Ui::MainWindow *ui;

    PatriciaTreeStoreBinaryDifferentLenKeys* patriciaTreeStoreBinaryDifferentLenKeys = nullptr;

    /*!
     * \brief updateDotFile
     */
    void updateDotFile();

    /*!
     * \brief updateImage
     */
    void updateImage();

    /*!
     * \brief renderImage
     */
    void renderImage();

    /*!
     * \brief reloadDraw
     */
    void reloadDraw();
};
#endif // MAINWINDOW_H
