# simulacion Aeropuerto
El servicio de atención al usuario del aeropuerto de Valencia está registrando quejas frecuentes de sus
usuarios en relación al uso de sus instalaciones. Con el objeto de solucionar estos problemas se solicita un
proyecto de mejora de las instalaciones.
La empresa adjudicataria del contrato con el fin de realizar las modificaciones necesarias en las instalaciones
decide llevar a cabo una fase previa de simulación, para lo que instala en el aeropuerto un sistema de
computación ubicua de forma que cada zona del aeropuerto está controlada por medios informáticos y
puedan estudiar durante unos meses como interaccionan los distintos usuarios del aeropuerto sus
instalaciones
##Compilar el simulador:
make 
### Resultados
Ejecucion con 5000 individuos
```
Tiempo Medio Tripulacion: 49.6094 SD: 16.6677 Minutos...
Tiempo Medio Operarios: 60.9455 SD: 13.1936 Minutos...
Tiempo Medio U_ENTRANTES: 60.904 SD: 15.4579 Minutos...
Tiempo Medio U_SALIENTES: 35.1875 SD: 14.6845 Minutos...
File saved: ./Resultados/Aeropuerto.csv
```

##Compilar los test estadísitcos
make test
### Resultados
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
