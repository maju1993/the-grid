//////////////////////////////////////////////////////////////////////
// (c) Janusz Ganczarski
// http://www.januszg.hg.pl
// JanuszG@enter.net.pl
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "targa.h"

//////////////////////////////////////////////////////////////////////
// sta�e u�ywane przy obs�udze plik�w TARGA:
//////////////////////////////////////////////////////////////////////
#define TARGA_HEADER_SIZE 0x12      // rozmiar nag��wka pliku
#define TARGA_UNCOMP_RGB_IMG 0x02   // nieskompresowany obraz RGB(A)
#define TARGA_UNCOMP_BW_IMG 0x03    // nieskompresowany obraz w odcieniach szaro�ci

//////////////////////////////////////////////////////////////////////
// odczyt pliku graficznego w formacie TARGA
// fileName - nazwa pliku
// width - szeroko�� obrazu
// height - wysoko�� obrazu
// format - format danych obrazu
// type - format danych pikseli obrazu
// pixels - wska�nik na tablic� z danymi obrazu
//////////////////////////////////////////////////////////////////////
GLboolean loadTarga( const char *fileName, GLsizei &width, GLsizei &height,
                     GLenum &format, GLenum &type, GLvoid *&pixels )
{
    // pocz�tkowe warto�ci danych wyj�ciowych
    pixels = NULL;
    width = 0;
    height = 0;

    // otwarcie pliku do odczytu
    std::ifstream file;
    file.open( fileName, std::ios::binary );
    if( file.bad() )
        return GL_FALSE;

    // tablica na nag��wek pliku TGA
    unsigned char header[ TARGA_HEADER_SIZE ];

    // odczyt nag��wka pliku
    file.read( reinterpret_cast<char *>( header ), TARGA_HEADER_SIZE );

    // omini�cie pola ImageID
    file.seekg( header [0], std::ios::cur );

    // szeroko�� obrazu
    width = header [12] + (header [13] << 8);

    // wysoko�� obrazu
    height = header [14] + (header [15] << 8);

    // obraz w formacie BGR - 24 bity na piksel
    if( header [2] == TARGA_UNCOMP_RGB_IMG && header [16] == 24 )
    {
        pixels = new unsigned char [width * height * 3];
        file.read( static_cast<char *>( pixels ), width * height * 3 );
        format = GL_BGR;
        type = GL_UNSIGNED_BYTE;
    }
    else

        // obraz w formacie BGRA - 32 bity na piksel
        if( header [2] == TARGA_UNCOMP_RGB_IMG && header [16] == 32 )
        {
            pixels = new unsigned char [width * height * 4];
            file.read( static_cast<char *>( pixels ), width * height * 4 );
            format = GL_BGRA;
            type = GL_UNSIGNED_BYTE;
        }
        else

            // obraz w odcieniach szaro�ci - 8 bit�w na piksel
            if( header [2] == TARGA_UNCOMP_BW_IMG && header [16] == 8 )
            {
                pixels = new unsigned char [width * height];
                file.read( static_cast<char *>( pixels ), width * height );
                format = GL_RED;
                type = GL_UNSIGNED_BYTE;
            }
            else
                return GL_FALSE;

    // zamkni�cie pliku
    file.close();

    // sukces
    return GL_TRUE;
}

//////////////////////////////////////////////////////////////////////
// zapis pliku graficznego w formacie TARGA
// fileName - nazwa pliku
// width - szeroko�� obrazu
// height - wysoko�� obrazu
// format - format danych obrazu
// type - format danych pikseli obrazu
// pixels - wska�nik na tablic� z danymi obrazu
//////////////////////////////////////////////////////////////////////
GLboolean saveTarga( const char *fileName, GLsizei width, GLsizei height,
                     GLenum format, GLenum type, GLvoid *pixels )

{
    // sprawdzenie formatu danych obrazu
    if( format != GL_BGR && format != GL_BGRA && format != GL_RED )
        return GL_FALSE;

    // sprawdzenie formatu pikseli obrazu
    if( type != GL_UNSIGNED_BYTE )
        return GL_FALSE;

    // otwarcie pliku do zapisu
    std::ofstream file;
    file.open( fileName, std::ios::binary );
    if( file.bad() )
        return GL_FALSE;

    // nag��wek pliku TGA
    unsigned char header [TARGA_HEADER_SIZE];

    // wyzerowanie p�l nag��wka
    memset( header, 0, TARGA_HEADER_SIZE );

    // pole Image Type
    if( format == GL_BGR || format == GL_BGRA )
        header [2] = TARGA_UNCOMP_RGB_IMG;
    else
        if( format == GL_RED )
            header [2] = TARGA_UNCOMP_BW_IMG;

    // pole Width
    header [12] = (unsigned char)width;
    header [13] = (unsigned char)(width >> 8);

    // pole Height
    header [14] = (unsigned char)height;
    header [15] = (unsigned char)(height >> 8);

    // pole Pixel Depth
    if( format == GL_BGRA )
        header [16] = 32;
    else
        if( format == GL_BGR )
            header [16] = 24;
        else
            if( format == GL_RED )
                header [16] = 8;

    // zapis nag��wka pliku TARGA
    file.write( reinterpret_cast<char *>( header ), TARGA_HEADER_SIZE );

    // zapis danych obrazu
    if( format == GL_BGRA )
        file.write( static_cast<char *>( pixels ), width * height * 4 );
    else
        if( format == GL_BGR )
            file.write( static_cast<char *>( pixels ), width * height * 3 );
        else
            if( format == GL_RED )
                file.write( static_cast<char *>( pixels ), width * height );

    // zamkni�cie pliku
    file.close();

    // sukces
    return GL_TRUE;
}

