# simulacion Aeropuerto
El servicio de atención al usuario del aeropuerto de Valencia está registrando quejas frecuentes de sus
usuarios en relación al uso de sus instalaciones. Con el objeto de solucionar estos problemas se solicita un
proyecto de mejora de las instalaciones.
La empresa adjudicataria del contrato con el fin de realizar las modificaciones necesarias en las instalaciones
decide llevar a cabo una fase previa de simulación, para lo que instala en el aeropuerto un sistema de
computación ubicua de forma que cada zona del aeropuerto está controlada por medios informáticos y
puedan estudiar durante unos meses como interaccionan los distintos usuarios del aeropuerto sus
instalaciones
## Compilar el simulador:
make 
### Resultados MAIN
Ejecucion con 5000 individuos
```
Tiempo Medio Tripulacion: 49.0536 SD: 16.3098 Minutos...
Tiempo Medio Operarios: 54.0655 SD: 11.629 Minutos...
Tiempo Medio U_ENTRANTES: 60.8278 SD: 15.2292 Minutos...
Tiempo Medio U_SALIENTES: 39.6103 SD: 15.0429 Minutos...
-------------------------------- Mas informacion ------------------------
Tiempo Medio zona_recepcion: 0.00166671 Minutos
Tiempo Medio zona_checkin: 2.38338 Minutos
Tiempo Medio zona_control: 4.22043 Minutos
Tiempo Medio zona_dutyfree: 8.50991 Minutos
Tiempo Medio zona_oficinas: 6.34905 Minutos
Tiempo Medio zona_pasarela: 4.02115 Minutos
Tiempo Medio zona_cinta: 31.8079 Minutos
Tiempo Medio zona_registro: 2.26395 Minutos
Tiempo Medio zona_vesturio: 14.8824 Minutos
Tiempo Medio zona_comedor: 26.6045 Minutos
Tiempo Medio cambiando Zona: 18.818 Minutos
File saved: ./Resultados/Aeropuerto.csv
File saved: ./Resultados/MediayDesviacion.csv
```

## Compilar los test estadísitcos
make test
### Resultados TEST
Tiempos de las distintas funciones estadísticas
```
exponencial 1059.48 s
getTiempoRegistro 0.1 s
getMaletas 0.944586 s
getPeligrosidad 1.6008 s
getTiempoChecking 154.084 s
getTiempoControl 473.653 s
getTiempoCambiarZona 225.569 s
getTiempoPrensa 99.6 s
getTiempoPerfumeria 148 s
getTiempoSouvenirs 180.6 s
getTiempoCafeteria 715.2 s
getTiempoPlanVuelo 391.029 s
getTiempoEmbarque 148.572 s
getTiempoRecogidaMaletas 528 s
getTiempoRegistroPersonal 126.6 s
getTiempoVestuario 1141.5 s
getTiempoCafeteria 618.105 s
getTiempoComedor 1784.66 s
```

## Version

Version 0.3 

## Autor

* **Mario Vasile** - *Practica de simulacion* - [Twitter](https://twitter.com/MarioSkill)
