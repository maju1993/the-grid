//////////////////////////////////////////////////////////////////////
// (c) Janusz Ganczarski
// http://www.januszg.hg.pl
// JanuszG@enter.net.pl
//////////////////////////////////////////////////////////////////////

#ifndef __TEXT__H__
#define __TEXT__H__

#include <string>
#include "extensions3.h"
#include "colors.h"

//////////////////////////////////////////////////////////////////////
// microsoft-cp1250 charset font
// generated with /usr/bin/bdfassemble cp1250.txt
// on 1998-06-26 by czyborra@cs.tu-berlin.de
// http://czyborra.com/charsets/cp1250.bdf.gz
// FONT -misc-fixed-medium-r-normal--16-160-75-75-c-80-microsoft-cp1250
//////////////////////////////////////////////////////////////////////
extern const unsigned char font8x16CP1250[224][16];

//////////////////////////////////////////////////////////////////////
// iso8859-2 charset font
// generated with /usr/bin/bdfassemble iso8859-2.txt
// on 1998-06-26 by czyborra@cs.tu-berlin.de
// http://czyborra.com/charsets/iso8859-2.bdf.gz
// FONT -misc-fixed-medium-r-normal--16-160-75-75-c-80-iso8859-2
//////////////////////////////////////////////////////////////////////
extern const unsigned char font8x16ISO8859_2[224][16];

//////////////////////////////////////////////////////////////////////
// inicjacja mechanizmów u¿ywanych podczas renderingu tekstu
// color - numer koloru fragmentu, do którego kierowane s¹ dane fragmentów
//////////////////////////////////////////////////////////////////////
void InitDrawText( GLuint color = 0 );

//////////////////////////////////////////////////////////////////////
// funkcja rysuj¹ca napis w wybranym miejscu
// x, y - wspó³rzêdne okienkowe pocz¹tku napisu
// str - tekst napisu
// color - kolor napisu, domyœlnie clBlack
// font - czcionka napisu, 8x16 pikseli, od znaku nr 32 (spacji),
//        domyœlnie font8x16CP1250
//////////////////////////////////////////////////////////////////////
void DrawText8x16( const int x, const int y, const std::string &str,
                  const GLfloat *color = clBlack,
                  const unsigned char font[][16] = font8x16CP1250 );

//////////////////////////////////////////////////////////////////////
// usuniêcie mechanizmów u¿ywanych podczas renderingu tekstu
//////////////////////////////////////////////////////////////////////
void DeleteDrawText();

#endif // __TEXT__H__
