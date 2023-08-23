#include <Arduino.h>

// déclaration des fonctions Ada ici où on les utilise (ou on peut les mettre dans un .h à part <hardware_abstraction_v2.h>)
// #include <hardware_abstraction_v2.h>
extern "C" void mainLoop(void);      // extern "C" pour déclarer l'import de fonctions au format C dans ce fichier cpp
//  extern "C" void Test_C_V2init(void); // extern "C" pour déclarer l'import de fonctions au format C dans ce fichier cpp

#include <TFT_eSPI.h>
// paramétrage de l'écran dans .pio\libdeps\nucleo_f446re\TFT_eSPI\User_Setup.h
// SPI2 est paramétré car SPI1 utilise la pin PA5 or PA5 est utilisé par la user led du Nucléo
#include <SPI.h>

/*
Voir https://blog.adacore.com/embedded-ada-spark-theres-a-shortcut
Mais cette fonction est-elle vraiment utile ?
En tout cas le build OK sans cette fonction
void __gnat_last_chance_handler(void)
{
  while (1)
    ;
}
*/

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  // on crée un gestionnaire TFT spécifique pour le setup()
  TFT_eSPI tft = TFT_eSPI();

  tft.init();

  tft.setRotation(3); // portrait: 0 ou 2, paysage: 1 ou 3.

  // affichage d'un message à l'écran:
  tft.fillScreen(TFT_BLACK);               // on efface tout (fond noir)
  tft.setFreeFont(&FreeSansOblique12pt7b); // police de caractère
  tft.setCursor(20, 70);                   // position du début du message
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.println("Hello !");

  delay(3000);

  /* Call Ada elaboration code */
  // Test_C_V2init();
}

void loop()
{
  mainLoop(); // Ada main loop
}
