/** @file
Questo file contiene la definizione del tipo `Item` e la documentazione delle
funzioni primitive (e non) relative alle liste. Si noti che il comportamento di
queste funzioni è indipendente dalla definizione di `ElemType`.
*/

#ifndef LIST_H_
#define LIST_H_

#include "elemtype.h"

#include <stdbool.h>
#include <stdio.h>

/*****************************************************************************/
/*                           Item & Primitives                               */
/*****************************************************************************/

/** @brief Definizione del tipo `struct Item`. */
struct Item {
    ElemType value; /*!< Valore associato all'`Item`. */
    struct Item *next; /*!< Puntatore all'`Item` successivo. */
};
/** @brief Definizione di un nome alternativo per `struct Item`. */
typedef struct Item Item;

/** @brief La funzione `ListCreateEmpty()` crea e ritorna una lista vuota, ovvero
           `NULL`.

@return Lista vuota (`NULL`).
*/
Item *ListCreateEmpty(void);

/** @brief La funzione `ListInsertHead()` aggiunge un nuovo elemento in testa ad 
           una lista e ritorna il puntatore alla nuova lista.

@param[in] e Puntatore all'elemento da aggiugnere in testa alla lista.
@param[in] i Lista a cui aggiungere il nuovo elemento. `i` può essere una lista
            vuota (NULL).

@return Lista risultante.
*/
Item *ListInsertHead(const ElemType *e, Item *i);

/** @brief La funzione `ListIsEmpty(`) verifica se una lista è vuota.

@param[in] i Lista su cui eseguire la verifica.

@return `true` se la lista è vuota, `false` altrimenti.
*/
bool ListIsEmpty(const Item *i);

/** @brief La funzione `ListGetHead()` ritorna un puntatore all'elemento in testa 
            alla lista, senza rimuoverlo.

@param[in] i Lista da cui estrarre il valore in testa. Questa lista non può 
         essere vuota, nel caso in cui lo sia la funzione termina il programma 
         con codice di errore `1`.

@returns Puntatore all'elemento (costante) in testa alla lista.
*/
const ElemType *ListGetHeadValue(const Item *i);

/** @brief La funzione `ListGetTail()` ritorna la lista privata dell'elemento in 
           testa. La funzione NON dealloca la memoria occupata dalla testa
           della lista.

@param[in] i Lista da cui ottenere la coda. La lista non può essere vuota, 
         nel caso in cui lo sia la funzione termina il programma con codice di 
         errore `2`. 

@return Lista ottenuta dopo l'eliminazione della testa. Il valore di ritorno 
        potrebbe essere una lista vuota (`NULL`).
*/
Item *ListGetTail(const Item *i);


/** @brief La funzione `ListInsertBack()` aggiunge un elemento in coda ad una
            lista (anche vuota) e ritorna la lista risultante.

@param[in] i Lista a cui aggiungere l'elemento specifciato. Questa lista può
            essere vuota (`NULL`).
@param[in] e Puntatore all'elemento da aggiugnere in testa alla lista. Il valore 
         contenuto in e non viene modificato.

@return  Lista ottenuta dopo l'aggiunta dell'elemento.
*/
Item *ListInsertBack(Item *i, const ElemType *e);

/** @brief La funzione `ListDelete()` libera la memoria occupata dagli elementi di 
           una lista.

@param[in] i Lista di cui liberare la memoria, può essere vuota (`NULL`).

@return Non ci sono valori di ritorno.
*/
void ListDelete(Item *i);

/*****************************************************************************/
/*                             Non Primitives                                */
/*****************************************************************************/

/** @brief La funzione `ListWrite()` stampa la lista specificata su file. 
           Nello specifico, la funzione stampa il carattere "[" seguito dagli 
           elementi della lista, separati dai caratter ", ", e dal carattere "]". 
           La stampa degli elementi dipende dalla definizione di `ElemType`. 

@param[in] i Lista da stampare su file: può essere vuota e non viene modificata.
@param[in] f `FILE *` su cui stampare la lista.

@return Non ci sono valori di ritorno.
*/
void ListWrite(const Item *i, FILE *f);

/** @brief La funzione `ListWriteStdout()` stampa la lista specificata su `stdout`.
           Nello specifico, la funzione stampa il carattere "[" seguito dagli
           elementi della lista, separati dai caratter ", ", e dal carattere "]".
           La stampa degli elementi dipende dalla definizione di `ElemType`.

@param[in] i Lista da stampare su `stdout`: può essere vuota e non viene modificata.

@return Non ci sono valori di ritorno.
*/
void ListWriteStdout(const Item *i);

/*****************************************************************************/
/*                     Additionally Exam Primitives                          */
/*****************************************************************************/

/** @brief La procedura permette di calcolare valore minimo, valore massimo e dimensione
        in termine di numero di elementi di una lista.

@param[in] i Puntatore all'item in testa alla lista di cui si desidera conoscere
        valore minimo, valore massimo e dimensione in termini di numero di elementi.
@param[out] min Minimo valore presente nella lista.
@param[out] max Massimo valore presente nella lista.
@param[out] size Numero di elementi della lista.

@return Non ci sono valori di ritorno.
*/
void GetMinMaxSize(const Item *i, int *min, int *max, int *size);

/** @brief La funzione concatena le due liste specificate senza allocare memoria.

@param[in] i1 Puntatore all'item in testa alla prima lista da concatenare. Può
        essere NULL.
@param[in] i2 Puntatore all'item in testa alla seconda lista da concatenare. Può
        essere NULL.

@return Puntatore all'item in testa alla lista risultato della concatenazione.
    Può	essere NULL.
*/
Item *ConcatList(Item *i1, Item *i2);

#endif // LIST_H_

