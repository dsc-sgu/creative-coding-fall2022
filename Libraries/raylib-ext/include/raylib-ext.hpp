#ifndef RAYLIB_EXT_HPP
#define RAYLIB_EXT_HPP

#include <string>
#include <iostream>
#include <raylib.h>

#undef RAYGUI_IMPLEMENTATION
#include <raygui.h>

#undef RLGL_IMPLEMENTATION
#include <rlgl.h>

extern "C" {
#undef RAYMATH_IMPLEMENTATION
#include <raymath.h>
}

/* Vector2 */

bool operator==(const Vector2 &v1, const Vector2 &v2) noexcept;
Vector2 operator+(const Vector2 &v1, const Vector2 &v2) noexcept;
Vector2 operator-(const Vector2 &v1, const Vector2 &v2) noexcept;
Vector2 operator-(const Vector2 &v) noexcept;
Vector2 operator*(const Vector2 &v, const float &f) noexcept;
Vector2 operator/(const Vector2 &v, const float &f);
Vector2& operator+=(Vector2 &v1, const Vector2 &v2) noexcept;
Vector2& operator-=(Vector2 &v1, const Vector2 &v2) noexcept;
Vector2& operator*=(Vector2 &v, const float &f) noexcept;
Vector2& operator/=(Vector2 &v, const float &f);
std::ostream& operator<<(std::ostream &stream, Vector2 &v) noexcept;

/* Vector3 */

bool operator==(const Vector3 &v1, const Vector3 &v2) noexcept;
Vector3 operator+(const Vector3 &v1, const Vector3 &v2) noexcept;
Vector3 operator-(const Vector3 &v1, const Vector3 &v2) noexcept;
Vector3 operator-(const Vector3 &v) noexcept;
Vector3 operator*(const Vector3 &v, const float &f) noexcept;
Vector3 operator/(const Vector3 &v, const float &f);
Vector3& operator+=(Vector3 &v1, const Vector3 &v2) noexcept;
Vector3& operator-=(Vector3 &v1, const Vector3 &v2) noexcept;
Vector3& operator*=(Vector3 &v, const float &f) noexcept;
Vector3& operator/=(Vector3 &v, const float &f);
std::ostream& operator<<(std::ostream &stream, Vector3 &v) noexcept;

/* Vector4/Quaternion */

bool operator==(const Vector4 &v1, const Vector4 &v2) noexcept;
Vector4 operator+(const Vector4 &v1, const Vector4 &v2) noexcept;
Vector4 operator-(const Vector4 &v1, const Vector4 &v2) noexcept;
Vector4 operator-(const Vector4 &v) noexcept;
Vector4 operator*(const Vector4 &v, const float &f) noexcept;
Vector4 operator/(const Vector4 &v, const float &f);
Vector4& operator+=(Vector4 &v1, const Vector4 &v2) noexcept;
Vector4& operator-=(Vector4 &v1, const Vector4 &v2) noexcept;
Vector4& operator*=(Vector4 &v, const float &f) noexcept;
Vector4& operator/=(Vector4 &v, const float &f);
std::ostream& operator<<(std::ostream &stream, Vector4 &v) noexcept;

/* Matrix */

Matrix operator+(const Matrix &m1, const Matrix &m2) noexcept;
Matrix operator-(const Matrix &m1, const Matrix &m2) noexcept;
Matrix operator*(const Matrix &m1, const Matrix &m2) noexcept;
Matrix& operator+=(Matrix &m1, const Matrix &m2) noexcept;
Matrix& operator-=(Matrix &m1, const Matrix &m2) noexcept;
Matrix& operator*=(Matrix &m1, const Matrix &m2) noexcept;

/* Color */

bool operator==(const Color &c1, const Color &c2) noexcept;
Color operator+(const Color &c1, const Color &c2) noexcept;
Color operator-(const Color &c1, const Color &c2) noexcept;
Color operator*(const Color &c, const float f) noexcept;
Color operator/(const Color &c, const float f);
Color& operator+=(Color &c1, const Color &c2) noexcept;
Color& operator-=(Color &c1, const Color &c2) noexcept;
Color& operator*=(Color &c, const float f) noexcept;
Color& operator/=(Color &c, const float f);
std::ostream& operator<<(std::ostream &stream, Color &c) noexcept;

/* Core */

void
InitWindow(int width, int height, const std::string &title);

void
SetWindowTitle(const std::string &title);

void
SetClipboardText(const std::string &text);

Shader
LoadShader(const std::string &vsFileName, const std::string &fsFileName);

Shader
LoadShaderFromMemory(const std::string &vsCode, const std::string &fsCode);

int
GetShaderLocation(Shader shader, const std::string &uniformName);

int
GetShaderLocationAttrib(Shader shader, const std::string &attribName);

void
TakeScreenshot(const std::string &fileName);

unsigned char *
LoadFileData(const std::string &fileName, unsigned int *bytesRead);

bool
SaveFileData(const std::string &fileName, void *data, unsigned int bytesToWrite);

char *
LoadFileText(const std::string &fileName);

bool
SaveFileText(const std::string &fileName, char *text);

bool
FileExists(const std::string &fileName);

bool
DirectoryExists(const std::string &dirPath);

bool
IsFileExtension(const std::string &fileName, const std::string &ext);

const char *
GetFileExtension(const std::string &fileName);

const char *
GetFileName(const std::string &filePath);

const char *
GetFileNameWithoutExt(const std::string &filePath);

const char *
GetDirectoryPath(const std::string &filePath);

const char *
GetPrevDirectoryPath(const std::string &dirPath);

bool
ChangeDirectory(const std::string &dir);

long
GetFileModTime(const std::string &fileName);

void
OpenURL(const std::string &url);

/* Textures */

Image
LoadImage(const std::string &fileName);

Image
LoadImageRaw(const std::string &fileName, int width, int height, int format,
             int headerSize);

Image
LoadImageAnim(const std::string &fileName, int *frames);

Image
LoadImageFromMemory(const std::string &fileType, const unsigned char *fileData,
                    int dataSize);

bool
ExportImage(Image image, const std::string &fileName);

bool
ExportImageAsCode(Image image, const std::string &fileName);

Image
ImageText(const std::string &text, int fontSize, Color color);

Image
ImageTextEx(Font font, const std::string &text, float fontSize, float spacing,
            Color tint);

void
ImageDrawText(Image *dst, const std::string &text, int posX, int posY,
              int fontSize, Color color);

void
ImageDrawTextEx(Image *dst, Font font, const std::string &text,
                Vector2 position, float fontSize, float spacing, Color tint);

Texture2D
LoadTexture(const std::string &fileName);

/* Text */

Font
LoadFont(const std::string &fileName);

Font
LoadFontEx(const std::string &fileName, int fontSize, int *fontChars,
           int glyphCount);

Font
LoadFontFromMemory(const std::string &fileType, const unsigned char *fileData,
                   int dataSize, int fontSize, int *fontChars, int glyphCount);

void
DrawText(const std::string &text, int posX, int posY, int fontSize, Color color);

void
DrawTextEx(Font font, const std::string &text, Vector2 position, float fontSize,
           float spacing, Color tint);

void
DrawTextPro(Font font, const std::string &text, Vector2 position,
            Vector2 origin, float rotation, float fontSize, float spacing,
            Color tint);

int
MeasureText(const std::string &text, int fontSize);

Vector2
MeasureTextEx(Font font, const std::string &text, float fontSize, float spacing);

int*
LoadCodepoints(const std::string &text, int *count);

int
GetCodepointCount(const std::string &text);

int
GetCodepoint(const std::string &text, int *bytesProcessed);

/* Models */

Model
LoadModel(const std::string &fileName);

bool
ExportMesh(Mesh mesh, const std::string &fileName);

Material*
LoadMaterials(const std::string &fileName, int *materialCount);

ModelAnimation*
LoadModelAnimations(const std::string &fileName, unsigned int *animCount);

/* Audio */

Wave
LoadWave(const std::string &fileName);

Wave
LoadWaveFromMemory(const std::string &fileType, const unsigned char *fileData,
                   int dataSize);

Sound
LoadSound(const std::string &fileName);

bool
ExportWave(Wave wave, const std::string &fileName);

bool
ExportWaveAsCode(Wave wave, const std::string &fileName);

Music
LoadMusicStream(const std::string &fileName);

Music
LoadMusicStreamFromMemory(const std::string &fileType, unsigned char *data,
                          int dataSize);

#endif // RAYLIB_EXT_HPP
