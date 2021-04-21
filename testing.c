#include "pa2m.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EXITO 0
#define ERROR -1
#define MAX_VECTOR_CHICO 10
#define MAX_VECTOR_MEDIO 100
#define MAX_VECTOR_GRANDE 10000

void prueba_creacion_lista(){

	lista_t* lista = lista_crear(NULL);

	pa2m_afirmar(lista != NULL, "Puedo crear una lista vacia");

	lista_destruir(lista);
}

void pruebas_insercion_simple_lista(){

	lista_t* lista = lista_crear(NULL);

	char letra = 'a';

	lista_insertar(lista, &letra);

	pa2m_afirmar(*(char*)lista_primero(lista) == letra, "Puedo insertar 1 elemento");
	pa2m_afirmar(lista_vacia(lista) != true, "La lista no está vacía");
	pa2m_afirmar(lista_elementos(lista) == 1, "La cantidad de elementos es igual a 1");
	
	lista_borrar(lista);
	pa2m_afirmar(lista_elementos(lista) == 0, "La cantidad de elementos es cero luego de borrar");
	
	lista_destruir(lista);
}

void pruebas_insercion_extrema_lista(){
	
	lista_t* lista = lista_crear(NULL);

	int contador = 0;
	int vector[MAX_VECTOR_GRANDE];

	for (int i = 0; i < 10000; i++){
		vector[i] = contador;
		contador++;
	}

	for (int i = 0; i < 10000; i++){
		lista_insertar(lista, &vector[i]);
	}


	pa2m_afirmar(lista_elementos(lista) == 10000, "Puedo insertar 10.000 elementos");

	pa2m_afirmar(lista_vacia(lista) == false, "La lista no está vacia");


	int elemento_a_borrar = *(int*)lista_elemento_en_posicion(lista, 9998);

	lista_borrar_de_posicion(lista, 9998);

	int elemento_nuevo = *(int*)lista_elemento_en_posicion(lista, 9998);

	pa2m_afirmar(elemento_nuevo == (elemento_a_borrar + 1), "Puedo borrar el ante ultimo de la lista");


	elemento_a_borrar = *(int*)lista_elemento_en_posicion(lista, 5000);

	lista_borrar_de_posicion(lista, 5000);

	elemento_nuevo = *(int*)lista_elemento_en_posicion(lista, 5000);

	pa2m_afirmar(elemento_nuevo == (elemento_a_borrar + 1),
		"El elemento de la posicion 500, luego de ser borrado, es reemplazado por su siguiente");


	int numero = -1;

	lista_insertar_en_posicion(lista, &numero, 0);

	pa2m_afirmar(*(int*)lista_elemento_en_posicion(lista, 0) == numero, "Puedo insertar un elemento al principio de la lista");


	lista_borrar_de_posicion(lista, 1);

	pa2m_afirmar(*(int*)lista_elemento_en_posicion(lista, 1) == 1, "Puedo eliminar el 2do de la lista y es reemplazado por su siguiente");


	numero = 5000;

	lista_insertar_en_posicion(lista, &numero, 5001);

	pa2m_afirmar(*(int*)lista_elemento_en_posicion(lista, 5001) == numero, "Puedo insertar un elemento en la posicion 501");


	pa2m_afirmar(lista_elemento_en_posicion(lista, 10500) == NULL, "No puedo acceder a la posicion 10.500 porque no existe");


	numero = 10000;

	lista_insertar_en_posicion(lista, &numero, 10500);

	pa2m_afirmar(*(int*)lista_ultimo(lista) == numero,
		"Inserta al final de la lista si le paso una posicion mayor a la cantidad de elementos");


	size_t cant_elementos_antes = lista_elementos(lista);

	for (int i = 0; i < 3000; i++){
		lista_borrar(lista);
	}

	pa2m_afirmar((lista_elementos(lista) + 3000) == cant_elementos_antes, "Se pudieron borrar 3000 elementos al final de la lista");
	

	cant_elementos_antes = lista_elementos(lista);

	for (int i = 1000; i < 3000; i++){
		lista_borrar_de_posicion(lista, 2500);
	}

	pa2m_afirmar((lista_elementos(lista) + 2000) == cant_elementos_antes, "Se pudieron borrar 2000 elementos en el medio de la lista");

	
	cant_elementos_antes = lista_elementos(lista);

	for (int i = 0; i < 1000; i++){
		lista_borrar_de_posicion(lista, 0);
	}

	pa2m_afirmar((lista_elementos(lista) + 1000) == cant_elementos_antes, "Su pudieron borrar 1000 elementos al principio de la lista");

	while (lista_elementos(lista) > 1){
		lista_borrar(lista);
	}

	pa2m_afirmar(lista_elementos(lista) == 1, "Se borraron casi todos los elementos y quedo 1 solo");

	lista_borrar(lista);

	pa2m_afirmar(lista_elementos(lista) == 0, "La lista esta vacia");

	lista_destruir(lista);
}

void pruebas_de_lista(){
	prueba_creacion_lista();
	pa2m_nuevo_grupo("INSERCION SIMPLE");
	pruebas_insercion_simple_lista();
	pa2m_nuevo_grupo("INSERCION EXTREMA");
	pruebas_insercion_extrema_lista();
}

void prueba_creacion_pila(){

	lista_t* pila = lista_crear(NULL);

	pa2m_afirmar(pila != NULL, "Puedo crear una pila vacia");

	lista_destruir(pila);
}

void pruebas_insercion_simple_pila(){

	lista_t* pila = lista_crear(NULL);

	char vector[MAX_VECTOR_CHICO] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

	lista_apilar(pila, &vector[0]);
	pa2m_afirmar(lista_elementos(pila) == 1, "Puedo apilar 1 elemento");
	pa2m_afirmar(*(char*)lista_ultimo(pila) == 'a', "El primer elemento de la pila es el esperado");

	lista_desapilar(pila);
	pa2m_afirmar(lista_elementos(pila) == 0, "La pila esta vacia");

	for (int i = 0; i < 10; i++){
		lista_apilar(pila, &vector[i]);
	}

	pa2m_afirmar(lista_elementos(pila) == 10, "Puedo apilar 10 elementos");

	char elemento = *(char*)lista_tope(pila);

	pa2m_afirmar(elemento == 'j', "El elemento tope de la pila es el esperado");

	while (lista_elementos(pila) > 4){
		lista_desapilar(pila);
	}

	elemento = *(char*)lista_tope(pila);

	pa2m_afirmar(elemento == 'd', "El cuarto elemento apilado es el esperado");

	while (lista_elementos(pila) > 1){
		lista_desapilar(pila);
	}

	elemento = *(char*)lista_tope(pila);

	pa2m_afirmar(elemento == 'a', "El primer elemento apilado es el esperado");

	lista_desapilar(pila);
	pa2m_afirmar(lista_elementos(pila) == 0, "La pila esta vacia");

	lista_destruir(pila);
}

void pruebas_insercion_extrema_pila(){

	lista_t* pila = lista_crear(NULL);

	int vector[MAX_VECTOR_GRANDE];
	int contador = 0;
	bool hay_distinto = false;

	for (int i = 0; i < 10000; i++){
		vector[i] = contador;
		contador++;
	}

	for (int i = 0; i < 10000; i++){
		lista_apilar(pila, &vector[i]);
	}

	pa2m_afirmar(lista_elementos(pila) == 10000, "Puedo apilar 10.000 elementos");

	lista_desapilar(pila);
	pa2m_afirmar(*(int*)lista_tope(pila) == 9998, "Desapilo un elemento, y el elemento tope es el esperado");

	contador-= 2;

	while (lista_elementos(pila) > 1){

		if (*(int*)lista_tope(pila) != vector[contador])
			hay_distinto = true;

		contador--;
		lista_desapilar(pila);
	}

	pa2m_afirmar(hay_distinto == false, "Luego de desapilar todos los elementos menos 1, los elementos son los esperados");

	pa2m_afirmar(*(int*)lista_tope(pila) == vector[0], "El primer elemento apilado es el ultimo es ser desapilado");

	lista_desapilar(pila);

	pa2m_afirmar(lista_elementos(pila) == 0, "La pila esta vacia");

	lista_destruir(pila);
}

void pruebas_de_pila(){
	prueba_creacion_pila();
	pa2m_nuevo_grupo("INSERCION SIMPLE");
	pruebas_insercion_simple_pila();
	pa2m_nuevo_grupo("INSERCION EXTREMA");
	pruebas_insercion_extrema_pila();
}

void prueba_creacion_cola(){
	
	lista_t* cola = lista_crear(NULL);

	pa2m_afirmar(cola != NULL, "Puedo crear una cola vacia");

	lista_destruir(cola);
}


void pruebas_insercion_simple_cola(){

	lista_t* cola = lista_crear(NULL);

	int vector[MAX_VECTOR_CHICO] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	lista_encolar(cola, &vector[0]);

	pa2m_afirmar(lista_elementos(cola) == 1, "Puedo encolar 1 elemento");
	pa2m_afirmar(*(int*)lista_primero(cola) == 1, "El primer elemento encolado es el esperado");

	lista_desencolar(cola);
	pa2m_afirmar(lista_elementos(cola) == 0, "Desencolo 1 elemento y la cola está vacía");

	for (int i = 0; i < 10; i++){
		lista_encolar(cola, &vector[i]);
	}

	pa2m_afirmar(lista_elementos(cola) == 10, "Puedo encolar 10 elementos");

	lista_desencolar(cola);
	pa2m_afirmar(*(int*)lista_primero(cola) == 2, "El primer elemento encolado es el primero en ser desencolado");

	while(lista_elementos(cola) > 1){
		lista_desencolar(cola);
	}

	pa2m_afirmar(*(int*)lista_primero(cola) == 10,
		"El ultimo elemento encolado, luego de desencolar casi todos, es el primero de la cola");

	lista_destruir(cola);
}

void pruebas_insercion_extrema_cola(){

	lista_t* cola = lista_crear(NULL);

	int vector[MAX_VECTOR_GRANDE];
	int contador = 0;
	bool hay_distinto = false;

	for (int i = 0; i < 10000; i++){
		vector[i] = contador;
		contador++;
	}

	for (int i = 0; i < 10000; i++){
		lista_encolar(cola, &vector[i]);
	}

	pa2m_afirmar(lista_elementos(cola) == 10000, "Puedo encolar 10.000 elementos");

	lista_desencolar(cola);
	pa2m_afirmar(*(int*)lista_primero(cola) == 1, "Desencolo un elemento, y el primer elemento es el esperado");

	contador = 1;

	while (!lista_vacia(cola)){

		if (*(int*)lista_primero(cola) != vector[contador])
			hay_distinto = true;

		contador++;
		lista_desencolar(cola);
	}

	pa2m_afirmar(hay_distinto == false, "Los elementos encolados, luego de desencolar, son los esperados");

	pa2m_afirmar(lista_elementos(cola) == 0, "La cola esta vacia");

	lista_destruir(cola);
}

void pruebas_de_cola(){
	prueba_creacion_cola();
	pa2m_nuevo_grupo("INSERCION SIMPLE");
	pruebas_insercion_simple_cola();
	pa2m_nuevo_grupo("INSERCION EXTREMA");
	pruebas_insercion_extrema_cola();
}

bool son_iguales(void* elemento1, void* elemento2){
	return (*(char*)elemento1 == *(char*)elemento2);
}

void pruebas_iterador_interno(){

	lista_t* lista = NULL;
	char letra = 'a';

	pa2m_afirmar(lista_con_cada_elemento(lista, son_iguales, (void*)&letra) == 0,
		"La cantidad de elementos iterados es cero si envio una lista nula");

	lista = lista_crear(NULL);

	pa2m_afirmar(lista_con_cada_elemento(lista, son_iguales, (void*)&letra) == 0,
		"La cantidad de elementos iterados es cero si envio una lista vacia");

	char vector[MAX_VECTOR_MEDIO];

	for (int i = 0; i < 100; i++){
		vector[i] = letra;
	}

	for (int i = 0; i < 100; i++){
		lista_insertar(lista, &vector[i]);
	}

	pa2m_afirmar(lista_con_cada_elemento(lista, NULL, (void*)&letra) == 0,
		"La cantidad de elementos iterados es cero si envio una funcion nula");

	pa2m_afirmar(lista_con_cada_elemento(lista, son_iguales, (void*)&letra) == 100,
		"Todos los elementos de la lista iterados son los esperados");

	lista_destruir(lista);
}

void prueba_iterador_con_lista_vacia(){
	lista_t* lista = lista_crear(NULL);

	lista_iterador_t* iterador = lista_iterador_crear(lista);

	pa2m_afirmar(iterador != NULL, "Puedo crear un iterador con una lista vacia");

	lista_iterador_destruir(iterador);

	lista_destruir(lista);
}

void prueba_iterador_con_lista_nula(){

	lista_t* lista = NULL;

	lista_iterador_t* iterador = lista_iterador_crear(lista);

	pa2m_afirmar(iterador == NULL, "No puedo crear un iterador con una lista nula");
}

void prueba_iterador_elementos_extremo(){
	lista_t* lista = lista_crear(NULL);
	lista_iterador_t* iterador;

	int vector[MAX_VECTOR_MEDIO];
	int contador = 0;

	for (int i = 0; i < 100; i++){
		vector[i] = contador;
		contador++;
	}

	for (int i = 0; i < 100; i++){
		lista_insertar(lista, &vector[i]);
	}

	iterador = lista_iterador_crear(lista);

	contador = 0;

	pa2m_afirmar(*(int*)lista_iterador_elemento_actual(iterador) == vector[contador],
		"El primer elemento del iterador es el esperado");

	while (lista_iterador_tiene_siguiente(iterador) && contador < 49){
		lista_iterador_avanzar(iterador);
		contador++;
	}

	pa2m_afirmar(*(int*)lista_iterador_elemento_actual(iterador) == vector[contador],
		"El elemento del iterador nro 50 es el esperado");

	while (lista_iterador_tiene_siguiente(iterador) && contador < 99){
		lista_iterador_avanzar(iterador);
		contador++;
	}

	pa2m_afirmar(*(int*)lista_iterador_elemento_actual(iterador) == vector[contador],
		"El ultimo elemento del iterador es el esperado");

	pa2m_afirmar(lista_iterador_avanzar(iterador) == false, "Se pudo iterar toda la lista");

	lista_iterador_destruir(iterador);
	lista_destruir(lista);
}

void pruebas_iterador_externo(){

	prueba_iterador_con_lista_nula();
	prueba_iterador_con_lista_vacia();
	prueba_iterador_elementos_extremo();

	lista_t* lista = lista_crear(NULL);
	lista_iterador_t* iterador;

	int vector[MAX_VECTOR_MEDIO];
	int contador = 0;

	for (int i = 0; i < 100; i++){
		vector[i] = contador;
		contador++;
	}

	for (int i = 0; i < 100; i++){
		lista_insertar(lista, &vector[i]);
	}

	iterador = lista_iterador_crear(lista);

	bool hay_distinto = false;
	contador = 0;

	while (lista_iterador_tiene_siguiente(iterador)){
		if (*(int*)lista_iterador_elemento_actual(iterador) != vector[contador]){
			hay_distinto = true;
		}

		lista_iterador_avanzar(iterador);
		contador++;
	}

	pa2m_afirmar(hay_distinto == false, "Todos los elementos iterados son los esperados");

	lista_iterador_destruir(iterador);
	lista_destruir(lista);
}

void pruebas_de_iterador(){
	pa2m_nuevo_grupo("ITERADOR INTERNO");
	pruebas_iterador_interno();
	pa2m_nuevo_grupo("ITERADOR EXTERNO");
	pruebas_iterador_externo();
}

void pruebas_de_error_y_null(){

	lista_t* lista = NULL;
	lista_t* pila = NULL;
	lista_t* cola = NULL;
	void* elemento = NULL;

	pa2m_afirmar(lista_insertar(lista, &elemento) == ERROR, "No puedo insertar en una lista nula");
	pa2m_afirmar(lista_insertar_en_posicion(lista, &elemento, 5) == ERROR,
		"No puedo insertar en una posicion aleatoria en una lista nula");
	pa2m_afirmar(lista_borrar(lista) == ERROR, "No puedo borrar en una lista nula");
	pa2m_afirmar(lista_borrar_de_posicion(lista, 5) == ERROR,
		"No puedo borrar en una posicion aleatoria en una lista nula");
	pa2m_afirmar(lista_elemento_en_posicion(lista, 0) == NULL, "No puedo obtener el primer elemento de una lista nula");
	pa2m_afirmar(lista_ultimo(lista) == NULL, "No puedo obtener el ultimo elemento de una lista nula");
	pa2m_afirmar(lista_elementos(lista) == 0, "La cantidad de elementos de una lista nula es cero");
	
	pa2m_afirmar(lista_apilar(pila, &elemento) == ERROR, "No puedo apilar en una pila nula");
	pa2m_afirmar(lista_desapilar(pila) == ERROR, "No puedo desapilar en una pila nula");
	pa2m_afirmar(lista_tope(pila) == NULL, "No puedo obtener el elemento tope de una pila nula");
	pa2m_afirmar(lista_elementos(pila) == 0, "La cantidad de elementos de una pila nula es cero");

	pa2m_afirmar(lista_encolar(cola, &elemento) == ERROR, "No puedo encolar en una cola nula");
	pa2m_afirmar(lista_desencolar(cola) == ERROR, "No puedo desencolar en una cola nula");
	pa2m_afirmar(lista_primero(cola) == NULL, "No puedo obtener el primer elemento de una cola nula");
	pa2m_afirmar(lista_elementos(cola) == 0, "La cantidad de elementos de una cola nula es cero");
}

int main(){

	pa2m_nuevo_grupo("PRUEBAS DE LISTA");
	pruebas_de_lista();

	printf("\n");

	pa2m_nuevo_grupo("PRUEBAS DE PILA");
	pruebas_de_pila();

	printf("\n");

	pa2m_nuevo_grupo("PRUEBAS DE COLA");
	pruebas_de_cola();

	printf("\n");

	pa2m_nuevo_grupo("PRUEBAS DE ITERADOR");
	pruebas_de_iterador();

	printf("\n");

	pa2m_nuevo_grupo("PRUEBAS DE ERROR Y NULL");
	pruebas_de_error_y_null();

	pa2m_mostrar_reporte();

	return 0;
}