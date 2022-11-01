#include <string>
#include <raylib.h>

extern "C" {
#define RAYMATH_IMPLEMENTATION
#include <raymath.h>
}

#include <raylib-ext.hpp>

/* Vector2 */

bool
operator==(const Vector2 &v1, const Vector2 &v2)
noexcept
{
    return v1.x == v2.x && v1.y == v2.y;
}

Vector2
operator+(const Vector2 &v1, const Vector2 &v2)
noexcept
{
    return Vector2Add(v1, v2);
}

Vector2
operator-(const Vector2 &v1, const Vector2 &v2)
noexcept
{
    return Vector2Subtract(v1, v2);
}

Vector2
operator-(const Vector2 &v)
noexcept
{
    return Vector2Negate(v);
}

Vector2
operator*(const Vector2 &v, const float &f)
noexcept
{
    return Vector2Scale(v, f);
}

Vector2
operator/(const Vector2 &v, const float &f)
{
    return Vector2Scale(v, 1 / f);
}

Vector2&
operator+=(Vector2 &v1, const Vector2 &v2)
noexcept
{
    v1.x += v2.x;
    v1.y += v2.y;
    return v1;
}

Vector2&
operator-=(Vector2 &v1, const Vector2 &v2)
noexcept
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    return v1;
}

Vector2&
operator*=(Vector2 &v, const float &f)
noexcept
{
    v.x *= f;
    v.y *= f;
    return v;
}

Vector2&
operator/=(Vector2 &v, const float &f)
{
    v.x /= f;
    v.y /= f;
    return v;
}

std::ostream&
operator<<(std::ostream &stream, Vector2 &v)
noexcept
{
    stream << "{ " << v.x << ", " << v.y << " }";
    return stream;
}

/* Vector3 */

bool
operator==(const Vector3 &v1, const Vector3 &v2)
noexcept
{
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

Vector3
operator+(const Vector3 &v1, const Vector3 &v2)
noexcept
{
    return Vector3Add(v1, v2);
}

Vector3
operator-(const Vector3 &v1, const Vector3 &v2)
noexcept
{
    return Vector3Subtract(v1, v2);
}

Vector3
operator-(const Vector3 &v)
noexcept
{
    return Vector3Negate(v);
}

Vector3
operator*(const Vector3 &v, const float &f)
noexcept
{
    return Vector3Scale(v, f);
}

Vector3
operator/(const Vector3 &v, const float &f)
{
    return Vector3Scale(v, 1 / f);
}

Vector3&
operator+=(Vector3 &v1, const Vector3 &v2)
noexcept
{
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    return v1;
}

Vector3&
operator-=(Vector3 &v1, const Vector3 &v2)
noexcept
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
    return v1;
}

Vector3&
operator*=(Vector3 &v, const float &f)
noexcept
{
    v.x *= f;
    v.y *= f;
    v.z *= f;
    return v;
}

Vector3&
operator/=(Vector3 &v, const float &f)
{
    v.x /= f;
    v.y /= f;
    v.z /= f;
    return v;
}

std::ostream&
operator<<(std::ostream &stream, Vector3 &v)
noexcept
{
    stream << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
    return stream;
}

/* Vector4/Quaternion */

bool
operator==(const Vector4 &v1, const Vector4 &v2)
noexcept
{
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}

Vector4
operator+(const Vector4 &v1, const Vector4 &v2)
noexcept
{
    return QuaternionAdd(v1, v2);
}

Vector4
operator-(const Vector4 &v1, const Vector4 &v2)
noexcept
{
    return QuaternionSubtract(v1, v2);
}

Vector4
operator-(const Vector4 &v)
noexcept
{
    return QuaternionScale(v, -1);
}

Vector4
operator*(const Vector4 &v, const float &f)
noexcept
{
    return QuaternionScale(v, f);
}

Vector4
operator/(const Vector4 &v, const float &f)
{
    return QuaternionScale(v, 1 / f);
}

Vector4&
operator+=(Vector4 &v1, const Vector4 &v2)
noexcept
{
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    v1.w += v2.w;
    return v1;
}

Vector4&
operator-=(Vector4 &v1, const Vector4 &v2)
noexcept
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
    v1.w -= v2.w;
    return v1;
}

Vector4&
operator*=(Vector4 &v, const float &f)
noexcept
{
    v.x *= f;
    v.y *= f;
    v.z *= f;
    v.w *= f;
    return v;
}

Vector4&
operator/=(Vector4 &v, const float &f)
{
    v.x /= f;
    v.y /= f;
    v.z /= f;
    v.w /= f;
    return v;
}

std::ostream&
operator<<(std::ostream &stream, Vector4 &v)
noexcept
{
    stream << "{ " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << " }";
    return stream;
}

/* Matrix */

Matrix
operator+(const Matrix &m1, const Matrix &m2)
noexcept
{
    return MatrixAdd(m1, m2);
}

Matrix
operator-(const Matrix &m1, const Matrix &m2)
noexcept
{
    return MatrixSubtract(m1, m2);
}

Matrix
operator*(const Matrix &m1, const Matrix &m2)
noexcept
{
    return MatrixMultiply(m1, m2);
}

Matrix&
operator+=(Matrix &m1, const Matrix &m2)
noexcept
{
    m1 = MatrixAdd(m1, m2);
    return m1;
}

Matrix&
operator-=(Matrix &m1, const Matrix &m2)
noexcept
{
    m1 = MatrixSubtract(m1, m2);
    return m1;
}

Matrix&
operator*=(Matrix &m1, const Matrix &m2)
noexcept
{
    m1 = MatrixMultiply(m1, m2);
    return m1;
}

/* Color */

bool
operator==(const Color &c1, const Color &c2)
noexcept
{
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;

}

Color
operator+(const Color &c1, const Color &c2)
noexcept
{
    return {
        (uint8_t) Clamp((float) c1.r + (float) c2.r, 0, 255),
        (uint8_t) Clamp((float) c1.g + (float) c2.g, 0, 255),
        (uint8_t) Clamp((float) c1.b + (float) c2.b, 0, 255),
        (uint8_t) Clamp((float) c1.a + (float) c2.a, 0, 255),
    };
}

Color
operator-(const Color &c1, const Color &c2)
noexcept
{
    return {
        (uint8_t) Clamp((float) c1.r - (float) c2.r, 0, 255),
        (uint8_t) Clamp((float) c1.g - (float) c2.g, 0, 255),
        (uint8_t) Clamp((float) c1.b - (float) c2.b, 0, 255),
        (uint8_t) Clamp((float) c1.a - (float) c2.a, 0, 255),
    };
}

Color
operator*(const Color &c, const float f)
noexcept
{
    return {
        (uint8_t) Clamp((float) c.r * f, 0, 255),
        (uint8_t) Clamp((float) c.g * f, 0, 255),
        (uint8_t) Clamp((float) c.b * f, 0, 255),
        c.a, // c.a doesn't change
    };
}

Color
operator/(const Color &c, const float f)
{
    return {
        (uint8_t) Clamp((float) c.r / f, 0, 255),
        (uint8_t) Clamp((float) c.g / f, 0, 255),
        (uint8_t) Clamp((float) c.b / f, 0, 255),
        c.a, // c.a doesn't change
    };
}

Color&
operator+=(Color &c1, const Color &c2)
noexcept
{
    c1.r = (uint8_t) Clamp((float) c1.r + (float) c2.r, 0, 255);
    c1.g = (uint8_t) Clamp((float) c1.g + (float) c2.g, 0, 255);
    c1.b = (uint8_t) Clamp((float) c1.b + (float) c2.b, 0, 255);
    c1.a = (uint8_t) Clamp((float) c1.a + (float) c2.a, 0, 255);
    return c1;
}

Color&
operator-=(Color &c1, const Color &c2)
noexcept
{
    c1.r = (uint8_t) Clamp((float) c1.r - (float) c2.r, 0, 255);
    c1.g = (uint8_t) Clamp((float) c1.g - (float) c2.g, 0, 255);
    c1.b = (uint8_t) Clamp((float) c1.b - (float) c2.b, 0, 255);
    c1.a = (uint8_t) Clamp((float) c1.a - (float) c2.a, 0, 255);
    return c1;
}

Color&
operator*=(Color &c, const float f)
noexcept
{
    c.r = (uint8_t) Clamp((float) c.r * f, 0, 255);
    c.g = (uint8_t) Clamp((float) c.g * f, 0, 255);
    c.b = (uint8_t) Clamp((float) c.b * f, 0, 255);
    // c.a doesn't change
    return c;
}

Color&
operator/=(Color &c, const float f)
{
    c.r = (uint8_t) Clamp((float) c.r / f, 0, 255);
    c.g = (uint8_t) Clamp((float) c.g / f, 0, 255);
    c.b = (uint8_t) Clamp((float) c.b / f, 0, 255);
    // c.a doesn't change
    return c;
}

std::ostream&
operator<<(std::ostream &stream, Color &c)
noexcept
{
    stream << "Color { "
           << c.r << ", "
           << c.g << ", "
           << c.b << ", "
           << c.a << " }";
    return stream;
}

/* Core */

void
InitWindow(int width, int height, const std::string &title)
{
    InitWindow(width, height, title.c_str());
}

void
SetWindowTitle(const std::string &title)
{
    SetWindowTitle(title.c_str());
}

void
SetClipboardText(const std::string &text)
{
    SetClipboardText(text.c_str());
}

Shader
LoadShader(const std::string &vsFileName, const std::string &fsFileName)
{
    return LoadShader(vsFileName.c_str(), fsFileName.c_str());
}

Shader
LoadShaderFromMemory(const std::string &vsCode, const std::string &fsCode)
{
    return LoadShaderFromMemory(vsCode.c_str(), fsCode.c_str());
}

int
GetShaderLocation(Shader shader, const std::string &uniformName)
{
    return GetShaderLocation(shader, uniformName.c_str());
}

int
GetShaderLocationAttrib(Shader shader, const std::string &attribName)
{
    return GetShaderLocationAttrib(shader, attribName.c_str());
}

void
TakeScreenshot(const std::string &fileName)
{
    TakeScreenshot(fileName.c_str());
}

unsigned char *
LoadFileData(const std::string &fileName, unsigned int *bytesRead)
{
    return LoadFileData(fileName.c_str(), bytesRead);
}

bool
SaveFileData(const std::string &fileName, void *data, unsigned int bytesToWrite)
{
    return SaveFileData(fileName.c_str(), data, bytesToWrite);
}

char *
LoadFileText(const std::string &fileName)
{
    return LoadFileText(fileName.c_str());
}

bool
SaveFileText(const std::string &fileName, char *text)
{
    return SaveFileText(fileName.c_str(), text);
}

bool
FileExists(const std::string &fileName)
{
    return FileExists(fileName.c_str());
}

bool
DirectoryExists(const std::string &dirPath)
{
    return DirectoryExists(dirPath.c_str());
}

bool
IsFileExtension(const std::string &fileName, const std::string &ext)
{
    return IsFileExtension(fileName.c_str(), ext.c_str());
}

const char *
GetFileExtension(const std::string &fileName)
{
    return GetFileExtension(fileName.c_str());
}

const char *
GetFileName(const std::string &filePath)
{
    return GetFileName(filePath.c_str());
}

const char *
GetFileNameWithoutExt(const std::string &filePath)
{
    return GetFileNameWithoutExt(filePath.c_str());
}

const char *
GetDirectoryPath(const std::string &filePath)
{
    return GetDirectoryPath(filePath.c_str());
}

const char *
GetPrevDirectoryPath(const std::string &dirPath)
{
    return GetPrevDirectoryPath(dirPath.c_str());
}

bool
ChangeDirectory(const std::string &dir)
{
    return ChangeDirectory(dir.c_str());
}

long
GetFileModTime(const std::string &fileName)
{
    return GetFileModTime(fileName.c_str());
}

void
OpenURL(const std::string &url)
{
    return OpenURL(url.c_str());
}

/* Textures */

Image
LoadImage(const std::string &fileName)
{
    return LoadImage(fileName.c_str());
}

Image
LoadImageRaw(const std::string &fileName, int width, int height, int format,
             int headerSize)
{
    return LoadImageRaw(fileName.c_str(), width, height, format, headerSize);
}

Image
LoadImageAnim(const std::string &fileName, int *frames)
{
    return LoadImageAnim(fileName.c_str(), frames);
}

Image
LoadImageFromMemory(const std::string &fileType, const unsigned char *fileData,
                    int dataSize)
{
    return LoadImageFromMemory(fileType.c_str(), fileData, dataSize);
}

bool
ExportImage(Image image, const std::string &fileName)
{
    return ExportImage(image, fileName.c_str());
}

bool
ExportImageAsCode(Image image, const std::string &fileName)
{
    return ExportImageAsCode(image, fileName.c_str());
}

Image
ImageText(const std::string &text, int fontSize, Color color)
{
    return ImageText(text.c_str(), fontSize, color);
}

Image
ImageTextEx(Font font, const std::string &text, float fontSize, float spacing,
            Color tint)
{
    return ImageTextEx(font, text.c_str(), fontSize, spacing, tint);
}

void
ImageDrawText(Image *dst, const std::string &text, int posX, int posY,
              int fontSize, Color color)
{
    ImageDrawText(dst, text.c_str(), posX, posY, fontSize, color);
}

void
ImageDrawTextEx(Image *dst, Font font, const std::string &text,
                Vector2 position, float fontSize, float spacing, Color tint)
{
    ImageDrawTextEx(dst, font, text.c_str(), position, fontSize, spacing, tint);
}

Texture2D
LoadTexture(const std::string &fileName)
{
    return LoadTexture(fileName.c_str());
}

/* Text */

Font
LoadFont(const std::string &fileName)
{
    return LoadFont(fileName.c_str());
}

Font
LoadFontEx(const std::string &fileName, int fontSize, int *fontChars,
           int glyphCount)
{
    return LoadFontEx(fileName.c_str(), fontSize, fontChars, glyphCount);
}

Font
LoadFontFromMemory(const std::string &fileType, const unsigned char *fileData,
                   int dataSize, int fontSize, int *fontChars, int glyphCount)
{
    return LoadFontFromMemory(fileType.c_str(), fileData, dataSize, fontSize,
                              fontChars, glyphCount);
}

void
DrawText(const std::string &text, int posX, int posY, int fontSize, Color color)
{
    DrawText(text.c_str(), posX, posY, fontSize, color);
}

void
DrawTextEx(Font font, const std::string &text, Vector2 position, float fontSize,
           float spacing, Color tint)
{
    DrawTextEx(font, text.c_str(), position, fontSize, spacing, tint);
}

void
DrawTextPro(Font font, const std::string &text, Vector2 position,
            Vector2 origin, float rotation, float fontSize, float spacing,
            Color tint)
{
    DrawTextPro(font, text.c_str(), position, origin, rotation, fontSize,
                spacing, tint);
}

int
MeasureText(const std::string &text, int fontSize)
{
    return MeasureText(text.c_str(), fontSize);
}

Vector2
MeasureTextEx(Font font, const std::string &text, float fontSize, float spacing)
{
    return MeasureTextEx(font, text.c_str(), fontSize, spacing);
}

int*
LoadCodepoints(const std::string &text, int *count)
{
    return LoadCodepoints(text.c_str(), count);
}

int
GetCodepointCount(const std::string &text)
{
    return GetCodepointCount(text.c_str());
}

int
GetCodepoint(const std::string &text, int *bytesProcessed)
{
    return GetCodepoint(text.c_str(), bytesProcessed);
}

/* Models */

Model
LoadModel(const std::string &fileName)
{
    return LoadModel(fileName.c_str());
}

bool
ExportMesh(Mesh mesh, const std::string &fileName)
{
    return ExportMesh(mesh, fileName.c_str());
}

Material*
LoadMaterials(const std::string &fileName, int *materialCount)
{
    return LoadMaterials(fileName.c_str(), materialCount);
}

ModelAnimation*
LoadModelAnimations(const std::string &fileName, unsigned int *animCount)
{
    return LoadModelAnimations(fileName.c_str(), animCount);
}

/* Audio */

Wave
LoadWave(const std::string &fileName)
{
    return LoadWave(fileName.c_str());
}

Wave
LoadWaveFromMemory(const std::string &fileType, const unsigned char *fileData,
                   int dataSize)
{
    return LoadWaveFromMemory(fileType.c_str(), fileData, dataSize);
}

Sound
LoadSound(const std::string &fileName)
{
    return LoadSound(fileName.c_str());
}

bool
ExportWave(Wave wave, const std::string &fileName)
{
    return ExportWave(wave, fileName.c_str());
}

bool
ExportWaveAsCode(Wave wave, const std::string &fileName)
{
    return ExportWaveAsCode(wave, fileName.c_str());
}

Music
LoadMusicStream(const std::string &fileName)
{
    return LoadMusicStream(fileName.c_str());
}

Music
LoadMusicStreamFromMemory(const std::string &fileType,
                          const unsigned char *data,
                          int dataSize)
{
    return LoadMusicStreamFromMemory(fileType.c_str(), data, dataSize);
}

