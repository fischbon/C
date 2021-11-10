#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Funkcja wypełnia przekazaną tablice 'array' wartościami od 'min' do 'max' co '1'.
 * @param array zadeklarowana tablica.
 * @param min wartość, od której zaczyna wypełniać się tablica.
 * @param min wartość,  na której kończy wypełniać się tablica.
 * @param limit długość zadeklarowanej tablicy.
 * @retval liczba elementów, którymi została wypełniona tablica.
 * Zwraca '0' jeżeli limit < abs(max - min).
 */
uint16_t FillArray32MinMax(int32_t array[], int32_t min, int32_t max, uint16_t limit)
{
  uint16_t i = 0;
  while(min != max) {
    if(max > min) array[i++] = min++;
    else array[i++] = min--;
    if(!--limit) return 0;
  };
  array[i++] = min;
  return i;
}

/**
 * Funkcja tworzy tablicę 'array' i wypełnia ją wartościami od 'min' do 'max' co '1'. 
 * @param array wskaźnik na niezadeklarowaną tablicę
 * @param min wartość, od której zaczyna wypełniać się tablica.
 * @param min wartość, na której kończy wypełniać się tablica.
 * @retval długość zwróconej tablicy.
 */
uint16_t GetArray32MinMax(int32_t *array[], int32_t min, int32_t max)
{
  uint16_t length;
  if(max > min) length = (uint16_t)(max - min + 1);
  else length = (uint16_t)(min - max + 1);

  *array = (int32_t *)malloc(length * sizeof(int32_t));
  return FillArray32MinMax(*array, min, max, length);
}

/**
 * Wektor typu uint32_t
 * @param buffer wskaźnik na zawartość wektora
 * @param length długość wektora
 */
typedef struct vectorType {
  int32_t *buffer;
  uint16_t length;
} vector_t;

/**
 * Funkcja tworzy wektor 'vector_t' i wypełnia go wartościami od 'min' do 'max' co '1'.
 * @param min wartość, od której zaczyna wypełniać się tablica.
 * @param min wartość, na której kończy wypełniać się tablica.
 * @retval wektor 'vector_t'.
 */
vector_t vectorInit(int32_t min, int32_t max)
{
  vector_t vector;
  vector.length = GetArray32MinMax(&vector.buffer, min, max);
  return vector;
}

/**
 * Funkcja sprawdza, czy wektor jest zainicjowany.
 * @param vector wskaźnika na wektor 'vector_t'.
 * @retval true: wektor zainicjowany, false: wektor niezainicjowany.
 */
bool vectorIsSet(vector_t *vector)
{
  if(vector->length) return true;
  else false;
}

void vectorPrint(vector_t strzalka)                                               //funkcja jest odpowiedzialna za drukowanie
{
if(vectorIsSet(&strzalka)) {                                                      //sprawdza czy taki wektor istnieje
    for(int i = 0; i < strzalka.length; i++) printf("%d ", strzalka.buffer[i]);   //petla for odpowiedzialana za dzialanie funkcji
  }
  else printf("error");                                                           //obsluga wyjatku
}

vector_t vectorSum(vector_t vector1, vector_t vector2)                            //funkcja odpowiedzialna za sumowanie
{
  for(int i=0; vector1.length > i; i++)                                           //petla for odpowiedzialna zad zialanie funkcji
  {
    vector1.buffer[i]=vector1.buffer[i]+vector2.buffer[i];                        //sumowanie wektorow
  }
  return vector1;                                                                 //zwracanie zsumowanego wektora
}

vector_t vectorDifference(vector_t vector1, vector_t vector2)                     //funkcja odpowiedzialna za odejmowanie wektorow
{
  for(int i=0; vector1.length > i; i++)                                           //petla odpowiedzialna za dzialanie funkcji
  {
    vector1.buffer[i]=vector1.buffer[i]-vector2.buffer[i];                        //odejmowanie wektorow
  }
  return vector1;                                                                 //zwracanie odjetych wektorow
}

vector_t vectorMultiplication(vector_t vector1, vector_t vector2)                 //funkcja odpowiedzialna za mnozenie wektorow
{
  for(int i=0; vector1.length > i; i++)                                           //petla for odpowiedzialna za dzialanie funkcji
  {
    vector1.buffer[i]=vector1.buffer[i]*vector2.buffer[i];                        //mnozenie wektorow
  }
  return vector1;
}

int main(void)
{
  vector_t vector2=vectorInit(10,25);                                             //tworzenie wektora drugiego
  vector_t vector = vectorInit(5, 20);                                            //tworzenie wektora pierwszego

  vectorPrint(vector);                                                            //drukuje wektor
  printf("\n\n");                                                                 //tworzenie odstepu pomiedzy liniami
  vectorPrint(vectorSum(vector,vector2));                                         //drukowanie zsumowanego wektora
  printf("\n\n");                                                                 //tworzenie odstepu pomiedzy liniami
  vectorPrint(vectorMultiplication(vector,vector2));                              //drukowanie pomnozonych wektorow
  printf("\n\n");                                                                 //tworzenie odstepu pomiedzy liniami
  vectorPrint(vectorDifference(vector,vector2));                                  //drukowanie odjetych wektorow
  printf("\n\n");                                                                 //tworzenie odstepu pomiedzy liniami

  return 0;
}