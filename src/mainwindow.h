#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>

#include "cscreenw.h"
#include "spritesw.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent( QCloseEvent *pEvent );

private slots:

    // Menu Project:
    void on_action_Project_New_triggered();
    void on_action_Project_Load_triggered();
    void on_action_Project_Save_triggered();
    void on_action_Project_Save_as_triggered();
    void on_action_Project_Close_triggered();
    void on_action_Project_Import_Polka_triggered();
    void on_action_Project_Export_Polka_triggered();
    void on_action_Project_Quit_triggered();

    // Menu Screen:
    void on_action_Screen_New_triggered();
    void on_action_Screen_Load_triggered();
    void on_action_Screen_Save_triggered();
    void on_action_Screen_Save_as_triggered();
    void on_action_Screen_Export_Screen_triggered();
    void on_action_Screen_Export_Map_PNG_File_triggered();
    void on_action_Screen_Export_Screen_PNG_File_triggered();
    void on_action_Screen_Fill_Screen_whith_tiles_1_to_255_triggered();
    void on_action_Screen_Exchange_tiles_triggered();

    // Menu Palette:
    void on_action_Palette_New_triggered();
    void on_action_Palette_Load_triggered();
    void on_action_Palette_Save_triggered();
    void on_action_Palette_Save_as_triggered();
    void on_action_Palette_Export_ASM_triggered();
    void on_action_Palette_Create_PNG_triggered();

    // Menu Tiles:
    void on_action_Tiles_New_triggered();
    void on_action_Tiles_Load_triggered();
    void on_action_Tiles_Save_triggered();
    void on_action_Tiles_Save_as_triggered();
    void on_action_Tiles_Load_from_Library_triggered();
    void on_action_Tiles_Export_ASM_data_triggered();
    void on_action_Tiles_Export_ASM_data_Hexadecimal_triggered();
    void on_action_Tiles_Export_bin_data_triggered();
    void on_action_Tiles_Export_bin_data_compressed_whith_Pletter_triggered();
    void on_action_Tiles_Export_PNG_file_triggered();
    void on_action_Tiles_Import_PNG_file_created_whith_nMSXtiles_triggered();
    void on_action_Tiles_Import_triggered();

    // Menu Tiles Tools:
    void on_action_Tiles_Tools_Reorder_colors_triggered();
    void on_action_Tiles_Tools_Copy_triggered();
    void on_action_Tiles_Tools_Paste_triggered();
    void on_action_Tiles_Tools_Paste_colors_triggered();
    void on_action_Tiles_Tools_Undo_triggered();
    void on_action_Tiles_Tools_Group_Tiles_triggered();

    // Menu Sprites:
    void on_action_Sprites_New_triggered();
    void on_action_Sprites_Load_triggered();
    void on_action_Sprites_Save_triggered();
    void on_action_Sprites_Save_as_triggered();
    void on_action_Sprites_Close_triggered();
    void on_action_Sprites_Export_triggered();

    // About:
    void on_action_About_nMSXtiles_triggered();
    void on_action_About_pentacour_triggered();
    void on_action_About_pipagerardo_triggered();
    void on_action_About_QT_triggered();

    void on_action_Palette_Change_triggered();

    void on_action_Palette_Export_VDP_triggered();

private:
    Ui::MainWindow *ui;

    QMdiSubWindow *m_pScreen_sbw;
    QMdiSubWindow *m_pSprites_sbw;
    CScreenW  *m_pScreen;
    CSpritesW *m_pSprites;

    QString m_ProjectFile;
    QString m_ScreenFile;
    QString m_PaletteFile;
    QString m_TilesFile;
    QString m_SpritesFile;
    QString m_LastPathLoadProject;
    QString m_LastPathExport;
    QString m_Version;

    int m_LastFormat;
    int m_LastFilesMode;
    int m_LastWidth;
    int m_LastHeight;
    int m_LastX;
    int m_LastY;

    void InitScreen();
    void QuitScreen();
    void InitSprites();
    void QuitSprites();
    void SaveProject();
    void EnableMenuItems();

};

#endif // MAINWINDOW_H
