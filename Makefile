all: build/nMSXTiles

build/nMSXTiles:
	cd src && qmake && make
