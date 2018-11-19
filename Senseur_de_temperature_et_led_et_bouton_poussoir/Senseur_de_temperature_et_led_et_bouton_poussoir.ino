/*    Signal lumineux en fonction de la température et 
 *     mesure immédiate à l'aide du bouton poussoir 
 *     
  */

//     Initialisation des variables pour le temps qui s'écoule 
int ledPinRouge = 13;   //LED  rouge en broche 13
int ledPinOrange = 12;   //LED  orange en broche 12
int ledPinVert = 11;     // LED vert en broche 11
int ledPinButton = 10;  //LED de bouton-poussoir jaune en broche 10
int buttonPin = 8;      //Bouton-poussoir en broche 8
int buttonState;        //Variable pour enregistrement de l’état du bouton-poussoir
int interval = 50;    //Intervalle de temps (1 secondes)
unsigned long prev;     //Variable de temps
int ledState = LOW;     //Variable d’état pour la LED clignotante 

int sensorPin = 0; 
float temperatureC;

void setup()
{
  Serial.begin (9600);
  pinMode(ledPinRouge, OUTPUT);  //Broche LED clignotante comme sortie   
  pinMode(ledPinOrange, OUTPUT);  //Broche LED clignotante comme sortie   
  pinMode(ledPinVert, OUTPUT);  //Broche LED clignotante comme sortie 
  digitalWrite (ledPinRouge,LOW);
  digitalWrite (ledPinOrange,LOW);
  digitalWrite (ledPinVert,LOW);
  
  pinMode(ledPinButton, OUTPUT); //Broche LED de bouton-poussoir comme sortie   
  pinMode (buttonPin, INPUT);    //Broche bouton-poussoir comme entrée   
  prev = millis();               //Mémoriser le compteur de temps actuel
} 

void loop()                     
{
float reading = analogRead(sensorPin); 
float temperatureC = reading; 
// float temperatureC = ((reading*5/1023)-0.5)*100;    // mesure de la température en degré celcius
//Serial.println (Volt);
//Serial.println (temperatureC);
if (temperatureC <= 100)
{  
  digitalWrite(ledPinVert, HIGH);
    digitalWrite(ledPinOrange, LOW);
    digitalWrite (ledPinRouge, LOW);
}
else if (temperatureC>100 && temperatureC<400)
{
  if((millis() - prev) > interval)
{    
  prev = millis();    
ledState = !ledState; 
  }
  digitalWrite(ledPinVert, LOW);
  digitalWrite (ledPinRouge, LOW);
  digitalWrite(ledPinOrange, ledState);
}
  else if (temperatureC >= 400)
  {
if((millis() - prev) > interval)
{    
  prev = millis();    
ledState = !ledState; 
}
  digitalWrite(ledPinRouge, ledState); //Bascule la LED rouge }   
  digitalWrite(ledPinVert,LOW);
    digitalWrite(ledPinOrange,LOW);
    digitalWrite(ledPinVert, LOW);
  }
//Interrogation de l’état du bouton-poussoir   
buttonState = digitalRead (buttonPin);   

if(buttonState == HIGH)     
  {int reading = analogRead(sensorPin);
  Serial.println (temperatureC) ;
  }
}
