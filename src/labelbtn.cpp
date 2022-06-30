#include <labelbtn.h>
#include <QImage>
#include <QPixmap>
#include <QDebug>

CLabelBtn::CLabelBtn( QWidget *pParent, int w, int h ):QLabel( pParent )
{
	int y, x;
	
	m_Image = QImage( w, h, QImage::Format_RGB32 );

	for( y = 0; y < h; y++ ) for( x = 0; x < w; x++ ) m_Image.setPixel( x, y , 0xff000000 );
	
	setPixmap( QPixmap::fromImage( m_Image ) );
	setAlignment( Qt::AlignTop );
}

void CLabelBtn::put_Image( const QImage &image )
{
	m_Image = image;
	setPixmap( QPixmap::fromImage( m_Image ) );
}

QImage& CLabelBtn::get_Image()
{
	return m_Image;
}

void CLabelBtn::mouseReleaseEvent( QMouseEvent *pE )
{
	if( pE->button() == Qt::LeftButton ) emit onReleasedLeft( pE->position().x(), pE->position().y() );
	else if( pE->button() == Qt::RightButton ) emit onReleasedRight( pE->position().x(), pE->position().y() );
}

void CLabelBtn::mousePressEvent( QMouseEvent *pE )
{
	if( pE->button() == Qt::LeftButton ) emit onClickedLeft( pE->position().x(), pE->position().y() );
	else if( pE->button() == Qt::RightButton ) emit onClickedRight( pE->position().x(), pE->position().y() );
}

void CLabelBtn::mouseDoubleClickEvent( QMouseEvent *pE )
{
	if( pE->button() == Qt::LeftButton ) emit onDoubleClickedLeft( pE->position().x(), pE->position().y() );
}

void CLabelBtn::mouseMoveEvent( QMouseEvent *pEvent )
{
    emit onMouseMoveEvent( pEvent->position().x(), pEvent->position().y() );
}

void CLabelBtn::SetPixel( int x, int y, uint color )
{
	m_Image.setPixel( x, y, color );
	setPixmap( QPixmap::fromImage( m_Image ) );
}

void CLabelBtnMove::mouseMoveEvent( QMouseEvent *pEvent ) {
    if( ( pEvent->position().x() < 0 ) || ( pEvent->position().x() >= m_Image.width()  ) ) return;
    if( ( pEvent->position().y() < 0 ) || ( pEvent->position().y() >= m_Image.height() ) ) return;
    switch( pEvent->buttons() ) {
        case Qt::LeftButton:
            emit onClickedLeft( pEvent->position().x(), pEvent->position().y() );
        break;
        case Qt::RightButton:
             emit onClickedRight( pEvent->position().x(), pEvent->position().y() );
        break;
    }
    // ¿ Es necesario ?
    // emit onMouseMoveEvent( pEvent->position().x(), pEvent->position().y() );
}
