//////////////////////////////////////////////////////////////////////
// (c) Janusz Ganczarski
// http://www.januszg.hg.pl
// JanuszG@enter.net.pl
//////////////////////////////////////////////////////////////////////

#ifndef __OBJ__H__
#define __OBJ__H__

#include <vector>
#include <string>
#include <sstream>
#include "extensions3.h"
#include "vecmatquat.h"

//////////////////////////////////////////////////////////////////////
// definicja materia�u z pliku MTL (Material Template Library)
//////////////////////////////////////////////////////////////////////
struct Mtl
{
    std::string name;       // nazwa materia�u
    GLfloat Ka[4];          // wsp�czynnik odbicia �wiat�a otoczenia
    GLfloat Kd[4];          // wsp�czynnik odbicia �wiat�a rozproszonego
    GLfloat Ks[4];          // wsp�czynnik odbicia �wiat�a zwierciadlanego
    int illum;              // model o�wietlenia:
                            // 0 - brak o�wietlenia
                            // 1 - tylko �wiat�o rozproszone
                            // 2 - �wiat�o rozproszone i zwierciadlane
    GLfloat Ns;             // wyk�adnik wsp�czynnika funkcji rozb�ysku
                            // warto�ci z przedzia�u <0;1000> 
    std::string map_Ka;     // nazwa pliku z tekstur� odbicia �wiat�a otoczenia
    std::string map_Kd;     // nazwa pliku z tekstur� odbicia �wiat�a rozproszonego
    std::string map_Ks;     // nazwa pliku z tekstur� odbicia �wiat�a zwierciadlanego
    std::string map_Bump;   // nazwa pliku z tekstur� wektor�w normalnych
};

//////////////////////////////////////////////////////////////////////
// klasa obs�uguj�ca pliki Alias/Wavefront OBJ oraz pliki MTL
//////////////////////////////////////////////////////////////////////
class Obj
{
public:
    // wczytanie pliku OBJ
    GLboolean Load( const char *fileName );

    // normalizacja zakresu wsp�rz�dnych do okre�lonego przedzia�u
    void Normalize( const GLfloat minX, const GLfloat maxX,
                    const GLfloat minY, const GLfloat maxY,
                    const GLfloat minZ, const GLfloat maxZ );

    // wczytanie tekstur
    GLboolean LoadTextures();

    // konwersja mapy wysoko�ci do mapy wektor�w normalnych
    void HeightMap2NormalMap( const unsigned char *src,
                          const int width, const int height,
                          unsigned char *&dst,
                          vector3<> scale = vector3<>( 0.0f, 0.0f, 0.0f ) );

    // generowanie wektor�w normalnych
    void GenerateNormals();

    // generowanie wektor�w stycznych
    void GenerateTangents();

    // pobranie wsp�rz�dnych wierzcho�k�w
    GLfloat *Position( const int count );

    // pobranie wsp�rz�dnych tekstury
    GLfloat *TexCoord( const int count );

    // pobranie wsp�rz�dnych wektor�w normalnych
    GLfloat *Normal( const int count );

    // pobranie wsp�rz�dnych wektor�w stycznych
    GLfloat *Tangent( const int count );

    // pobranie definicji materia��w
    GLfloat *Material();

    // pobranie indeks�w wsp�rz�dnych wierzcho�k�w
    GLint *PositionIndices();

    // pobranie indeks�w wsp�rz�dnych tekstury
    GLint *TexCoordIndices();

    // pobranie indeks�w wsp�rz�dnych wektor�w normalnych
    GLint *NormalIndices();

    // pobranie indeks�w wsp�rz�dnych wektor�w stycznych
    GLint *TangentIndices();

    // pobranie indeks�w definicji materia��w
    GLint *MaterialIndices();

    // pobranie ilo�ci wsp�rz�dnych wierzcho�k�w
    int PositionCount() { return v.size(); }

    // pobranie ilo�ci wsp�rz�dnych tekstury
    int TexCoordCount() { return vt.size(); }

    // pobranie ilo�ci wsp�rz�dnych wektor�w normalnych
    int NormalCount() { return vn.size(); }

    // pobranie ilo�ci wsp�rz�dnych wektor�w stycznych
    int TangentCount() { return vtan.size(); }

    // pobranie ilo�ci definicji materia��w
    int MaterialCount() { return material.size(); }

    // pobranie ilo�ci indeks�w wsp�rz�dnych wierzcho�k�w
    int PositionIndicesCount() { return iv.size(); }

    // pobranie ilo�ci indeks�w wsp�rz�dnych tekstury
    int TexCoordIndicesCount() { return ivt.size(); }

    // pobranie ilo�ci indeks�w wsp�rz�dnych wektor�w normalnych
    int NormalIndicesCount() { return ivn.size(); }

    // pobranie ilo�ci indeks�w wsp�rz�dnych wektor�w stycznych
    int TangentIndicesCount() { return ivtan.size(); }

    // pobranie ilo�ci indeks�w definicji materia��w
    int MaterialIndicesCount() { return imaterial.size(); }

    // pobranie ilo�ci warstw tekstury
    int TextureLayerCount();

    // pobranie numeru warstwy tekstury
    GLint TextureLayer( const std::string &fileName );

protected:
    // odczyt danych o wierzcho�kach �ciany (wielok�ta)
    void LoadFace( std::istringstream &txt );

    // odczyt pliku MTL z definicjami materia��w
    void LoadMTL( const char *fileName );

    // ustawienie domy�lnych w�a�ciwo�ci materia�u
    void DeafultMaterial( Mtl &mat );

protected:
    // wsp�rz�dne wierzcho�k�w
    std::vector <vector4<> > v;

    // wsp�rz�dne tekstury
    std::vector <vector4<> > vt;

    // wsp�rz�dne wektor�w normalnych
    std::vector <vector3<> > vn;

    // wsp�rz�dne wektor�w stycznych
    std::vector <vector3<> > vtan;

    // indeksy wsp�rz�dnych wierzcho�k�w
    std::vector <GLint> iv;

    // indeksy wsp�rz�dnych tekstury
    std::vector <GLint> ivt;

    // indeksy wsp�rz�dnych wektor�w normalnych
    std::vector <GLint> ivn;

    // indeksy wsp�rz�dnych wektor�w stycznych
    std::vector <GLint> ivtan;

    // tablica z definicjami materia��w
    std::vector <Mtl> material;

    // indeksy materia��w
    std::vector <GLint> imaterial;

    // indeks bie��cego materia�u
    GLuint matIdx;

    // nazwy poszczeg�lnych warstw tekstury
    std::vector <std::string> mapTexture;

protected:
    // �cie�ka do pliku OBJ/MTL
    std::string path;
};

#endif // __OBJ__H__

