void timepo(int *segundos, int *minutos, int *horas){

*minutos=*segundos/60;

*segundos=(*segundos-(*minutos*60));

*horas=*minutos/60;

*minutos=(*minutos-(*horas*60));

}
