#ifndef DATALOADING_H_
#define DATALOADING_H_

int getPalabra(char palabra[], char mensaje[], char mensajeErrorFinal[]);
int getCodigoVuelo(char codigo[], int lenCodigo);
int getPassegerType(int* typePassenger);
int getPrice(float* price);
int getStatusFlight(int* statusFlight);
int getStr_StatusFlight(char statusStr[], int statusNum);
int getNum_StatusFlight(char statusStr[], int* statusNum);
int getNum_PassegerType(char passegerTypeStr[], int* passegerTypeNum);
int getStr_PassegerType(char passegerTypeStr[], int passegerTypeNum);

#endif /* DATALOADING_H_ */
