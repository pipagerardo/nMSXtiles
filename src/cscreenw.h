#ifndef SCREENW_H
#define SCREENW_H

// #include "ui_fscreenw.h"
#include "tile.h"
#include "labelbtn.h"
#include <QCloseEvent>
#include <QLabel>
#include <QDialog>
#include <QObject>
#include <QImage>
#include <QPoint>
#include <QPoint>
#include <QTabWidget>
#include <QDrag>

namespace Ui {
class CScreenW;
}

// class CScreenW : public QDialog, public Ui_FScreenW
class CScreenW : public QDialog
{
    Q_OBJECT
	
	static const int PAL_ALL;

signals:
    void signal_close();

public:
    explicit CScreenW( QWidget *parent = 0 );
    ~CScreenW();

protected:
    void closeEvent( QCloseEvent *pEvent );
    void keyPressEvent(QKeyEvent *e);

public:
    int get_MapWidth();
    int get_MapHeight();
    void SetMapWidth( int value);
    void SetMapHeight( int value);

	void Initialize();

    // Screen:
	void NewScreen();
	bool LoadScreen( QString fileName );
	bool SaveScreen( QString fileName );
    bool ExportScreenData( QString fileName, bool hexa, int initX, int initY, int w, int h );
    bool ExportScreenBin( QString fileName, int initX, int initY, int w, int h );
    bool ExportScreenBinScroll( QString fileName, int initX, int initY, int w, int h );
    bool ExportScreenBinPletter( QString fileName, int initX, int initY, int w, int h );
    bool ExportScreenBinPletterScroll( QString fileName, int initX, int initY, int w, int h );
    bool ExportScreenPNG( QString fileName );
    bool ExportMapPNG( QString fileName );
    bool GenPNGPaletteFile( QString fileName );
    void ExchangeTiles( int tile1, int tile2 );

    // Palette:
    void UpdatePalette();
    void NewPalette();
    bool LoadPalette( QString fileName );
    bool SavePalette( QString fileName );
    bool ExportPaletteASM( QString fileName );
    bool ExportPaletteVDP( QString fileName );

    // Tiles:
	void NewTiles();
	bool LoadTiles( QString fileName );
	bool LoadTilesLibrary( QString fileName, int bankOr, int xOr, int yOr, int width, int height, int bankDest, int xDest, int yDest );
	bool SaveTiles( QString fileName );
	bool ExportTilesData( QString fileName, bool hexa );
	bool ExportTilesBin( QString fileName );
	void ExportTilesBinPletter( QString fileName );
    void ExportTilesPNG( QString fileName );
    bool ImportTiles( QString fileName, QString paletteFileName = "" );
    //bool ImportTilesPNGAdv( QString fileName );
	bool ImportPolkaTiles( QString fileName );
	bool ExportPolkaTiles( QString fileName );
    void ReorderColors();
	void CopyTile();
	void PasteTile();
	void PasteTileColors();
	void Undo();
	void GroupTiles();
	void SetOneBank( bool value );
	bool GetOneBank();
    void Fill1to255();
	
public slots:
    void OnBank0Click( int x, int y);
    void OnBank1Click( int x, int y);
    void OnBank2Click( int x, int y);
    void OnBank0ClickRight( int x, int y);
    void OnBank1ClickRight( int x, int y);
    void OnBank2ClickRight( int x, int y);
    void OnBank0DoubleClick( int x, int y );
    void OnBank1DoubleClick( int x, int y );
    void OnBank2DoubleClick( int x, int y );
    void OnPaletteClick( int x, int y );
    void OnPalBackClick( int, int );
    void OnPalForeClick( int, int );
    void OnColorsClick( int x, int y );
    void OnColorsChange( int x, int y );     // Cambia el color de la paleta (Nuevo)
    void OnTileClickLeft( int x, int y );
    void OnTileClickRight( int x, int y );
    void OnFromBank();
    void OnToBank();
    void OnScreenClickLeft( int x, int y );
    void OnScreenReleaseLeft( int x, int y );
    void OnScreenReleaseRight( int x, int y );
    void OnRadBack();
    void OnRadFore();
    void OnBankChanged( int index );
    void OnTileClear();
    void OnTileReorder();
    void OnTileRotate();
    void OnTileInvertColors();
    void OnTileShiftDown();
    void OnTileShiftUp();
    void OnTileShiftLeft();
    void OnTileShiftRight();
    void OnTileFlipHorizontal();
    void OnTileFlipVertical();
    void OnScreenMouseMoveEvent( int x, int y );
    //void OnBankTileMouseMoveEvent( int x, int y );
    void OnBankTileDoubleClickLeft( int , int  );
    void OnOneBank();
    void OnQuitFocus( int );
    void OnChangeColors();
    void OnMapXChanged(int value );
    void OnMapYChanged( int value );
    void OnMapNextX();
    void OnMapPrevX();
    void OnMapNextY();
    void OnMapPrevY();
    void OnMapWidthChanged(int value);
    void OnMapHeightChanged(int value);

public:
    uint COLORS_TABLE_SCREEN[16];
private:
    Ui::CScreenW *ui;

	QTabWidget *m_pTabBank;
	QFrame *m_pFrmBank[3];
	CLabelBtn *m_pLblBank[3];
	CLabelBtn *m_pLblPalette;
	CLabelBtn *m_pLblPalBack;
	CLabelBtn *m_pLblPalFore;
	CLabelBtn *m_pLblTile;
	CLabelBtn *m_pLblColors;
	CLabelBtn *m_pLblScreen;
	bool m_Selecting;
	CTile m_TilesBank[256][3];
	CTile m_TileDesign;
	CTile m_CopyTile;
    int m_Screen[64][64][256*3];	//Codi de Tile assignat
    unsigned char m_Buffer[256*3*64*64]; //TODO - 1
	QPoint m_SelColor;
	QPoint m_SelTile;
	QImage m_BankImages[3];
	QLabel *m_pColsLabels[32];
	QLabel *m_pRowsLabels[24];
	QPoint m_LastGridValue;
	QList<QVariant> m_Undo;
	CTile m_UndoTile;
	QPoint m_LastClickPos;
	CLabelBtn *m_pLblSelection;
	QList< QList<int> > m_ScreenSelection;		//Codis de Tile sel_leccionats
	QList< QList<int> > m_ScreenSelectionCopy;	//Copia de m_ScreenSelection en fer Copiar
	QRect m_SelectionRect;						//Rectangle de sel_leccio
	int m_LastTilesBlockW;
	int m_LastTilesBlockH;

    int m_MapScreenX;
    int m_MapScreenY;
	int m_MouseX;
	int m_MouseY;
    int m_CurrentScreen;
	QImage m_CursorImage;
	CLabelBtn *m_pLblCursor[4];
	QDrag *m_pDrag;
    int m_LastBank;
    int m_LastBankX;
    int m_LastBankY;
	
	void CopyToTileDesign( int index, int bank );
	void SetTileDesign();
	void UpdateBank( int tile, int bank, bool updateBank = true );
	void UpdateScreen();
	void InitBanks();
    int GetBackgroundTile( int y );
	
	void PaintTile( QImage *pImage, CTile &tile, int posX, int posY, int dotSize );
	void PaintGrid( QImage *pImage, int gridWidth, int gridHeight );
	
	void OnBankClick( int x, int y, int bank );
    void OnBankClickRight( int x, int y, int bank );
	void OnBankDoubleClick( int x, int y, int bank );
	
	int GetColor( unsigned int color, unsigned int palette[] );

    bool DeduceColorPalette( unsigned int color, unsigned int palette[16] );
    void CheckImagePalette( QString fileName, unsigned int palette[] );

};

#endif
