// queue::push/pop
#include "Mascota.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto mascota dado en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Mascota*mascota, int posicion)
{

    ofstream MyFile(nombre_archivo.c_str(),ios::in | ios::binary);// Creamos el archivo MyFile y lo abrimos en modo lectura y escritura para no borrar lo que hay en el
    //cout << sizeof(mascota->edad);
    MyFile.seekp( posicion*10); //Luego multiplicamos la posicion por 10 ya que es el tamaño que requiere nuestra nueva mascota Y utilizamos el seekp por que mueve el puntero del archivo de salida(posicion a escribir)
    MyFile.write(mascota->nombre.c_str(),6); // Escribimos el Nombre
    MyFile.write((char *) &mascota->edad,4);// Escribimos la edad
    MyFile.close(); //Cerramos el archivo

}

//Devuelve una mascota previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Mascota* leer(string nombre_archivo, int posicion)
{
     Mascota *m; //Creamos un apuntador de tipo mascota
    ifstream MyFile(nombre_archivo.c_str()); //Abrimos el archivo en modo lectura
    MyFile.seekg(posicion*10); //Luego multiplicamos la posicion por 10 ya que es el tamaño que requiere nuestra  mascota Y utilizamos el seekg por que mueve el puntero del archivo de entrada
                char nombre[6]; //Declaramos la variable nombre para guardar el nombre de la mascota
                int edad; // Y la variable edad para guardar la edad de la mascota
                MyFile.read(nombre,6); // Leemos el nombre
                MyFile.read((char*)&edad,4); //Leemos la edad
                m=  new Mascota(edad,nombre); //luego guardamos en m la nueva  mascota con su respectiva edad y nombre
    return m; // retornamos la mascota creada
}

//Devuelve un vector que contenga todas las mascotas previamente escritas (con la funcion escribir()) en un archivo binario con nombre dado
//Nota: El vector debe contener las mascotas ordenadas de acuerdo a la posicion en la que se escribieron
vector<Mascota*> leerTodos(string nombre_archivo)
{
    vector<Mascota*>respuesta; // Vector en el cual vamos a guardar cada uno de los registros de la mascota
    Mascota *m ; // Creamos una variable m de tipo mascosta
    ifstream MyFile(nombre_archivo.c_str()); // Abrimos el archivo en modo de lectura
    MyFile.seekg(0,MyFile.end);  //Nos ubicamos al final de archivo
    int tam = MyFile.tellg()/10;  //Luego  dividimos la posicion actual del archivo entre 10. Para saber la posicion utilizamos el tellg
    MyFile.seekg(0,MyFile.beg); //Luego nos ubicamos en la posicion inicial del archivo.

    for(int i =0 ; i< tam; i++){ // Creamos este ciclo para poder recorrer el archivo.
        char nombre[6]; int edad; //Declaramos las variables para almacenar el nombre y la edad
        MyFile.read(nombre,6); //Leemos el nombre
        MyFile.read((char*)&edad,4); //Leemos la edad
        m = new Mascota(edad,nombre); //agregamos a m la nueva mascota con su edad y su nombre
        respuesta.push_back(m); //Y lo agregamos al vector.
    }
    return respuesta; //Retornamos la mascota
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
