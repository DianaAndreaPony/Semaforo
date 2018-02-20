
int carRed = 12; //asignar las luces del coche
int carYellow = 11;
int carGreen = 10;
int button = 9; //boton pin
int pedRed = 8; //asignar las luces peatonales
int pedGreen = 7;
int crossTime =5000; //tiempo para que los peatones crucen
unsigned long changeTime;//tiempo desde que se presiona el botón

void setup() {
    pinMode(carRed, OUTPUT);
    pinMode(carYellow, OUTPUT);
    pinMode(carGreen, OUTPUT);
    pinMode(pedRed, OUTPUT);
    pinMode(pedGreen, OUTPUT);
    pinMode(button, INPUT); 
    digitalWrite(carGreen, HIGH); //enciende las luces verdes
    digitalWrite(pedRed, HIGH); 
}

void loop() {
  int state = digitalRead(button);
        //compruebe si se presiona el botón y es más de 5 segundos desde la última pulsación del botón
        if(state == HIGH && (millis() - changeTime)> 5000){
               //llamar a la función para cambiar las luces
               changeLights();
        }
}

void changeLights() {
  digitalWrite(carGreen, LOW); //verde apagado
  digitalWrite(carYellow, HIGH); //amarillo prendido
  delay(2000); //wait 2 seconds
    
  digitalWrite(carYellow, LOW); //amarillo apagado
  digitalWrite(carRed, HIGH); //rojo prendido
        delay(1000); //espera 1 segundo hasta que sea seguro
        
  digitalWrite(pedRed, LOW); //ped rojo apagado
  digitalWrite(pedGreen, HIGH); //ped verde prendido

  delay(crossTime); //esperar por un período de tiempo preestablecido
    
  //flash el verde de ped
        for (int x=0; x<10; x++) {
          digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
         }
          
  digitalWrite(pedRed, HIGH);//encender rojo en
  delay(500);

  digitalWrite(carRed, LOW); //rojo apagado
  digitalWrite(carYellow, HIGH); //amarillo prendido  
  delay(1000);
  digitalWrite(carYellow, LOW); //amarillo apagado
  digitalWrite(carGreen, HIGH); 

  changeTime = millis(); //registre el tiempo desde el último cambio de luces
  //luego regrese al ciclo principal del programa
}
