#ifdef __APPLE__
#include <GLUT/glut.h> // Pour Mac OS X.
#else
#include <GL/glut.h> // Pour les autres systèmes.
#endif

#include "textures.h"
#include "utils.h"

/// Nombre de textures total chargées.
#define NOMBRE_TEXTURES 2

/// Identifiants des textures générées.
unsigned int texIds[NOMBRE_TEXTURES];

void initTextures()
{
    TTexture textureFeu = loadJpeg("textures/feu.jpg");
    TTexture textureTerre = loadJpeg("textures/terre.jpg");

    glGenTextures(2, texIds);

    // Charger la texture de feu.
    glBindTexture(GL_TEXTURE_2D, texIds[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureFeu.largeur, textureFeu.hauteur, 0, GL_RGB, GL_UNSIGNED_BYTE, textureFeu.texels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    // Charger la texture du globe terrestre.
    glBindTexture(GL_TEXTURE_2D, texIds[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureTerre.largeur, textureTerre.hauteur, 0, GL_RGB, GL_UNSIGNED_BYTE, textureTerre.texels);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
}

void setTexture(const unsigned int textureId)
{
    glBindTexture(GL_TEXTURE_2D, texIds[textureId]);
}

void clearTexture()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
