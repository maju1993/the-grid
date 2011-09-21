//////////////////////////////////////////////////////////////////////
// (c) Janusz Ganczarski
// http://www.januszg.hg.pl
// JanuszG@enter.net.pl
//////////////////////////////////////////////////////////////////////

#ifndef __TARGA__H__
#define __TARGA__H__

#include "extensions3.h"

//////////////////////////////////////////////////////////////////////
// odczyt pliku graficznego w formacie TARGA
// fileName - nazwa pliku
// width - szeroko�� obrazu
// height - wysoko�� obrazu
// format - format danych obrazu
// type - format danych pikseli obrazu
// pixels - wska�nik do tablicy z danymi obrazu
//////////////////////////////////////////////////////////////////////
GLboolean loadTarga( const char *fileName, GLsizei &width, GLsizei &height,
                     GLenum &format, GLenum &type, GLvoid *&pixels );

//////////////////////////////////////////////////////////////////////
// zapis pliku graficznego w formacie TARGA
// fileName - nazwa pliku
// width - szeroko�� obrazu
// height - wysoko�� obrazu
// format - format danych obrazu
// type - format danych pikseli obrazu
// pixels - wska�nik do tablicy z danymi obrazu
//////////////////////////////////////////////////////////////////////
GLboolean saveTarga( const char *fileName, GLsizei width, GLsizei height,
                      GLenum format, GLenum type, GLvoid *pixels );

#endif // __TARGA__H__

