//////////////////////////////////////////////////////////////////////
// (c) Janusz Ganczarski
// http://www.januszg.hg.pl
// JanuszG@enter.net.pl
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "obj.h"
#include "targa.h"
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#include <algorithm>
#include <map>

//////////////////////////////////////////////////////////////////////
// operator por�wnuj�cy dwa znormalizowane wektory normalne
//////////////////////////////////////////////////////////////////////
template <class T> bool operator < ( const vector3<T> &n1, const vector3<T> &n2 )
{
    return n1[0] + 10*n1[1] + 100*n1[2] < n2[0] + 10*n2[1] + 100*n2[2];
}

//////////////////////////////////////////////////////////////////////
// normalizacja zakresu wsp�rz�dnych do okre�lonego przedzia�u
//////////////////////////////////////////////////////////////////////
void Obj::Normalize( const GLfloat minX, const GLfloat maxX,
                        const GLfloat minY, const GLfloat maxY,
                        const GLfloat minZ, const GLfloat maxZ )
{
    // wyszukanie mininum i maksimum zakresu wsp�rz�dnych
    const unsigned int size = v.size();
    vector4<> minPos( v.at( 0 ) );
    vector4<> maxPos( v.at( 0 ) );
    for( unsigned int i = 0; i < size; i++ )
    {
        if( v.at( i )[0] < minPos[0] ) minPos[0] = v.at( i )[0];
        if( v.at( i )[1] < minPos[1] ) minPos[1] = v.at( i )[1];
        if( v.at( i )[2] < minPos[2] ) minPos[2] = v.at( i )[2];
        if( v.at( i )[0] > maxPos[0] ) maxPos[0] = v.at( i )[0];
        if( v.at( i )[1] > maxPos[1] ) maxPos[1] = v.at( i )[1];
        if( v.at( i )[2] > maxPos[2] ) maxPos[2] = v.at( i )[2];
    }

    // obliczenie wektora przesuni�cia
    vector4<> translate( 0.5f * (minPos[0] + maxPos[0]),
                        0.5f * (minPos[1] + maxPos[1]),
                        0.5f * (minPos[2] + maxPos[2]), 0.0f );

    // obliczenie wsp�czynnika skalowania
    GLfloat scaleX = 1.0f, scaleY = 1.0f, scaleZ = 1.0f;
    if( maxPos[0] - minPos[0] )
        scaleX = (maxX - minX ) / (maxPos[0] - minPos[0]);
    if( maxPos[1] - minPos[1] )
        scaleY = (maxY - minY ) / (maxPos[1] - minPos[1]);
    if( maxPos[2] - minPos[2] )
        scaleZ = (maxZ - minZ ) / (maxPos[2] - minPos[2]);
    GLfloat scale = std::min( scaleX, std::min( scaleY, scaleZ ) );

    // transformacja wsp�rz�dnych wierzcho�k�w
    for( unsigned int i = 0; i < size; i++ )
    {
        v.at( i ) -= translate;
        v.at( i ) *= scale;
        v.at( i )[3] = 1.0f;
    }
}

//////////////////////////////////////////////////////////////////////
// generowanie wektor�w normalnych
//////////////////////////////////////////////////////////////////////
void Obj::GenerateNormals()
{
    // porz�dki
    vn.erase( vn.begin(), vn.end() );

    // sta�e do sterownaia p�tlami: ilo�� tr�jk�t�w (�cian)
    // i ilo�� wektor�w normalnych
    const unsigned int ivSize3 = iv.size()/3;
    const unsigned int vSize = v.size();

    // obliczenie wektora normalnego �cian
    std::vector <vector3<> > faceNormals;
    for( unsigned int i = 0; i < ivSize3; i++ )
    {
        // wektory zbudowane na podstawie wierzcho�k�w
        // tr�jk�ta, kt�ry zawiera bie��ca �ciana
        vector4<> v1( v[iv[3*i + 1]] - v[iv[3*i + 0]] );
        vector4<> v2( v[iv[3*i + 2]] - v[iv[3*i + 1]] );

        // obliczenie wektora normalnego przy pomocy iloczynu wektorowego
        faceNormals.push_back( normalize3( cross3( v1, v2 ) ).data() );
    }

    // obliczanie wektor�w normalnych dla kolejnych wierzcho�k�w
    for( unsigned int i = 0; i < vSize; i++ )
    {
        // wynikowy, u�redniony wektor normalny
        vector3<> normal;

        // wyszukanie wszystkich �cian-tr�jk�t�w posiadaj�cych bie��cy wierzcho�ek
        for( unsigned int j = 0; j < ivSize3; j++ )
            if ( iv[3*j+0] == i || iv[3*j+1] == i || iv[3*j+2] == i )
            {
                // dodanie wektora �ciany do wektora u�rednionego
                normal += faceNormals[j];
            }

        // normalizacja wektora normalnego i zapisanie go do tablicy
        vn.push_back( normal.normalize() );
    }

    // kopiowanie indeks�w wierzcho�k�w
    ivn = iv;
}

//////////////////////////////////////////////////////////////////////
// generowanie wektor�w stycznych
//////////////////////////////////////////////////////////////////////
void Obj::GenerateTangents()
{
    // porz�dki
    vtan.erase( vtan.begin(), vtan.end() );
    ivtan.erase( ivtan.begin(), ivtan.end() );

    // sprawdzenie czy obiekt zawiera wsp�rz�dne tekstury
    if( !vt.size() || !ivt.size() )
        return;

    // sta�e do sterownaia p�tlami: ilo�� tr�jk�t�w (�cian)
    // i ilo�� wektor�w stycznych
    const unsigned int ivSize3 = iv.size()/3;
    const unsigned int vSize = v.size();

    // obliczenie wektora stycznego �cian
    std::vector <vector3<> > faceTangents;
    for( unsigned int i = 0; i < ivSize3; i++ )
    {
        // wektory pomocnicze
        vector4<> v10( v[iv[3*i + 1]] - v[iv[3*i + 0]] );
        vector4<> v20( v[iv[3*i + 2]] - v[iv[3*i + 0]] );
        vector4<> st10( vt[ivt[3*i + 1]] - vt[ivt[3*i + 0]] );
        vector4<> st20( vt[ivt[3*i + 2]] - vt[ivt[3*i + 0]] );

        // obliczanie wektora stycznego �ciany
        float det = st10[0] * st20[1] - st20[0] * st10[1];
        vector3<> tangent( 0.0f, 0.0f, 0.0f );
        if( fabs( det ) < 1e-6f )
        {
            tangent[0] = 1.0f;
            tangent[1] = 0.0f;
            tangent[2] = 0.0f;
        }
        else
        {
            tangent = (st20[1] * vector3<>( v10[0], v10[1], v10[2] ) - 
                        st10[1] * vector3<>( v20[0], v20[1], v20[2] ) ) / det;
        }
        faceTangents.push_back( normalize( tangent ) );
    }

    // tablica asoscjacyjna do wyszukiwania duplikat�w wektor�w stycznych
    std::map< vector3<>, unsigned int > tangentCache;

    // obliczanie wektor�w stycznych dla kolejnych wierzcho�k�w (wg indeks�w)
    for( unsigned int i = 0; i < vSize; i++ )
    {
        // wynikowy, u�redniony wektor styczny
        vector3<> tangent( 0.0f, 0.0f, 0.0f );

        // wyszukanie wszystkich �cian-tr�jk�t�w posiadaj�cych bie��cy wierzcho�ek
        // z zachowaniem warunku zgodno�ci wsp�rz�dnych tekstury
        for( unsigned int j = 0; j < ivSize3; j++ )
            if ( ( iv[3*j + 0] == iv[i] && ivt[i] == ivt[3*j + 0] ) || 
                 ( iv[3*j + 1] == iv[i] && ivt[i] == ivt[3*j + 1] ) || 
                 ( iv[3*j + 2] == iv[i] && ivt[i] == ivt[3*j + 2] ) )
            {
                // dodanie wektora �ciany do wektora u�rednionego
                tangent += faceTangents[j];
            }

        // ortogonalizacja Grama-Schmidta i normalizacja wektora stycznego
        float NdotT = dot3( vn[ivn[i]], tangent );
        tangent -= NdotT * vn[ivn[i]];
        tangent.normalize();

        // sprawdzenie, czy w tablicy nie duplikatu wektora stycznego
        if( tangentCache.find( tangent ) == tangentCache.end() )
        {
            // zapisanie wektora stycznego do tablicy
            vtan.push_back( tangent );

            // dodanie nowego indeksu
            ivtan.push_back( vtan.size() - 1 );

            // dopisanie wektora do tablicy asocjacyjnej
            tangentCache[tangent] = vtan.size() - 1;
        }
        else
            // zapisanie indeksu do duplikatu
            ivtan.push_back( tangentCache[tangent] );
    }
}

//////////////////////////////////////////////////////////////////////
// pobranie wsp�rz�dnych wierzcho�k�w
// count - ilo�� pobieranych sk�adowych: 1, 2, 3 lub 4
//////////////////////////////////////////////////////////////////////
GLfloat *Obj::Position( const int count )
{
    const unsigned int size = v.size();
    GLfloat *tmpPos = new GLfloat[ size * count ];
    for( unsigned int i = 0; i < size; i++ )
        for( int j = 0; j < count; j++ )
            tmpPos[ i * count + j ] = v.at( i )[j];
    return tmpPos;
}

//////////////////////////////////////////////////////////////////////
// pobranie wsp�rz�dnych tekstury
// count - ilo�� pobieranych sk�adowych: 1, 2, 3 lub 4
//////////////////////////////////////////////////////////////////////
GLfloat *Obj::TexCoord( const int count )
{
    const unsigned int size = vt.size();
    GLfloat *tmpTex = new GLfloat[ size * count ];
    for( unsigned int i = 0; i < size; i++ )
        for( int j = 0; j < count; j++ )
            tmpTex[ i * count + j ] = vt.at( i )[j];
    return tmpTex;
}

//////////////////////////////////////////////////////////////////////
// pobranie wsp�rz�dnych wektor�w normalnych
// count - ilo�� pobieranych sk�adowych: 2, 3 lub 4
//////////////////////////////////////////////////////////////////////
GLfloat *Obj::Normal( const int count )
{
    const unsigned int size = vn.size();
    GLfloat *tmpNor = new GLfloat[ size * count ];
    if( count == 2 )
        for( unsigned int i = 0; i < size; i++ )
        {
            tmpNor[ i * 2 + 0 ] = vn.at( i )[0];
            tmpNor[ i * 2 + 1 ] = vn.at( i )[1];
        }
    else
    if( count == 3 )
        for( unsigned int i = 0; i < size; i++ )
        {
            tmpNor[ i * 3 + 0 ] = vn.at( i )[0];
            tmpNor[ i * 3 + 1 ] = vn.at( i )[1];
            tmpNor[ i * 3 + 2 ] = vn.at( i )[2];
        }
    else
    if( count == 4 )
        for( unsigned int i = 0; i < size; i++ )
        {
            tmpNor[ i * 4 + 0 ] = vn.at( i )[0];
            tmpNor[ i * 4 + 1 ] = vn.at( i )[1];
            tmpNor[ i * 4 + 2 ] = vn.at( i )[2];
            tmpNor[ i * 4 + 3 ] = 1.0f;
        }
    return tmpNor;
}

//////////////////////////////////////////////////////////////////////
// pobranie wsp�rz�dnych wektor�w stycznych
// count - ilo�� pobieranych sk�adowych: 3 lub 4
//////////////////////////////////////////////////////////////////////
GLfloat *Obj::Tangent( const int count )
{
    const unsigned int size = vtan.size();
    GLfloat *tmpTan = new GLfloat[ size * count ];
    if( count == 3 )
        for( unsigned int i = 0; i < size; i++ )
        {
            tmpTan[ i * 3 + 0 ] = vtan.at( i )[0];
            tmpTan[ i * 3 + 1 ] = vtan.at( i )[1];
            tmpTan[ i * 3 + 2 ] = vtan.at( i )[2];
        }
    else
    if( count == 4 )
        for( unsigned int i = 0; i < size; i++ )
        {
            tmpTan[ i * 4 + 0 ] = vtan.at( i )[0];
            tmpTan[ i * 4 + 1 ] = vtan.at( i )[1];
            tmpTan[ i * 4 + 2 ] = vtan.at( i )[2];
            tmpTan[ i * 4 + 3 ] = 1.0f;
        }
    return tmpTan;
}
//////////////////////////////////////////////////////////////////////
// pobranie definicji materia��w, kolejno Ka, Kd, Ks i Ns
//////////////////////////////////////////////////////////////////////
GLfloat *Obj::Material()
{
    const unsigned int size = material.size();
    GLfloat *tmpMat = new GLfloat[ size * 20 ];
    for( unsigned int i = 0; i < size; i++ )
    {
        // Ka
        tmpMat[ i * 20 + 0 ] = material.at( i ).Ka[0];
        tmpMat[ i * 20 + 1 ] = material.at( i ).Ka[1];
        tmpMat[ i * 20 + 2 ] = material.at( i ).Ka[2];
        tmpMat[ i * 20 + 3 ] = material.at( i ).Ka[3];

        // Kd
        tmpMat[ i * 20 + 4 ] = material.at( i ).Kd[0];
        tmpMat[ i * 20 + 5 ] = material.at( i ).Kd[1];
        tmpMat[ i * 20 + 6 ] = material.at( i ).Kd[2];
        tmpMat[ i * 20 + 7 ] = material.at( i ).Kd[3];

        // Ks
        tmpMat[ i * 20 + 8 ] = material.at( i ).Ks[0];
        tmpMat[ i * 20 + 9 ] = material.at( i ).Ks[1];
        tmpMat[ i * 20 + 10 ] = material.at( i ).Ks[2];
        tmpMat[ i * 20 + 11 ] = material.at( i ).Ks[3];

        // Ns
        tmpMat[ i * 20 + 12 ] = material.at( i ).Ns;
        tmpMat[ i * 20 + 13 ] = 0.0f;
        tmpMat[ i * 20 + 14 ] = 0.0f;
        tmpMat[ i * 20 + 15 ] = 0.0f;

        // map_Ka
        tmpMat[ i * 20 + 16 ] = static_cast<GLfloat>( TextureLayer( material.at( i ).map_Ka ) );

        // map_Kd
        tmpMat[ i * 20 + 17 ] = static_cast<GLfloat>( TextureLayer( material.at( i ).map_Kd ) );

        // map_Ks
        tmpMat[ i * 20 + 18 ] = static_cast<GLfloat>( TextureLayer( material.at( i ).map_Ks ) );

        // map_Bump
        tmpMat[ i * 20 + 19 ] = static_cast<GLfloat>( TextureLayer( material.at( i ).map_Bump ) );
    }
    return tmpMat;
}

//////////////////////////////////////////////////////////////////////
// pobranie indeks�w wsp�rz�dnych wierzcho�k�w
//////////////////////////////////////////////////////////////////////
GLint *Obj::PositionIndices()
{
    const unsigned int size = iv.size();
    GLint *tmpI = new GLint[ size ];
    for( unsigned int i = 0; i < size; i++ )
        tmpI[ i ] = iv.at( i );
    return tmpI;
}

//////////////////////////////////////////////////////////////////////
// pobranie indeks�w wsp�rz�dnych tekstury
//////////////////////////////////////////////////////////////////////
GLint *Obj::TexCoordIndices()
{
    const unsigned int size = ivt.size();
    GLint *tmpI = new GLint[ size ];
    for( unsigned int i = 0; i < size; i++ )
        tmpI[ i ] = ivt.at( i );
    return tmpI;
}

//////////////////////////////////////////////////////////////////////
// pobranie indeks�w wsp�rz�dnych wektor�w normalnych
//////////////////////////////////////////////////////////////////////
GLint *Obj::NormalIndices()
{
    const unsigned int size = ivn.size();
    GLint *tmpI = new GLint[ size ];
    for( unsigned int i = 0; i < size; i++ )
        tmpI[ i ] = ivn.at( i );
    return tmpI;
}

//////////////////////////////////////////////////////////////////////
// pobranie indeks�w wsp�rz�dnych wektor�w stycznych
//////////////////////////////////////////////////////////////////////
GLint *Obj::TangentIndices()
{
    const unsigned int size = ivtan.size();
    GLint *tmpT = new GLint[ size ];
    for( unsigned int i = 0; i < size; i++ )
        tmpT[ i ] = ivtan.at( i );
    return tmpT;
}

//////////////////////////////////////////////////////////////////////
// pobranie indeks�w definicji materia��w
//////////////////////////////////////////////////////////////////////
GLint *Obj::MaterialIndices()
{
    const unsigned int size = imaterial.size();
    GLint *tmpI = new GLint[ size ];
    for( unsigned int i = 0; i < size; i++ )
        tmpI[ i ] = imaterial.at( i );
    return tmpI;
}

//////////////////////////////////////////////////////////////////////
// pobranie ilo�ci warstw tekstury
//////////////////////////////////////////////////////////////////////
int Obj::TextureLayerCount()
{
    return mapTexture.size();
}

//////////////////////////////////////////////////////////////////////
// pobranie numeru warstwy tekstury, w przypadku gdy tekstura
// o podanej nazwie nie znajduje si� w tablicy mapTexture, funkcja
// zwraca warto�� r�wn� -1
//////////////////////////////////////////////////////////////////////
GLint Obj::TextureLayer( const std::string &fileName )
{
    unsigned int layer = 0;
    while( layer < mapTexture.size() )
    {
        if( mapTexture[layer] == fileName )
            return layer;
        layer++;
    }
    return -1;
}

//////////////////////////////////////////////////////////////////////
// wczytanie tekstur do tablicy tekstur 2D
//////////////////////////////////////////////////////////////////////
GLboolean Obj::LoadTextures()
{
    // sprawdzenie czy s� tekstury i czy s� wsp�rz�dne tekstury
    if( !TextureLayerCount() || !TexCoordCount() )
        return GL_FALSE;

    // tryb upakowania bajt�w danych tekstury
    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

    // odczyt kolejnych warstw tablicy tekstur
    for( int i = 0; i < TextureLayerCount(); i++ )
    {
        GLsizei width;      // szeroko�� obrazu
        GLsizei height;     // wysoko�� obrazu
        GLenum format;      // format danych obrazu
        GLenum type;        // format danych pikseli obrazu
        GLvoid *pixels;     // wska�nik na tablic� z danymi obrazu

        // odczyt pliku TARGA i ewentualny komunikat o b��dzie
        if( !loadTarga( mapTexture.at( i ).c_str(), width, height, format, type, pixels ) )
        {
            std::cout << "Niepoprawny odczyt pliku " << mapTexture.at( i ) << std::endl;
            exit( 0 );
        }

        // sprawdzenie, czy odczytana tekstura nie jest map� wysoko�ci;
        // je�eli tak realizowan jest jej konwersja na map� wektor�w normalnych
        if( format == GL_RED && material[imaterial[i]].map_Bump == mapTexture.at( i ) )
        {
            unsigned char *normal;
            HeightMap2NormalMap( static_cast<unsigned char*>( pixels ), width, height, normal );
            delete [] static_cast<unsigned char*>( pixels );
            pixels = normal;
            format = GL_RGB;
        }

        // utworzenie tablicy tekstur 2D - bez danych obrazu
        if( i == 0 )
            glTexImage3D( GL_TEXTURE_2D_ARRAY, 0, GL_RGB, width, height, TextureLayerCount(), 0, GL_RGB, GL_UNSIGNED_BYTE, NULL );

        // za�adowanie danych
        glTexSubImage3D( GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, width, height, 1, format, type, pixels );

        // porz�dki
        delete [] static_cast<unsigned char*>( pixels );
    }

    // parametry tablicy tekstur - filtracja
    glTexParameteri( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );

    // generownanie mipmap
    glGenerateMipmap( GL_TEXTURE_2D_ARRAY );

    // sukces
    return GL_TRUE;
}

//////////////////////////////////////////////////////////////////////
// konwersja mapy wysoko�ci do mapy wektor�w normalnych
// src - dane mapy wysoko�ci
// width - szeroko�� mapy wysoko�ci / mapy wektor�w normalnych
// height - wysoko�� mapy wysoko�ci / mapy wektor�w normalnych
// dst - dane mapy wektorow normalnych
// scale - wsp�czynniki skalowania wektora normalnego; w przypadku
//         u�ycia warto�ci domy�lnej lub co najmniej jednej sk�adowej
//         zerowej, wsp�czynniki skalowania obliczane s� na podstawie
//         proporcji rozmiar�w mapy wysoko�ci
//////////////////////////////////////////////////////////////////////
void Obj::HeightMap2NormalMap( const unsigned char *src,
                          const int width, const int height,
                          unsigned char *&dst,
                          vector3<> scale )
{
    // obliczenie wsp�czynnik�w skalowania je�eli nie s� niezerowe
    if( scale[0] == 0.0f || scale[1] == 0.0f || scale[2] == 0.0f )
    {
        float a = static_cast<float>( width )/static_cast<float>( height );
        if( a < 1.0f )
        {
            scale[0] = 1.0f;
            scale[1] = 1.0f/a;
        }
        else
        {
            scale[0] = a;
            scale[1] = 1.0f;
        }
        scale[2] = 1.0f;
    }

    // dane na map� wektor�w normalnych
    dst = new unsigned char[width * height * 3];

    // obliczenia wektor�w stycznych
    for( int w = 1; w < width - 1; w++ )
    {
        for( int h = 1; h < height - 1; h++ )
        {
            // obliczenie wektora normalnego z wektor�w pochodnych cz�stkowych
            vector3<> dfdw( 1.0f, 0.0f, static_cast<float> ( src[w + 1 + h*height] - src[w - 1 + h*height] )/255.0f );
            vector3<> dfdh( 0.0f, 1.0f, static_cast<float> ( src[w + (h + 1)*height] - src[w + (h - 1)*height] )/255.0f );
            vector3<> normal = cross3( dfdw, dfdh );

            // skalowanie i normalizacja wektora normalnego
            normal[0] *= scale[0];
            normal[1] *= scale[1];
            normal[2] *= scale[2];
            normal.normalize();

            // przeskalowanie sk�adowych wektora normalnego do przedzia�u <0;1>
            // i zapisanie w mapie wektor�w normalnych
            dst[3*w + 0 + h*height*3] = static_cast<unsigned char> ( (normal[0]+1.0)*127.5f );
            dst[3*w + 1 + h*height*3] = static_cast<unsigned char> ( (normal[1]+1.0)*127.5f );
            dst[3*w + 2 + h*height*3] = static_cast<unsigned char> ( (normal[2]+1.0)*127.5f );
        }
    }

    // wektory normalne brzegu mapy kopiowane s� z s�siednich (wewn�trznych) wektor�w mapy
    for( int w = 0; w < width; w++ )
    {
        dst[3*w + 0 + height*0*3]   = dst[3*w + 0 + height*1*3];
        dst[3*w + 1 + height*0*3]   = dst[3*w + 1 + height*1*3];
        dst[3*w + 2 + height*0*3]   = dst[3*w + 2 + height*1*3];

        dst[3*w + 0 + (height-1)*3] = dst[3*w + 0 + (height-2)*3];
        dst[3*w + 1 + (height-1)*3] = dst[3*w + 1 + (height-2)*3];
        dst[3*w + 2 + (height-1)*3] = dst[3*w + 2 + (height-2)*3];
    }
    for( int h = 0; h < height; h++ )
    {
        dst[3*0 + 0 + height*h*3]   = dst[3*1 + 0 + height*h*3];
        dst[3*0 + 1 + height*h*3]   = dst[3*1 + 1 + height*h*3];
        dst[3*0 + 2 + height*h*3]   = dst[3*1 + 2 + height*h*3];

        dst[3*(width-1) + 0 + height*h*3] = dst[3*(width-2) + 0 + height*h*3];
        dst[3*(width-1) + 1 + height*h*3] = dst[3*(width-2) + 1 + height*h*3];
        dst[3*(width-1) + 2 + height*h*3] = dst[3*(width-2) + 2 + height*h*3];
     }
}

//////////////////////////////////////////////////////////////////////
// odczyt pliku graficznego w formacie OBJ
// fileName - nazwa pliku
//////////////////////////////////////////////////////////////////////
GLboolean Obj::Load( const char *fileName )
{
    // porz�dki
    v.erase( v.begin(), v.end () );
    vt.erase( vt.begin(), vt.end() );
    vn.erase( vn.begin(), vn.end() );
    vtan.erase( vtan.begin(), vtan.end() );
    iv.erase( iv.begin(), iv.end () );
    ivt.erase( ivt.begin(), ivt.end() );
    ivn.erase( ivn.begin(), ivn.end() );
    ivtan.erase( ivtan.begin(), ivtan.end() );
    material.erase( material.begin (), material.end () );
    imaterial.erase( imaterial.begin (), imaterial.end () );
    mapTexture.erase( mapTexture.begin (), mapTexture.end () );
    matIdx = 0;

    // pobranie �cie�ki pliku
    path.clear();
    std::string name = fileName;
    std::string::size_type offset = name.find_last_of( '\\' );
    if( offset != std::string::npos )
    {
        path = name.substr( 0, offset + 1 );
    }
    else
    {
        offset = name.find_last_of( '/' );
        if( offset != std::string::npos )
            path = name.substr( 0, offset + 1 );
    }

    // otwarcie pliku do odczytu
    std::ifstream file;
    file.open( name.c_str() );

    // sprawdzenie poprawno�ci otwarcia pliku
    if( file.good() )
    {
        // bufor na kolejne wiersze pliku
        std::string line;

        // odczyt danych pliku
        while( getline( file, line ) )
        {
            // strumie� znak�w
            std::istringstream txt( line );

            // pobranie pierwszego ci�gu znak�w
            std::string str;
            txt >> str;

            // wsp�rz�dne wierzcho�k�w
            if( str == "v" )
            {
                vector4<> tmpV( 0.0f, 0.0f, 0.0f, 1.0f );
                txt >> tmpV[0] >> tmpV[1] >> tmpV[2] >> tmpV[3];
                v.push_back( tmpV );
            }

            // wsp�rz�dne tekstury
            else if( str == "vt" )
            {
                vector4<> tmpVT( 0.0f, 0.0f, 0.0f, 1.0f );
                txt >> tmpVT[0] >> tmpVT[1] >> tmpVT[2] >> tmpVT[3];
                vt.push_back( tmpVT );
            }

            // wsp�rz�dne wektor�w normalnych
            else if( str == "vn" )
            {
                vector3<> tmpN( 0.0f, 0.0f, 0.0f );
                txt >> tmpN[0] >> tmpN[1] >> tmpN[2];
                vn.push_back( tmpN );
            }

            // �ciana wielok�ta
            else if( str == "f" )
                LoadFace( txt );

            // plik(i) z bibliotek� materia��w
            else if( str == "mtllib" )
            {
                while( !txt.eof() )
                {
                    txt >> str;
                    str = path + str;
                    LoadMTL( str.c_str() );
                }
            }

            // u�ycie wybranego materia�u
            else if( str == "usemtl" )
            {
                matIdx = 0;
                txt >> str;
                for( unsigned int i = 0; i < material.size(); i++ )
                    if( material[i].name == str )
                    {
                        // zapisanie indeksu materia�u
                        matIdx = i;
                        break;
                    }
            }

            // komentarz - porzucenie dalszego przetwarzania wiersza
            else if( str == "#" )
                continue;
        }
    }
    else
        return GL_FALSE;

    // zamkni�cie pliku
    file.close();

    // w razie potrzeby dodanie materia�u domy�lnego
    if( material.size () == 0 )
    {
        Mtl mat;
        DeafultMaterial( mat );
        material.push_back( mat );
    }

    // sukces
    return GL_TRUE;
}

//////////////////////////////////////////////////////////////////////
// odczyt danych o wierzcho�kach �ciany (wielok�ta)
// str - analizowany pojedynczy wiersz pliku
//////////////////////////////////////////////////////////////////////
void Obj::LoadFace( std::istringstream &txt )
{
    // ustalenie ilo�ci i formatu danych opisuj�cych wierzcho�ek �ciany
    // w zmiennej format znajduje si� ilo�� atrybut�w wierzcho�ka:
    enum
    {
        F_V,        // format: f v
        F_V_T,      // format: f v/t
        F_V_T_N,    // format: f v/t/n
        F_V_N       // format: f v//n
    };
    std::string str;
    txt >> str;
    unsigned int format = 0;
    for( unsigned int i = 0; i < str.length(); i++ )
        if( str[i] == '/' )
        {
            format++;
            if( str[i+1] == '/' )
                format++;
        }
        
    // licznik wierzcho�k�w
    int count = 0;

    // odczyt indeks�w atrybut�w poszczeg�lnych wierzcho�k�w
    txt.seekg( 2, std::ios::beg );
    while( !txt.eof() )
    {
        GLint fv, fvt, fvn;
        switch( format )
        {
            // format: f v
            case F_V:
                txt >> fv;

                // czworok�t lub wielok�t - dodatkowe tr�jk�ty
                if( count > 2 )
                {
                    iv.push_back( iv[ iv.size() - 3*(count-2) ] );
                    iv.push_back( iv[ iv.size() - 2 ] );
                    imaterial.push_back( matIdx );
                    imaterial.push_back( matIdx );
                }

                // dodanie bi�acego wierzcho�ka
                iv.push_back( fv-1 );
                imaterial.push_back( matIdx );
                break;

            // format: f v/t
            case F_V_T:
                txt >> fv;
                txt.seekg( 1, std::ios::cur );
                txt >> fvt;

                // czworok�t lub wielok�t - dodatkowe tr�jk�ty
                if( count > 2 )
                {
                    iv.push_back( iv[ iv.size() - 3*(count-2) ] );
                    iv.push_back( iv[ iv.size() - 2 ] );
                    ivt.push_back( ivt[ ivt.size() - 3*(count-2) ] );
                    ivt.push_back( ivt[ ivt.size() - 2 ] );
                    imaterial.push_back( matIdx );
                    imaterial.push_back( matIdx );
                }

                // dodanie bi�acego wierzcho�ka
                iv.push_back( fv-1 );
                ivt.push_back( fvt-1 );
                imaterial.push_back( matIdx );
                break;

            // format: f v/t/n
            case F_V_T_N:
                txt >> fv;
                txt.seekg( 1, std::ios::cur );
                txt >> fvt;
                txt.seekg( 1, std::ios::cur );
                txt >> fvn;

                // czworok�t lub wielok�t - dodatkowe tr�jk�ty
                if( count > 2 )
                {
                    iv.push_back( iv[ iv.size() - 3*(count-2) ] );
                    iv.push_back( iv[ iv.size() - 2 ] );
                    ivt.push_back( ivt[ ivt.size() - 3*(count-2) ] );
                    ivt.push_back( ivt[ ivt.size() - 2 ] );
                    ivn.push_back( ivn[ ivn.size() - 3*(count-2) ] );
                    ivn.push_back( ivn[ ivn.size() - 2 ] );
                    imaterial.push_back( matIdx );
                    imaterial.push_back( matIdx );
                }

                // dodanie bi�acego wierzcho�ka
                iv.push_back( fv-1 );
                ivt.push_back( fvt-1 );
                ivn.push_back( fvn-1 );
                imaterial.push_back( matIdx );
                break;

            // format: f v//n
            case F_V_N:
                txt >> fv;
                txt.seekg( 2, std::ios::cur );
                txt >> fvn;

                // czworok�t lub wielok�t - dodatkowe tr�jk�ty
                if( count > 2 )
                {
                    iv.push_back( iv[ iv.size() - 3*(count-2) ] );
                    iv.push_back( iv[ iv.size() - 2 ] );
                    ivn.push_back( ivn[ ivn.size() - 3*(count-2) ] );
                    ivn.push_back( ivn[ ivn.size() - 2 ] );
                    imaterial.push_back( matIdx );
                    imaterial.push_back( matIdx );
                }

                // dodanie bi�acego wierzcho�ka
                iv.push_back( fv-1 );
                ivn.push_back( fvn-1 );
                imaterial.push_back( matIdx );
                break;
        }

        // nast�pny wierzcho�ek
        count++;
        txt.seekg( 1, std::ios::cur );
    }
}

//////////////////////////////////////////////////////////////////////
// odczyt pliku MTL z definicjami materia��w
//////////////////////////////////////////////////////////////////////
void Obj::LoadMTL( const char *fileName )
{
    // otwarcie pliku do odczytu
    std::ifstream file;
    file.open( fileName );

    // struktura z danymi materia�u z warto�ciami domy�lnymi
    Mtl mat;
    DeafultMaterial( mat );

    // sprawdzenie poprawno�ci otwarcia pliku
    if( file.good() )
    {
        // bufor na kolejne wiersze pliku
        std::string line;

        // odczyt danych pliku
        while( getline( file, line ) )
        {
            // strumie� znak�w
            std::istringstream txt( line );

            // pobranie pierwszego ci�gu znak�w
            std::string str;
            txt >> str;

            // nazwa materia�u
            if( str == "newmtl" )
            {
                // sprawdzenie czy to pierwsza definicja materia�u
                // je�eli nie, to zapisujemy materia� do tablicy
                if( mat.name.length() )
                {
                    material.push_back( mat );

                    // ponownie warto�ci domy�lne
                    DeafultMaterial( mat );
                }

                // dodanie nazwy materia�u
                txt >> mat.name;
            }

            // wsp�czynnik odbicia �wiat�a otoczenia
            else if( str == "Ka" )
                txt >> mat.Ka[0] >> mat.Ka[1] >> mat.Ka[2];

            // wsp�czynnik odbicia �wiat�a rozproszonego
            else if( str == "Kd" )
                txt >> mat.Kd[0] >> mat.Kd[1] >> mat.Kd[2];

            // wsp�czynnik odbicia �wiat�a zwierciadlanego
            else if( str == "Ks" )
                txt >> mat.Ks[0] >> mat.Ks[1] >> mat.Ks[2];

            // sk�adowa alfa - przezroczysto��
            else if( str == "d" || str == "Tr" )
            {
                GLfloat d;
                txt >> d;
                mat.Ka[3] = d;
                mat.Kd[3] = d;
                mat.Ks[3] = d;
            }

            // wyk�adnik wsp�czynnika funkcji rozb�ysku
            else if( str == "Ns" )
            {
                txt >> mat.Ns;

                // przeskalowanie z przedzia�u <0;1000> do <0;128>
                mat.Ns /= 1000.0f;
                mat.Ns *= 128.0f;
            }

            // tekstura odbicia �wiat�a otoczenia
            else if( str == "map_Ka" )
            {
                txt >> mat.map_Ka;
                mat.map_Ka = path + mat.map_Ka;

                // sprawdzenie nazw dotychczasowych materia��w w celu poszukiwania duplikat�w tekstur
                if( TextureLayer( mat.map_Ka ) < 0 && 
                    mat.map_Ka != mat.map_Kd && mat.map_Ka != mat.map_Ks && mat.map_Ka != mat.map_Bump )
                    mapTexture.push_back( mat.map_Ka );
            }

            // tekstura odbicia �wiat�a rozproszonego
            else if( str == "map_Kd" )
            {
                txt >> mat.map_Kd;
                mat.map_Kd = path + mat.map_Kd;

                // sprawdzenie nazw dotychczasowych materia��w w celu poszukiwania duplikat�w tekstur
                if( TextureLayer( mat.map_Kd ) < 0 && 
                    mat.map_Kd != mat.map_Ka && mat.map_Kd != mat.map_Ks && mat.map_Kd != mat.map_Bump )
                    mapTexture.push_back( mat.map_Kd );
            }

            // tekstura odbicia �wiat�a zwierciadlanego
            else if( str == "map_Ks" )
            {
                txt >> mat.map_Ks;
                mat.map_Ks = path + mat.map_Ks;

                // sprawdzenie nazw dotychczasowych materia��w w celu poszukiwania duplikat�w tekstur
                if( TextureLayer( mat.map_Ks ) < 0 && 
                    mat.map_Ks != mat.map_Ka && mat.map_Ks != mat.map_Kd && mat.map_Ks != mat.map_Bump )
                    mapTexture.push_back( mat.map_Ks );
            }

            // tekstura wektor�w normalnych
            else if( str == "map_Bump" || str == "map_bump" || str == "bump" )
            {
                txt >> mat.map_Bump;
                mat.map_Bump = path + mat.map_Bump;

                // sprawdzenie nazw dotychczasowych materia��w w celu poszukiwania duplikat�w tekstur
                if( TextureLayer( mat.map_Bump ) < 0 && 
                    mat.map_Bump != mat.map_Ka && mat.map_Bump != mat.map_Kd && mat.map_Bump != mat.map_Ks )
                    mapTexture.push_back( mat.map_Bump );
            }

            // model o�wietlenia
            else if( str == "illum" )
                txt >> mat.illum;

            // komentarz - porzucenie dalszego przetwarzania wiersza
            else if( str == "#" )
                continue;
        }
    }

    // zapisanie ostatniego materia�u do tablicy
    material.push_back( mat );

    // zamkni�cie pliku
    file.close();
}

//////////////////////////////////////////////////////////////////////
// ustawienie domy�lnych w�a�ciwo�ci materia�u
//////////////////////////////////////////////////////////////////////
void Obj::DeafultMaterial( Mtl &mat )
{
    mat.name.clear();
    mat.Ka[0] = 0.2f;
    mat.Ka[1] = 0.2f;
    mat.Ka[2] = 0.2f;
    mat.Ka[3] = 1.0f;
    mat.Kd[0] = 0.8f;
    mat.Kd[1] = 0.8f;
    mat.Kd[2] = 0.8f;
    mat.Kd[3] = 1.0f;
    mat.Ks[0] = 1.0f;
    mat.Ks[1] = 1.0f;
    mat.Ks[2] = 1.0f;
    mat.Ks[3] = 1.0f;
    mat.illum = 1;
    mat.Ns = 0.0f;
    mat.map_Ka.clear();
    mat.map_Kd.clear();
    mat.map_Ka.clear();
    mat.map_Bump.clear();
}

