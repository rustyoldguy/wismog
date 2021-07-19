#include "mainwindow.h"
#include "ui_mainwindow.h"


//globale Variablen zum Datenaustausch
//int initrandom = 0;



MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), initrandom(0), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->setWindowTitle("wismog V0.31");
  this->move(150,100); //Setzt die Widget-Ausgabeposition
  InitAreale();

  ui->le_Frequenz->setText("800");

  ui->SliderVolume->setValue(50);

  ui->comboBox->addItem("1");
  ui->comboBox->addItem("2");
  ui->comboBox->addItem("3");

  ui->cbx_letter->setChecked(true); //Setzt "Haeckchen"

  dummy = QString("%1").arg(mspeed);
  ui->le_mspeed->setText(dummy);


  //connect(ui->SliderVolume,  SIGNAL(valueChanged(int)), this, SLOT(Lautstaerke() ) );
  //connect(ui->SliderVolumes,   SIGNAL(valueChanged(int)),this,
  //            verticalSliders, &SlidersGroup::setValue);

  connect(ui->Ltest,          SIGNAL (clicked()),  this, SLOT(Lautsteaerke() ) );
  connect(ui->pb_setspeed,    SIGNAL (clicked()),  this, SLOT(SetSpeed() ) );
  connect(ui->pbZeichenliste, SIGNAL (clicked()),  this, SLOT(kurze_Zeichenliste_ausgeben() ) );
  connect(ui->genletter,      SIGNAL (clicked()),  this, SLOT(generiere_gruppe() ) );
  connect(ui->finito,         SIGNAL (clicked()),  qApp, SLOT(quit() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAutor_triggered()
{
    QMessageBox::about( this, "Autor",
                               "Wismog V 0.3\n"
                               "von Josef Wismeth\n"
                               "Version vom 17er-Mai-2021"
                                  );
}

///generiert Zufallszahlen von 1 bis 32767;
int MainWindow::getrand(int zmin, int zmax)
{
int zuza, zuza2, zuza3, rewer;
// bis 32767
//srand (time (NULL));
if (initrandom == 0)
{
srand (static_cast<unsigned int>(time (nullptr))); //new style cast
initrandom = 1;
}

zmax++;
zuza  = rand();
zuza2 = (zmax - zmin); // + 1);
zuza3 = zuza % zuza2;
rewer = zuza3 + zmin;
return rewer;
}

void MainWindow::InitAreale(void)
{
  short slei, sleia; // alt war int

  cwtxtvals = 0;
  grupgroesse = 20;
  mspeed = 1;
  fs = 48000;
  frequenz = 800;
  zeichenzahl = 72;

  buchstabenweg = 0;
  umlauteweg = 0;
  zahlenweg = 0;
  satzzeichenweg = 0;
  franzweg = 0;
  griechischeweg = 0;

  STRICHLAENGE = BUFFER_LEN;       //z.Z 30000
  PUNKTLAENGE = DIT_BUFFER_LEN;    //z.Z 5000
  ZWRAUMLAENGE = WRT_BUFFER_LEN;   //z.Z 3000
  LEERZEICHEN = WRT_BUFFER_LEN * 3;

    ///Zeichen 0 bis 25 Alphabet; 26 bis 29 ö,ä,ü,ß; 30 bis 39 Zahlen; 40 bis 52 Satzzeichen; 53 bis 60 Sonderzeichen; 61 ist Leerzeichen
     char mcode[72][10] = {"._",    "_...",   "_._.",   "_..",     ".",      ".._.",   "__.",    "....",   "..",    ".___",   "_._",    "._..",   "__",       // 13 Zeichen
                           "_.",    "___",    ".__.",   "__._",    "._.",    "...",    "_",      ".._",    "..._",   ".__",   "_.._",   "_.__",   "__..",     // 13 Zeichen
                           "___.",  "._._",   "..__",   "...__..", ".____",  "..___",  "...__",  "...._",  ".....",  "_....", "__...",  "___..",  "____.",    // 13 Zeichen
                           "_____", "_..._",  "_._._.", "__..__",  ".____.", "_...._", "_.__.",  "_.__._", "._.._.", "_.._.", "..__._", "___...", "..__..",   // 13 Zeichen
                           "._._._",".__._",  ".__._",  ".__._",  ".._..",   ".._..",  "_.._.", "_._..",   "__.__",  " ",     ".._..",  "_..._",  "_._._",    // 13 Zeichen
                           "._._.", "__.._", "_.._",   ".__._",  "__.__",    ".._.__", "__._"};                                                               //  7 Zeichen
    /*
     Zeichen     Hex    Okt
    ========================
       'Ä'       8E     216
       'ä'       84     204
       'Ö'       99     231
       'ö'       94     224
       'Ü'       9A     232
       'ü'       81     201
       'ß'       E1     341
     */

    char msign[72][4] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l",  "m", // 13 Zeichen
                         "n", "o", "p", "q", "r", "s", "t", "u",  "v", "w", "x", "y", "z", // 13 Zeichen
                         "ö", "ä", "ü", "ß", "1", "2", "3", "4", "5", "6", "7", "8",  "9", // 13 Zeichen
                         "0", "=", ";", ",", "'", "-", "(", ")", "\"", "/", "_", ":", "?", // 13 Zeichen
                         ".", "à", "á", "â", "é", "è", "ê", "ç", "ñ", " ", "α", "β",  "γ", // 13 Zeichen
                         "δ", "ε", "η", "λ", "ϱ", "φ", "ω"};                               //  7 Zeichen                                                                         //  7 Zeichen
    for(slei = 0; slei < 72; slei++)
     for(sleia = 0; sleia < 8; sleia++)
     {
      mchar[slei][sleia] = mcode[slei][sleia];
      mchar[slei][sleia + 1] = '\0';
     }

    for(slei = 0; slei < 72; slei++)
     {
     for(sleia = 0; sleia < 4; sleia++)
      {
       mletr[slei][sleia] = msign[slei][sleia];
       mletr[slei][sleia + 1] = '\0';
      }
     }
     for (slei = 0; slei < BUFFER_LEN; slei++) buffer[slei] = 0;
     for (slei = 0; slei < PAUSEN_BUFFER_LEN; slei++) warte[slei] = 0;
     //for (slei = 0; slei < DIT_BUFFER_LEN; slei++) punkt[slei] = 0;
     
  for(slei = 0; slei < 72; slei++)
   zeichensatz[slei] = slei;

}

void MainWindow::FrameFehler(void)
{
    if (frames < 0)
     {
      frames = snd_pcm_recover(handle, static_cast<int>(frames), 0);
      Nachricht = QString("snd_pcm_writei failed:  %1").arg(snd_strerror(err));
      QMessageBox::about( this, "Fehler", Nachricht);
     }
}

/// ermittelt ob Strich, Punkt, Zwischenraum oder Leerzeichen vorliegt und spielt den zugeordneten Ton ab
void MainWindow::mksound(int f, int fs, int tonart)
{
 int k;

 if (tonart == 1) /// Strich
  {
   for (k=0; k < (STRICHLAENGE * mspeed) / 3; k++) buffer[k] = static_cast<float>((sin(2*M_PI*f/fs*k))); //sine wave value generation
   frames = snd_pcm_writei(handle, buffer, static_cast<unsigned long>((STRICHLAENGE  * mspeed) / 3));            //sending values to sound driver
  }
 if (tonart == 2) /// Zwischenraum
  {
   for (k=0; k < ZWRAUMLAENGE * mspeed / 3; k++) warte[k] = 0;               //war vorher ohne mspeed / 3
    frames = snd_pcm_writei(handle, warte, static_cast<unsigned long>(ZWRAUMLAENGE));    //sending values to sound driver
   }
 if (tonart == 3) /// Punkt
  {
   for (k=0; k < (PUNKTLAENGE * mspeed) / 3; k++) buffer[k] = static_cast<float>((sin(2*M_PI*f/fs*k))); //sine wave value generation
    frames = snd_pcm_writei(handle, buffer, static_cast<unsigned long>((PUNKTLAENGE * mspeed) / 3));          //sending values to sound driver
  }
 if (tonart == 4) /// Leerzeichen
   {
   for (k=0; k < (SPACE_BUFFER_LEN * mspeed) / 3; k++) warte[k] = 0;               //sine wave value generation
    frames = snd_pcm_writei(handle, warte, SPACE_BUFFER_LEN);    //sending values to sound driver
   }

 FrameFehler();
}

int MainWindow::Daat(void)
{
 int  i, j, k, pspalte, f;
 i = j = k = pspalte = 0;
 int clen = 0;

 f = frequenz;

    if ((err = snd_pcm_open(&handle, device, SND_PCM_STREAM_PLAYBACK, 0)) < 0)
     {
      Nachricht = QString("Playback open error:  %1").arg(snd_strerror(err));
      QMessageBox::about( this, "Fehler", Nachricht);
      return -1;
     }
    if ((err = snd_pcm_set_params(handle,
               SND_PCM_FORMAT_FLOAT,
               SND_PCM_ACCESS_RW_INTERLEAVED,
               1, // Wie viele Kanäle 1=mono
               48000, // required sample rate in Hz
               1, // soft_resample / 0 = disallow alsa-lib resample stream, 1 = allow resampling
               8000)) < 0)
        { // latency / required overall latency in us (0 = optimum latency for players)
         Nachricht = QString("Playback open error:  %1").arg(snd_strerror(err));
         QMessageBox::about( this, "Fehler", Nachricht);
         return -1;
        }

  pspalte = 0;

 /// In cwtext sind nur die Nummern, an welchen sich die Zeichen im Array
 /// von 0 bis 72 befinden, hier ersetzt durch cwtext.

 for (k = 0; k < cwtxtvals; k++)
  {
   i = cwtxt[k];  // motext ist Parameter, bei der Uebergabe cwtxt

   if (k == 61)  mksound(f, fs, 4); //61 ist das Leerzeichen
   else
   {
    clen = static_cast<int>(strlen(mchar[i]));

    for (j = 0; j < clen; j++)
     {
      if (mchar[i][j] == '.')
       {
        mksound(f, fs, 3);
        mksound(f, fs, 2);
        ///if (einzelzeichen != 0) std::cout << mchar[i][j];
       }
       if (mchar[i][j] == '_')
       {
        mksound(f, fs, 1);
        mksound(f, fs, 2);
        ///if (einzelzeichen != 0) std::cout << mchar[i][j];
       }
     }
    }
    mksound(f, fs, 4);

    Nachricht = QString(" %1").arg(mletr[i]);
    if (pspalte >= 5)
    {
     pspalte = 0;
     ui->textEdit->append(Nachricht);
    }
    else
     ui->textEdit->insertPlainText(Nachricht);

    pspalte++;
  }

  snd_pcm_close(handle);

return fehler;
}

void MainWindow::SetmtxtNULL(void)
{
 int i;
 for (i = 0; i < 1000; i++)
        mtext[i] = '\0';
}


void MainWindow::generiere_gruppe()
{
 int  ug, og, zufallszeichen;
 short i;

 zufallszeichen = 0;

 ug = 0;
 og = 25;

 check_letter_settings();

 ug = 0;
 og = zeichenzahl - 1;


 Teila = QString("Generiere %1 zufaellige Buchstaben").arg(grupgroesse);
 Teilb = QString(" Zeichen ug=%1 bis ").arg(ug);
 dummy = QString(" og=%1\n").arg(og);
 Nachricht = Teila + Teilb + dummy;
 ui->textEdit->append(Nachricht);

 SetmtxtNULL();

      cwtxtvals = grupgroesse;

      /// In cwtext werden nur die Nummern der Zeichen gespeichert
      for (i = 0; i < cwtxtvals; i++)
       { 
        zufallszeichen = getrand(ug, og);
        cwtxt[i] = static_cast<unsigned char>(zeichensatz[zufallszeichen]);
       } 
 Daat();

}


void MainWindow::generiere_Umlaute()
{
 int i;


 Nachricht = QString("Generiere %1 zufaellige deutsche Umlaute\n").arg(grupgroesse);
 ui->textEdit->append(Nachricht);

 SetmtxtNULL();

      cwtxtvals = grupgroesse;

      for (i = 0; i < cwtxtvals; i++)
        cwtxt[i] = static_cast<unsigned char>(getrand(26, 29));


 Daat();
}

void MainWindow::generiere_lettres()
{
 int i;


 Nachricht = QString("Generiere %1 zufaellige franzoesishe Letter\n").arg(grupgroesse);
 ui->textEdit->append(Nachricht);

 SetmtxtNULL();

      cwtxtvals = grupgroesse;

      for (i = 0; i < cwtxtvals; i++)
        cwtxt[i] = static_cast<unsigned char>(getrand(53, 61));


 Daat();
}


void MainWindow::generiere_griechische()
{
 int i;


 Nachricht = QString("Generiere %1 zufaellige griechische Buchstaben\n").arg(grupgroesse);
 ui->textEdit->append(Nachricht);

 SetmtxtNULL();

      cwtxtvals = grupgroesse;

      for (i = 0; i < cwtxtvals; i++)
        cwtxt[i] = static_cast<unsigned char>(getrand(62, 71));


 Daat();
}

void MainWindow::SetSpeed(void)
{
  //dummy = ui->le_mspeed->text();
  dummy = ui->comboBox->currentText();
  mspeed = dummy.toInt();


  if((mspeed < 1) || (mspeed > 3)) mspeed = 1;
   else
    {
     dummy = QString("%1").arg(mspeed);
     ui->le_mspeed->setText(dummy);
    }

}

void MainWindow::on_actionCLS_Textfeld_triggered()
{
  ui->textEdit->clear();
}

void  MainWindow::kuerzearreal(short stelle)
{
short slei, sleib, zeiza;

// Initialisiere Array mit Werten
for (sleib = 0; sleib < 72; sleib++)
 if(zeichensatz[sleib] == stelle)
  break;

if ((stelle == 71) && (sleib < 71))
{
 for (slei = sleib; slei < 72; slei++)
       zeichensatz[slei] = zeichensatz[slei + 1];
}


if(stelle < 71)  for (slei = sleib; slei < 72; slei++)
       zeichensatz[slei] = zeichensatz[slei + 1];

  zeichensatz[71] = 0;

for (zeiza = 1; zeiza < 72; zeiza++)
 {
  if(zeichensatz[zeiza] == 0)
  break;
 }
 zeichenzahl = zeiza;

}

void MainWindow::kurze_Zeichenliste_ausgeben(void)
{
 //int i;
 short i, slei;

check_letter_settings();

Nachricht = QString("\nAusgabe der Zeichenliste, Zeichenzahl %1").arg(zeichenzahl);
ui->textEdit->append(Nachricht);


  Nachricht = QString("\nZeichenzahl %1").arg(zeichenzahl);
  ui->textEdit->append(Nachricht);


 for (slei = 0; slei < zeichenzahl; slei++)
       {
        i = zeichensatz[slei];


        dummy = QString("%1  ").arg(slei);
        Teila= QString("%1   ").arg(i);
        Teilb = QString("= %1").arg(mletr[i]);
        Nachricht = dummy + Teila + Teilb;
        ui->textEdit->append(Nachricht);
       }

}

void MainWindow::check_letter_settings(void)
{
short slei;

buchstaben = ui->cbx_letter->isChecked();
umlaute = ui->cbx_umlaute->isChecked();
zahlen = ui->cbx_zahlen->isChecked();
satzzeichen = ui->cbx_szeichen->isChecked();
francais = ui->cbx_francais->isChecked();
griechische = ui->cbx_griechische->isChecked();


if((!buchstaben) && (!umlaute) && (!zahlen) && (!satzzeichen) && (!francais) && (!griechische))
 {
  ui->cbx_letter->setChecked(true); //Setzt "Haeckchen"
  buchstaben = ui->cbx_letter->isChecked();
 }


zeichenzahl = 72;

for (slei = 0; slei < 72; slei++)
 zeichensatz[slei] = slei;

//Kuerze die Buchstaben aus zeichensatz-Array heraus;
if(!buchstaben)
 {
  for (slei = 0; slei <= 25; slei++)
   kuerzearreal(slei);
 }

//Kuerze die Umlaute aus zeichensatz-Array heraus;
if(!umlaute)
 {
  for (slei = 26; slei <= 29; slei++)
   kuerzearreal(slei);
 }

//Kuerze die Zahlen aus zeichensatz-Array heraus;
if(!zahlen)
 {
  dummy = QString("kuerze Zahlen weg\n");
   ui->textEdit->append(dummy);
    for (slei = 30; slei <= 39; slei++)
   kuerzearreal(slei);
 }

//Kuerze die Satzzeichen Buchstaben aus zeichensatz-Array heraus;
if(!satzzeichen)
 {
  for (slei = 40; slei <= 52; slei++)
   kuerzearreal(slei);
 }

//Kuerze die franzoesischen Buchstaben aus zeichensatz-Array heraus;
if (!francais)
 {
  for (slei = 53; slei <= 61; slei++)
   kuerzearreal(slei);
 }

//Kuerze die griechischen Buchstaben aus zeichensatz-Array heraus;
if(!griechische)
 {
  for (slei = 62; slei <= 71; slei++)
   kuerzearreal(slei);
 }
}

void MainWindow::on_actionZeige_alle_Zeichen_triggered()
{
    int i;

         for (i = 0; i < 72; i++)
          {
           if (i == 26)
           {
            Nachricht = QString("\ndeutsche Umlaute:");
            ui->textEdit->append(Nachricht);
           }
           if (i == 30)
           {
            Nachricht = QString("\nZahlen:");
            ui->textEdit->append(Nachricht);
           }
           if (i == 40)
           {
            Nachricht = QString("\nSatzzeichen:");
            ui->textEdit->append(Nachricht);
           }
           if (i == 53)
           {
            Nachricht = QString("\nfranzösische Buchstaben:");
            ui->textEdit->append(Nachricht);
           }
           if (i == 62)
           {
            Nachricht = QString("\ngriechische Buchstaben:");
            ui->textEdit->append(Nachricht);
           }

           dummy = QString("%1   ").arg(i);
           Teila = QString("%1 = ").arg(mletr[i]);
           if (i != 61)
            Teilb = QString("%1").arg(mchar[i]);
           else Teilb = QString("Leerzeichen\n");
           Nachricht = dummy + Teila + Teilb;
           ui->textEdit->append(Nachricht);
          }


}


void MainWindow::Lautsteaerke(void)
{
     double xvalue=ui->SliderVolume->value();
     Nachricht = QString("Lautstärke: %1 Prozent").arg(xvalue);
     ui->textEdit->append(Nachricht);
     //ui->le_Frequenz->setText("500");



    long min, max;
        snd_mixer_t *handle;
        snd_mixer_selem_id_t *sid;
        const char *card = "default";
        const char *selem_name = "Master";

        snd_mixer_open(&handle, 0);
        snd_mixer_attach(handle, card);
        snd_mixer_selem_register(handle, NULL, NULL);
        snd_mixer_load(handle);

        snd_mixer_selem_id_alloca(&sid);
        snd_mixer_selem_id_set_index(sid, 0);
        snd_mixer_selem_id_set_name(sid, selem_name);
        snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);

        snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
        snd_mixer_selem_set_playback_volume_all(elem, xvalue * max / 100);

        snd_mixer_close(handle);
}
