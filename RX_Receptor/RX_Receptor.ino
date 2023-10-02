#include <SoftwareSerial.h>          //Biblioteca de comunicação do módulo                     
#include <EBYTE.h>                  //Biblioteca do Kris             
  
#define M0_LoRa   18
#define M1_LoRa   19
#define RX_LoRa   5                // Vai no TXD do módulo                     
#define TX_LoRa   4                 // Vai no RXD do módulo                     
#define AUX_LoRa  23
//#define rele     8
                                                  
SoftwareSerial lora(RX_LoRa, TX_LoRa);                 //Definição dos pinos para criar a comunicação serial  
EBYTE LoRa(&lora, M0_LoRa, M1_LoRa, AUX_LoRa);        //Definição dos pinos para criar a comunicação serial

void setup() {
Serial.begin (115200);                         //Definir taxa de trabalho em 9600
//pinMode (rele, OUTPUT);

  //digitalWrite(rele, HIGH);                  //MÓDULO RELÉ INICIA DESLIGADO                              
  lora.begin(115200);
  LoRa.init();                                          
  
  //LoRa.Reset();                            // Inicializa a comunicação e obtem todos os parâmetros do módulo          
  //LoRa.SetAirDataRate(ADR_1K);             // Estabelece a taxa de dados de transmissão            
  //LoRa.SetAddress(1);                      // Estabelece endereço da rede            
  //LoRa.SetChannel(23);                     // Estabelece canal como 23    
  //LoRa.SetSpeed(2);
  //LoRa.SetOptions(5);
  //LoRa.SetTransmissionMode(23);         
  //LoRa.SaveParameters(TEMPORARY);          // Salva todas as definições de forma temporária             

  LoRa.PrintParameters();                      // Imprime todos os parâmetros (configurações) obtidos do módulo         
  LoRa.SetMode(MODE_NORMAL);                    // Define modo de operação como normal         
}
 

void loop() {
  
if (lora.available()>0){
  String input = lora.readString();
  Serial.print(" A Mensagem do Lora é: "); 
  Serial.println(input);
  }
}