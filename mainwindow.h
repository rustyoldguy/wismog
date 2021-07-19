#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qmessagebox.h>

///Von codeblocks cpp-Programm
#include <alsa/asoundlib.h>
#include <alsa/pcm.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include <QSlider>

//#define BUFFER_LEN 48000
#define BUFFER_LEN 30000 //15000
#define DIT_BUFFER_LEN 5000 //5000 test: 10000
#define WRT_BUFFER_LEN 3000 //2000 test: 4000 Zeit zwischen den Bestandteilen eines Zeichens
#define PAUSEN_BUFFER_LEN 10000 //10000 test 20000
#define SPACE_BUFFER_LEN 8000  //6000Leerzeichen test 12000

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int fehler;
    int frequenz;
    int duration;

    float buffer[BUFFER_LEN];// = {0};
    float warte[PAUSEN_BUFFER_LEN];// = {0};
    snd_pcm_t *handle;
    snd_pcm_sframes_t frames;
    //int f = 800;              //frequency
    //snd_output_t *output = NULL;
    const char *device = "default";//NULL;                       //soundcard


    int STRICHLAENGE;
    int PUNKTLAENGE;
    int ZWRAUMLAENGE;
    int LEERZEICHEN;

    int initrandom;

     char mtext[1000]; // war vorher 200
     unsigned char cwtxt[1000];
     char mchar[72][10];
     char mletr[72][6];
     short zeichensatz[72];
     int zeichenzahl;
     unsigned char zuzatxt[200];
     int mtextlen;
     int cwtxtvals;
     int fs;             //sampling frequency
     int textlaenge;
     int err;
     int mspeed;
     int grupgroesse;
     int einzelzeichen;

     QString Teila;
     QString Teilb;
     QString Nachricht;
     QString dummy;

     bool buchstaben;
     bool satzzeichen;
     bool zahlen;
     bool umlaute;
     bool francais;
     bool griechische;

     short buchstabenweg;
     short zahlenweg;
     short umlauteweg;
     short franzweg;
     short satzzeichenweg;
     short griechischeweg;

private slots:
   void on_actionAutor_triggered();
   int getrand(int zmin, int zmax);
   void InitAreale(void);
   void FrameFehler(void);
   void mksound(int f, int fs, int tonart);
   int Daat(void);
   void SetmtxtNULL(void);
   void generiere_gruppe();
   void generiere_Umlaute();
   void generiere_lettres();
   void generiere_griechische();
   void SetSpeed(void);
   void kuerzearreal(short stelle);
   void kurze_Zeichenliste_ausgeben(void);
   void check_letter_settings(void);


   void on_actionCLS_Textfeld_triggered();

   void on_actionZeige_alle_Zeichen_triggered();

   void Lautsteaerke(void);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
