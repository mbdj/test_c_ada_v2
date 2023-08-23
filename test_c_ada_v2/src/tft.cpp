// les fonctions C exportées vers le code Ada sont codées ici dans un fichier C++ car elles font appel à des classes C++

#include <Arduino.h>

// Déclaration des fonctions exportées vers le code Ada
// Elles sont implémentées plus bas
// Elles doivent être déclarées avec extern "C" car elles ont dans un fichier C++ et doivent être exportées au format C
// autre possibilité : mettre la déclaration dans un fichier include #include <tft.h>
extern "C" void tftInit();
extern "C" void tftPrintln(char *s);

// librairie Arduino (écrant TFT)
#include <TFT_eSPI.h>
// paramétrage de l'écran dans .pio\libdeps\nucleo_f446re\TFT_eSPI\User_Setup.h
// SPI2 est paramétré car SPI1 utilise la pin PA5 or PA5 est utilisé par la user led du Nucléo
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

void tftPrintln(char *s)
{
    tft.println(s);
}

void tftInit()
{
    tft.init();

    tft.setRotation(3); // portrait: 0 ou 2, paysage: 1 ou 3.

    // affichage d'un message à l'écran:
    tft.fillScreen(TFT_BLACK);               // on efface tout (fond noir)
    tft.setFreeFont(&FreeSansOblique12pt7b); // police de caractère
    tft.setCursor(20, 70);                   // position du début du message
    tft.setTextSize(1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.println("Ada !");
}
