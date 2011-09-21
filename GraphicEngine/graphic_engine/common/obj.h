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
// definicja materia³u z pliku MTL (Material Template Library)
//////////////////////////////////////////////////////////////////////
struct Mtl
{
    std::string name;       // nazwa materia³u
    GLfloat Ka[4];          // wspó³czynnik odbicia œwiat³a otoczenia
    GLfloat Kd[4];          // wspó³czynnik odbicia œwiat³a rozproszonego
    GLfloat Ks[4];          // wspó³czynnik odbicia œwiat³a zwierciadlanego
    int illum;              // model oœwietlenia:
                            // 0 - brak oœwietlenia
                            // 1 - tylko œwiat³o rozproszone
                            // 2 - œwiat³o rozproszone i zwierciadlane
    GLfloat Ns;             // wyk³adnik wspó³czynnika funkcji rozb³ysku
                            // wartoœci z przedzia³u <0;1000> 
    std::string map_Ka;     // nazwa pliku z tekstur¹ odbicia œwiat³a otoczenia
    std::string map_Kd;     // nazwa pliku z tekstur¹ odbicia œwiat³a rozproszonego
    std::string map_Ks;     // nazwa pliku z tekstur¹ odbicia œwiat³a zwierciadlanego
    std::string map_Bump;   // nazwa pliku z tekstur¹ wektorów normalnych
};

//////////////////////////////////////////////////////////////////////
// klasa obs³uguj¹ca pliki Alias/Wavefront OBJ oraz pliki MTL
//////////////////////////////////////////////////////////////////////
class Obj
{
public:
    // wczytanie pliku OBJ
    GLboolean Load( const char *fileName );

    // normalizacja zakresu wspó³rzêdnych do okreœlonego przedzia³u
    void Normalize( const GLfloat minX, const GLfloat maxX,
                    const GLfloat minY, const GLfloat maxY,
                    const GLfloat minZ, const GLfloat maxZ );

    // wczytanie tekstur
    GLboolean LoadTextures();

    // konwersja mapy wysokoœci do mapy wektorów normalnych
    void HeightMap2NormalMap( const unsigned char *src,
                          const int width, const int height,
                          unsigned char *&dst,
                          vector3<> scale = vector3<>( 0.0f, 0.0f, 0.0f ) );

    // generowanie wektorów normalnych
    void GenerateNormals();

    // generowanie wektorów stycznych
    void GenerateTangents();

    // pobranie wspó³rzêdnych wierzcho³ków
    GLfloat *Position( const int count );

    // pobranie wspó³rzêdnych tekstury
    GLfloat *TexCoord( const int count );

    // pobranie wspó³rzêdnych wektorów normalnych
    GLfloat *Normal( const int count );

    // pobranie wspó³rzêdnych wektorów stycznych
    GLfloat *Tangent( const int count );

    // pobranie definicji materia³ów
    GLfloat *Material();

    // pobranie indeksów wspó³rzêdnych wierzcho³ków
    GLint *PositionIndices();

    // pobranie indeksów wspó³rzêdnych tekstury
    GLint *TexCoordIndices();

    // pobranie indeksów wspó³rzêdnych wektorów normalnych
    GLint *NormalIndices();

    // pobranie indeksów wspó³rzêdnych wektorów stycznych
    GLint *TangentIndices();

    // pobranie indeksów definicji materia³ów
    GLint *MaterialIndices();

    // pobranie iloœci wspó³rzêdnych wierzcho³ków
    int PositionCount() { return v.size(); }

    // pobranie iloœci wspó³rzêdnych tekstury
    int TexCoordCount() { return vt.size(); }

    // pobranie iloœci wspó³rzêdnych wektorów normalnych
    int NormalCount() { return vn.size(); }

    // pobranie iloœci wspó³rzêdnych wektorów stycznych
    int TangentCount() { return vtan.size(); }

    // pobranie iloœci definicji materia³ów
    int MaterialCount() { return material.size(); }

    // pobranie iloœci indeksów wspó³rzêdnych wierzcho³ków
    int PositionIndicesCount() { return iv.size(); }

    // pobranie iloœci indeksów wspó³rzêdnych tekstury
    int TexCoordIndicesCount() { return ivt.size(); }

    // pobranie iloœci indeksów wspó³rzêdnych wektorów normalnych
    int NormalIndicesCount() { return ivn.size(); }

    // pobranie iloœci indeksów wspó³rzêdnych wektorów stycznych
    int TangentIndicesCount() { return ivtan.size(); }

    // pobranie iloœci indeksów definicji materia³ów
    int MaterialIndicesCount() { return imaterial.size(); }

    // pobranie iloœci warstw tekstury
    int TextureLayerCount();

    // pobranie numeru warstwy tekstury
    GLint TextureLayer( const std::string &fileName );

protected:
    // odczyt danych o wierzcho³kach œciany (wielok¹ta)
    void LoadFace( std::istringstream &txt );

    // odczyt pliku MTL z definicjami materia³ów
    void LoadMTL( const char *fileName );

    // ustawienie domyœlnych w³aœciwoœci materia³u
    void DeafultMaterial( Mtl &mat );

protected:
    // wspó³rzêdne wierzcho³ków
    std::vector <vector4<> > v;

    // wspó³rzêdne tekstury
    std::vector <vector4<> > vt;

    // wspó³rzêdne wektorów normalnych
    std::vector <vector3<> > vn;

    // wspó³rzêdne wektorów stycznych
    std::vector <vector3<> > vtan;

    // indeksy wspó³rzêdnych wierzcho³ków
    std::vector <GLint> iv;

    // indeksy wspó³rzêdnych tekstury
    std::vector <GLint> ivt;

    // indeksy wspó³rzêdnych wektorów normalnych
    std::vector <GLint> ivn;

    // indeksy wspó³rzêdnych wektorów stycznych
    std::vector <GLint> ivtan;

    // tablica z definicjami materia³ów
    std::vector <Mtl> material;

    // indeksy materia³ów
    std::vector <GLint> imaterial;

    // indeks bie¿¹cego materia³u
    GLuint matIdx;

    // nazwy poszczególnych warstw tekstury
    std::vector <std::string> mapTexture;

protected:
    // œcie¿ka do pliku OBJ/MTL
    std::string path;
};

#endif // __OBJ__H__

