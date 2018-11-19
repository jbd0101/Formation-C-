/*    Signal lumineux en fonction de la température et
 *     mesure immédiate à l'aide du bouton poussoir
 *
  */

//     Initialisation des variables pour le temps qui s'écoule
const int ledPinRouge = 13;   //LED  rouge en broche 13
const int ledPinOrange = 12;   //LED  orange en broche 12
const int ledPinVert = 11;     // LED vert en broche 11
const int ledPinButton = 10;  //LED de bouton-poussoir jaune en broche 10
const int buttonPin = 8;      //Bouton-poussoir en broche 8
const int interval = 50;    //Intervalle de temps (1 secondes)
const int sensorPin = 0;
int buttonState;        //Variable pour enregistrement de l’état du bouton-poussoir
int ledState = LOW;     //Variable d’état pour la LED clignotante
float temperatureC;
unsigned long prev;     //Variable de temps


void setOrange(){
  Serial.println("Couleur orange sélectionné");
  digitalWrite (ledPinRouge,LOW);
  digitalWrite (ledPinOrange,HIGH);
  digitalWrite (ledPinVert,LOW);
}
void setRed(){
  Serial.println("Couleur rouge sélectionné");
  digitalWrite (ledPinRouge,HIGH);
  digitalWrite (ledPinOrange,LOW);
  digitalWrite (ledPinVert,LOW);
}
void setVert(){
  Serial.println("Couleur verte sélectionné");
  digitalWrite (ledPinRouge,LOW);
  digitalWrite (ledPinOrange,LOW);
  digitalWrite (ledPinVert,HIGH);
}
void setWhite(){
  Serial.println("Couleur blanche sélectionné");
  digitalWrite (ledPinRouge,LOW);
  digitalWrite (ledPinOrange,LOW);
  digitalWrite (ledPinVert,LOW);
}


void setup()
{
  Serial.begin (9600);
  pinMode(ledPinRouge, OUTPUT);  //Broche LED clignotante comme sortie   
  pinMode(ledPinOrange, OUTPUT);  //Broche LED clignotante comme sortie   
  pinMode(ledPinVert, OUTPUT);  //Broche LED clignotante comme sortie
  setWhite();

  pinMode(ledPinButton, OUTPUT); //Broche LED de bouton-poussoir comme sortie
  pinMode (buttonPin, INPUT);    //Broche bouton-poussoir comme entrée
  prev = millis();               //Mémoriser le compteur de temps actuel
}
void clignote(){
  prev = millis();
  setWhite();
}
float readTemp(){
  return analogRead(sensorPin);
}
void dispatch(){
  if (temperatureC <= 100)
  {
    setVert();
  }
  else if (temperatureC>100 && temperatureC<400)
  {
    setOrange();
  }
  else if (temperatureC >= 400)
  {
    setRed();
  }

//Interrogation de l’état du bouton-poussoir
  buttonState = digitalRead (buttonPin);
  if(buttonState == HIGH){
    Serial.println (readTemp()) ;
  }
}

void loop()
{

  temperatureC = readTemp();
// float temperatureC = ((reading*5/1023)-0.5)*100;    // mesure de la température en degré celcius
//Serial.println (Volt);
//Serial.println (temperatureC);
  dispatch();

  if((millis() - prev) > interval)
  {
    clignote();
  }
}
