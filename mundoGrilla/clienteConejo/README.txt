#Aqui explicare en amyor detalle el file conejos.cpp

GRILLA

Tengo una estructura grilla que guarda un char segun el animal q se encuentra ahi:
'c' = conejo
'z' = zorro
'v' = vacio

Tambien posee un entero que guarda la cantidad de hierba en esa grilla.

CONEJO
La clase conejo posee una coordenada x y una y(px,py), para su posicion, posee energia que al llegar a 0 hace morir al conejo(eso deben hacerlo), y tambien si la edad lllega a 10, debe morir el conejo
por ahora el conejo solo se mueve, los chicos de IA estan trabajando en eso

MAIN

Tengo un entero q guarda el numero de conejos, el cual sera random, uso el mt19937(MERSENNE TWISTER) para generar aleatorios(mas informacion consultar cppreference)

Creo un vector de vectores de 100*100 con valores default de Grilla, esta sera como una copia de mi mundo

Tengo un Map, el cual guardara la posicion del conejo(en un pair) y un puntero hacia este.
Para mayor referecnia de un map leer en cppreference.
el siguiente bucle me genera los conejos en posiciones random usando el mt_rand, con la semilla ya definida anteriormente.

Segun Acuerdo nosotros enviamos primero la informacion, entonces tengo un array de chars que guardara las posiciones de los conejos de la sgte forma:
Ejm:
	"102343545606" esto quiere decir q tiene 3 conejos:
		       posicion (10,23)
		       posicion (43,54)
		       posicion (56,06)
es decir las posiciones se concatenan en un string, el q luego sera enviado a Mundo por medio de sockets

luego vamos al bucle grande(while(true)), dentro empieza con un puntero q guarda la informacion recibida, aunq falta arreglar algunas cosas con los sockets, lo transformo en un string llamado datos, luego comienzo a hacer la interpretacion de lo enviado por mundo como actualizar la hierba y la posicion de los zorros, tambien se toma en cuenta q si un zorro esta en la posicion donde de haber un conejo, entonces asumiremos q el zorro mato al conejo, entonces tenemos que quitarlo del Map, y tambien borrar con delete su objeto, asi como actualizar la matriz y decir q hay un zorro, si hay consultas por le booleano "hz" es para saber si las coordenadas son de un zorro o de la hierba, porque luego q viene una 'z', significa que comienzan a llegar coordenadas de la hierba, estas llegan de forma similar a la forma en como entregamos.
ejemplo:
	"103401023402z11224567" significa q la hierba en posicion (10,34) es de tamaño 01 y la hierba en (02,34) es de tamaño 02, luego de la z significa q son zorros, y q tengo uno en la posicion (11,22) y otro en (45,67)segun eso updateamos nuestro vector de vectores y nuestro map, luego tenemos q updatear informacion por conejo como q decrementa su energia o q aumenta su edad y llamamos a movimiento de cada 1, asi como tambien actualizar las posiciones de los conejos en el Map asi como en el vector de vectores.
	
Finalmente, tenermos q guardar la info de posiciones nuevas de conejos en un string del formato ya explicado para enviarlo a mundo, solo conejos, y luego por medio del socket enviamos a mundo, y asi repetimos el ciclo
