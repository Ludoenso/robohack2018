/*
Commande de servo-moteur par impulsion
Nanomaître 2015
Le servo est connecté au pin 8 de l'arduino
*/
int periode=20000;// période entre chaque début d'impulsion en microsecondes
int pinServo=8; // variable pour le pin connecté à la commande du servo

void setup() {
  pinMode(pinServo,OUTPUT);// on prépare le pin en mode OUTPUT
  digitalWrite(pinServo,LOW); // on l'initialise à l'état bas
}

//boucle principale
void loop() {
  for (int angle=0;angle<=180;angle+=5){//on fait varier l'angle de 0 à 180° par tranche de 20°
    setAngle(angle);// on appelle la fonction setAngle définie plus bas
  }
}

//fonction setAngle pour envoyer les impulsions
void setAngle(int a){
  int duree=map(a,0,179,1000,2000);// on transforme l'angle en microsecondes et on stocke dans la variable duree
  digitalWrite(pinServo,LOW);//on met le pin à l'état bas
  
  // la boucle qui suit est nécessaire 
  // pour laisser le temps au servo d'aller à sa position
  for (int t=0;t<300;t++){ 
    digitalWrite(pinServo,HIGH);// on envoie l'impulsion
    delayMicroseconds(duree); // pendant la bonne durée
    digitalWrite(pinServo,LOW); // on stoppe l'impulsion
    delayMicroseconds(periode-duree); // on attend le temps restant pour atteindre la période
  }
}
