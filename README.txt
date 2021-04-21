-------------------------------------------------------
--------------------PRIMERA SECCION--------------------
-------------------------------------------------------

¿QUÉ ES LO ENTREGADO?
El trabajo se basa en crear una lista, pila o cola cuya estructura sea de nodos simplemente enlazados.
Esto quiere decir que cada elemento tendra la direccion de su siguiente.

También se trata de adjuntar 4 Tipos de Dato Abstraco (TDA) en una misma implementacion. Los TDAs
desarrollados son Lista, Pila, Cola e Iterador. Ademas se agrega un codigo de testeo el cual prueba
todas las funciones que se desarrolaron en el trabajo.

[SOLO CORRE DE MANERA CORRECTA EN UNA TERMINAL DE LINUX QUE TENGA GCC, MAKEFILE Y VALGRIND INSTALADOS]

Para compilarlo y ejecutarlo se utliza Makefile. Se pueden realizar ambas instrucciones con una sola
linea de comando. Dependerá de que testeo desee ejecutar (el más simple o el más complejo).

PARA EL MAS SIMPLE:
Se utiliza el comando 'make ejecutar_minipruebas'. En caso de querer saber si hubo un manejo adecuado
de memoria dinamica se utiliza el comando 'make valgrind_minipruebas'.

PARA EL MAS COMPLEJO:
Se utiliza el comando 'make ejecutar_testing'. En caso de querer saber si hubo un manejo adecuado de
memoria dinamica se utiliza el comando 'make valgrind_testing'.

--------------------

¿COMO FUNCIONA EL TRABAJO?
Para cada TDA existe cierta cantidad de funciones primitivas. A continuacion se veran detalladas.

La primeras 2 funciones primitivas que se deben utilizar son:
		-lista_crear():----------------->reserva la memoria necesaria para crear una lista, pila o cola.
		-lista_destruir():-------------->libera la memoria reservada para crear la lista, inclusive
		sus elementos.

En el caso de lista posee las primitivas:
		-lista_insertar():-------------->inserta un elemento al final de la lista.
		-lista_insertar_en_posicion():-->inserta un elemento en una posicion especifica de la lista.
		-lista_borrar():---------------->borra el ultimo elemento de la lista.
		-lista_borrar_de_posicion():---->borra un elemento en una posicion especifica de la lista.
		-lista_ultimo():---------------->devuelve el ultimo elemento de la lista.

En el caso de pila posee las primitivas:
		-lista_apilar():---------------->inserta un elemento al final de la pila.
		-lista_desapilar():------------->borra un elemento al final de la pila.
		-lista_tope():------------------>devuelve el ultimo elemento de la pila.

En el caso de cola posee las primitivas:
		-lista_encolar():--------------->inserta un elemento al final de la cola.
		-lista_desencolar():------------>borra un elemento al inicio de la cola.
		-lista_primero():--------------->devuelve el primer elemento de la cola.

Tambien existe 2 primitivas mas generales que se pueden utilizar tanto en lista, cola y pila.
		-lista_elementos():------------->devuelve la cantidad de elementos que posee la lista.
		-lista_vacia():----------------->determina si la lista esta o no vacia.

En el caso del iterador posee dos tipos: 'iterador interno' e 'iterador externo'.

		ITERADOR INTERNO:
		-lista_con_cada_elemento():----->itera por la lista 1 sola vez comparando elementos segun
		la funcion que reciba por parametro y devuelve la cantidad iterada.

		ITERADOR EXTERNO:
		-lista_iterador_crear():-------->reserva la memoria necesaria para crear 1 iterador.
		-lista_iterador_tiene_siguiente():chequea que el elemento corriente del iterador no sea nulo.
		-lista_iterador_avanzar():------>avanza al siguiente elemento de la lista.}
		-lista_iterador_elemento_actual():devuelve el elemento actual al que apunta el iterador.
		-lista_iterador_destruir():----->libera la memoria reservada para el iterador.

--------------------

IMPLEMENTACION:
Para la creacion de lista, pila y cola se eligio la implementacion de 'nodos simplemente enlazados'.
Ésto es debido a la seguridad que brinda el hecho de unir espacios de memoria no necesariamente
contiguos, ademas de (no en todos los casos) disminuir la complejidad algoritmica que implica
utilizar las funciones primitivas de cada TDA.


-------------------------------------------------------
--------------------SEGUNDA SECCION--------------------
-------------------------------------------------------

¿Qué es lo que entendés por una lista? ¿Cuáles son las diferencias entre ser simple o doblemente enlazada?

Una lista es un tipo de dato abstracto basada en una estructura de datos que agrupa elementos. Dentro de
la lista se tiene una referencia de ultimo elemento y del primer elemento. A diferencia de Pila y Cola, no
hay una politica de entrada y salida de datos (LIFO para Pila, FIFO para Cola), sino que se puede acceder
a cualquier posicion de la lista.

Las diferencias entre una lista simplemente enlazada y una doblemente enlazada son:

1- en la simplemente enlazada, cada elemento tiene la direccion de si siguiente elemento; en cambio, en la
lista doblemente enlazada, cada elemento tiene la direccion de su anterior elemento y de su siguiente elemento.

2- en la doblemente enlazada la implementacion se hace mas tediosa debido a que se debe tener en cuenta no
perder la direccion de su elemento anterior y siguiente. En la simplemente enlazada solo se tiene en cuenta
la direccion del siguiente elemento.

--------------------

¿Cuáles son las características fundamentales de las Pilas? ¿Y de las Colas?

Las caracteristicas fundamentales de las Pilas son sus funciones primitivas (crear, apilar, desapilar, tope,
vacia, destruir) y que su politica de de entrada y salida de datos (en general) es LIFO.
LIFO significa que el ultimo elemeto apilado (nodo final) es el primero en ser desapilado.

Las caracteristicas fundamentales de las Colas son sus funciones primitivas (crear, encolar, desencolar,
primero, vacia, destruir) y que su politica de de entrada y salida de datos (en general) es FIFO.
FIFO significa que el primer elemento encolado (nodo inicial) es el primero en ser desencolado.

--------------------

¿Qué es un iterador? ¿Cuál es su función?

Un iterador es un tipo de dato abstracto encargado de recorrer los elementos de la lista a gusto del usuario.
Su funcion principal es disminuir la complejidad que conlleva recorrer una lista.

--------------------

¿En qué se diferencia un iterador interno de uno externo?

El iterador interno recorre la lista completa de una sola vez, permitiendole al usuario interactuar con cada
elemento que recorre. En cambio, el iterador externo recorre la lista una cierta cantidad de elementos que
el usuario quiera, sin permitirle interaccion con los elementos.

La duracion del iterador externo dependera de si se termina la lista, o de si ésta es modificada en el medio
de su recorrido. En cambio el iterador interno no tiene limite en ese sentido ya que recorre todos los elementos
de una vez, sin quedarse en el medio.
