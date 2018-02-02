#ifndef TILE_H
#define TILE_H

#include <QList>
#include <QPoint>

class CTile
{
public:
	int get_ForeColor( int y );
	int get_BgColor( int y );
	int get_Pixel( int x, int y );
	
	void put_ForeColor( int y, int color );
	void put_BgColor( int y, int color );
	void put_Pixel( int x, int y, int color );
	
	CTile();

	void Reset();
	void Reorder();
    void ReorderLessFirst();
	void Rotate();
	int GetPixelColor( int x, int y );
	int GetBgColor( int y );
	int GetForeColor( int y );
	void SetBackColor( int y, int color );
	void SetForeColor( int y, int color );
	void SetBackPixel( int x, int y );
	void SetForePixel( int x, int y );
	int GetRowPattern( int row );
	int GetRowColor( int row );
	void InvertRow( int y );
	bool IsBlack();
	void ShiftUp();
	void ShiftDown();
	void ShiftLeft();
	void ShiftRight();
	void FlipHorizontal();
	void FlipVertical(); 
    void ChangeColors( QList<QPoint> changes );
	
private:
	int m_ForeColors[8];
	int m_BgColors[8];
	int m_Pixels[8][8];

};

#endif
